LIBS = -lm
OBJS = houseRobber.o
main: ${OBJS}
	gcc -o main ${OBJS} ${LIBS}
	rm -f main ${OBJS} ${LIBS}
clean:
	rm -f  main ${OBJS}
