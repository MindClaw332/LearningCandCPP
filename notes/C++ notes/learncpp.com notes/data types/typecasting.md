## implicit type conversion
implicit : this is when the language itself will jsut convert it when we have a function that takes a double and we give it an int it will just turn it into a double

```cpp
#include <iostream>

void print(double x) // print takes a double parameter
{
	std::cout << x << '\n';
}

int main()
{
	int y { 5 };
	print(y); // y is of type int

	return 0;
}
```
the above works

THIS WILL CREATE A NEW VALUE we dont get back the same variable but a new one
it doesnt actually return Y it returns a temp double

Some advanced type conversions (e.g. those involving `const_cast` or `reinterpret_cast`) do not return temporary objects, but instead reinterpret the type of an existing value or object.

this doesnt work the other way though goveong something that wants an int a double will just cut off the decimal thus losing data (this will give a warning)

char to int is also safe since we dont lose data there

## explicit type conversion
this is when we actually tell the program we want something to convert no matter what

for example if i want the double to int i can use a static_cast so the compiler knows i know what will happen and take responsibility
```cpp
#include <iostream>

void print(int x)
{
	std::cout << x << '\n';
}

int main()
{
	print( static_cast<int>(5.5) ); // explicitly convert double value 5.5 to an int

	return 0;
}
```

```cpp
static_cast<int>(ch) 
```
we can do this to cast a char for example

we can also do this to unsigned ints and signed ones as long as the destination is present so for example unsigned 2 can be signed 2 and vice versa

```cpp
#include <iostream>

int main()
{
    int s { -1 };
    std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

    unsigned int u { 4294967295 }; // largest 32-bit unsigned int
    std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20

    return 0;
}
```

otherwise it modulo wraps

**Warning**
Converting an unsigned integral value to a signed integral value will result in implementation-defined behavior prior to C++20 if the value being converted can not be represented in the signed type.

INT8_T is treated as a char this can create problems 
```cpp
#include <cstdint>
#include <iostream>

int main()
{
    std::int8_t myInt{65};
    std::cout << static_cast<int>(myInt) << '\n'; // will always print 65

    return 0;
}
```

if we dont static cast this might return the char A

```cpp
#include <cstdint>
#include <iostream>

int main()
{
    std::cout << "Enter a number between 0 and 127: ";
    std::int8_t myInt{};
    std::cin >> myInt;

    std::cout << "You entered: " << static_cast<int>(myInt) << '\n';

    return 0;
}
```

result:
Enter a number between 0 and 127: 35
You entered: 51

Here’s what’s happening. When `std::int8_t` is treated as a char, the input routines interpret our input as a sequence of characters, not as an integer. So when we enter `35`, we’re actually entering two chars, `'3'` and `'5'`. Because a char object can only hold one character, the `'3'` is extracted (the `'5'` is left in the input stream for possible extraction later). Because the char `'3'` has ASCII code point 51, the value `51` is stored in `myInt`, which we then print later as an int.

In contrast, the other fixed-width types will always print and input as integral values.