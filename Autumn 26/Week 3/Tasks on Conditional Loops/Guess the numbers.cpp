#include <iostream>

int main()
{
    int l, u, guess, flag = 0;
    char input;
    std::cout << "Please input an integer lower and upper bound: " << std::endl;
    std::cin >> l >> u;
    while (!flag)
    {
        guess = (l+u)/2; //value will be floored, but thats fine.
        std::cout << "My guess is: " << guess << std::endl << "Please enter 'y' is my guess is correct, otherwise enter 'l' if your number is lower or 'h' if the your number is higher" << std::endl;
        std::cin >> input;
        if (input == 'y') flag = 1;
        else if(input == 'l') u = guess;
        else l = guess;
    }
}