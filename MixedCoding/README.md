C++ 编译混编 __cplusplus 的过程

编译指令：
`
g++ -E main.cpp -o main.i
`
将混编代码 main.cpp
```.h

#ifdef __cplusplus
extern "C" {
#endif


// insert code here...
void print(){
    std::cout<<"print ..."<<std::endl;
}


#ifdef __cplusplus
}
#endif

```
编译成 main.i
```.i
# 9 "main.cpp" 2
# 1 "./__cplusplus.h" 1
# 13 "./__cplusplus.h"
extern "C" {

void print(){
    std::cout<<"print ..."<<std::endl;
}

}


```
