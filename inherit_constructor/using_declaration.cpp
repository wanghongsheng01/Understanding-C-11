#include<iostream>
using namespace std;

struct Base{
	void f(double i){
		std::cout<<"Base:"<<i<<std::endl;
	}
};

struct Derived : Base{

	// 使用 using 声明，声明派生类也可以使用基类的成员函数
	using Base::f; 
	void f(int i){
		std::cout<<"Derived:"<<i<<std::endl; 
	}
};

int main(){
	Base b;
	b.f(4.5); // Base:4.5

	Derived d;
	d.f(4.5); // Base:4.5

	return 0;
}