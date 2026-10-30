#include <iostream>

int min_vector_element(const std::vector<double>& vin){
    int smallest;
    if(vin.size() == 0) return -1;
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] < smallest) smallest = vin[i];
    }
    return smallest;
}

int main()
{
    std::vector<double> test{1, 4, 6, 8, -9, -19, -4, 0, 0, 1};
    std::cout << min_vector_element(test);

}