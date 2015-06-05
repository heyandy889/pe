
#include <stdio.h>


void assertEquals(int expected, int actual){
	if(expected != actual){
		printf("fail: %d != %d\n", expected, actual);
	}

}

int sumBelow(int max){

	int total = 0;
	int i = 0;
	while( i < max ){
		if( i%3 == 0){
			total += i;
		}
		else if( i%5 == 0){
			total += i;
		}
		i += 1;
	}
	return total;
}

int main(){

	assertEquals(0, sumBelow(3));
	assertEquals(3, sumBelow(4));
	assertEquals(8, sumBelow(6));
	assertEquals(23, sumBelow(10));
	assertEquals(23, sumBelow(1000));


	return 0;
}

