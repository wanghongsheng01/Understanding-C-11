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
