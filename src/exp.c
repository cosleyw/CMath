#include"common.h"

/*
	computes the exponential of two unsigned integers

	classic square and multiply strategy
	which is basically a binary search
*/
uint32_t
expu(uint32_t n, uint32_t u)
{
	uint32_t approx = 1;
	do{
		if(u & 1)
			approx *= n;
		n *= n;
	}while(u>>=1);

	return approx;
}

