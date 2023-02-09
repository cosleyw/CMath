#include<stdio.h>
#include"src/cmath.h"

/*

this is for testing/validating my heuristics :)

*/

#define min(a, b) ((a) < (b) ? (a) : (b))

int
main(int argc, char **argv)
{
	argc--;
	argv++;

	uint32_t testVal = 1;
	while(testVal){
		uint32_t sqr = sqrtu(testVal);
		for(int64_t i = -1; i < 2; i++){
			int64_t l = testVal - (sqr-1)*(sqr-1),
				a = testVal - sqr*sqr,
			        b = testVal - (sqr+1)*(sqr+1);

			if(min(l, min(a, b)) != a)
				printf("%d \n", testVal);
		}
		testVal++;

		if(!(testVal % 100000000))
			printf("currently at: %d\n", testVal);
	}

	return 0;
}
