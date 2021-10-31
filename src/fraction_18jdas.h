/*
 * Jack Studiner
 * Submitted on October 22nd, 2021
 */

#ifndef FRACTION_18JDAS_H_
#define FRACTION_18JDAS_H_
#include <iostream>

class Fraction{
public:
	//empty constructor that sets the numerator to 0 and the denominator to 1
	Fraction();
	//sets the numerator to n and the denominator to 1
	Fraction(int n);
	//sets the numerator to n and the denominator to d, reduces the fraction by the gcd
	Fraction(int n,int d);
	//overloads the negation operator that returns a fraction where the numerator is multiplied by -1
	Fraction operator-();
	//overloads the pre-increment function and increments the fraction by 1 before dealing with the operation
	Fraction operator++();
	//overloads the post-increment function and increments the fraction by 1 after dealing with the operation
	Fraction operator++(int);
	//overloads the addition assignment operator that takes the fraction and increments it by the fraction specified in f1
	void operator+=(const Fraction& f1);
	//getter for the numerator
	int numerator() const;
	//getter for the denominator
	int denominator() const;

private:
	//private variables for the numerator and denominator
	int num;
	int denom;

//overloads the out stream operator and displays a fraction in to form "numerator/denominator" in the out stream
friend ostream& operator<<(ostream& os, const Fraction& frac);

//overloads the in stream operator and takes in a fraction in the form "numerator/denominator". if the numerator is entered as 0 the fraction sets the denominator to 1
friend istream& operator>>(istream& is,Fraction& frac);

//overloads the addition operator and returns a fraction calculated by getting a common denominator and adding the numerators
friend Fraction operator+(const Fraction& f1, const Fraction& f2);

//overloads the subtraction operator and returns a fraction calculated by getting a common denominator and subtracting the numerators
friend Fraction operator-(const Fraction& f1, const Fraction& f2);

//overloads the multiplication operator and returns a fraction calculated by multiplying the numerators and denominators of the input parameters
friend Fraction operator*(const Fraction& f1, const Fraction& f2);

//overloads the division operator and returns a fraction calculated by multiply the numerator of the first by the denominator of the second and vice versa
friend Fraction operator/(const Fraction& f1, const Fraction& f2);

//overload the boolean equals operator and returns true if the numerator and denominator values of the fractions are equal
friend bool operator==(const Fraction& f1, const Fraction& f2);

//overload the boolean equals operator and returns true if the numerator and denominator values of the fractions are not equal
friend bool operator!=(const Fraction& f1, const Fraction& f2);

//overloads the greater than operator by finding a common denominator between fractions and returning true if the numerator of the LHS > numerator of the RHS
friend bool operator>(const Fraction& f1, const Fraction& f2);

//overloads the less than operator by finding a common denominator between fractions and returning true if the numerator of the LHS < numerator of the RHS
friend bool operator<(const Fraction& f1, const Fraction& f2);

//overloads the greater than or equals to operator by finding a common denominator between fractions and returning true if the numerator of the LHS >= numerator of the RHS
friend bool operator>=(const Fraction& f1, const Fraction& f2);

//overloads the less than or equals to operator by finding a common denominator between fractions and returning true if the numerator of the LHS <= numerator of the RHS
friend bool operator<=(const Fraction& f1, const Fraction& f2);


};


//standard exception class for a fraction exception that prints error messages when the fraction is declared or entered improperly
class FractionException{
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};




#endif /* FRACTION_18JDAS_H_ */
