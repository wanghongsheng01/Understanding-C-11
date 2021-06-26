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

## 运行时检查 && 编译时检查
* 运行时检查，使用 assert()
* 编译时检查，使用 static_assert()

## 编译时检查
代码示例
static_assert.cpp
```cpp
#include <cstring>
using namespace std;

template <typename t, typename u> int bit_copy(t& a, u& b){
	static_assert(
		sizeof(b) == sizeof(a),
		"the two parameters of bit_copy must have the same width."
		);
}

int main(){
	int a = 0x2468;
	double b;
	int c;
	bit_copy(a, c);
	bit_copy(a, b);
}
```

预处理，生成 static_assert.i 文件
static_assert.i
```.i
# 2 "static_assert.cpp" 2
using namespace std;

template <typename t, typename u> int bit_copy(t& a, u& b){
 _Static_assert(sizeof(b) == sizeof(a), "the two parameters of bit_copy must have the same width.");
}

int main(){
 int a = 0x2468;
 double b;
 bit_copy(a, b);
}

```

运行 `g++ static_assert.cpp -std=c++11 -Wall -o static_assert`，编译时检查，报错<br>
```
static_assert.cpp:15:2: note: in instantiation of function template specialization 'bit_copy<int, int>' requested here<br>
        bit_copy(a, c);<br>
        
static_assert.cpp:5:2: error: static_assert failed due to requirement 'sizeof (b) == sizeof (a)' "the two parameters of bit_copy must have the same width."<br>
        static_assert(<br>
        
static_assert.cpp:16:2: note: in instantiation of function template specialization 'bit_copy<int, double>' requested here<br>
        bit_copy(a, b);<br>
```

编译期，模版 `template <typename t, typename u> int bit_copy(t& a, u& b)` 特化为 `bit_copy<int, double>`，static_assert 检查错误。
```s时
```
