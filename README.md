# ice-cream-factory-in-linix-cIce Cream Factory using Multi Thread Programming


A thread is a single sequence stream within in a process. Because threads have some of the properties of processes, they are sometimes called lightweight processes. In a process, threads allow multiple executions of streams. In many respect, threads are popular way to improve application through parallelism. The CPU switches rapidly back and forth among the threads giving illusion that the threads are running in parallel. Like a traditional process i.e., process with one thread, a thread can be in any of several states (Running, Blocked, Ready or terminated). Each thread has its own stack. Since thread will generally call different procedures and thus a different execution history. This is why thread needs its own stack. An operating system that has thread facility, the basic unit of CPU utilization is a thread. A thread has or consists of a program counter (PC), a register set, and a stack space. Threads are not independent of one other like processes as a result threads shares with other threads their code section, data section, OS resources  also known as task, such as open files and signals.

In this project we have implemented Ice cream factory using Multi-Threading, in which component of ice creams are a made by Thread at each counter. These Threads will be executing concurrently with other Threads
It consist of two components Client and Server implemented on Inter process communication with shared memory.
Firstly Server will allocate the shared memory with address to which our Ice cream (Thread) will do function. Then it will write data on thread by allocating flavors to our ice cream and then it will call other processor. After all it will detach and DE-allocate the shared memory segments of our Ice-cream or Thread of client and server.
While in the Client shared memory segments will be allocated and attached to our ice cream components or Threads.
Local semaphore will be used there .It will also show as Ice cream or thread has been successfully created.

Order of ice cream will arrived at first counters then sequence of counter will accomplish the order by providing different flavors for their ice-creams. They will be served by multiple flavors including in critical section and after that it will wait for 5 sec so that ice cream flavors will be assign to ice cream without any hurdle. After completely filling, Ice cream orders will be ready to distribute.




#Instruction:

1.first open terminal to run the server
2.compile server using
	gcc -o ser ser.c
3.now run the server
	./ser

4.Now open another terminal in same folder to run client
5.Compile the client using
	 gcc -o cli -pthread cli.c
6.Now run the client
	./cli

7.It will ask you the numbers of counter you want from (1-10)
