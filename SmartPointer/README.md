# shared_ptr 
## shared_ptr 初始化
* 方式1. 使用 `make_shared<T>(value)`
* 方式2. 使用构造函数 `shared_ptr<T> ptr(new T(value))`
* 方式3. 使用 reset，`shared_ptr<T>ptr, if(!ptr) ptr.reset(new T(value))`

shared_ptr.cpp
```.cpp
#include<iostream>
#include<memory>
using namespace std;

void DeleteIntPtr(int* ptr){ delete ptr; }
int main(){

	/**
	 ************** shared_ptr 的初始化 ****************
	 */
	
	// 优先使用 make_shared 构造智能指针，因为它更高效
	shared_ptr<int> ptr = make_shared<int>(10);

	// 智能指针重载了 bool 类型操作符来判断智能指针是否已初始化（是否为空）
	if(ptr){ 
		cout<<"ptr is not null"<<endl; 
		cout<<"*ptr:"<< *ptr <<endl;
		cout<<"ptr.use_count():"<<ptr.use_count()<<"\n"<<endl;
		ptr.reset();
		cout<<"ptr:"<<ptr<<endl; // 0x0 返回十六进制的 0
		// cout<<"*ptr:"<<*ptr<<endl; // 编译报错，因为空指针，已释放了所指向对象的堆内存空间
		cout<<"ptr.use_count():"<<ptr.use_count()<<"\n"<<endl; // 0

	}
	
	shared_ptr<int> p(new int(100));
	if(p){ 
		cout<<"p is not null"<<endl; 
		cout<<"*p:"<< *p <<endl;
		cout<<"p.use_count():"<<p.use_count()<<"\n"<<endl;
	}

	shared_ptr<int> p2(p);
	if(p2){ 
		cout<<"p2 is not null"<<endl; 
		cout<<"*p2:"<< *p2 <<endl;
		cout<<"p2.use_count():"<<p2.use_count()<<"\n"<<endl;
	}

	shared_ptr<int>p3;
	p3.reset(new int(300));
	if(p3){ 
		cout<<"p3 is not null"<<endl; 
		cout<<"*p3:"<< *p3 <<endl;
		cout<<"p3.use_count():"<<p3.use_count()<<"\n"<<endl;
	}
	return 0;
}
```

注意：
1. 智能指针重载了 bool 类型操作符来判断智能指针是否已初始化（是否为空)<br>
   如`std::shared_ptr<T>ptr, if(!ptr) {std::make_shared<T>(value)}`<br>
   
2. shared_ptr 不能将一个原始指针直接赋值给一个智能指针来初始化<br>
   如 `shared_ptr<int>p4 = new int(600); ` 编译报错，不允许直接赋值<br>
   
3. shared_ptr 使用 reset 方法时<br>
	* 情况1: 对于未初始化的空指针，可以使用 reset 初始化<br>
	* 情况2: 当智能指针中有值时，使用 reset 会使引用计数减<br>
	* 情况3: 可以使用 reset 让当前智能指针释放引用对象堆内存空间的所有权，导致引用计数降低，不会导致堆内存的释放<br>
			只有当引用计数归零时，shared_ptr 释放所占有的堆内存空间<br>
	 
## shared_ptr 获取原始指针

	shared_ptr<int> ptr2(new int(1000));
	int* p_ori = ptr2.get();
	cout<<"*p_ori:"<<*p_ori<<"\n"<<endl; // *p_ori:1000
	
## shared_ptr 指定删除器
* 方式1:删除器是自定义函数，当 ptr3 的引用计数为 0 时，自动调用删除器释放对象内存
	
	```.cpp
	shared_ptr<int> ptr3(new int(2000), DeleteIntPtr); 
	cout<<"reset 前，DeleteIntPtr 前，ptr3:"<<ptr3<<endl; // ptr3:0x7fddb34059b0
	ptr3.reset(); 
	cout<<"ptr3.use_count():"<<ptr3.use_count()<<endl;   // ptr3.use_count():0
	cout<<"reset 后，DeleteIntPtr 后，ptr3:"<<ptr3<<"\n"<<endl; // ptr3:0x0，表示空指针，已释放对象内存
	```

* 方式2:删除器是 lambda 表达式

	```.cpp
	shared_ptr<int> ptr4(new int(3000), [](int* ptr){ delete ptr; });
	cout<<"reset 前，DeleteIntPtr 前，ptr4:"<<ptr4<<endl; // ptr4:0x7f9588c059b0
	ptr4.reset(); 
	cout<<"ptr3.use_count():"<<ptr4.use_count()<<endl;   
	cout<<"reset 后，DeleteIntPtr 后，ptr4:"<<ptr4<<"\n"<<endl; // ptr4:0x0
	```
	
## shared_ptr 管理动态数组
shared_ptr 管理数组时，需要指定删除器，因为 shared_ptr 默认删除器不支持数组对象<br>
如 `shared_ptr<int> ptr_arra(new int[3], [](int* p){ delete[] p; });`

* new T 分配的内存，使用 delete 析构，delete 释放 new 分配的单个对象指针指向的内存
* new T[ ] 分配的内存，使用 delete[] 析构，delete[]释放 new 分配的对象数组指针指向的内存

	```.cpp
	// 创建动态数组，shared_ptr 管理动态数组
	int* a = new int[3];
	a[0] = 100;
	a[1] = 900;
	
    std::shared_ptr<int> p4(a, [](int* p){ delete[] p;} );

    std::cout<<p4.get()[0]<<std::endl;// 返回 100 // p2.get()获取原始指针 a
    std::cout<<p4.get()[1]<<std::endl;// 返回 900
	```
## unique_ptr 管理动态数组 new T[size]
# unique_ptr
