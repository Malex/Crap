#include <vector>
#include <string>
#include <pcrecpp.h>

#include "dictionary.hpp"

using namespace std;
typedef unsigned int uint;

void on_def(string&,string&,string&);

vector<dictionary> globals;

string statements[] = { "def" };
dictionary* stat_regxp = new dictionary<string>((vector<string>)statements,["def\s+(\w+)\s*:\s*(\w+)\s+{?(\w+)}?",""]);

dictionary* stat_func = new dictionary<string>((vector<string>)statements,on_def);

void parse(char**,uint);
void exec(string);

int main(int argc, char* argv[])
{
	parse(argv,argc);

	return 0;
}

void parse(char** args,uint size)
{
	for(uint i=0; i<size; i++) {
		if(args[i]=="-c") {
			exec((string) args[i+1]);
		}
	}
}

void exec(string str) {
	size_t found, start=0;
	vector<string> to_parse;
	vector<pcrecpp::RE> re;
	string u,d,t;

	while(found!=string::npos) {
		found = str.find(";",start);
		to_parse.push_back(str.substr(start,found-start));
		start = found + 1;
	}

	for(uint i=0;i<stat_regxp->size();i++) {
		re.push_back(pcrecpp::RE(stat_regxp[stat_regxp.keys()[i]]);
	}

	for(uint c=0; c<to_parse.size(); c++) {
		for(uint j=0;j<re.size();j++) {
			if(re[j].PartialMatch(to_parse[c],&u,&d,&t)) {
				on_def(u,d,t);
			}
		}
	}
}

void on_def(string& u, string& d, string& t) {
	//TODO
}
