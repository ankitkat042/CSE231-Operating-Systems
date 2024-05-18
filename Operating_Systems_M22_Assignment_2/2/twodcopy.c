#include <linux/kernel.h>
#include <linux/syscalls.h>

/*
 * Definition for twodcopy system call 
 */
SYSCALL_DEFINE4(twodcopy, float *, MAT1, float *, MAT2, int, ROW, int, COL)
{
	float kerMat[ROW][COL];
	if(__copy_from_user(&kerMat, MAT1, sizeof(kerMat))) {
		return -EFAULT;
	}

	if(__copy_to_user(MAT2, &kerMat, sizeof(kerMat))){
		return -EFAULT;
	}	

	return 0;
}


