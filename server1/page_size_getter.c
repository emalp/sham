#include<unistd.h>
#include<stdio.h>

void main(){
	// this is only for non-portable definitions
	// sysconf(_SC_PAGESIZE) works better for portable apps
	//int pagesize1 = getpagesize();
	//printf("Your page size is 1, %d bytes\n", pagesize1);

	int pagesize2 = sysconf(_SC_PAGESIZE);
	printf("Your computer's page size is , %d bytes\n", pagesize2);
}
