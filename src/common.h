#ifndef CMATH_COMMON_H
#define CMATH_COMMON_H

/*

	this header will define common types and functions

*/


//NULL, size_t
#include<stddef.h>
//uint_t/int_t types
#include<stdint.h>

/*
	converts uint32_t to float
*/
inline float
u32asf32(uint32_t a)
{
	union _{float f; uint32_t i;};
	return ((union _*)&a)->f;
}

/*
	converts uint64_t to double
*/
inline double
u64asf64(uint64_t a)
{
	union _{double f; uint64_t i;};
	return ((union _*)&a)->f;
}

/*
	converts float to uint32_t
*/
inline uint32_t
f32asu32(float a)
{
	union _{float f; uint32_t i;};
	return ((union _*)&a)->i;
}

/*
	converts double to uint64_t
*/
inline uint64_t
f64asu64(double a)
{
	union _{double f; uint64_t i;};
	return ((union _*)&a)->i;
}

#endif

