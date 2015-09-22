/*
 * HyperInt.h
 *
 *  Created on: 2014-03-07
 *      Author: Ryan
 */

#ifndef HYPERINT_H_
#define HYPERINT_H_

#include <vector>
#include <iostream>
using namespace std;
class HyperInt{
	 friend const bool operator== (const HyperInt & left, const HyperInt & right);
	 friend const bool operator!= (const HyperInt & left, const HyperInt & right);
	 friend const bool operator< (const HyperInt & left, const HyperInt & right);
	 friend const bool operator> (const HyperInt & left, const HyperInt & right);
	 friend const bool operator<= (const HyperInt & left, const HyperInt & right);
	 friend const bool operator>= (const HyperInt & left, const HyperInt & right);
     friend istream & operator>> (istream & is, HyperInt & num);
	 friend ostream & operator<< (ostream& os,const HyperInt & num);

     public:
	 HyperInt();
	 HyperInt(long num);
	 HyperInt(string num);
	 HyperInt(const HyperInt& otherInt);
	 const HyperInt & operator+= (const HyperInt & right);
	 const HyperInt & operator*= (const HyperInt & right);
	 const HyperInt operator^ (int e)const;
	 const HyperInt operator^ (const HyperInt& e)const;
	 HyperInt & operator=(const HyperInt & other);
     operator bool() const;
     HyperInt& operator++();
     HyperInt operator++(int);
     private:
	 vector<int> nums;


};
	const HyperInt operator+ (const HyperInt & left, const HyperInt & right);
	const HyperInt operator* (const HyperInt & left, const HyperInt & right);

#endif /* HYPERINT_H_ */
