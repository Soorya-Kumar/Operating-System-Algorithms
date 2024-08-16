# Operating System Algorithms

This repository contains implementations of key algorithms used in operating systems, focusing on process scheduling, page replacement, disk scheduling, and synchronization problems. These algorithms are fundamental for understanding how operating systems manage resources efficiently.
Process Scheduling Algorithms

    First-In-First-Out (FIFO): Simple queue-based process scheduling.
    Shortest Job First (SJF): Prioritizes processes with the shortest burst time.
    Shortest Remaining Job First (SRJF): Preemptive version of SJF.
    Round Robin (RR): Time-slice based, cyclic scheduling for fair CPU allocation.
    Priority-Based Scheduling: Assigns CPU based on process priority.

Page Replacement Algorithms

    Least Recently Used (LRU): Replaces the least recently accessed page.
    Optimal Page Replacement: Replaces the page that won’t be needed for the longest time.
    First-In-First-Out (FIFO): Replaces the oldest page in memory.

Disk Scheduling Algorithms

    SCAN: Moves the disk arm towards one end, then reverses direction.
    C-SCAN (Circular SCAN): Like SCAN but only moves in one direction.
    LOOK: Similar to SCAN but stops at the last request before reversing.
    C-LOOK (Circular LOOK): Similar to C-SCAN but stops at the last request in the direction.
    First-Come-First-Serve (FCFS): Serves disk requests in the order they arrive.
    Shortest Seek Time First (SSTF): Prioritizes requests closest to the current head position.

Synchronization Problems

    Sleeping Barber Problem: Classic synchronization problem involving customer and barber threads.
    Producer-Consumer Problem: Demonstrates thread synchronization using shared resources.
    Reader-Writer Problem: Handles priority between readers and writers to avoid data inconsistency.
    Cigarette Smokers Problem: Synchronization problem involving resources shared by multiple processes.
