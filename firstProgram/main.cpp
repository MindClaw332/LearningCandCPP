#include <iostream>

int main()
{
    std::cout << "enter an integer: \n";
    int x{};
    std::cin >> x;
    std::cout << "double that number is: "<< x << " is: " << x * 2 << '\n';
    std::cout << "triple " << x << " is: " << x * 3 << '\n';
    return 0;
}
