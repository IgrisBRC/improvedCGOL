main: main.o screen.o gol.o
	cc -o main main.o screen.o gol.o -g -Wall -fsanitize=address

main.o: main.c screen.h gol.h
	cc -c main.c -g -Wall -fsanitize=address

screen.o: screen.c screen.h
	cc -c screen.c -g -Wall -fsanitize=address

gol.o: gol.c gol.h
	cc -c gol.c -g -Wall -fsanitize=address

clean: main main.o screen.o gol.o
	rm main main.o screen.o gol.o
