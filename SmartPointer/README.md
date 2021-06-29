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
1. 智能指针重载了 bool 类型操作符来判断智能指针是否已初始化（是否为空），如`std::shared_ptr<T>ptr, if(!ptr) {std::make_shared<T>(value)}`
2. shared_ptr 不能将一个原始指针直接赋值给一个智能指针来初始化，如 `shared_ptr<int>p4 = new int(600); `// 编译报错，不允许直接赋值
	 
## shared_ptr 指定删除器
## shared_ptr 管理动态数组

# unique_ptr
