//
// Created by PcMax on ١٤/٠٥/٢٠٢٤.
//

#include "Source.h"

Source Source::addSource(Source S) {
    Source A;
    if (S.I_Source == 0) {
        A.R = S.R;
        A.V_Source = S.V_Source;
        A.I_Source = 0;
        A.VR = S.V_Source;
        A.VI = 0;
        A.II = S.V_Source / S.R;
    } else if (S.V_Source == 0) {
        A.R = S.R;
        A.V_Source = 0;
        A.I_Source = S.I_Source;
        A.VR = S.R * S.I_Source;
        A.VI = S.R * S.I_Source;
        A.II = S.I_Source;
    } else {
        A.R = S.R;
        A.V_Source = S.V_Source;
        A.I_Source = S.I_Source;
        A.VR = S.R * S.I_Source;
        A.VI = (S.R * S.I_Source) - S.V_Source;
        A.II = S.I_Source;
    }
    return A;
}

Source Source::operator+(Source &obj) const {
    Source sum;
    if (obj.I_Source != 0 && I_Source != 0) {
        std::cout << "error !! \n";
        return sum;
    }
    sum.R = R + obj.R;
    sum.V_Source = V_Source + obj.V_Source;
    sum.I_Source = I_Source + obj.I_Source;

    return sum;
}

Source Source::operator*(Source &obj) const {
    Source sum;
    if (obj.R == 0) {
        sum.R = R;
    } else if (R == 0) {
        sum.R = obj.R;
    } else {
        sum.R = (R * obj.R) / (R + obj.R);
    }
    sum.I_Source = I_Source + obj.I_Source;
    sum.V_Source = V_Source + obj.V_Source;

    return sum;
}

void Source::Print() const {
    printf("R = %4.2f Ohm \nV = %4.2f Volt \nI = %4.2f Amber \n"
           "VR = %4.2f Volt \nVI = %4.2f Volt \nII = %4.2f Amber \n", R, V_Source, I_Source, VR, VI, II);
}

void Source::Delete() {
    R = 0;
    V_Source = 0;
    I_Source = 0;
    VR = 0;
    VI = 0;
    II = 0;
}

std::istream &operator >> (std::istream &input, Source &obj) {
    input >> obj.R >> obj.V_Source >> obj.I_Source;

    return input;
}
