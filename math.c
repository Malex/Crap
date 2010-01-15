/* Math.C For Crap Language.
 * This file is written for Crap Languge
 * Math DLL, so the license is the same
 * of that project. Please read the README
 * for more information.
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
	int tmp,rad;
	double tmp2;
	int* r;
	if(num<0)
		return -1;
	else
	{
		if(num==0)
			return 0;
		else
		{
			tmp = (int) num;
			for(*r=1; *r; tmp--)
				rad = (double) int_sqrt(tmp,r);
			tmp2 = (double) num-tmp;
			return rad+(tmp2/(2*rad))-((pow(tmp2,2))/(8*pow(rad,3)+4*rad*tmp2));		
		}
	}
}

int int_sqrt(int num,int* ptr)
{
	int x, r, dp1, L, g[10], j, y ,yn;
	L=0; 
	while(num>0) 
	{ 
		  g[L++]=num%100; 
		    num /= 100; 
	}
	x=r=0; 
	for(j=L-1;j>=0;j--) 
	{ 
		r=r*100+g[j];
		y=0;
		for(dp1=1;dp1<10;dp1++)
		{ 
		yn=dp1*(20*x+dp1); 
		if(yn<=r)
		       	y=yn; 
		else 
			break; 
		} 
		x=x*10+dp1-1;
		r -= y;
	} 
	*ptr=r;
	return x;
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
		return TRUE;
	else
		return FALSE;
}
