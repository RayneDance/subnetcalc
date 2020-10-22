//Subnet Calculator

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include "subnetclass.cpp"

int main(int argc, char **argv) {

    SubnetCalc sub;


    if(argc == 1){
        std::cout << "Uses:\nsubnetcalc 192.168.0.1/24\nsubnetcalc -count 16\n";
    }

    if(argc == 2){
        std::cout << sub.fastMaskByAddr(argv[1]);
        return 0;
    }

    if(strcmp(argv[1],"-count")==0){
        std::cout << sub.maskByCount(argv[2]);
        return 0;
    }
/*
    for (int i = 0; i < argc; i++){
        std::cout << argv[i] << "\n";
        std::cout << typeid(argv[i]).name() << "\n";
    }
*/
    
    //std::cout << sub.getbmask();
    return 0;
}
