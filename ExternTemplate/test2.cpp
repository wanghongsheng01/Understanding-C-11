#include "test.h"
#include<iostream>
using namespace std;

int main(){
	fun(4);
	std::cout<<"extern template void fun<int>(int)"<<std::endl;
	return 0;
}

