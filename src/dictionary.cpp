#include <vector>
#include <string>
#include "dictionary.hpp"

using namespace std;

dictionary::dictionary(vector<string> keys, vector<T> values)
{
	this->key = keys;
	this->value = values;
}

dictionary::~dictionary()
{
	~(this->key);
	~(this->value);
}

T dictionary::operator[] (string key) const
{
	for(int i=0;
		(i <= this->key.size) && (this->key[i] != key);
		 i++) {}

	if(i==this->key.size) {
		//TODO throw
	} else {
		return this->value[i];
	}
}

vector<string> keys() const
{
	return this->key;
}

vector<T> values() const
{
	return this->value;
}
