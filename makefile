LIBS = -lm
NAME = kthLargestElementInAnArray
OBJS = ${NAME}.o
main: ${OBJS}
	gcc -o main ${OBJS} ${LIBS}
	rm -f ${OBJS}	
	#----------------------------------#
	./main
	#----------------------------------#
	rm -f main	
clean:
	rm -f  a.out main ${OBJS}
