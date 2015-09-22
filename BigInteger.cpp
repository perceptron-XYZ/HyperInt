
#include "HyperInt.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	HyperInt bigint1(99000);
	HyperInt bigint2(313);
	HyperInt bigint3(313);
	cout<<left<<setw(30)<<"Test ^ operator:"<<(bigint2^bigint3)<<endl;
//	cout<<((bigint2^313)^2)<<endl;
//	bigint1 = bigint2;
	cin >> bigint3;
	cout<<left<<setw(30)<<"Test << operator:"  << bigint3<<endl;
	cout<<left<<setw(30)<<"Test + and += operator:"<<bigint2+bigint1<< endl;
	cout<<left<<setw(30)<<"Test * and *= operator:"<<bigint1*bigint2<< endl;

	cout<<"The following outputs are testing the function of comparison operators"<<endl;
	HyperInt num1(11111111);
	HyperInt num2(11111111);
	if(num1==num2)
		    cout<<num1<<"="<<num2<<endl;
	if(num1!=bigint1)
		    cout<<num1<<"!="<<bigint1<<endl;
	if(num1>bigint1)
			cout<<num1<<">"<<bigint1<<endl;
	if(num1>=num2)
			cout<<num1<<">="<<num2<<endl;
	if(bigint2<bigint1)
			cout<<bigint2<<"<"<<bigint1<<endl;
	if(bigint2<=num1)
			cout<<bigint2<<"<="<<num1<<endl;
	if(bigint2)
		cout<<bigint2<<" is not zero"<<endl;

	cout<<"Before post-increment,bigint2 was: "<<bigint2;
	cout<<". After post-increment in the same line, bigint2 is: "<<bigint2++<<endl;
	cout<<"After post-increment in the next line, bigint2 is: "<<bigint2<<endl;
	cout<<"Before pre-increment,bigint1 was: "<<bigint1;
	cout<<". After pre-increment in the same line, bigint1 is: "<<++bigint1<<endl;
	cout<<"After pre-increment in the next line, bigint1 is: "<<bigint1;
	return 0;
}
