/* Math CPP For Crap Language.
 * This file is written for Crap Languge
 * Math DLL, so the license is the same
 * of that Language.
 */
#include "math.h"

double pow(double base, int exp)
{
	int i;
	if(exp==0)
		return 1;
	for(i=1; i<exp; i++)
		base*=base;
	return base;
}

double sum(array_t myarr) /* It read an array and returns the sum of all values*/
{
	int i;
	double ret=0;
	for(i=0; i<myarr.size_t; i++)
		ret+=myarr.array[i];
	return ret;
}
