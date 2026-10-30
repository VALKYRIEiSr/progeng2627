#include <iostream>

void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout){
    for(int x : vin){
        if(x < t) vout.push_back(x);
    }
}

int main(){
    double t;
    std::cout << "Please enter a value for filter: ";
    std::cin >> t;

    std::vector<double> v{1, 2, 3, 4, 5};
    std::vector<double> vout;

    filter_v(v, t, vout);
    for(int x : vout){
        std::cout << x << std::endl;
    }
}