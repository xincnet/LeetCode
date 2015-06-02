#ifndef _LINKSTACK_H_ 
#define _LINKSTACK_H_
#include <stdlib.h>
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode* ElementType;

/*------------------------------------*/

struct StackNode;
typedef struct StackNode* PtrToStackNode;

int isEmpty(PtrToStackNode s);
PtrToStackNode creatStack();
ElementType top(PtrToStackNode s);
void makeEmpty(PtrToStackNode s);
void push(ElementType x, PtrToStackNode s);
void pop(PtrToStackNode s);

struct StackNode
{
	ElementType element;
	struct StackNode* next;
};

int isEmpty(PtrToStackNode s)
{
	return NULL == s->next;
}

PtrToStackNode creatStack()
{
	PtrToStackNode s;
	s = malloc(sizeof(struct StackNode));
	if (s)
	{
		s->next = NULL;
		makeEmpty(s);
	}
	return s;
}
void makeEmpty(PtrToStackNode s)
{
	if (s)
		while(!isEmpty(s))
			pop(s);
}

ElementType top(PtrToStackNode s)
{
	if (!isEmpty(s))
		return s->next->element;
	return 0;
}

void push(ElementType x, PtrToStackNode s)
{
	PtrToStackNode tmpCell;
	tmpCell = malloc(sizeof(struct StackNode));
	if (tmpCell)
	{
		tmpCell->element = x;
		tmpCell->next = s->next;
		s->next = tmpCell;
	}
}

void pop(PtrToStackNode s)
{
	PtrToStackNode fistCell;
	if (!isEmpty(s))
	{
		fistCell = s->next;
		s->next = s->next->next;
		free(fistCell);
	}
}

#endif
