## 1.Introduction

## SUMMARY
- An operating system is software that manages the computer hardware, as
well as providing an environment for application programs to run.
- Interrupts are a key way in which hardware interacts with the operating
system. A hardware device triggers an interrupt by sending a signal to the
CPU to alert the CPU that some event requires attention. The interrupt is
managed by the interrupt handler.
- For a computer to do its job of executing programs, the programs must be
in main memory, which is the only large storage area that the processor
can access directly.
- The main memory is usually a volatile storage device that loses its contents
when power is turned off or lost
- Nonvolatile storage is an extension of main memory and is capable of
holding large quantities of data permanently.
- The most common nonvolatile storage device is a hard disk, which can
provide storage of both programs and data.
- The wide variety of storage systems in a computer system can be organized
in a hierarchy according to speed and cost. The higher levels are expensive,
but they are fast. As we move down the hierarchy, the cost per bit generally
decreases, whereas the access time generally increases.
- Modern computer architectures are multiprocessor systems in which each
CPU contains several computing cores.
- To best utilize the CPU, modern operating systems employ multiprogramming, which allows several jobs to be in memory at the same time, thus
ensuring that the CPU always has a job to execute.
- Multitasking is an extension of multiprogramming wherein CPU scheduling algorithms rapidly switch between processes, providing users with a
fast response time

- To prevent user programs from interfering with the proper operation of
the system, the system hardware has two modes: user mode and kernel
mode.
- Various instructions are privileged and can be executed only in kernel
mode. Examples include the instruction to switch to kernel mode, I/O
control, timer management, and interrupt management.
- A process is the fundamental unit of work in an operating system. Process management includes creating and deleting processes and providing
mechanisms for processes to communicate and synchronize with each
other.
- An operating system manages memory by keeping track of what parts of
memory are being used and by whom. It is also responsible for dynamically allocating and freeing memory space.
- Storage space is managed by the operating system; this includes providing
file systems for representing files and directories and managing space on
mass-storage devices

- Operating systems provide mechanisms for protecting and securing the
operating system and users. Protection measures control the access of
processes or users to the resources made available by the computer system.
- Virtualization involves abstracting a computer’s hardware into several
- Computing takes place in a variety of environments, including traditional
computing, mobile computing, client–server systems, peer-to-peer systems, cloud computing, and real-time embedded systems.
- Free and open-source operating systems are available in source-code format. Free software is licensed to allow no-cost use, redistribution, and
modification. GNU/Linux, FreeBSD, and Solaris are examples of popular
open-source systems.



## NOTES
> An operating system is a program that manages a computer’s hardware. It
also provides a basis for application programs and acts as an intermediary
between the computer user and the computer hardware. 

>  A computer system can be divided roughly into four
components: the hardware, the operating system, the application programs,
and the users

> We can also view a computer system as consisting of hardware, software,
and data. The operating system provides the means for proper use of these
resources in the operation of the computer system. An operating system is
similar to a government. Like a government, it performs no useful function by
itself. It simply provides an environment within which other programs can do
useful work.

> in some cases, a user sits at a terminal connected to a mainframe or a
minicomputer. Other users are accessing the same computer through other
terminals. These users share resources and may exchange information. The
operating system in such cases is designed to maximize resource utilization—
to assure that all available CPU time, memory, and I/O are used efficiently and
that no individual user takes more than her fair share.

> from the system view, we can view an operating system as a resource allocator. A computer system has many resources that may be required to solve a problem: CPU time, memory space,
file-storage space, I/O devices, and so on. The operating system acts as the
manager of these resources. 

> For a computer to start running—for instance, when it is powered up or
rebooted—it needs to have an initial program to run. This initial program,
or bootstrap program, tends to be simple. Typically, it is stored within
the computer hardware in read-only memory (ROM) or electrically erasable
programmable read-only memory (EEPROM), known by the general term
firmware. It initializes all aspects of the system, from CPU registers to device
controllers to memory contents. The bootstrap program must know how to load
the operating system and how to start executing that system. To accomplish
this goal, the bootstrap program must locate the operating-system kernel and
load it into memory.

> A recent trend in CPU design is to include multiple computing cores
on a single chip. Such multiprocessor systems are termed multicore. They
can be more efficient than multiple chips with single cores because on-chip
communication is faster than between-chip communication. In addition, one
chip with multiple cores uses significantly less power than multiple single-core
chips.

> Another type of multiprocessor system is a clustered system, which gathers
together multiple CPUs. Clustered systems differ from the multiprocessor
systems described in Section 1.3.2 in that they are composed of two or more
individual systems—or nodes—joined together. Such systems are considered
loosely coupled. 

> a cluster consists of several computer systems connected via a
network, clusters can also be used to provide high-performance computing
environments. Such systems can supply significantly greater computational
power than single-processor or even SMP systems because they can run an
application concurrently on all computers in the cluster. The application must
have been written specifically to take advantage of the cluster, however. This
involves a technique known as parallelization, which divides a program into
separate components that run in parallel on individual computers in the cluster.

> One of the most important aspects of operating systems is the ability
to multiprogram. A single program cannot, in general, keep either the CPU
or the I/O devices busy at all times. Single users frequently have multiple
programs running. Multiprogramming increases CPU utilization by organizing
jobs (code and data) so that the CPU always has one to execute.

> In a multiprogrammed system, the operating system simply switches to,
and executes, another job. When that job needs to wait, the CPU switches to
another job, and so on. Eventually, the first job finishes waiting and gets the
CPU back. As long as at least one job needs to execute, the CPU is never idle

> Time sharing (or multitasking) is a logical extension of
multiprogramming. In time-sharing systems, the CPU executes multiple jobs
by switching among them, but the switches occur so frequently that the users
can interact with each program while it is running.

> A time-shared operating system allows many users to share the computer
simultaneously. Since each action or command in a time-shared system tends
to be short, only a little CPU time is needed for each user. As the system switches
rapidly from one user to the next, each user is given the impression that the
entire computer system is dedicated to his use, even though it is being shared
among many users

> A more common method for ensuring reasonable response time is virtual memory, a
technique that allows the execution of a process that is not completely in
memory. The main advantage of the virtual-memory scheme is that
it enables users to run programs that are larger than actual physical memory.
Further, it abstracts main memory into a large, uniform array of storage,
separating logical memory as viewed by the user from physical memory.
This arrangement frees programmers from concern over memory-storage
limitations.

> In order to ensure the proper execution of the operating system, we must be
able to distinguish between the execution of operating-system code and userdefined code. 
At the very least, we need two separate modes of operation: user mode
and kernel mode 

> The dual mode of operation provides us with the means for protecting the
operating system from errant users and errant users from one another. We
accomplish this protection by designating some of the machine instructions that
may cause harm as privileged instructions. 

> System calls provide the means for a user program to ask the operating
system to perform tasks reserved for the operating system on the user
program’s behalf. In all forms, it is the
method used by a process to request action by the operating system

> We must ensure that the operating system maintains control over the CPU.
We cannot allow a user program to get stuck in an infinite loop or to fail
to call system services and never return control to the operating system. To
accomplish this goal, we can use a timer.

> Virtualization is a technology that allows operating systems to run as applications within other operating systems.

> With virtualization, an operating system that is natively compiled for a particular CPU architecture runs within another operating system
also native to that CPU.

