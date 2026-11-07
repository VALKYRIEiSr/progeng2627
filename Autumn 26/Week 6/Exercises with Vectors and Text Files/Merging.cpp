#include <iostream>

void merge_vectors_int(const std::vector<int> &v1, const std::vector<int> &v2, std::vector<int> &merged)
{
    int x = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        merged.push_back(v1[i]);
        while(v2[x] >= v1[i] && v2[x] <= v1[i+1] && x < v2.size()){
            merged.push_back(v2[x]);
            x++;
        }
    }
    while(x < v2.size()){
        merged.push_back(v2[x]);
        x++;
    }
}

int main()
{

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> out;

    v1 = {1, 3, 5, 6, 19, 21};
    v2 = {4, 6, 10, 12, 15, 20};

    merge_vectors_int(v1, v2, out);

    for(const int& x : out){
        std::cout << x << std::endl;
    }
}