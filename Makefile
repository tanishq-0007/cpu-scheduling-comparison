all:
[TAB]gcc main.c fcfs.c sjf.c round_robin.c -o scheduler

run:
	./scheduler

clean:
	del scheduler.exe
