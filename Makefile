main: main.o screen.o gol.o
	cc -o main main.o screen.o gol.o -g -Wall -fsanitize=address

main.o: main.c screen.h gol.h
	cc -c main.c -g -Wall -fsanitize=address

screen.o: screen.c screen.h
	cc -c screen.c -g -Wall -fsanitize=address

gol.o: gol.c gol.h
	cc -c gol.c -g -Wall -fsanitize=address

release: release_main.o release_screen.o release_gol.o
	cc -o release_main release_main.o release_screen.o release_gol.o -O3

release_main.o: main.c screen.h gol.h
	cc -o release_main.o main.c -c -O3

release_screen.o: screen.c screen.h
	cc  -o release_screen.o screen.c -c -O3

release_gol.o: gol.c gol.h
	cc  -o release_gol.o gol.c -c -O3

clean: main main.o screen.o gol.o
	rm main main.o screen.o gol.o

clean_release: release_main release_main.o release_screen.o release_gol.o
	rm release_main release_main.o release_screen.o release_gol.o
