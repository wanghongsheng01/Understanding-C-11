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



