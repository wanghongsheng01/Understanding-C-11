#include<memory>
#include<iostream>
using namespace std;

/**
 * weak_ptr 指向 shared_ptr 指向的对象内存，却不拥有该内存（即该内存对象的引用计数不会加1）
 * weak_ptr 的 lock 成员返回其指向内存的一个 shared_ptr 对象，且在所指对象内存无效时，返回指针空值 nullptr。
 *
 * 功能：利用 weak_ptr 验证 shared_ptr 的有效性
 */

void Check(weak_ptr<int> wp){
	shared_ptr<int> sp = wp.lock();
	if(sp != nullptr){
		cout<<"still "<<*sp<<endl;
	}else{
		cout<<"is a nullptr"<<endl;
	}
}

int main(){
	shared_ptr<int>sp1(new int(22));
	shared_ptr<int>sp2 = sp1;
	weak_ptr<int> wp = sp1; // weak_ptr<int> 指向 shared_ptr<int> 所指对象内存

	cout<<*sp1<<endl;
	cout<<*sp2<<endl;
	// cout<<*wp<<endl; //报错，weak_ptr 指向 shared_ptr 对象内存，但不占用
	cout<<"sp2.use_count():"<<sp2.use_count()<<endl; // weak_ptr 没使引用计数加1
	cout<<"wp.lock():"<<wp.lock()<<endl; // weak_ptr 转换为 shared_ptr，才能打印出该对象内存及其值
	cout<<"*(wp.lock()):"<<*(wp.lock())<<endl; // 22
	cout<<"(wp.lock()).use_count():"<<(wp.lock()).use_count()<<endl; // 所指向对象内存引用计数加1

	// 验证 shared_ptr 有效性
	sp1.reset();
	cout<<"sp1.use_count():"<<sp1.use_count()<<endl; // 0
	cout<<"sp2.use_count():"<<sp2.use_count()<<endl; // 1
	Check(wp); // still 22，因为对象内存引用计数器为1

	sp2.reset();
	cout<<"sp2.use_count():"<<sp2.use_count()<<endl; // 0
	Check(wp); // is a nullptr，因为对象内存引用计数器为0

	return 0;
}
