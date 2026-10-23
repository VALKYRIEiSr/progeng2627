#include <iostream>

bool prime(int n){
    for(int cf = 2; cf < n; cf++){

        if( (n % cf) == 0){ // n can be divided by cf...

            return false;
        }

    }
    return true;
}

int main(){
    int lower, upper;
    std::cin >> lower >> upper;
    for(int i = lower; i <= upper; i ++){
        if(prime(i)) std::cout << i << std::endl;
    }
}