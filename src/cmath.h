
#ifndef CMATH_CMATH_H
#define CMATH_CMATH_H
#include"common.h"

uint32_t sqrtu32(uint32_t);
float sqrtf32(float);

uint32_t expu32(uint32_t, uint32_t);

uint32_t log2u32(uint32_t);
uint8_t ilog2f32(float);

/*
	converts uint32_t to float
*/
inline float
u32asf32(uint32_t a)
{
	union{
		float f;
		uint32_t i;
	} conv = {.i = a};

	return conv.f;
}

/*
	converts uint64_t to double
*/
inline double
u64asf64(uint64_t a)
{
	union{
		double f;
		uint64_t i;
	} conv = {.i = a};

	return conv.f;
}

/*
	converts float to uint32_t
*/
inline uint32_t
f32asu32(float a)
{
	union{
		float f;
		uint32_t i;
	} conv = {.f = a};

	return conv.i;
}

/*
	converts double to uint64_t
*/
inline uint64_t
f64asu64(double a)
{
	union{
		double f;
		uint64_t i;
	} conv = {.f = a};

	return conv.i;
}


#endif
