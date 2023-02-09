#include"cmath.h"

#if 0
/*
	computes log2 of an unsigned integer

	classic loop variant.
*/
uint32_t
log2u32(uint32_t n)
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
log2u32(uint32_t n)
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

inline int32_t
i32log2f32(float n)
{
	return ((f32asu32(n)>>23) & 0xff) - 127;
}
