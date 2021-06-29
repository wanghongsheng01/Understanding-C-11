#include<memory>
#include<iostream>
using namespace std;

int main(){
	int* a = new int[3];
	a[0] = 100;
	a[1] = 900;

	std::shared_ptr<int> p(new int[3], [](int* p){ delete[] p;} );
	
    std::shared_ptr<int> p2(a, [](int* p){ delete[] p;} );

    std::cout<<p2.get()[0]<<std::endl;// 返回 100 // p2.get()获取原始指针 int* a
    std::cout<<p2.get()[1]<<std::endl;// 返回 900
    
	return 0;
}


