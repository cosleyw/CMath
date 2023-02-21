#include<stdio.h>
#include<math.h>
#include<fenv.h>
#include"src/test.h"
#include"src/cmath.h"

void printError(double actual, double approx){
	double abserr = fabs(actual - approx);
	double relerr = (actual - approx)/actual;

	printf("actual: %e approx: %e\nabserr: %a relerr: %e\n", actual, approx, abserr, relerr);
}

void
cmath_comparefnf32(float (*a)(float), float (*b)(float))
{
	uint32_t tv = 0x00800000;
	while(tv < 0x7f800000){
		float testv = u32asf32(tv);
		float av = a(testv), bv = b(testv);
		if(av != bv){
			float ta = av*av, tb = bv*bv;
			printError(tb, ta);
		}

		if((tv % 100000000) == 0)
			printf("at %u\n", tv);
		tv++;
	}
}


void
cmath_comparefnf64(double (*a)(double), double (*b)(double))
{
	uint64_t tv = 0x0010000000000000ll;
	while(tv < 0x8000000000000000ll){
		double testv = u32asf32(tv);
		double av = a(testv), bv = b(testv);
		if(av != bv){
			double ta = av*av, tb = bv*bv;
			printError(tb, ta);
		}

		if((tv % 100000000) == 0)
			printf("at %lu\n", tv);
		tv++;
	}
}



/*
	this is for testing/validating my heuristics :)
*/

int
main(int argc, char **argv)
{
	#pragma STDC FENV_ACCESS ON
	//fesetenv(FE_DFL_ENV);
	//fesetround(FE_TONEAREST);
	

	argc--;
	argv++;

	cmath_comparefnf32(cmath_sqrtf32, sqrtf);
	//cmath_comparefnf64(cmath_sqrtf64, sqrt);
	return 0;
}
