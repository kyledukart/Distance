// Distance class
#ifndef DISTANCE_H_INCLUDED
#define DISTANCE_H_INCLUDED
#include <iostream>
using namespace std;

typedef int Feet;
typedef int Inches;

class Distance{
    // Overload <<
    friend ostream& operator<<(ostream&, const Distance&);

    // Overload >>
    friend istream& operator>>(istream&, Distance&);

public:
    // Constructor, default is 0 ft 0 in
    Distance(Feet f=0, Inches i=0);

    // Get methods
    Feet getFeet() const;
    Inches getInches() const;

    // Set methods
    void setFeet(Feet);
    void setInches(Inches);

    // Arithmetic operators
    Distance operator+(const Distance&);
    Distance operator-(const Distance&);
    double operator*(const Distance&);
    double operator/(const Distance&);
    Distance operator-() const;

    // Boolean comparison operators
    bool operator==(const Distance&) const;
    bool operator!=(const Distance&) const;
    bool operator>(const Distance&) const;
    bool operator<(const Distance&) const;
    bool operator>=(const Distance&) const;
    bool operator<=(const Distance&) const;

    // Assignment operators
    Distance& operator+=(const Distance&);
    Distance& operator-=(const Distance&);

private:
    Feet ft;
    Inches in;

    // reduce inches up to 12, simplify positive ft negative in and negative ft positive in
    void reduce();

    // return value in inches for comparison
    double convert_to_inches() const;
};


#endif // DISTANCE_H_INCLUDED
