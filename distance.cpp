// Distance member function definitions
#include "distance.h"

// Constructor: the default is 0 ft 0 in
    Distance::Distance(Feet f, Inches i) : ft(f), in(i) {
        reduce( );
    }

// Get methods
    Feet Distance::getFeet() const {
        return ft;
    }

    Inches Distance::getInches() const {
        return in;
    }

// Set methods
    void Distance::setFeet(Feet f) {
        ft = f;
    }

    void Distance::setInches(Inches i) {
        in = i;
    }

// Operator + : Addition of two distances, current object and parameter
    Distance Distance::operator+(const Distance& rhs) {
        Distance sum;
        sum.ft = ft + rhs.getFeet();
        sum.in = in + rhs.getInches();
        reduce();
        return sum;
    }

// Operator - : Subtraction of two distances, current object and parameter
    Distance Distance::operator-(const Distance& rhs) {
        Distance sub;
        sub.ft = ft - rhs.getFeet();
        sub.in = in - rhs.getInches();
        reduce();
        return sub;
    }

// Operator * : Multiplication of two distances, returns a double that represents square feet
    double Distance::operator*(const Distance& rhs) {
        double ans = 0.0;
        ans = convert_to_inches() * rhs.convert_to_inches();
        ans = ans/144;
        return ans;
    }

// Operator / : Division of two distances, returns the ratio of the two as a double
    double Distance::operator/(const Distance& rhs) {
        double ans;
        if (rhs.convert_to_inches() != 0)
            ans = convert_to_inches() / rhs.convert_to_inches();
        else
            cerr << "Error: Divide by zero";
        return ans;
    }

// Negation, returns the negative value of distance input
    Distance Distance::operator-() const {
        Distance ans;
        ans.ft = -ft;
        ans.in = -in;
        return ans;
    }

// Overload ==: Return true if this object == parameter, otherwise false
    bool Distance::operator==(const Distance& rhs) const {
        if (convert_to_inches() == rhs.convert_to_inches())
            return true;
        else
            return false;
    }

// Overload !=: Return false if this object == parameter, otherwise false
    bool Distance::operator!=(const Distance& rhs) const {
        return !(*this == rhs);
    }

// Overload >: Return true if this object > parameter, otherwise false
    bool Distance::operator>(const Distance& rhs) const {
         if (convert_to_inches() > rhs.convert_to_inches())
            return true;
         else
            return false;
     }

// Overload <: Return true if this object < parameter, otherwise false
    bool Distance::operator<(const Distance& rhs) const {
        if (convert_to_inches() < rhs.convert_to_inches())
            return true;
        else
            return false;
    }

// Overload >=: Return true if this object >= parameter, otherwise false
    bool Distance::operator>=(const Distance& rhs) const {
        if (convert_to_inches() >= rhs.convert_to_inches())
            return true;
        else
            return false;
    }

// Overload <=: Return true if this object <= parameter, otherwise false
    bool Distance::operator<=(const Distance& rhs) const {
        if (convert_to_inches() <= rhs.convert_to_inches())
            return true;
        else
            return false;
    }

// Overload +=: This object += parameter
    Distance& Distance::operator+=(const Distance& rhs) {
        ft += rhs.getFeet();
        in += rhs.getInches();
        reduce();
        return *this;
    }

// Overload -=: This object -= parameter
    Distance& Distance::operator-=(const Distance& rhs) {
        ft -= rhs.getFeet();
        in -= rhs.getInches();
        reduce();
        return *this;
    }

    // Overload <<: Prints the distance as "X ft Y in" to the output
    ostream& operator<<(ostream& out, const Distance& d){
        if (d.ft != 0)
            out << d.ft << " ft ";
        if (d.in != 0)
            out << d.in << " in";
        else
            out << "0 in";
        return out;
    }

    // Overload >>: Requests 2 ints as input from the user
    istream& operator>>(istream& in, Distance& d) {
        Feet infeet;
        Inches ininches;
        in >> infeet >> ininches;
        d.ft = infeet;
        d.in = ininches;
        return in;
    }

// reduce inches up to 12, simplify positive ft negative in and negative ft positive in
    void Distance::reduce() {
        ft += in / 12;
        in %= 12;
        if (ft > 0 && in < 0) {
            --ft;
            in += 12;
        }
        if (ft < 0 && in > 0) {
            ++ft;
            in -= 12;
        }
    }

// return value in inches for comparison
    double Distance::convert_to_inches() const {
        return ((ft*12) + in);
    }
