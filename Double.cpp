
class Double
{
	private:
		union {
			int v_int;
			double v_double;
		} value;
	public:
		bool isset;
		
		Double()
		{
			isset=false;
		}
		
		Double(double val)
		{
			isset=true;
			value.v_double = val;
		}

		double read()
		{	
			return value.v_double;
		}
		
		int read_int()
		{	
			return value.v_int;
		}

		Double operator + (Double add)
		{	
			return (Double) value.v_double+add.read();
		}


};
