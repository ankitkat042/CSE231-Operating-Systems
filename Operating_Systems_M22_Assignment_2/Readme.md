
# Operating Systems CSE-231
## Assignment 02 Documentation
Ankit Kumar IIIT Delhi 2021015

### 1.1 Thread Scheduling
Three functions `countA()`, `countB()`, and `countC()` count from 0 to 2^32 (4294967296 hardcoded the number to avoid any calculation overhead).

Three file pointers `f`, `o`, and `r` to write the time taken to the files named `fifo_sched.txt`, `other_sched.txt`, and `rr_sched.txt`.

The code is divided into three blocks and each block contains similar functionality with different scheduling. A block of code is explained for better understanding.
![image](https://github.com/community/community/assets/79627254/cea6d16a-047f-428c-b2b7-ffebb09c76d6)

- Initialise the `which` variable to `PRIO_PROCESS` which will be used as t11’s priority using `setpriority()` method [further explained in IBM docs here](https://www.ibm.com/docs/en).
- A thread is created and the location of function `countA` is passed.
- Then the priority is set using the scheduler function `sched_setscheduler`.
- Lastly, the thread is completed and joined using `pthread_join()`.

Then, with 3 different thread scheduling, the code is run 5 times using `for()` loop to get 15 different threads and their respective timings.

The final plot is generated using `plot.py` which uses matplotlib and reads data from the respective files mentioned earlier.

![image](https://github.com/community/community/assets/79627254/174d2c5d-7621-4ea4-931d-3e01dcec06c6)
### 1.2 Process Scheduling
The idea is to run 3 different processes parallel to each other. In this part, I have compiled a Linux kernel thrice using `fork` and `execvp`.

We have to create three parallel processes using `fork` (all three child processes) and use three different `compile.sh` which contains following contents:
![image](https://github.com/community/community/assets/79627254/36795454-10bf-4235-b791-3f6d9f9854c1)
- Each folder will contain its each `compile.sh`.
- Now run `prog.c` and wait for kernel compilation.
- The final time might look like this:
![image](https://github.com/community/community/assets/79627254/fdf53313-d7f3-4775-91a2-90dd4985efc6)
### 2. Kernel Memory Copy (kernel 2d memcpy())

Steps to attain the intentional functionality:
- Create a system call define a function to copy a 2D matrix.
![image](https://github.com/community/community/assets/79627254/b283a06b-529d-4551-be43-d5d79559040c)
- It is using kernel's internal system calls `__copy_from_user` and `__copy_to_user` to copy the memory locations.
- Add the above code in `sys.c` in freshly untarred folder for `linux-x.xx.xx/kernel`.
- After that, add the entry of the system call in `sys64` table at line 451.
- Now compile the kernel and install it in the system using the link [How to Implement a System Call In Linux](https://cool-dev.in/posts/How-to-Implement-a-System-Call-In-Linux/).
- After that, boot into the new kernel and test your code using `2D_systemcall_test.c`.
- The output should look like this:
![image](https://github.com/community/community/assets/79627254/bed13e51-87f0-4ff1-802b-47ea32213ef0)

### Thats it. Make sure you are using kernel session called linux-hojabhai
