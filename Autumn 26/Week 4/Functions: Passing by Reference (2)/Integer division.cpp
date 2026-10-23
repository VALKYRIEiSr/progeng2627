#include <iostream>
#include <cmath>
// for the square root

void integer_division(int a, int b, int &quotient, int &remainder)
{
    quotient = a/b;
    remainder = a%b;
}

int main()
{

    int a, b;

    std::cout << "please enter two integer values for value 1 / value 2:" << std::endl;

    std::cin >> a >> b;

    int quotient, remainder;
    // we pass these variables uninitialised to the function
    // because the values will be provided in output
    // by the function

    integer_division(a, b, quotient, remainder);
    std::cout << "the quotient is: " << quotient << std::endl;
    std::cout << "the remainder is: " << remainder << std::endl;
}