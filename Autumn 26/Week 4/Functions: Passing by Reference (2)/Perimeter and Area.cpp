#include <iostream>
#include <cmath>
// for the square root

void perimeter_and_area(double a, double b, double &perimeter, double &area)
{
    perimeter = 2*a + 2*b;
    area = a*b;
}

int main()
{

    double a, b;

    std::cout << "please enter the coefficients side lengths:" << std::endl;

    std::cin >> a >> b;

    double perimeter, area;
    // we pass these variables uninitialised to the function
    // because the values will be provided in output
    // by the function

    perimeter_and_area(a, b, perimeter, area);
    std::cout << "the perimeter is: " << perimeter << std::endl;
    std::cout << "the area is: " << area << std::endl;
}