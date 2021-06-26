## 静态断言

* 运行时检查，使用 `assert`
* 编译时检查，使用 `static_assert(返回为 bool 的常量表达式，字符串)`

## 示例代码
static_assert.cpp
```.cpp
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
预处理生成的 static_assert.i 文件<br>
static_assert.i<br>
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
运行 `g++ static_assert.cpp -std=c++11 -Wall -o static_assert`，编译时检查，控制台报错<br>
```

static_assert.cpp:15:2: note: in instantiation of function template specialization 'bit_copy<int, int>' requested here<br>
        bit_copy(a, c);
        
static_assert.cpp:5:2: error: static_assert failed due to requirement 'sizeof (b) == sizeof (a)' "the two parameters of bit_copy must have the same width."<br>
        static_assert(
        
static_assert.cpp:16:2: note: in instantiation of function template specialization 'bit_copy<int, double>' requested here<br>
        bit_copy(a, b);
        
1 warning and 1 error generated.<br>

```

编译时检查，编译器实例化模版 `template <typename t, typename u> int bit_copy(t& a, u& b)` 时，将实例化参数代码模版中 `'bit_copy<int, double>'`<br>
利用 static_assert(bool const expression, string) 在编译时检查两个参数类型。


