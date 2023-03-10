#include"common.h"

#if 0
/*
	computes log2 of an unsigned integer

	classic loop variant.
*/
uint32_t
cmath_log2u32(uint32_t n)
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
cmath_log2u32(uint32_t n)
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

inline int16_t
cmath_i16log2f32(float n)
{
	return ((f32asu32(n)>>23) & 0xff) - 127;
}

/*
	computes log2 of a float

	it appears to be off by one ulp sometimes
	works on anything that isn't nan, subnormal, negative, or infinity
*/
float
cmath_log2f32(float n)
{
	uint8_t bit = 24;
	int64_t res = cmath_i16log2f32(n);
	n = u32asf32((f32asu32(n) & 0x7fffff) | 0x3f800000);

	while(bit--){
		n*=n;
		res<<=1;
		if(f32asu32(n) & 0x40000000){
			res++;
			n = u32asf32(f32asu32(n) - 0x800000);
		}
	}

	return res * 0x1p-24;
}
