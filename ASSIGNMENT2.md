# Assignment 2: Scheduling

For this assignment you will be making modifications to the egos-2000 operating system.  You will be implementing a new scheduler, a new system call, and a few assorted utility programs.

You may complete this assignment in groups of up to two people. If you wish to be in a group you must add your group to the spreadsheet linked in the Canvas assignment no later than 07/02/23 at at 11:59pm. 

## Requirements

### Scheduler
Change the scheduling in scheduler.c from a round robin to a multi-queue priority scheduler.  Priorities are represented as integers from 1 to 10 with 1 being the highest priority.  Each priority level must have its own queue.  The scheduler shall select the process from the queue with the highest priority level to run.  To keep from starving processes, your scheduler must implement aging.  Each time all the processes in a priority level are run every process with priority levels lower are moved up a priority level.  For example, if the priority level 1 queue completes then before those processes are run again all priority two processes are temporarily promoted to priority one. All priority three processes are temporarily promoted to prioirity two, etc.  Once a process is allowed to run it is returned back to its original priority.

You can think of your scheduler as having one run queue and 9 levels of waiting queues.

You must keep both schedulers, the round robin and your new scheduler.  You will use a #define and #ifdef / #endif to choose the scheduler you want to compile into your OS.

### Default priority
All processes must start with a default priority of 2, except for the four kernel processes. The kernel processes start with a priority of 1.

### Implement setprio system call
Implement the setprio system call to allow processes to set their priority. The priority must be between 1 and 10.  

### Process control blocks
To the process control block add:
1. Priority, an integer from 1 to 10
2. Current aged priority
3. Number of context switches, an integer representing the nunmber of times a process is scheduled to be run by the scheduler

### kill

Add a user application kill.c that takes a PID as a command line parameter and kills the process that has the user supplied PID.

You will need edit tools/mkfs.c to add your new executable to disk image.  You will need to add a new type of proc_req: PROC_KILL and the associated code in servers.c and sys_proc.c

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
The above example will run 100 times at priority level 2 and print its PID.
You will need edit tools/mkfs.c to add your new executable to disk image.

## How to submit code and report.

Your program source code is to be turned in via the Feedback GitHub pull request. Do not merge this pull request. Submission time is determined by the GitHub system time. You may push your code as often as you wish. Only your last submission will be graded.

## Administrative

This assignment must be coded in C. Any other language will result in 0 points. Your programs will be compiled and graded on the course GitHub Codespace. Code that does not compile with the provided makefile will result in a 0.

## Academic Integrity

This assignment must be 100% your own work. No code may be copied from friends, previous students, books, web pages, etc. All code submitted is automatically checked against a database of previous semester’s graded assignments, current student’s code and common web sources. By submitting your code on GitHub you are attesting that you have neither given nor received unauthorized assistance on this work. Code that is copied from an external source or used as inspiration, excluding the course github, will result in a 0 for the assignment and referral to the Office of Student Conduct.
