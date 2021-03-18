//Damaris Poppe
#include <iostream>
#include <string>

int array[8] = {0};

int main(){
    int TC, index;

    std::cin >> TC;

    for (int i = 1; i <= TC; ++i){

        std::string seq;
        std::cin >> seq;

        //clearing arr[8] every time
        for(int j = 0; j < 8; j++){
            array[j] = 0;
        }

        for (int j = 0; j < 38; ++j){
            //reading each three-coing sequence,
            // TTT, TTH, THT, THH, HTT, HTH, HHT, HHH
            //  0    1    2    3    4    5    6    7
            index = ( seq[j]	 == 'H' ? 4 : 0 )  // 1st of seq
                    + ( seq[j+1] == 'H' ? 2 : 0 )  // 2nd of seq
                    + ( seq[j+2] == 'H' ? 1 : 0 ); // 3rd of seq

            array[index]++;
        }

        for (unsigned index = 0; index < 8; ++index){
            if (index == 7 ) {
                std::cout << array[index];
            }
            else {
                std::cout << array[index] << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}