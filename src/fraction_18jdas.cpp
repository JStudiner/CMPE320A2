#include <iostream>
#include<cmath>
#include<string>
using namespace std;

#include "fraction_18jdas.h"
int GCD(int n,int d);
bool
FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() { return message; }

Fraction::Fraction(){
	num=0;
	denom=1;

}

//hello
Fraction::Fraction(int n){
	num=n;
	denom=1;
}

Fraction::Fraction(int n,int d){
	if(d==0){
		throw FractionException("The denominator is 0 you can't do this buddy");
	}

	int gcd=GCD(n,d);

	if(d<0){
		num=-n/gcd;
		denom=-d/gcd;
	}
	else {
		num=n/gcd;
		denom=d/gcd;
	}


}

int GCD(int n,int d){
	n=abs(n);
	d=abs(d);
	if(d<=n &&n%d==0)return d;
	else if(n<d)return GCD(d,n);
	else return GCD(d,n%d);
}
int Fraction::numerator() const{
	return num;
}

int Fraction::denominator() const{
	return denom;
}

ostream& operator<<(ostream& os,const Fraction& frac){
	os<<frac.num<<"/"<<frac.denom;
	return os;
}

istream& operator>>(istream& in,Fraction& frac){
	string token;
	if(!(in>>token))throw FractionException("Invalid input");
	int num,denom;


}

Fraction operator+(const Fraction& frac1, const Fraction& frac2){
	int totalNumerator=frac1.num*frac2.denom+frac2.num*frac1.denom;
	int denominator=frac1.denom*frac2.denom;
	return 	Fraction(totalNumerator,denominator);
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2){
	int totalNumerator=frac1.num*frac2.denom-frac2.num*frac1.denom;
	int denominator=frac1.denom*frac2.denom;
	return 	Fraction(totalNumerator,denominator);
}

Fraction operator*(const Fraction& frac1, const Fraction& frac2){
	int totalNumerator=frac1.num*frac2.num;
	int denominator=frac1.denom*frac2.denom;
	return 	Fraction(totalNumerator,denominator);
}


Fraction operator/(const Fraction& frac1, const Fraction& frac2){
	int totalNumerator=frac1.num*frac2.denom;
	int denominator=frac1.denom*frac2.num;
	return 	Fraction(totalNumerator,denominator);
}

Fraction Fraction::operator-(){
	return Fraction(-num,denom);
}

Fraction Fraction::operator++(){
	*this=*this+1;
	return *this;
}

Fraction Fraction::operator++(int){
	Fraction temp=*this;
	*this=*this+1;
	return temp;
}

void Fraction::operator+=(const Fraction& f1){
	*this=*this+f1;
}

bool operator==(const Fraction& f1, const Fraction& f2){
	if (f1.numerator()==f2.numerator()&& f1.denominator()==f2.denominator())return true;
	return false;
}

bool operator!=(const Fraction& f1, const Fraction& f2){
	if(f1.numerator()!=f2.numerator() || f1.numerator()!=f2.denominator())return true;
		return false;
}

bool operator>(const Fraction& f1, const Fraction& f2){
	if((f1.numerator()*f2.denominator())>(f1.denominator()*f2.numerator())) return true;
	return false;
}

bool operator<(const Fraction& f1, const Fraction& f2){
	if((f1.numerator()*f2.denominator())<(f1.denominator()*f2.numerator())) return true;
	return false;
}

bool operator>=(const Fraction& f1, const Fraction& f2){
	if((f1.numerator()*f2.denominator())>=(f1.denominator()*f2.numerator())) return true;
	return false;
}

bool operator<=(const Fraction& f1, const Fraction& f2){
	if((f1.numerator()*f2.denominator())<=(f1.denominator()*f2.numerator())) return true;
	return false;
}
