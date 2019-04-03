#include<iostream>
#include<cstdlib>
using namespace std;
class base{
	public:
		int i;
		base(int x){
			i=x;
		}
		virtual void func(){
			cout<<"using base version of function(): "<<i<<endl;
	}
};
class derived1:public base{
	public:
		derived1(int x):base(x){
		}
		void func(){
			cout<<"using derived1's version of func(): ";
			cout<<i*i<<endl;
		}
};
class derived2:public base{
	public:
		derived2(int x):base(x){
		}
		void func(){
			cout<<"using derived2's version of func(): ";
			cout<<i+i<<endl;
		}
};
int main(){
	base *p;
	derived1 d_ob1(10);
	derived2 d_ob2(10);
	int i,j;
	for(i=0;i<10;i++){
		j=rand();
		if((j%2))
		p=&d_ob1;
		else
		p=&d_ob2;
		p->func();
	}
}
