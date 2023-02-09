
#include"common.h"

#if 0
/*
	computes the floor sqrt of an unsigned integer

	its basically a binary search written recursively, not very fast but i think its pretty cool.
*/

uint32_t
sqrtu(uint32_t n)
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
sqrtu(uint32_t n)
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


/*
	computes the floor sqrt of an unsigned integer

	its still a binary search but i avoid the multiply by shifting
*/
uint32_t
sqrtu(uint32_t n)
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

