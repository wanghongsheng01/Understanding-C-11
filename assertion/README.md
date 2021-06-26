C++11 标准库在 或 <assert.h> 头文件中提供了 assert 宏，程序运行时进行断言。<br>
## 代码示例<br>
assert.cpp
```.cpp
#include<cassert>
using namespace std;

// 一个简单的堆内存数组分配函数
char* ArrayAlloc(int n){
	assert(n>0); // 断言 n 必须大于 0
	return new char[n];
}

int main(){
	char* a = ArrayAlloc(100);
}
```
预处理 `g++ -E assert.cpp -o assert.i`<br>
assert.i
```.i
char* ArrayAlloc(int n){
 (__builtin_expect(!(n>0), 0) ? __assert_rtn(__func__, "assert.cpp", 6, "n>0") : (void)0);
 return new char[n];
}

int main(){
 char* a = ArrayAlloc(100);
}
```
