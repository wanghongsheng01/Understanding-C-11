#include<iostream>
#include<memory>
using namespace std;

int main(){
	shared_ptr<int> p = make_shared<int>(10); // p 指向的对象只有 p 一个引用者
	cout<<"p.use_count()"<<p.use_count()<<endl; // 指向对象的引用计数器 = 1
	shared_ptr<int> q(p); // p 和 q 指向相同对象，此对象有两个引用者
	cout<<"p.use_count()"<<p.use_count()<<endl; // 指向对象的引用计数器 = 2
	cout<<"q.use_count()"<<q.use_count()<<endl; // 指向对象的引用计数器 = 2

	shared_ptr<int> r = make_shared<int>(42); 
	r = q; // 给 r 赋值，令它指向另一个地址，递增 q 指向对象的引用计数；
	// 递减 r 原来指向对象的引用计数，r 原来指向的对象已没有引用者，会自动释放
	cout<<"r.use_count()"<<r.use_count()<<endl; // 指向对象的引用计数器 = 3 

	return 0;
}