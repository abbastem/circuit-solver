//
// Created by PcMax on ١٤/٠٥/٢٠٢٤.
//

#ifndef CIRCUIT_DESIGN_SOURCE_H
#define CIRCUIT_DESIGN_SOURCE_H
#include "iostream"
#include "cmath"

class Source {
public:
    double R = 0, V_Source = 0, I_Source = 0, II = 0, VR = 0, VI = 0;

    Source() = default;

    static Source addSource(Source S);

    Source operator + (Source &obj) const;

    Source operator * (Source &obj) const;

    void Print() const;

    void Delete();
};
std::istream &operator >> (std::istream &intput, Source &obj);

#endif //CIRCUIT_DESIGN_SOURCE_H
