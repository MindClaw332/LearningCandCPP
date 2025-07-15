#include <iostream>

int doubleNumber(int num)
{
    return 2 * num;
}

int getUserInput(){
    std::cout << "enter an integer: \n";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    int x{getUserInput()};
    std::cout << "your doubled number is: " << doubleNumber(x) << '\n';

}
