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
	Fraction(int numerator);
	Fraction(int numerator,int denominator);
	friend ostream& operator<<(ostream& os, const Fraction& frac);
	int getNumerator() const;
	int getDenominator() const;

private:
	int numerator;
	int denominator;
	int GCD(int numerator,int denominator)const;
};


class FractionException{
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};




#endif /* FRACTION_18JDAS_H_ */
