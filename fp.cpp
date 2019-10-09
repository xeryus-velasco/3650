// fp.cpp
#include "fp.h"

fp::fp()
{
	;	// EMPTY
}

fp::~fp()
{
	;	// EMPTY
}

char *fp::myName(void)
{
	return "Xeryus Velasco";
}

FPNumber nan()
{
	FPNumber to_ret {0};
	to_ret.setE(0xFF);
	to_ret.setF(0xFF);
	to_ret.setS(0);

	return  to_ret;
}


int fp::add(int a, int b)
{
	FPNumber fa(a);
	FPNumber fb(b);
	FPNumber result(0);

	// Put your code in here!

	//handle NaN
	if(fa.isNaN() || fb.isNaN())
    {
	    return nan().asInt();
    }

	//handle 0
    if(fb.isZero())
    {
        return fa.asInt();
    }
    else if(fa.isZero())
    {
        return fb.asInt();
    }


	//handle infinity
	//fa is +inf and fb is +inf
    if(fa.isInfinity() && fb.isInfinity())
    {
    	if(fa.s() == fb.s())
	    {
    		return a;
	    }
    	else
	    {
    		return nan().asInt();
	    }

    }



	return result.asInt();
}

int fp::mul(int a, int b)
{
	FPNumber fa(a);
	FPNumber fb(b);
	FPNumber result(0);

	// Put your code in here!

	return result.asInt();
}
