#include<iostream>
#include<memory>
using namespace std;

int main(){

	unique_ptr<int> up1(new int(11));

	// up1 唯一地占有 new 分配的堆内存，up2 无法共享其指向对象内存的“所有权”。
	// unique_ptr<int> up2 = up1; // 不能通过编译，不能与其它 unique_ptr 类型的指针对象共享所指对象的内存。
	
	std::cout<<"*up1:"<< *up1 <<std::endl; // 11

	unique_ptr<int> up3 = move(up1);// up1 的“所有权”仅能通过 move 来转移
	std::cout<<"*up3:"<< *up3 <<std::endl; // 11
	// std::cout<< *up1 <<std::endl; // 运行时错误，一旦“所有权”转移成功，原来的 up1 就失去了对象内存的“所有权”。
	
	up3.reset(); // up3 释放其拥有的堆内存
	up1.reset();
	// std::cout<< *up3 <<std::endl; // 运行时错误
	
	shared_ptr<int> sp1(new int(22));
	std::cout<<"sp1.use_count():"<< sp1.use_count() <<std::endl; // 1
	shared_ptr<int> sp2(sp1);
	std::cout<<"sp2.use_count():"<< sp2.use_count() <<std::endl; // 2

	std::cout<<"*sp1:"<< *sp1 <<std::endl; // 22
	std::cout<<"*sp2"<< *sp2 <<std::endl; // 22

	sp1.reset();
	std::cout<<"*sp2:"<<*sp2<<std::endl; // 22
	std::cout<<"sp2.use_count():"<< sp2.use_count() <<std::endl; // 1
	
	

}