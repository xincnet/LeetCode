LIBS = -lm
NAME = climbingStairs
OBJS = ${NAME}.o
main: ${OBJS}
	gcc -o main ${OBJS} ${LIBS}
	rm -f ${OBJS} ${LIBS}	
	#----------------------------------#
	./main
	#----------------------------------#
	rm -f main	
clean:
	rm -f  a.out main ${OBJS}
