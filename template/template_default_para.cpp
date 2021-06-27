#include <iostream>
using namespace std;

template<typename T> 
void TempFun(T a){
	std::cout<<a<<std::endl;
}

int main(){
	TempFun(1); // 实例化为 TempFun<const int>(1)
	TempFun("1"); // 实例化为 TempFun<const char*>("1")
}
