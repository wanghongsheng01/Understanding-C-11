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

## 值得注意的几点：<br>
* 当一个派生类从多个基类继承时，继承构造函数发生冲突的情况，可通过显式定义冲突的继承构造函数，阻止隐式生成的继承构造函数来解决冲突。
```.cpp
struct A{
	A(int){}
};
struct B{
	B(int){}
};
struct C : A, B{
	using A:A;
	using B:B;
	C(int){}
};
```
构造函数 C(int) 就解决了继承构造函数冲突的问题。

* 如果派生类使用了继承构造函数，则编译器就不会为派生类生成默认构造函数，即派生类没有无参构造函数。
no_default_constructor.cpp
```.cpp
struct A{
	A(int){}
};

struct B: A{
	using A:A;
};

int main(){
	B b; // B 没有默认构造函数，由于 B 使用了继承构造函数
	return 0;
}

```
编译报错：<br>
`note: default constructor of 'B' is implicitly deleted because base class 'A' has no default constructor`
