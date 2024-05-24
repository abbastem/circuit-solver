//
// Created by PcMax on ١٤/٠٥/٢٠٢٤.
//

#include "generat.h"


void generat::main2() {

    int i, c = 1;
    while (true) {
        std::cout << "Enter 1 to set data and 2 to rerun the program any key to break : ";
        std::cin >> i;
        if (i == 2) {
            c = 1;
            Seq.Delete();
        }else if (i != 1)
            break;

        firstBranch:
        std::cout << "Enter R -> V -> I  for branch " << c << " \n";
        std::cin >> t;

        if (c == 1) {
            ++c;
            Seq = Seq + t;
            Seq = Source::addSource(Seq);
            goto firstBranch;
        }
        ++c;

        char state;
        try_again:
        std::cout << "Enter state ('S' or 'P') : ";
        std::cin >> state;
        if (state == 'S' || state == 's') {
            Seq = Seq + t;
            Seq = Source::addSource(Seq);
        } else if (state == 'P' || state == 'p') {
            Seq = Seq * t;
            Seq = Source::addSource(Seq);
        } else {
            std::cout << "Error !! \nyou must input ('S' or 'P').\ntry again\n";
            goto try_again;
        }
        Seq.Print();
    }
    std::cout << "The End !! \n";
}