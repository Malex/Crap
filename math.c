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
	else if(exp<0)
	{
		base=1/base;
		exp*=-1;
	}
	for(i=1; i<exp; i++)
		base*=base;
	return base;
}

double sqrt(double num) /* to do, inserted only to avoid
* compiler errors */
{
	return num;
}

double sum(array_t myarr) /* It read an array and returns
* the sum of all values*/
{
	int i;
	double ret=0;
	for(i=0; i<myarr.size; i++)
		ret+=myarr.array[i];
	return ret;
}

array_t divisors(int num)
{
	int i,size=0;
	int* arr;
	array_t ret;
	for(i=1;i<sqrt(num);i++)
	{
		if(num%i==0)
		{
			arr[i-1]=i;
			size++;
		}
	}
	ret = (array_t) { size,(double*) arr };
	return ret;
}

unsigned int is_prime(int num)
{
	array_t arr = divisors(num);
	if(arr.size==2)
		return 1;
	else
		return 0;
}
