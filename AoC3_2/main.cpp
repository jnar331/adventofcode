#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>

using namespace std;

enum class Mode{
    LeastCommon = 0,
    MostCommon = 1
};

void performAlgorithm(std::vector<bitset<12>>& binary, Mode mode){
    int oneCount = 0;
    int zeroCount = 0;

    for (int i = 0; i<12; i++){

        for(auto const& bin: binary)
        {
            if(bin[i] == 0){
                zeroCount++;
            }

            else{
                oneCount++;
            }
        }

        if(zeroCount > oneCount){
            for(std::vector<std::bitset<12>>::size_type j = 0; j != binary.size(); j++) {
                if(mode == Mode::MostCommon){
                    if(binary[j][i] == 1){
                        binary.erase(binary.begin() + j);
                    }
                }

                else{
                    if(binary[j][i] == 0){
                        binary.erase(binary.begin() + j);
                    }
                }

            }

        }

        else if(oneCount > zeroCount){
            for(std::vector<std::bitset<12>>::size_type j = 0; j != binary.size(); j++) {
                if(mode == Mode::MostCommon){
                    if(binary[j][i] == 0){
                        binary.erase(binary.begin() + j);
                    }
                }

                else{
                    if(binary[j][i] == 1){
                        binary.erase(binary.begin() + j);
                    }
                }

            }
        }

        if(binary.size() == 1){
            break;
        }

        }


}

int main()
{
    ifstream myfile("InputDay3");
    std::vector<std::bitset<12>> binaries;
    std::bitset<12> binary;
    while(myfile >> binary){
        binaries.emplace_back(binary);
    }

    std::vector<std::bitset<12>> oxygen;
    std::vector<std::bitset<12>> co2;

    oxygen = binaries;
    co2 = binaries;

    performAlgorithm(oxygen,Mode::MostCommon);
    performAlgorithm(co2,Mode::LeastCommon);

    std::cout << oxygen.size();



    return 0;
}

