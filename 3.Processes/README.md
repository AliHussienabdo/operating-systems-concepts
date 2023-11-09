## 3.Processes

## SUMMARY
- A process is a program in execution, and the status of the current activity of a process is represented by the program counter, as well as other registers.
- The layout of a process in memory is represented by four different sections: (1) text, (2) data, (3) heap, and (4) stack.
- As a process executes, it changes state. There are four general states of a
process: (1) ready, (2) running, (3) waiting, and (4) terminated.
- A process control block (PCB) is the kernel data structure that represents a
process in an operating system.
- The role of the process scheduler is to select an available process to run on
a CPU.
- An operating system performs a context switch when it switches from
running one process to running another.
- The fork() and CreateProcess() system calls are used to create processes on UNIX and Windows systems, respectively.
- When shared memory is used for communication between processes, two
(or more) processes share the same region of memory. POSIX provides an
API for shared memory.
- Two processes may communicate by exchanging messages with one another using message passing. The Mach operating system uses message passing as its primary form of interprocess communication. Windows provides a form of message passing as well.
- A pipe provides a conduit for two processes to communicate. There are
two forms of pipes, ordinary and named. Ordinary pipes are designed for
communication between processes that have a parent–child relationship.
Named pipes are more general and allow several processes to communicate.
- UNIX systems provide ordinary pipes through the pipe() system call.
Ordinary pipes have a read end and a write end. A parent process can, for example, send data to the pipe using its write end, and the child process can read it from its read end. Named pipes in UNIX are termed FIFOs.
- Windows systems also provide two forms of pipes—anonymous and
named pipes. Anonymous pipes are similar to UNIX ordinary pipes. They
are unidirectional and employ parent–child relationships between the
communicating processes. Named pipes offer a richer form of interprocess
communication than the UNIX counterpart, FIFOs.
- Two common forms of client–server communication are sockets and
remote procedure calls (RPCs). Sockets allow two processes on different
machines to communicate over a network. RPCs abstract the concept of
function (procedure) calls in such a way that a function can be invoked on
another process that may reside on a separate computer.
- The Android operating system uses RPCs as a form of interprocess communication using its binder framework.

## NOTES
>   We emphasize that a program by itself is not a process. A program is a
passive entity, such as a file containing a list of instructions stored on disk
(often called an executable fil ). In contrast, a process is an active entity,
with a program counter specifying the next instruction to execute and a set
of associated resources. A program becomes a process when an executable file
is loaded into memory.

>  Although two processes may be associated with the same program, they
are nevertheless considered two separate execution sequences. For instance,
several users may be running different copies of the mail program, or the same
user may invoke many copies of the web browser program. Each of these is a
separate process; and although the text sections are equivalent, the data, heap,
and stack sections vary. 

>  Each process is represented in the operating system by a process control
block (PCB)—also called a task control block.
It contains many pieces of information associated with a specific process,
including these: 
> - Process state. The state may be new, ready, running, waiting, halted, and
so on.
> - CPU registers. 
> -  Program counter. The counter indicates the address of the next instruction
to be executed for this process.
> -  CPU-scheduling information. This information includes a process priority, pointers to scheduling queues.
> - Memory-management information. This information may include such
items as the value of the base and limit registers and the page tables
> - Accounting information. This information includes the amount of CPU
and real time used
> - I/O status information. This information includes the list of I/O devices
allocated to the process, a list of open files, and so on.

>   The objective of multiprogramming is to have some process running at all times
so as to maximize CPU utilization. The objective of time sharing is to switch
a CPU core among processes so frequently that users can interact with each
program while it is running. To meet these objectives, the process scheduler
selects an available process for program execution on a core. Each CPU core can run one process at a time. For a system with a single CPU core, there will never be more than one process
running at a time, whereas a multicore system can run multiple processes at
one time.

>   The number of processes currently in memory is known as the degree of multiprogramming.

>   An I/O-bound process is one that spends more of its time doing I/O than it spends doing
computations. A CPU-bound process, in contrast, generates I/O requests
infrequently, using more of its time doing computations.

>  a ready queue, where they are ready and waiting to execute on 
a CPU’s core This queue is generally stored as a linked list.
Processes that are waiting for a certain
event to occur — such as completion of I/O — are placed in a wait queue
> - The process could issue an I/O request and then be placed in an I/O wait queue.
> - The process could create a new child process and then be placed in a wait
queue while it awaits the child’s termination.
> - The process could be removed forcibly from the core, as a result of an
interrupt or having its time slice expire, and be put back in the ready queue.
> - In the first two cases, the process eventually switches from the waiting state
to the ready state and is then put back in the ready queue. A process continues
this cycle until it terminates, 

>  The role of the CPU scheduler is to select from among the processes that are in the ready queue and allocate a CPU core to one of them.

>  Switching the CPU core to another process requires performing a state
save of the current process and a state restore of a different process. This
task is known as a context switch 

>  When a process creates a new process, two possibilities for execution exist:
> 1. The parent continues to execute concurrently with its children.
> 2. The parent waits until some or all of its children have terminated.

>  Processes executing concurrently in the operating system may be either independent processes or cooperating processes. A process is independent if it does
not share data with any other processes executing in the system. A process
is cooperating if it can affect or be affected by the other processes executing
in the system

>  There are several reasons for providing an environment that allows process cooperation:
Information sharing, Computation speedup, Modularity. 

> Cooperating processes require an interprocess communication (IPC)
mechanism that will allow them to exchange data, There are two fundamental models of
interprocess communication: shared memory and message passing. 

> Typically, a shared-memory region resides in the address space of the process creating the shared-memory segment. Other processes that wish to communicate using this shared-memory
segment must attach it to their address space. Recall that, normally, the operating system tries to prevent one process from accessing another process’s
memory. Shared memory requires that two or more processes agree to remove
this restriction. 

> Message passing provides a mechanism to allow processes to communicate
and to synchronize their actions without sharing the same address space. It
is particularly useful in a distributed environment, where the communicating
processes may reside on different computers connected by a network.
If processes P and Q want to communicate, they must send messages to and
receive messages from each other: a communication link must exist between
them. 

> Asocket is defined as an endpoint for communication. Apair of processes communicating over a network employs a pair of sockets—one for each process.
A socket is identified by an IP address concatenated with a port number. 

