/* Math Header For Crap Language.
 * This file is written for Crap Languge
 * Math DLL, so the license is the same
 * of that Language.
 */

/* Math Constants */
#define PI 3,141592653589793
#define PI_2 PI/2.0
#define PI_3 PI/3.0
#define PI_4 PI/4.0
#define PI_6 PI/6.0

/* Needed Structure */
typedef struct MYarray
{
	unsigned int size_t;
	double* array;
} array_t;

/* Functions */
double pow(double,int);
double sum(array_t);
