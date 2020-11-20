run.exe: main.c graphics.c keyboard.c ball.c screen.c
	gcc main.c graphics.c keyboard.c ball.c screen.c -o run.exe

main.o: main.c
	gcc -c main.c

graphics.o: graphics.c
	gcc -c graphics.c

keyboard.o: keyboard.c
	gcc -c keyboard.c

ball.o: ball.c
	gcc -c ball.c

screen.o: screen.c
	gcc -c screen.c