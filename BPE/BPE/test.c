#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Let's define an exemplary string.
#define TEST_STR "This is a test"

// The memory used in the TEXT SEGMENT equals the exemplary string's lenght
// multiplied by the size of one of its elements.
const unsigned int test_str_lenght = sizeof(TEST_STR)/sizeof(TEST_STR[0]);

// Function for allocation and initialization of a dynamic array of integers.
// The array is created and returned through the function's return value.
int *AllocateAndInitRet(unsigned int size) {
	int *arr = NULL;

	// Allocate the memory on the HEAP segment.
	arr = (int *)malloc(sizeof(int)*size );

	// Initialize all its elements to 0.
	memset(arr, 0, sizeof(int) * size);
	return arr;
}

// Function for allocation and initialization of a dynamic array of integers.
// The array is created and returned through a function's argument.
void AllocateAndInitArg(int **arr, unsigned int size) {

	// Allocate the memory on the HEAP.
	*arr = (int *)malloc(sizeof(int)*size);

	// Initialize all its elements to 0.
	memset(*arr, 0, sizeof(int) * size); 
}

int main() {

	// Prepare a pointer on the STACK. 
	// It will be used to point to the HEAP.
	int *a = NULL;
	AllocateAndInitArg(&a, 40);

	// Use calloc for both initialization and allocation of a dynamic array.
	// We currently use it to store character data.
	char *c = (char *)calloc(50, sizeof(char));
	
	// Always check for pointer's validity before usage.
	if (a != NULL) {
		int i = 0;
		// Initialize all elements of "a" with 1.
		for (; i < 40; i++){
			a[i] = 1;
		}

		// Print all elements of "a".
		for(i = 0; i < 40; i++) {
			printf("%d", a[i]);
		}

		// Free (deallocate) the memory on the HEAP, allocated for "a".
		free(a);
	}

	// Always check for pointer's validity before usage.
	if (c != NULL) {
		// Initialize the "c" dynamic array with the exemplary string.
		strncpy(c, TEST_STR, test_str_lenght);
		// Let's print it out.
		printf("\n%s\n", c);

		// Free (deallocate) the memory on the HEAP, allocated for "c".
		free(c);	
	}

	int *b = AllocateAndInitRet(40);

	// Initialize "b" with multiple 1.
	memset(b, 1, sizeof(int)*40);

	// Reallocate the memory of the array.
	// Unless you do a memcpy, the data will be destroyed.
	b = (int *)realloc(b, sizeof(int)*50);
	
	if (b != NULL){
		int i;

		// Prove the data is destroyed on reallocation.
		// You will see gibberish printed out.
		for(i = 0; i < 40; i++) {
			printf("%d", b[i]);
		}

		// Free (deallocate) the memory on the HEAP, allocated for "b".
		free(b);	
	}

	return 0;
}