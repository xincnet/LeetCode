#ifndef __HEAP_H__
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;
typedef int ElementType;

PriorityQueue initialize(int MaxElements);
void insert(ElementType X, PriorityQueue H);
ElementType deleteMax(PriorityQueue H);
bool isFull(PriorityQueue H);
bool isEmpty(PriorityQueue H);
#endif

struct HeapStruct
{
	int capacity;
	int size;
	ElementType* elements;
};

PriorityQueue initialize(int MaxElements)
{
	PriorityQueue H;
	
	if (MaxElements < 0)
		return NULL;
	H = malloc(sizeof(struct HeapStruct));
	if(NULL == H)
		return NULL;
	
	H->elements = malloc((MaxElements + 1) * sizeof(ElementType));

	if (NULL == H->elements)
		return NULL;
	
	H->capacity = MaxElements;
	H->size = 0;
	H->elements[0] = 0x7FFFFFFF;
	
	return H;
}



void insert(ElementType X, PriorityQueue H)
{
	int i;
	
	if (isFull(H)) return;
	for (i = ++H->size; H->elements[i / 2] < X; i /= 2)
	{
		H->elements[i] = H->elements[i / 2];
	}
	H->elements[i] = X;
}



bool isFull(PriorityQueue H)
{
	return (H->capacity <= H->size);
}


ElementType deleteMax(PriorityQueue H)
{
	int i, Child;
	ElementType MaxElement, LastElement;

	if (isEmpty(H)) return H->elements[0];

	MaxElement = H->elements[1];
	LastElement = H->elements[H->size--];

	for (i = 1; i * 2 <= H->size; i = Child)
	{
		Child = i * 2;
		if (Child != H->size && H->elements[Child + 1] > H->elements[Child])
			Child++;

		if (LastElement < H->elements[Child])
			H->elements[i] = H->elements[Child];
		else break;
	}
	H->elements[i] = LastElement;
	return MaxElement;
}

bool isEmpty(PriorityQueue H)
{
	return (0 == H->size);
}


