**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Sleeping - the process is waiting for an event to wake it up and make it run
Ready - the process is waiting in line and ready to run
Running - the process is either running or it is ready to run
Waiting - the process is waiting for an event or for a resource
Terminated - the process has been stopped, usually by receiving a signal
Zombie - the process is dead but have not been removed from the process table

**2. What is a zombie process?**
When a program forks and the child finishes before the parent, the kernel still keeps some of its information about the child in case the parent might need it. The parent needs to check the child's exit status. Then the parent calls wait(). When the process is in between the child terminating and the parent calling wait(), the child is in zombie process.

**3. How does a zombie process get created? How does one get destroyed?**
A zombie process is created when the child terminates and the parent has not called wait() to destroy it yet. It gets destroyed when the parent calls wait() after the child terminates.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
