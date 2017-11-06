#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>

void main(){
	int test;

	int addr;
	addr = shmat(1234, 1376266,SHM_EXEC );
	
	printf("Got the attached mem %d", addr);

}
