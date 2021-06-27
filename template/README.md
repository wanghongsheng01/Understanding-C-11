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

`强调`：模版函数的默认形参不是模板参数推导的依据，是由函数的实参推导。

* 类模板的默认参数：默认模板参数放右边位置（自右往左的规则进行指定）
	```.cpp
	tempplate<typename T, int i = 0> class DefClass;  // 正确，默认模板参数放右边
	tempplate<int i = 0, typename T> class DefClass;  // 无法通过编译
	```
* 函数模板默认模板参数：都可以
