## friend
为类模版声明友元<br>
friend.cpp
```.cpp
class P;
template<typename T> class People{
	friend T;
}; 

int main(){
	
	People<P> people;
	People<int> pi;

	return 0;
}
```

使用类 P 为模版 template<typename T> 的参数时，P 是 People<P> 的一个 friend 类。<br>
