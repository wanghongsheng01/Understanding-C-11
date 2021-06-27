#include "test.h"
#include<iostream>
using namespace std;

extern template void fun<int>(int);

int main(){
	fun(4);
	std::cout<<"extern template void fun<int>(int)"<<std::endl;
	return 0;
}

