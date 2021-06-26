#include<cassert>
using namespace std;

// 一个简单的堆内存数组分配函数
char* ArrayAlloc(int n){
	assert(n>0); // 断言 n 必须大于 0
	return new char[n];
}

int main(){
	char* b = ArrayAlloc(0);
}

