#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include "page_size_calculator.c"
// this only allocates a shared memory ,(takes key as input from user)

int key;
int shm_id;
int sizeOfMem;
int pageSize;
FILE *keymemLocation;
int allids[10];


int detailsWriter(){

	keymemLocation = fopen("keyMemSizepairs", "w");
	
	fprintf(keymemLocation, "%d\n%d\n%d\n", key, sizeOfMem, shm_id);
	if(keymemLocation >0){
		printf("Details written to file!\n");
	}
	else{
		perror("Details could not be written to file! error\n");
		exit(1);
	}
	fclose(keymemLocation);
	return 0;
}


void main(){
	printf("Enter the unique key for your shared memory:\n");
	scanf("%d", &key);
	if(key > 32767){
		perror("Key exceeded limit, exiting\n");
		exit(1);
	}
	printf("Enter the size of memory you want to allocate (in bytes): \n");
	scanf("%d", &sizeOfMem);
	if(sizeOfMem > 1342177280){
		perror("Size of memory exceeded limit, exiting\n");
		exit(1);
	}	

	// CHECK WHAT SHM_HUGETLB IS , OR WHAT  hugetlb pages are

	shm_id = shmget(key, sizeOfMem, IPC_CREAT | IPC_EXCL);

	if(shm_id > 0){
		printf("The shared memory ID is : %d \n", shm_id);
	}
	else{
		perror("ERROR:: Could not create shared memory\n");
		exit(1);
	}	
	pageSize = pageSizeGiver();
	printf("Your memory size will be rounded to the multiple of : %d bytes\n", pageSize);

	detailsWriter();
}

