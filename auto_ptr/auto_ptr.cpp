#include<iostream>
#include<memory>
using namespace std;

int main(){

	unique_ptr<int> up1(new int(11));
	unique_ptr<int> up2 = up1; // 不能通过编译
	// unique_ptr 与所指向对象的内存一一绑定。
	// 每个 unique_ptr 都是唯一地拥有所指向的对象内存。
	// up1 唯一地占有 new 分配的堆内存，up2 无法共享其指向对象内存的“所有权”。
	// 不能与其它 unique_ptr 类型的指针对象共享所指对象的内存。
	

}