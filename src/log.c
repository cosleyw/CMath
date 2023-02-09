#include"common.h"

#if 0
/*
	computes log2 of an unsigned integer

	classic loop variant.
*/
uint32_t
log2u(uint32_t n)
{
	uint32_t approx = 0;
	while(n>>=1)
		approx++;

	return approx;
}
#endif

/*
	computes log2 of an unsigned integer

	its a binary search.
*/
uint32_t
log2u(uint32_t n)
{
	uint32_t approx = 0, bit = 1<<5;
	do{
		if(n >> bit >= 1){
			approx |= bit;
			n >>= bit;
		}
	}while(bit >>= 1);

	return approx;
}
