//
// Created by PcMax on ١٤/٠٥/٢٠٢٤.
//

#ifndef CIRCUIT_DESIGN_COMPLEX_H
#define CIRCUIT_DESIGN_COMPLEX_H
#include "iostream"
#include "cmath"

class Complex {
public:
    double X,Y,R,Angle;

    Complex()  = default;

    static double sqrt(double x, double y);

    Complex(double x, double y, bool z) {
        if (z) {
            X = x;
            Y = y;
            R = sqrt(X, Y);
            Angle = atan(Y / X);
        } else {
            R = x;
            Angle = y;
            X = R * cos(Angle);
            Y = R * sin(Angle);
        }
    }
    Complex operator + (Complex obj) const;

    Complex operator - (Complex obj) const;

    Complex operator * (Complex obj) const;

    Complex operator / (Complex obj) const;

};
std::ostream &operator << (std::ostream &output, Complex &obj);


#endif //CIRCUIT_DESIGN_COMPLEX_H
