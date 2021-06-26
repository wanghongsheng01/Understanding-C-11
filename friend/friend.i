# 1 "friend.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 380 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "friend.cpp" 2
class P;
template<typename T> class People{
 friend T;
};

int main(){

 People<P> people;
 People<int> pi;

 return 0;
}
