#include <iostream>

int main()
{
    int n, i;
    i = 0;
    while (n <= 1)
    {
        std::cout << "input a natural integer n: " << std::endl;
        std::cin >> n;
    }
    while (n - 1)
    {
        if (!(n % 2))
            n = n / 2;
        else
            n = 3 * n + 1;
        i++;
        std::cout << n << std::endl;
    }
    std::cout << "Number of steps: " << i << std::endl;
}