#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include "page_size_calculator.c"
// this only allocates a shared memory ,(takes key as input from user)

int key;
int sharedMem;
int sizeOfMem;
int pageSize;

void main(){
	printf("Enter the unique key for your shared memory:\n");
	scanf("%d", &key);
	if(key > 32767){
		printf("Key exceeded limit, exiting\n");
		exit(1);
	}
	printf("Enter the size of memory you want to allocated: \n");
	scanf("%d", &sizeOfMem);
	if(sizeOfMem > 1342177280){
		printf("Size of memory exceeded limit, exiting\n");
		exit(1);
	}	

	// CHECK WHAT SHM_HUGETLB IS , OR WHAT  hugetlb pages are

	sharedMem = shmget(1234, sizeOfMem, IPC_CREAT | IPC_EXCL);

	if(sharedMem > 0){
		printf("The shared memory location is : %d \n", sharedMem);
	}
	else{
		printf("ERROR:: Could not create shared memory");
	}	
	pageSize = pageSizeGiver();
	printf("Page size is : %d", pageSize);
}

