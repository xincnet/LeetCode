LIBS = -lm
OBJS = countPrimes.o
main: ${OBJS}
	rm -f main	
	gcc -o main ${OBJS} ${LIBS}
	rm -f ${OBJS} ${LIBS}	
	./main
clean:
	rm -f  a.out main ${OBJS}
