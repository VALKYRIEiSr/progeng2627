#include <iostream>
#include <vector>


void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout){
    for(int x : vin1){
        vout.push_back(x);
    }
    for(int x : vin2){
        vout.push_back(x);
    }
}

int main(){
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{6, 7, 8, 9, 10};
    std::vector<int> vout;
    append_vectors(v1, v2, vout);
    for(int x : vout){
        std::cout << x << std::endl;
    }
}