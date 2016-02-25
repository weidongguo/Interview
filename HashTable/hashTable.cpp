#include <iostream>
#include <unordered_map>

int main(){
	std::unordered_map<int*, int> mymap;
	int *ptr = new int(100);
	int *ptr2 = new int(203);		
	std::cout << ptr << std::endl << ptr2 << std::endl;

	mymap[ptr] = 2;
	mymap[ptr2] = 3;
	mymap[new int(2)];
	for(auto& i: mymap){
		std::cout << i.first << ": " << i.second << std::endl;
	}

}
