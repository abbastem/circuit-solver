#include "Complex.h"


std::ostream &operator<<(std::ostream &output, Complex &obj) {
    output << "X = " << obj.X << "\nY = " << obj.Y << "\nR = " << obj.R << "\nAngle = " << obj.Angle << "\n";

    return output;
}

double Complex::sqrt(double x, double y) {
    return pow(x, 2) + pow(y, 2);
}

Complex Complex::operator+(Complex obj) const {
    Complex sum;
    sum.X = X + obj.X;
    sum.Y = Y + obj.Y;
    sum.R = sqrt(sum.X, sum.Y);
    sum.Angle = atan(sum.Y / sum.X);

    return sum;
}

Complex Complex::operator-(Complex obj) const {
    Complex sum;
    sum.X = X - obj.X;
    sum.Y = Y - obj.Y;
    sum.R = sqrt(sum.X, sum.Y);
    sum.Angle = atan(sum.Y / sum.X);

    return sum;
}

Complex Complex::operator*(Complex obj) const {
    Complex sum;
    sum.X = X * obj.X;
    sum.Y = Y * obj.Y;
    sum.R = sqrt(sum.X, sum.Y);
    sum.Angle = atan(sum.Y / sum.X);

    return sum;
}

Complex Complex::operator/(Complex obj) const {
    Complex sum;
    sum.X = X / obj.X;
    sum.Y = Y / obj.Y;
    sum.R = sqrt(sum.X, sum.Y);
    sum.Angle = atan(sum.Y / sum.X);

    return sum;
}