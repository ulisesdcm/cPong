run.exe: main.c graphics.c keyboard.c
	gcc main.c graphics.c keyboard.c -o run.exe

main.o: main.c
	gcc -c main.c

graphics.o: graphics.c
	gcc -c graphics.c

keyboard.o: keyboard.c
	gcc -c keyboard.c