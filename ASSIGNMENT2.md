# Assignment 2: Scheduling

## Requirements

1. ### Implement setprio
Implement the setprio system call to allow processes to set their priority.  

### Process control blocks
To the process control block add:
1. Priority, an integer from 1 to 10
2. Number of context switches, an integer representing the nunmber of times a process is scheduled to be run by the scheduler

### ps 
Add functionality to the ps command in ps.c to display:
1. Process priority
2. Number of context switches

```shell
➜ /home/cse3320 ps
PID     STATUS  PRIORITY  CTX
1       11      1
2       5       2
3       4       1
4       4       3
6       4       2
......
```
