//
// Created by PcMax on ١٤/٠٥/٢٠٢٤.
//

#include "generat.h"


void generat::main2() {

    int i, c = 1;
    while (true) {
        again:
        std::cout << "Enter 1 to set data and 2 to rerun the program and any key to break : ";
        try {
            std::cin >> i;

            if (std::cin.fail() || std::cin.peek() != '\n'){
                throw std::runtime_error("Invalid input. Place enter a valid number.");
            }

            if (i == 2) {
                c = 1;
                Seq.Delete();
                std::cout.clear();
            } else if (i != 1)
                break;

            firstBranch:
            std::cout << "Enter R -> V -> I  for branch " << c << " \n";
            try {
                std::cin >> t;

                if (std::cin.fail() || std::cin.peek() != '\n') {
                    throw std::runtime_error("Invalid input. Place enter a valid number.");
                }

                t = Source::addSource(t);
                if (t.check(t))
                    goto again;

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
                if (!Seq.check(Seq))
                    Seq.Print();
            }
            catch (const std::exception& e) {
                std::cerr << "\033[1;31mWarning " << e.what() << "\033[0m" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        catch(const std::exception& e) {
            std::cerr << "\033[1;31mWarning " << e.what() << "\033[0m" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "The End !! \n";
}