#ifndef CMATH_TEST_H
#define CMATH_TEST_H

#include<stdlib.h>
#include<time.h>
#include"cmath.h"

//time macro will store how long the given operation took in the second argument, which is expected to be a double pointer.
#define TIME(a, b){clock_t _time_start=clock();{a}clock_t _time_end=clock();*(b)=(float)(_time_end-_time_start)*(1.0f/CLOCKS_PER_SECOND);}0

//prevents value from being optimized away
#define KEEP(a){volatile typeof(a) _time_val=a;}

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))

/*
	validation function for sqrtu32
*/
inline uint8_t
val_sqrtu32(uint32_t n)
{
	int64_t v = sqrtu32(n);
	int64_t val[] = {(v-1)*(v-1), v*v, (v+1)*(v+1)};
	int64_t err[] = {ABS(val[0] - n), ABS(val[1] - n), ABS(val[2] - n)};

	//case where our value is invalid
	if(val[1] > n)
		return 1;

	//case where the value after ours is closer and valid
	if(err[2] < err[1] && val[2] < n)
		return 1;

	//case where the value before ours is closer and valid
	if(err[0] < err[1] && val[0] < n)
		return 1;

	return 0;
}


#endif
