
#ifndef DICTIONARY_CRAP
#define DICTIONARY_CRAP

#include <vector>
#include <string>

template<class T>
class dictionary {

	public:
		//dictionary();
		dictionary(vector<std::string>,vector<T>);
		~dictionary();

		T operator[] (std::string) const;

		vector<std::string> keys() const;
		vector<T> values() const;

	private:
		vector<std::string> key;
		vector<T> value;


};
#endif //DICTIONARY_CRAP
