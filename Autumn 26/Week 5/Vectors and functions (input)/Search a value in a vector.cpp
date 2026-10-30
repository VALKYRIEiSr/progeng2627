#include <iostream>

int search_vector(int n, const std::vector<int>& vin){
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == n) return i;
    }
    return -1;
}

int main()
{
    std::vector<int> test{1, 4, 6, 8, -9, -19, -4, 0, 0, 1};
    std::cout << search_vector(8, test);

}