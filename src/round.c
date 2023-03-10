#include"common.h"

/*
 	rounds based on the floating point rounding mode

 	FE_DOWNWARD turns it into floor
	FE_UPWARD turns it into ceil
	FE_TONEAREST turns it into round for the most part (if your number is x.5 it will round to x)
*/
float
cmath_roundf32(float n)
{
	return n > 0 ? (n+0x1p23f)-0x1p23f : (n-0x1p23f)+0x1p23f;
}

/*
 	rounds based on the floating point rounding mode

 	FE_DOWNWARD turns it into floor
	FE_UPWARD turns it into ceil
	FE_TONEAREST turns it into round for the most part (if your number is x.5 it will round to x)
*/
double
cmath_roundf64(double n)
{
	return n > 0 ? (n+0x1p52l)-0x1p52l : (n-0x1p52l)+0x1p52l;
}
