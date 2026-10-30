#include <iostream>

int main()
{
    int n, s, i = 0;
    std::cout << "Please enter an integer n for the number of inputs to take: ";
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> indices;
    for (int &x : a)
    {
        std::cout << "Please enter a value: ";
        std::cin >> x;
    }
    std::cout << "Please enter s: ";
    std::cin >> s;
    for (int x : a)
    {
        if (x == s)
        {
            i++;
            indices.push_back(i);
        }
    }
    std::cout << "There are: " << i << " occurrences of " << s << std::endl;
    for (int x : indices)
    {
        std::cout << x << std::endl;
    }
}