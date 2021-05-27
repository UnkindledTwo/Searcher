#include <iostream>
#include <vector>
#include <cctype>
#include <map>
#include <string>

using namespace std;

class Searcher{
	private:
		bool caseSensitive;
		string parent, child;
	public:

		Searcher(const string parent = "", const string child = "", bool caseSensitive = false){
			this->parent = parent;
			this->caseSensitive = caseSensitive;
			this->child = child;
		}
		
		void setParent(string newParent){
			this->parent = newParent;
		}

		void setChild(string newChild){
			this->child = newChild;
		}

		void setCaseSensitive(bool newCaseSensitive){
			this->caseSensitive = newCaseSensitive;
		}

		vector<int> search(){
			vector<int> returnVal;
			int pLen = parent.length(); int cLen = child.length();
			if(caseSensitive){
				for(int i = 0; i < (pLen - cLen) + 1; i++){
					if(parent[i] == child[0]){
						bool fail = false;
						for(int j = 0; j < cLen; j++){
							if(parent[i+j] != child[j]){
								fail = true;
							}
						}
						if(!fail) returnVal.push_back(i);
					}
				}

			}
			else{
				for(int i = 0; i < (pLen - cLen) + 1; i++){
					if(tolower(parent[i]) == tolower(child[0])){
						bool fail = false;
						for(int j = 0; j < cLen; j++){
							if(tolower(parent[i+j]) != tolower(child[j])){
								fail = true;
							}
						}
						if(!fail) returnVal.push_back(i);
					}
				}

			}
			return returnVal;
		}
};
