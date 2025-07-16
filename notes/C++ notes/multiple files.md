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

there is a thing called naming collision where if you have two identical identifiers the program wont know which is which
Most naming collisions occur in two cases:

1. Two (or more) identically named functions (or global variables) are introduced into separate files belonging to the same program. This will result in a linker error, as shown above.
2. Two (or more) identically named functions (or global variables) are introduced into the same file. This will result in a compiler error.
scope region is an area where all indentifiers are considered unique

a namespace is one of those regions called a namespace scop but also a function is a scope
any name that is not defined inside a class, function, or a namespace is considered to be part of an implicitly-defined namespace called the **global namespace**

The :: symbol is an operator called the **scope resolution operator**. The identifier to the left of the `::` symbol identifies the namespace that the name to the right of the `::` symbol is contained within. If no identifier to the left of the `::` symbol is provided, the global namespace is assumed.

```cpp
#include <iostream>

using namespace std; // this is a using-directive that allows us to access names in the std namespace with no namespace prefix

int main()
{
    cout << "Hello world!";
    return 0;
}
```

A **using directive** allows us to access the names in a namespace without using a namespace prefix. So in the above example, when the compiler goes to determine what identifier `cout` is, it will match with `std::cout`, which, because of the using-directive, is accessible as just `cout`.

THIS IS DISCOURAGED