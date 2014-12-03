launch : shelllauncher.o
	gcc -o launch shelllauncher.o
shelllauncher.o : myshell.o
	gcc -c shelllauncher.c
myshell.o : myshell.c
	gcc myshell.c -o myshell.o
clean:
	rm shelllauncher.o myshell.o launch
