/*
 * fraction_18jdas.h
 *
 *  Created on: Oct. 11, 2021
 *      Author: jstud
 */

#ifndef FRACTION_18JDAS_H_
#define FRACTION_18JDAS_H_
#include <iostream>

class Fraction{
public:
	Fraction();
	Fraction(int n);
	Fraction(int n,int d);
	Fraction operator-();
	Fraction operator++();
	Fraction operator++(int);
	void operator+=(const Fraction& f1);

	int numerator() const;
	int denominator() const;

private:
	int num;
	int denom;

friend ostream& operator<<(ostream& os, const Fraction& frac);

friend istream& operator>>(istream& is,Fraction& frac);

friend Fraction operator+(const Fraction& f1, const Fraction& f2);

friend Fraction operator-(const Fraction& f1, const Fraction& f2);

friend Fraction operator*(const Fraction& f1, const Fraction& f2);

friend Fraction operator/(const Fraction& f1, const Fraction& f2);



friend bool operator==(const Fraction& f1, const Fraction& f2);

friend bool operator!=(const Fraction& f1, const Fraction& f2);

friend bool operator>(const Fraction& f1, const Fraction& f2);

friend bool operator<(const Fraction& f1, const Fraction& f2);

friend bool operator>=(const Fraction& f1, const Fraction& f2);

friend bool operator<=(const Fraction& f1, const Fraction& f2);


};



class FractionException{
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};




#endif /* FRACTION_18JDAS_H_ */
