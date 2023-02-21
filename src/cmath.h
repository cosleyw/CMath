
#ifndef CMATH_CMATH_H
#define CMATH_CMATH_H
#include"common.h"
#include"constants.h"

uint32_t cmath_sqrtu32(uint32_t);
float cmath_sqrtf32(float);
double cmath_sqrtf64(double);

uint32_t cmath_expu32(uint32_t, uint32_t);
float cmath_exp2f32(float);

uint32_t cmath_log2u32(uint32_t);
uint8_t cmath_log2f32(float);

float cmath_roundf32(float);
double cmath_roundf64(double);

#endif
