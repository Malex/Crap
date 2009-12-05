#include <cstdlib>

class String
{
      protected char* words;
      public:
             unsigned int Lenght;
             
             String(char* raw) //Standard Constructor
             {
                 //Iter the array until Null-Point is found; save array lenght
                 for(int i=0;*(raw+i);i++) {}
                 words = (char*) malloc (sizeof(char)*i);
                 Lenght = i;
                 for(int j=0;j<i;j++)
                         *(words+j) = *(raw+j);
             }
             
             ~String()
             {
                 delete Lenght;
                 free(words);
             }
      
             char* read()
             {
                   char* ret = new char [Lenght];
                   for(int i=0;*(words+i);i++)
                           *(ret+i) = *(words+i);
                   return ret;
             }
             
             String operator +(String app)
             {
                    String* ret;
                    char* tmp = new char [Lenght+app.Lenght];
                    char* read = app.read();
                    for(int i=0;i<Lenght;i++)
                            *(tmp+i)=*(words+i);
                    for(int j=0;j<app.Lenght;j++)
                            *(tmp+i+j)=*(read+j);
                    ret = new String(tmp);
                    delete[] tmp;
                    free(read);
                    return *ret;
             }
             
             String operator *(unsigned int times)
             {
                    String* ret;
                    unsigned int len = Lenght*times;
                    char* tmp = new char [len];
                    for(int i=0, j=0; j<len; (i+1<Lenght)?i++:i=0, j++)
                            *(tmp+j)=*(words+i);
                    ret = new String(tmp);
                    delete len;
                    delete[] tmp;
                    return ret;
             
             static String capitalize(String src)
             {
                 String* ret;
                 char* read = src.read();
                 if(*read>=97 && *read<=122)
                              *read-=32;
                 ret = new String(read)
                 free(read);
                 return *ret;
             }
};
