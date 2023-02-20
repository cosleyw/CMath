#ifndef CMATH_TEST_H
#define CMATH_TEST_H

#include<time.h>

//time macro will store how long the given operation took (first argument) in the second argument, which is expected to be a double pointer.
#define TIME(a, b)0;								\
{										\
	clock_t _time_start=clock();						\
	{a}									\
	clock_t _time_end=clock();						\
	*(b)=(double)(_time_end-_time_start)*(1.0l/CLOCKS_PER_SECOND);		\
}0

//prevents value from being optimized away
#define KEEP(a)0;{volatile typeof(a) _time_val=a;}0

#endif
