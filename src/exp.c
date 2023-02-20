#include"common.h"

/*
	computes the exponential of two unsigned integers

	classic square and multiply strategy
	which is basically a binary search
*/
uint32_t
expu32(uint32_t n, uint32_t u)
{
	uint32_t approx = 1;
	do{
		if(u & 1)
			approx *= n;
		n *= n;
	}while(u>>=1);

	return approx;
}


float
exp2f32i(uint16_t e)
{
	uint8_t m = (e+127);
	return u32asf32(m << 23);
}

float
exp2f32(float a)
{
	static const float v[] = { 0x1p+0, 0x1.000002p+0, 0x1.000004p+0, 0x1.00000ap+0, 0x1.000016p+0, 0x1.00002cp+0, 0x1.000058p+0, 0x1.0000bp+0, 0x1.000162p+0, 0x1.0002c4p+0, 0x1.00058ap+0, 0x1.000b16p+0, 0x1.00162ep+0, 0x1.002c6p+0, 0x1.0058c8p+0, 0x1.00b1aep+0, 0x1.0163dap+0, 0x1.02c9a2p+0, 0x1.059b0cp+0, 0x1.0b5586p+0, 0x1.172b82p+0, 0x1.306fep+0, 0x1.6a09e6p+0 };
			
	int16_t ex = a;
	if(a < 0) ex--;
	float res = exp2f32i(ex);
	uint32_t r = (a-ex)*0x1p23;
	int bit = 23;
	while(bit--)
		if(r & (1 << bit))
			res *= v[bit];
	return res;
}
