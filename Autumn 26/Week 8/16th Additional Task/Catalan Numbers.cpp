#include <iostream>
#include <vector>

std::vector<unsigned long> catalan_numbers(int n)
{
    std::vector<unsigned long> Cn = {1};
    for (int x = 1; x <= n; x++)
    {
        unsigned long sum = 0;
        for (int i = 0; i < x; i++)
        {
            sum += Cn[i] * Cn[x - 1 - i];
            
        }
        Cn.push_back(sum);
    }
    return Cn;
}

int main()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<unsigned long> numbers = catalan_numbers(n);

    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << "C" << i << " = " << numbers[i] << std::endl;
    }

    return 0;
}
