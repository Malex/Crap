class Int
{
      protected int value;
      public:
             bool isset = false;
             
             Int() {}
             Int(int val)
             {
                     isset = true;
                     value = val;
             }
             
             int read()
             {
                 return value;
             }
             void set(int val)
             {
                  value = val;
             }
             
             Int operator + (Int sum)
             {
                 return *(new Int(value+sum.read()));
             }
             Int operator - (Int sub)
             {
                 return *(new Int(value-sub.read()));
             }
             Int operator * (Int mul)
             {
                 return *(new Int(value*mul.read()));
             }
             Int operator / (Int mul)
             {
                 return *(new Int(value/mul.read()));
             }
             Int operator % (Int mul)
             {
                 return *(new Int(value%mul.read()));
             }
};    