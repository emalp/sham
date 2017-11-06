#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>

void main(){

	int addr;
	void *test = (void *) shmat(1376266, NULL, SHM_EXEC);
	
	printf("Got the attached mem %d", addr);

}
