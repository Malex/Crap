#include <cstdlib>
#include "std.h"

class String
{
      protected:
      		char* words;
      public:
             uint Length;

             String(char* raw) //Standard Constructor
             {
                 /*Iter the array until Null-Point is
                 * found; save array lenght */
                 uint i;
                 for(i=0;*(raw+i);i++)
                 {}
                 words = (char*) malloc (sizeof(char)*i);
                 Length = i;
                 for(uint j=0;j<i;j++)
                         *(words+j) = *(raw+j);
             }

             ~String()
             {
                 free(words);
             }

             char* read()
             {
                   char* ret = new char [Length];
                   for(uint i=0;*(words+i);i++)
                           *(ret+i) = *(words+i);
                   return ret;
             }

             String operator +(String app)
             {
                    String* ret;
                    char* tmp = new char [Length+app.Length];
                    char* read = app.read();
                    uint i;
                    for(i=0;i<Length;i++)
                            *(tmp+i)=*(words+i);
                    for(uint j=0;j<app.Length;j++)
                            *(tmp+i+j)=*(read+j);
                    ret = new String(tmp);
                    delete[] tmp;
                    free(read);
                    return *ret;
             }

             String operator *(uint times)
             {
                    String* ret;
                    uint len = Length*times;
                    char* tmp = new char [len];
                    for(uint i=0, j=0; j<len; (i+1<Length)?i++:i=0, j++)
                            *(tmp+j)=*(words+i);
                    ret = new String(tmp);
                    delete[] tmp;
                    return *ret;
	     }

             static String capitalize(String src)
             {
                 String* ret;
                 char* read = src.read();
                 if(*read>=97 && *read<=122)
                              *read-=32;
                 ret = new String(read);
                 free(read);
                 return *ret;
             }
	     static String upper(String src)
	     {
		     String *ret;
		     char* read = src.read();
		     for(uint i=0;i<src.Length;i++)
		     {
			     if(*(read+i)>=97 && *(read+i)<=122)
				     *(read+i)-=32;
		     }
		     ret = new String(read);
		     free(read);
		     return *ret;
	     }
	     static String lower(String src)
	     {
		     String *ret;
		     char* read = src.read();
		     for(uint i=0;i<src.Length;i++)
		     {
			     if(*(read+i)>=65 && *(read+i)<=90)
				     *(read+i)+=32;
		     }
		     ret = new String(read);
		     free(read);
		     return *ret;
	     }
};
