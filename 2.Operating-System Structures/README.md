## 2.Operating-System Structures

## SUMMARY

- An operating system provides an environment for the execution of programs by providing services to users and programs.
- The three primary approaches for interacting with an operating system
are (1) command interpreters, (2) graphical user interfaces, and (3) touchscreen interfaces.
-System calls provide an interface to the services made available by an operating system. Programmers use a system call’s application programming
interface (API) for accessing system-call services.
- System calls can be divided into six major categories: (1) process control,
(2) file management, (3) device management, (4) information maintenance,
(5) communications, and (6) protection.
- The standard C library provides the system-call interface for UNIX and
Linux systems.
- Operating systems also include a collection of system programs that provide utilities to users.
- A linker combines several relocatable object modules into a single binary
executable file. A loader loads the executable file into memory, where it
becomes eligible to run on an available CPU.
- There are several reasons why applications are operating-system specific.
These include different binary formats for program executables, different
instruction sets for different CPUs, and system calls that vary from one
operating system to another.

- An operating system is designed with specific goals in mind. These goals
ultimately determine the operating system’s policies. An operating system
implements these policies through specific mechanisms.
- A monolithic operating system has no structure; all functionality is provided in a single, static binary file that runs in a single address space.
Although such systems are difficult to modify, their primary benefit is
efficiency.
- A layered operating system is divided into a number of discrete layers,
where the bottom layer is the hardware interface and the highest layer is
the user interface. Although layered software systems have had some success, this approach is generally not ideal for designing operating systems
due to performance problems.
- The microkernel approach for designing operating systems uses a minimal
kernel; most services run as user-level applications. Communication takes
place via message passing.
- A modular approach for designing operating systems provides operatingsystem services through modules that can be loaded and removed during
run time. Many contemporary operating systems are constructed as hybrid
systems using a combination of a monolithic kernel and modules.
- A boot loader loads an operating system into memory, performs initialization, and begins system execution.
- The performance of an operating system can be monitored using either
counters or tracing. Counters are a collection of system-wide or perprocess statistics, while tracing follows the execution of a program through
the operating system.

## practical exercises.
- What is the purpose of system calls?
    - allows applications to interact with the os and request services.
- What is the purpose of system programs?
    - System programs are the programs that the os provides for the user (file managment, cmd, etc)
    , so They provide basic functionality to users so that users do not need to write their own programs to solve common problems 

-  What is the main advantage of the layered approach to system     design? What are the disadvantages of the layered approach?

    - The monolithic approach is often known as a tightly coupled system because changes to one part of the system can have  effects on other parts. 
    Alternatively, we could design a loosely coupled system. Such a system is divided into separate, smaller components that have specific and limited functionality. 
    All these components together comprise the kernel. The advantage
    of this modular approach is that changes in one component affect only that component, and no others, allowing system implementers more freedom in creating and changing the inner workings of the system.
    `This approach simplifies debugging and system verification. The first layer can be debugged without any concern for the rest of the system.`
    `a few operating systems use a pure layered approach. One reason involves the challenges of defining the functionality of each layer. In addition, the overall performance of such systems is poor due to the overhead of requiring a user program to traverse through multiple layers to obtain an operating-system service.`
- List five services provided by an operating system, and explain how each
creates convenience for users. In which cases would it be impossible for
user-level programs to provide these services?

    - Program Execution
        - on. The operating system loads the contents of a file into memory and begins its execution. A userlevel program could not be trusted to properly allocate CPU-time.
    - File-system manipulation.
        - tion. There are many details in file creation,
        deletion, allocation, and naming that users should not have to perform. Blocks of disk space are used by files and must be tracked.
        Deleting a file requires removing the name file information and
        freeing the allocated blocks. Protections must also be checked
        to assure proper access.

    - I/O
        - ons. It is necessary to communicate with disks, tapes,
        and other devices at a very low level. The user need only specify
        the device and the operation to perform on it, and the system
        converts that request into device- or controller-specic com
    - communication
        - Message passing between systems requires
        messages to be turned into packets of information, sent to the
        network controller, transmitted across a communications medium,
        and reassembled by the destination system.
    - Error detection

-  How could a system be designed to allow a choice of operating systems
from which to boot? What would the bootstrap program need to do?

    
    - Consider a system that would like to run both Windows and three different distributions of Linux.
    Each operating system will be stored on disk. During system boot, a
    special program (which we will call the boot manager) will determine
    which operating system to boot into. This means that rather than initially booting to an operating system, the boot manager will first run
    during system startup. Typically, boot managers must
    be stored at certain locations on the hard disk to be recognized during
    system startup. Boot managers often provide the user with a selection of
    systems to boot into; boot managers are also typically designed to boot
    into a default operating system if no choice is selected.