/*  Distance program
    Kyle Dukart
    CSIS 342
    Created on 10/7/18

    This main.cpp tests the methods of the Distance class
*/

#include <iostream>
#include "distance.h"

using namespace std;

int main()
{
    Distance d1(8,10), d2(-10, -5), d3(8,-2), d4, d5;

    cout << "type two integers for d4";
    cin >> d4;

    cout << "d1 =" << d1 << endl;
    cout << "d2 =" << d2 << endl;
    cout << "d3 =" << d3 << endl;
    cout << "d4 =" << d4 << endl;
    cout << "d5 =" << d5 << endl;

    cout << "d1 + d2 + d3 = " << d1 + d2 + d3 << endl;
    cout << "d1 - d2 - d3 = " << d1 - d2 - d3 << endl;
    cout << "d1 * 15 = " << d1 * 15 << endl;
    cout << "d1 * d3 = " << d1 * d3 << endl;
    cout << "d1 / d3 = " << d1 / d3 << endl;
    cout << "-d1 = " << -d1 << endl;

    cout << "d1 <= d2 is " << ( ( d1 <= d2 ) ? "true" : "false" ) << endl;
    cout << "d2 >= d3 is " << ( ( d2 >= d3 ) ? "true" : "false" ) << endl;
    cout << "d3 > d4 is " << ( ( d3 > d4 ) ? "true" : "false" ) << endl;
    cout << "d4 < d5 is " << ( ( d4 < d5 ) ? "true" : "false" ) << endl;
    cout << "d1 == d1 is " << ( ( d1 == d1 ) ? "true" : "false" ) << endl;
    cout << "d1 != d1 is " << ( ( d1 != d1 ) ? "true" : "false" ) << endl;

    cout << "(d5 += d1) += d2 is " << ( (d5 += d1) += d2 ) << endl;
    cout << "(d4 = 0) is " << ( d4 = 0 ) << endl;
    cout << "(d3 -= d1) -= d2 is " << ( (d3 -= d1) -= d2 ) << endl;

    return 0;
}
