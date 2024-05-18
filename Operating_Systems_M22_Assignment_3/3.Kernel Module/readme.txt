3 Kernel Module
my program logic:

1.included all neccessary header files which are required to get access to main kernel functionalities
2. added a GPL licence to allow module loading in kernel
3. variable procID initialised, which will be given as a parameter while running the module

4. static int __init get_info_taskStruct(void): 
The __init attribute indicates that the function is only used during the initialization of the kernel and can be discarded after the kernel has finished booting. 
This attribute is typically used for functions that perform one-time setup tasks, such as setting up data structures or registering drivers. 
The static keyword in the function declaration indicates that the function has local scope and is not visible outside of the file in which it is defined.
printk is a function that is used to print messages to the kernel log buffer.
unload_taskStruct is a function with the __exit attribute. The __exit attribute indicates that the function is only used when the kernel is being unloaded or shut down, and it will not be needed once the kernel has finished shutting down
5. also included a reference link
