## Template Default Para
template_default_para.cpp
```.cpp
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

```
TmpFun(1) 实例化时使用默认参数 TemFun<默认参数>(1)，即 `TempFun<const int>(1)`
