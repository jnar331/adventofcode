#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>

using namespace std;

int main()
{
    ifstream myfile("InputDay3");
    int size = 0;
    int first;


    std::vector<std::bitset<12>> binaries;
    std::bitset<12> binary;
    while(myfile >> binary){
        binaries.emplace_back(binary);
    }


    std::bitset<12> gamma;
    std::bitset<12> epsilon;

    for (int i = 0; i<12; i++){
        int oneCount = 0;
        int zeroCount = 0;

        for(auto const& binary: binaries) {
        switch (binary[i]){

        case 0:
            zeroCount++;
            break;
        case 1:
            oneCount++;
            break;
        }

    }

    if(zeroCount > oneCount){
        gamma.set(i,false);
        epsilon.set(i,true);
    }
    else{
        gamma.set(i,true);
        epsilon.set(i,false);
    }

    }


    cout << gamma << endl;
    cout << epsilon << endl;


    cout << gamma.to_ulong() * epsilon.to_ulong() << endl;

    return 0;
}

