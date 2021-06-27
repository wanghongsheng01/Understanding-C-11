## 继承构造函数
* 继承构造函数，在派生类中，只需使用 using Base::Base;就将 Base 类的所有构造函数继承到基类
* 继承构造函数只会初始化基类中的成员变量，无法初始化派生类中的成员变量，只能程序员自己实现初始化派生类成员的构造函数

inherit_constructor.cpp
```.cpp
#include<iostream>
using namespace std;

struct A{
	A(int i){
		std::cout<<"A-int_i:"<<i<<std::endl;
	}

	A(double d, int i){
		std::cout<<"A-double_d:"<<d<<std::endl;
		std::cout<<"A-int_i:"<<i<<std::endl;
	}

	A(float a, int i, const char* c){
		std::cout<<"A-float_a:"<<a<<std::endl;
		std::cout<<"A-int_i:"<<i<<std::endl;
		std::cout<<"A-const char* c:"<<c<<std::endl;
	}
};

struct B : A{
	// 继承构造函数只会初始化基类中的成员变量，无法初始化派生类中的成员变量
	using A::A; // 继承构造函，使用 using 声明，将基类中的构造函数继承到派生类中

};

int main(){
	A a1(100);

	// 继承构造函数只会初始化基类中的成员变量，无法初始化派生类中的成员变量
	B b1(30);


	B b2(40.9, 30);

	B b3(50.99, 60, "char");
	return 0;
}

```

运行结果：<br>
A-int_i:100 <br>
A-int_i:30 <br>
A-double_d:40.9 <br>
A-int_i:30 <br>
A-float_a:50.99 <br>
A-int_i:60 <br>
A-const char* c:char <br>

