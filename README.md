# Comparative Analysis of CPU Scheduling Algorithms

## Objective
To compare different CPU scheduling algorithms and determine the most efficient algorithm based on waiting time.

## Algorithms Implemented
1. First Come First Serve (FCFS)
2. Shortest Job First (SJF)
3. Round Robin (RR)

## Input
User provides:
- number of processes
- arrival time
- burst time
- time quantum (for Round Robin)

## Output
Program displays:
- Gantt Chart
- Waiting Time
- Average Waiting Time
- Best Algorithm

## Technologies Used
- C Programming Language
- Linux Concepts
- Makefile
- GitHub

## Project Structure
main.c → controls program flow  
fcfs.c → implements FCFS scheduling  
sjf.c → implements SJF scheduling  
round_robin.c → implements Round Robin scheduling  
scheduler.h → function declarations  
Makefile → compiles project  

## Conclusion
SJF algorithm usually gives minimum waiting time.
Round Robin ensures fair CPU allocation among processes.
