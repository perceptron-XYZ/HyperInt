/*
 * HyperInt.cpp
 *
 *  Created on: 2014-03-08
 *      Author: Ryan
 */

#include "HyperInt.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
HyperInt::HyperInt(){};
HyperInt::HyperInt(long num){
	do{
		nums.push_back(num%10);
		num = num/10;
	}while(num!=0);
}
HyperInt::HyperInt(string num){
	for(string::const_reverse_iterator it=num.rbegin();it!=num.rend();++it)
		nums.push_back(*it-'0');
}
HyperInt::HyperInt(const HyperInt& otherInt){
     for(vector<int>::size_type i=0;i!=otherInt.nums.size();++i)
    	 nums.push_back(otherInt.nums[i]);
}
const HyperInt & HyperInt::operator+= (const HyperInt & right){
	int carry=0,temp=0;
	vector<int>::size_type i;
	for(i=0;i!=min(nums.size(),right.nums.size());++i){
		 temp = nums[i]+right.nums[i]+carry;
         nums[i]=(temp)%10;
         carry = temp/10;
	}
	if(nums.size()>right.nums.size()){
		for(vector<int>::size_type j=i;j!=nums.size();++j){
			temp = nums[j]+carry;
			nums[j]= temp%10;
			carry = temp/10;
		}
	}
	else if(nums.size()<right.nums.size()){
		for(vector<int>::size_type j=i;j!=right.nums.size();++j){
			temp = right.nums[j]+carry;
			nums.push_back(temp%10);
			carry = temp/10;
		}
	}
	if(carry>0)
		nums.push_back(carry);

	return *this;
}
const HyperInt & HyperInt::operator*= (const HyperInt & right){
	int temp=0,carry=0;
	vector<HyperInt> results(right.nums.size());
    for(vector<int>::size_type i=0;i!=right.nums.size();++i){
    	for(size_t k=0;k!=i;++k)
    		results[i].nums.push_back(0);
    	for(vector<int>::size_type j=0;j!=nums.size();++j){
            temp = right.nums[i]*nums[j]+carry;
            results[i].nums.push_back(temp%10);
            carry = temp/10;
    	}
    	if(carry>0)
    	   results[i].nums.push_back(carry);
    	carry=0;
    }
    nums.clear();
    for(vector<HyperInt>::size_type i=0; i!=results.size();++i)
    	 *this += results[i];
    return *this;
}

const HyperInt HyperInt::operator^ (int e) const {
	HyperInt big = *this;
	HyperInt result = *this;
	for(int i=0;i!=e-1;++i){
		result *= big;
	}
	return result;
}
const HyperInt HyperInt::operator^ (const HyperInt& e) const{
	HyperInt result = HyperInt(1);
	HyperInt base = *this;
	int exp;
    for(vector<int>::size_type i=0;i!=e.nums.size();++i){
    	   exp=e.nums[i]*pow(10,i);
    	  result *= base^exp;
    }
    return result;
}
HyperInt & HyperInt::operator= (const HyperInt & other)
{
if (this == &other)
return *this;
nums.clear();
for(vector<int>::size_type i=0;i!=other.nums.size();++i)
    	 nums.push_back(other.nums[i]);
return *this;
}

HyperInt::operator bool() const{
	return (*this)!=HyperInt(0);
}
HyperInt& HyperInt::operator ++(){
	*this += HyperInt(1);
	return *this;
}
HyperInt HyperInt::operator ++(int n){
	HyperInt temp(*this);
	*this += HyperInt(1);
	return temp;
}
const bool operator== (const HyperInt & left, const HyperInt & right){
     return equal(left.nums.begin(),left.nums.end(),right.nums.begin());
 }
const bool operator!= (const HyperInt & left, const HyperInt & right){
     return !(left==right);
}
const bool operator< (const HyperInt & left, const HyperInt & right){
      if(left.nums.size()<right.nums.size()){
    	  return true;}
      else if(left.nums.size()>right.nums.size()){
    	  return false;}
      else if(left.nums.size()==right.nums.size()){
          for(vector<int>::size_type i=left.nums.size();i!=0;--i){
        	  if(left.nums[i]<right.nums[i])
        		  return true;
        	  else if(left.nums[i]>right.nums[i])
        		  return false;
          }
      }
      cout<<left<<" "<<right;
      return false;

}
const bool operator> (const HyperInt & left, const HyperInt & right){
      return !((left<right)&&left==right);
}
const bool operator<= (const HyperInt & left, const HyperInt & right){
      return left<right||left==right;
 }
const bool operator>= (const HyperInt & left, const HyperInt & right){
      return left>right||left==right;
}
istream & operator>> (istream & is, HyperInt & num){
	 cout <<"Test >> operator.Enter an int:";
	 string n;
	 is>>n;
     num = HyperInt(n);
     return is;
}
ostream & operator<< (ostream& os,const HyperInt & num){
     for(vector<int>::const_reverse_iterator i=num.nums.rbegin();i!=num.nums.rend();++i)
    	  os<<*i;
     return os;
}
const HyperInt operator+ (const HyperInt & left, const HyperInt & right){
	HyperInt big=left;
	big += right;
	return big;
}
const HyperInt operator* (const HyperInt & left, const HyperInt & right){
	HyperInt big =left;
	big *=right;
	return big;
}
