#include<iostream>
#include<memory>
using namespace std;

class A : public std::enable_shared_from_this<A>{
public:
	std::shared_ptr<A> GetSelf(){
		return shared_from_this();
	}
};

int main(){
	std::shared_ptr<A> p(new A);
	std::cout<<"p:"<<p<<std::endl; // 0x7fc3f4405920
	std::shared_ptr<A> ptr = p->GetSelf(); // 0x7fc3f4405920
	std::cout<<"*ptr:"<<ptr<<std::endl;
	return 0;
}
