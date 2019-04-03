#include<iostream>
using namespace std;
class coord{
	private:
		int x,y;
		
	public:
		coord(){
			x=0;y=0;
		}
		
		coord(int i,int j){
			x=i;y=j;
		}
		
		void get_xy(int &i,int &j){
			i=x;j=y;
		}
		
		coord operator+(coord ob2);
		coord operator-(coord ob2);
		coord operator=(coord ob2);
		int operator==(coord ob2);
		int operator&&(coord ob2);
		coord operator++();
		coord operator++(int notused);
};

coord coord::operator+(coord ob2){
	coord temp;
	temp.x=x+ob2.x;
	temp.y=y+ob2.y;
	return temp;
}

coord coord::operator-(coord ob2){
	coord temp;
	temp.x=x-ob2.x;
	temp.y=y-ob2.y;
	return temp;
}

coord coord::operator=(coord ob2){
	x=ob2.x;
	y=ob2.y;
	return *this;
}

int coord::operator==(coord ob2){
	return (x==ob2.x)&&(y==ob2.y);
}

int coord::operator&&(coord ob2){
	return (x&&ob2.x)&&(y&&ob2.y);
}

void f1(coord o1,coord o2,char *x,char *y){
	if(o1==o2)
	cout<<x<<" and "<<y<<" are same"<<endl;
	else cout<<x<<" and "<<y<<" are different"<<endl;
}

void f2(coord o1,coord o2,char *x,char *y){
	if(o1&&o2)
	cout<<x<<" "<<"&& "<<y<<" "<<"is true"<<endl;
	else cout<<x<<" "<<"&& "<<y<<" "<<"is false"<<endl;
}

coord coord::operator++(){
	x++,y++;
	return *this;
}

coord coord::operator++(int notused){
	coord temp;
	temp.x=x;
	temp.y=y;
	x++;
	y++;
	return temp;
}

int main(){
	coord ob1(10,10),ob2(20,30),ob3,ob4(10,10),ob5();
	int x,y;
	
	ob3=ob1+ob2;
	ob3.get_xy(x,y);
	cout<<"(ob1+ob2) "<<x<<" "<<y <<endl;
	
	ob3=ob1-ob2;
	ob3.get_xy(x,y);
	cout<<"(ob1-ob2)"<<x<<" "<<y<<endl;
	
	ob3=ob1;
	ob3.get_xy(x,y);
	cout<<"(ob3=ob1)"<<x<<" "<<y<<endl;
	
	f1(ob1,ob2,"ob1","ob2");
	f1(ob1,ob4,"ob1","ob4");
	f2(ob1,ob2,"ob1","ob2");
	f2(ob1,ob4,"ob1","ob4");
	
	ob2=++ob1;
	ob1.get_xy(x,y);
	cout<<"(++ob1)"<<x<<" "<<y<<endl;
	
	ob2.get_xy(x,y);
	cout<<x<<" "<<y<<endl;
	
	ob2=ob1++;
	ob1.get_xy(x,y);
	cout<<"(ob1++)"<<x<<" "<<y<<endl;
	
	ob2.get_xy(x,y);
	cout<<x<<" "<<y<<endl;

}
