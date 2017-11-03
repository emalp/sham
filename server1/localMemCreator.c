#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

// this only allocates a shared memory ,(takes key as input from user)

int key;
int sharedMem;
int sizeOfMem;

void main(){
	printf("Enter the unique key for your shared memory:\n");
	scanf("%d", &key);
	printf("Enter the size of memory you want to allocated: \n");
	scanf("%d", &sizeOfMem);	

	//printf("Unique key: %d \n", key);
	// ^^ this has the unique key
	//printf("Size of mem allocated: %d \n", sizeOfMem);

	// CHECK WHAT SHM_HUGETLB IS , OR WHAT  hugetlb pages are

	sharedMem = shmget(key, sizeOfMem, IPC_CREAT | IPC_EXCL);

	if(sharedMem > 0){
		printf("The shared memory location is : %d \n", sharedMem);
	}
	else{
		printf("ERROR:: Could not create shared memory");
	}	
	//  DO PROPER VALIDATION CHECK FOR THIS
}

