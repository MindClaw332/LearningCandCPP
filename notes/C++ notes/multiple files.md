VSCODE
in the .vscode folder change the taks file
instead of "${file}" -> "file.cpp", "file2.cpp"

can also do `"${filedirname}/**.cpp"` 

main.cpp (with forward declaration):
```cpp
#include <iostream>

int add(int x, int y); // needed so main.cpp knows that add() is a function defined elsewhere

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}
```

add.cpp
```cpp
int add(int x, int y)
{
    return x + y;
}
```
Because the compiler compiles each code file individually (and then forgets what it has seen), each code file that uses `std::cout` or `std::cin` needs to `#include <iostream>`.

In the above example, if `add.cpp` had used `std::cout` or `std::cin`, it would have needed to `#include <iostream>`.

## namespaces
