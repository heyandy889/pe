
#include <stdio.h>



void assertEquals(int expected, int actual){
	if(expected != actual){
		printf("fail: expected %d, got %d\n", expected, actual);
	}

}


void assertEqualsArray(int *expected, int *actual, int length){

	for(int i=0; i<length; i++){
		assertEquals(expected[i], actual[i]);
	}

}


int sumArray(int* array, int length){
	
	int total = 0;
	for(int i=0; i<length; i++){
		if(array[i] % 2 == 0){
			total += array[i];
		}
	}

	return total;
}



void generateFiboNumbers(int numTermsToCalculate, int *bigArray){

	bigArray[0] = 1;
	bigArray[1] = 2;

	int i = 2; 

	while( i <= numTermsToCalculate ){
		bigArray[i] = bigArray[i-1] + bigArray[i-2];
		i += 1;
	}

}


int main(){

	int N = 32;
	int fibonacci[N];

	// = = = = =
	printf("testing sum...\n");

	int a[] = {0};
	assertEquals(0, sumArray(a, 1));

	int b[] = {0,1,1,1};
	assertEquals(0, sumArray(b, 4));

	int b1[] = {0,1,2,2};
	assertEquals(4, sumArray(b1, 4));

	int c[] = {0,1,2,3,4,5,6,7,8,9,10};
	assertEquals(30, sumArray(c, 11));

	// = = = = =
	printf("testing fibonacci...\n");

	int exp1[] = {1};
	generateFiboNumbers(1, fibonacci);
	assertEqualsArray(exp1, fibonacci, 1);

	int exp2[] = {1, 2};
	generateFiboNumbers(2, fibonacci);
	assertEqualsArray(exp2, fibonacci, 2);

	int exp4[] = {1, 2, 3, 5};
	generateFiboNumbers(4, fibonacci);
	assertEqualsArray(exp4, fibonacci, 4);

	int expMany[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	generateFiboNumbers(10, fibonacci);
	assertEqualsArray(expMany, fibonacci, 10);

	// = = = = =

	generateFiboNumbers(N, fibonacci);
	for(int i=0; i<N; i++){
		printf("%d:\t%d\n", i,fibonacci[i]);
	}
	printf("sum of evens: %d\n", sumArray(fibonacci, N));

	return 0;
}

