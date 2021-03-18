//Name: Damaris Poppe
#include <iostream>
#include <cstdint>

using namespace std;
typedef unsigned long long int ullong;

ullong CPair(ullong n, ullong i){
    uint64_t answer;
    if (i == 0 || n == 0 || i == n)
        answer = 1;
    if(i > 0 && i < n)
        answer = CPair(n - 1, i - 1) + CPair(n - 1, i);
    return answer;
}

ullong Factorial(ullong n){
    if (n >= 0 && n <= 16) {
        if (n > 1)
            return n * Factorial(n - 1);
        else
            return 1;
    }
    return 0;
}

ullong xPower(ullong x, ullong pow){
    ullong numPower = 1;
    while(pow != 0){
        numPower *= x;
        pow--;
    }
    return numPower;
}

ullong SPair(ullong m, ullong n){
    ullong surjections;
    if (n == 1)
        surjections = 1;
    if (m < n)
        surjections = 0;
    if (m == n)
        surjections =  Factorial(m);

    if (n > 1 && m > n) {
        ullong totalSum = 0;
        for(ullong i = 1; i <= n-1; i++){
            ullong temp;
            temp = CPair(n, i) * SPair(m, i);
            totalSum += temp;
        }
        surjections = xPower(n, m) - totalSum;
    }
    return surjections;
}

int main(){
    ullong i_m, i_n;
    while(cin >> i_m >> i_n && i_m > 0 && i_n > 0) {  //read until EOF or 0 0
        cout << "S(" << i_m << "," << i_n << ") = " << SPair(i_m, i_n) << endl;
    }
}

