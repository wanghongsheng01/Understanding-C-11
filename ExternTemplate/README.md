## extern template
* 显式的实例化
  ```.cpp
  template<typename T>
  void fun(T t){}
  ```
  声明显式实例化
  ```
  template void fun<int>(int);
  ```
* 外部模板的声明
  ```
  extern template void fun<int>(int);
  ```
  
  ## Core Code
  
  test.h
  ```.h
  template<typename T>
  void fun(T t){}
  ```
  
  test1.cpp
  ```.cpp
  #include "test.h"
  template void fun<int>(int); // 显式的实例化
  void test1(){
    fun(3);
  }
  ```
  
  test2.cpp
  ```.cpp
  #include "test.h"
  #include<iostream>
  using namespace std;

  extern template void fun<int>(int); // 外部模板声明

  int main(){
    fun(4);
    std::cout<<"extern template void fun<int>(int)"<<std::endl;
    return 0;
  }
  ```
  
  ## 外部模板函数的编译与链接<br>
  * 编译 test1.cpp，生成 test1.o 目标文件<br>
    `g++ -std=c++11 -Wall -Wextra -pedantic -c -o test1.o test1.cpp`
  
  * 编译 test2.cpp，生成 test2.o 目标文件<br>
    `g++ -std=c++11 -Wall -Wextra -pedantic -c -o test2.o test2.cpp`
  
  * 将 test1.o 与 test2.o 链接成单个 test.out 可执行文件<br>
    `g++ -std=c++11 -Wall -Wextra -pedantic -o test.out test1.o test2.o`
  
  * 运行可执行文件<br>
    `./test.out`<br>
    运行结果：extern template void fun<int>(int)<br>
  
  ## 编译解析外部模板<br>
  
  * 只有 test1.cpp 模板实例化，因此只有 test1.o 中的 fun 有定义<br>
    查看指令：`nm -C test1.o | grep fun`<br>
    查看结果：0000000000000000 T void fun<int>(int)<br>
    代码位置：0000000000000000<br>
    外部模板只需保证让 test1.cpp 和 test2.cpp 共享一份代码位置。<br>
    
  
  * test2.cpp 的模板没有实例化，因此 test2.o 不再包含 fun<int>(int) 的实例。<br>
    查看指令：`nm -C test2.o | grep fun`<br>
    查看结果：U void fun<int>(int)<br>
    U 指 Undefined<br>
  
  这里也可以把外部模板声明放在头文件中，这样所有包含 test.h 的头文件都可以共享这个外部模板声明了。
  
  test.h
  ```.h
  template<typename T>
  void fun(T t){}
  // 外部模板声明
  extern template void fun<int>(int);
  ```
  
  test1.cpp
  ```.cpp
  #include "test.h"
  template void fun<int>(int);
  void test1(){
    fun(3);
  }
  ```
  
  test2.cpp
  ```.cpp
  #include "test.h"
  #include<iostream>
  using namespace std;

  int main(){
    fun(4);
    std::cout<<"extern template void fun<int>(int)"<<std::endl;
    return 0;
  }

  ```
  
