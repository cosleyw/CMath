
#include"cmath.h"

#if 0
/*
	computes the floor sqrt of an unsigned integer

	its basically a binary search written recursively, not very fast but i think its pretty cool.
*/

uint32_t
sqrtu32(uint32_t n)
{
	uint32_t guess;
	if(n > 0){
		guess = (sqrtu(n>>2)<<1) + 1;
		return guess - (n < guess*guess);
	}

	return 0;
}
#endif


#if 0
/*
	computes the floor sqrt of an unsigned integer

	its a binary search.
*/
uint32_t
sqrtu32(uint32_t n)
{
	uint32_t bit = (1<<15), guess = 0;

	do{
		guess ^= bit;
		if(guess*guess > n)
			guess ^= bit;
	}while(bit >>= 1);

	return guess;
}
#endif

#if 0
/*
	computes the floor sqrt of an unsigned integer

	its still a binary search but i avoid the multiply by shifting

	i use the fact that  (bit + approx)**2 = bit**2 + 2*approx + approx**2
	and then since approx**2 would be part of every subsequent multiplication im able to subtract it from the original and basically ignore it
*/
uint32_t
sqrtu32(uint32_t n)
{
	uint32_t bit = 15, approx = 0;
	do{
		uint32_t guess = (approx<<(bit+1)) + (1<<(bit+bit));
		if(guess <= n){
			approx |= 1<<bit;
			n -= guess;
		}
	}while(bit--);

	return approx;
}
#endif


/*
	computes the floor sqrt of an unsigned integer

	yet another binary search, this one is pretty similar to the last one but i refactored to make it even faster
	apperently chat gpt can generate this, so i deffinetly wasn't the first to find it
*/
uint32_t
sqrtu32(uint32_t n)
{
	uint32_t bit = 1<<30, approx = 0;
	do{
		uint32_t guess = approx + bit;
		approx>>=1;
		if(guess <= n){
			approx |= bit;
			n -= guess;
		}
	}while(bit>>=2);

	return approx;
}

//used for sqrtf32
static uint64_t
sqrtu50(uint64_t n)
{
	uint64_t bit = 1ull<<48, approx = 0;
	do{
		uint64_t guess = approx + bit;
		approx>>=1;
		if(guess <= n){
			approx |= bit;
			n -= guess;
		}
	}while(bit>>=2);

	return approx;
}

/*
	returns the sqrt of a float rounded to nearest

	this function only returns a correct value when n is not infinity, nan, negative, or a subnormal.
	it should be trivial to deal with those cases if you actually want to use this
*/
float
sqrtf32(float n)
{
	uint32_t uval = f32asu32(n);
	//signed to force arith shift
	int8_t e = (uval>>23)-127;
	uint64_t nm = sqrtu50(((uval&0xffffffull)|(1<<23))<<(25+(e&1)));
	//if you want it to round down remove the +(nm&1)
	nm = ((nm>>1)+(nm&1))^(1<<23);
	uint8_t ne = (e>>1)+127;
	return u32asf32((ne<<23)|nm);
}
