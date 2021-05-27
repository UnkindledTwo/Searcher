#include "Search.h"

int main(){
	Searcher *s = new Searcher("alalalaL", "al", true);
	vector<int> A = s->search();
	std::cout << A.size();
	std::cout << std::endl;
	
	return 0;
}
