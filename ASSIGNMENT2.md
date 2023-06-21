# Assignment 2: Scheduling

## Requirements

### Scheduler
CHange the scheduling in scheduler.c from a round robin to a multi-queue priority scheduler.  Priorities are represented as integers from 1 to 10 with 1 being the highest priority.  Each priority level must have its own queue.  The scheduler shall select the process from the queue with the highest priority level to run.  To keep from starving processes, your scheduler must implement aging.  Each time all the processes in a priority level are run every process with priority levels lower are moved up a priority level.  For example, if the priority level 1 queue completes then before those processes are run again all priority two processes a temporarily promoted to priority one. All priority three processes are temporarily promoted to prioirity two, etc.  Once a process is allowed to run it is returned back to its original priority.

You must keep both schedulers, the round robing and your new scheduler.  You will use a #define and #ifdef / #endif to choose the scheduler you want to compile into your OS.

### Implement setprio
Implement the setprio system call to allow processes to set their priority.  

### Process control blocks
To the process control block add:
1. Priority, an integer from 1 to 10
2. Current aged priority
3. Number of context switches, an integer representing the nunmber of times a process is scheduled to be run by the scheduler

### ps 
Add functionality to the ps command in ps.c to display:
1. Process priority
2. Number of context switches

```shell
➜ /home/cse3320 ps
PID     STATUS  PRIORITY  CTX
1       11      1         50    
2       5       2         23
3       4       1         49
4       4       3         12
6       4       2         19
......
```
### test_pri
Add a user program test_pri.c in apps/user.  This program will take two command-line parameters: number of iterations to run and priority.
```shell
➜ /home/cse3320 test_pri 100 2
......
```
The above example will run 100 times at prioirty level 2 and print its PID.
You will need edit tools/mkfs.c to add your new executable to disk image.
