#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// The signature is not identical to the one of realloc as we need to know
// the size of the memory previously allocated to guarantee that the initial
// number of bytes will be the same
void * my_realloc(void * ptr, size_t size, size_t new_size){
    void * new_ptr = malloc(new_size);

    memcpy(new_ptr, ptr, size);
    free(ptr);

    return new_ptr;
}

//taken from ex3 for testing purposes
int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = calloc(n1, sizeof(int));
	
	for(int i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = my_realloc(a1, n1*sizeof(int), n2*sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
    if(n2 > n1){
        for(int i = n1; i < n2; i++){
            a1[i] = 0;
        }
    }
	

	for(int i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
    free(a1);
	
	return 0;
}