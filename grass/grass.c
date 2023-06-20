/*
 * (C) 2022, Cornell University
 * All rights reserved.
 */

/* Author: Yunhao Zhang
 * Description: grass layer initialization
 * Initialize timer and the process control block; 
 * Spawn the first kernel process, GPID_PROCESS (pid=1).
 */

#include "egos.h"
#include "process.h"
#include "syscall.h"


struct grass *grass = (void*)APPS_STACK_TOP;
struct earth *earth = (void*)GRASS_STACK_TOP;

static int sys_proc_read(int block_no, char* dst) {
    return earth->disk_read(SYS_PROC_EXEC_START + block_no, 1, dst);
}

int main() {
    CRITICAL("Enter the grass layer");

    /* Initialize the grass interface functions */

    grass->proc_alloc = proc_alloc;
    grass->proc_free = proc_free;
    grass->proc_set_ready = proc_set_ready;
    grass->proc_get_pid = proc_get_pid;
    grass->proc_get_proc_set = proc_get_proc_set;

    grass->sys_exit = sys_exit;
    grass->sys_send = sys_send;
    grass->sys_recv = sys_recv;
    
    grass->gettime = mtime_get;

    /* Load and enter the first kernel process sys_proc */
    INFO("Load kernel process #%d: sys_proc", GPID_PROCESS);
    elf_load(GPID_PROCESS, sys_proc_read, 0, 0);
    earth->mmu_switch(GPID_PROCESS);

    proc_init();
    timer_init();
    timer_reset();
    /* For page table translation, interrupt was enabled in earth layer */
    if (earth->translation == SOFT_TLB) earth->intr_enable();

    void (*sys_proc_entry)() = (void*)APPS_ENTRY;
    asm("mv a0, %0" ::"r"(APPS_ARG));
    sys_proc_entry();
}
