
#ifndef DICTIONARY_CRAP
#define DICTIONARY_CRAP

#include <vector>
#include <string>

class dictionary {

	public:
		dictionary();
		dictionary(vector<class T>,vector<class T>);
		dictionary(vector<class T>*);
		~dictionary();



	private:

		vector<class T> key;
		vector<class T> values;

};
#endif //DICTIONARY_CRAP
