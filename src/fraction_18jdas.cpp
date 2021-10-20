#include <iostream>
#include<cmath>
using namespace std;

#include "fraction_18jdas.h"

Fraction::Fraction(){
	numerator=0;
	denominator=1;

}

Fraction::Fraction(int n){
	numerator=n;
	denominator=1;
}

Fraction::Fraction(int n,int d){
	int negative=1;
	if((n<0)!=(d<0))negative=-1;
	int gcd=GCD(n,d);
	numerator=negative*n/gcd;
	denominator=negative*d/gcd;
}
int Fraction::GCD(int n,int d) const{
	n=abs(n);
	d=abs(d);
	if(d<=n &&n%d==0)return d;
	else if(n<d)return GCD(d,n);
	else return GCD(d,n%d);
}
int Fraction::getNumerator() const{
	return numerator;
}
int Fraction::getDenominator() const{
	return denominator;
}

ostream& operator<<(ostream& os,const Fraction& frac){
	os<<frac.getNumerator()<<"/"<<frac.getDenominator();
	return os;
}
