## friend
为类模板声明友元<br>
friend.cpp
```.cpp
class P;
template<typename T> class People{
	friend T;
}; 

int main(){
	
	People<P> people;
	People<int> pi;

	return 0;
}
```

使用类 P 为模版 template<typename T> 的参数时，P 是 People<P> 的一个 friend 类。<br>
	
## friend template class 
示例代码
friend_template_class.cpp
```.cpp
#include<iostream>
using namespace std;

template<typename T> class CaseT{
public:
	friend T;
	void print(int x){ 
		std::cout<<"print ..."<<std::endl; 
		std::cout<<"x:"<<x<<std::endl; 
	}
};

using Case = CaseT<int>; //普通的类定义,没有友元

class Test;
using TestCase = CaseT<Test>; //测试类用，Test成员友元类

class Test{
public:
	void test_result(){ 
		std::cout<<"test result ..."<<std::endl; 
	}

};



int main(){
	TestCase tc;
	tc.print(100);	
	
	return 0;
}

```
