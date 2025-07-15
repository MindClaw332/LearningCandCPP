#include <iostream>

int main()
{
    std::cout << "enter an integer: \n";
    int a{};
    int b{};
    std::cin >> a;
    std::cout << "enter another integer: \n";
    std::cin >> b;
    std::cout << a << " + " << b << " = " << a + b << "\n";
    std::cout << a << " - " << b << " = " << a - b << "\n";


    return 0;
}
