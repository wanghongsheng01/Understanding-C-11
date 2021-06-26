class P;
template<typename T> class People{
	friend T;
}; 

int main(){
	
	People<P> people;
	People<int> pi;

	return 0;
}
