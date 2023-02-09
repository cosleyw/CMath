#include<stdio.h>
#include"src/cmath.h"
#include"src/test.h"

/*

this is for testing/validating my heuristics :)

*/

#define min(a, b) ((a) < (b) ? (a) : (b))

int
main(int argc, char **argv)
{
	argc--;
	argv++;

	uint32_t testVal = 0;
	do{
		if(val_sqrtu32(testVal))
			printf("%d \n", testVal);

		testVal++;

		if(!(testVal % 100000000))
			printf("currently at: %u\n", testVal);
	}while(testVal);

	return 0;
}
