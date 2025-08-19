most chunks of data are byte-sized because of limited memory adresses if we were to use bits

## fundamental data types (primitives)

| Types                                                                              | Category             | Meaning                                          | Example |
| ---------------------------------------------------------------------------------- | -------------------- | ------------------------------------------------ | ------- |
| float  <br>double  <br>long double                                                 | Floating Point       | a number with a fractional part                  | 3.14159 |
| bool                                                                               | Integral (Boolean)   | true or false                                    | true    |
| char  <br>wchar_t  <br>char8_t (C++20)  <br>char16_t (C++11)  <br>char32_t (C++11) | Integral (Character) | a single character of text                       | ‘c’     |
| short int  <br>int  <br>long int  <br>long long int (C++11)                        | Integral (Integer)   | positive and negative whole numbers, including 0 | 64      |
| std::nullptr_t (C++11)                                                             | Null Pointer         | a null pointer                                   | nullptr |
| void                                                                               | Void                 | no type                                          | n/a     |
integral types -> like an int a bool, char and standard ints are integral types

- The “fundamental data types” provide the most the basic and essential data types.
- The “compound data types” provide more complex data types and allow for the creation of custom (user-defined) types. We cover these in lesson
- The third (and largest) set of types is provided by the C++ standard library. Because the standard library is included in all C++ distributions, these types are broadly available and have been standardized for compatibility. Use of the types in the standard library requires the inclusion of the appropriate header and linking in the standard library.
If you see something with a `_t` suffix, it’s probably a type

**void**: this is an incomplete type because the compiler cant allocate memory for it which make sense since it is the lack of a type that makes void void
## **sizeof**: 
object can hold 2^n bits where n is an int so an 8 bit byte can hold 2^8 or 256 bits 

the standard says the following:

- An object must occupy at least 1 byte (so that each object has a distinct memory address).
- A byte must be at least 8 bits.
- The integral types `char`, `short`, `int`, `long`, and `long long` have a minimum size of 8, 16, 16, 32, and 64 bits respectively.
- `char` and `char8_t` are exactly 1 byte (at least 8 bits).

| Category       | Type           | Minimum Size     | Typical Size       |
| -------------- | -------------- | ---------------- | ------------------ |
| Boolean        | bool           | 1 byte           | 1 byte             |
| Character      | char           | 1 byte (exactly) | 1 byte             |
|                | wchar_t        | 1 byte           | 2 or 4 bytes       |
|                | char8_t        | 1 byte           | 1 byte             |
|                | char16_t       | 2 bytes          | 2 bytes            |
|                | char32_t       | 4 bytes          | 4 bytes            |
| Integral       | short          | 2 bytes          | 2 bytes            |
|                | int            | 2 bytes          | 4 bytes            |
|                | long           | 4 bytes          | 4 or 8 bytes       |
|                | long long      | 8 bytes          | 8 bytes            |
| Floating point | float          | 4 bytes          | 4 bytes            |
|                | double         | 8 bytes          | 8 bytes            |
|                | long double    | 8 bytes          | 8, 12, or 16 bytes |
| Pointer        | std::nullptr_t | 4 bytes          | 4 or 8 bytes       |
you can see this with sizeof THIS DOES NOT SHOW DYNAMIC MEMORIES

You might assume that types that use less memory would be faster than types that use more memory. This is not always true. CPUs are often optimized to process data of a certain size (e.g. 32 bits), and types that match that size may be processed quicker. On such a machine, a 32-bit int could be faster than a 16-bit short or an 8-bit char.

## signed ints
| Type          | Minimum Size | Note                                      |
| ------------- | ------------ | ----------------------------------------- |
| short int     | 16 bits      |                                           |
| int           | 16 bits      | Typically 32 bits on modern architectures |
| long int      | 32 bits      |                                           |
| long long int | 64 bits      |                                           |
being a positive negative or zero number means its signed unsigned can not be negative
```cpp
short s;      // prefer "short" instead of "short int"
int i;
long l;       // prefer "long" instead of "long int"
long long ll; // prefer "long long" instead of "long long int"
```

can also have signed infront

| Size / Type   | Range                                                   |
| ------------- | ------------------------------------------------------- |
| 8-bit signed  | -128 to 127                                             |
| 16-bit signed | -32,768 to 32,767                                       |
| 32-bit signed | -2,147,483,648 to 2,147,483,647                         |
| 64-bit signed | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |

**overflow**: this is when we try to store a value that is too big for the variable inside of said variable thus giving us undefined behaviour
when performing arithmetic with two integers c++ will always return an integer

## unsigned ints
| Size/Type       | Range                           |
| --------------- | ------------------------------- |
| 8 bit unsigned  | 0 to 255                        |
| 16 bit unsigned | 0 to 65,535                     |
| 32 bit unsigned | 0 to 4,294,967,295              |
| 64 bit unsigned | 0 to 18,446,744,073,709,551,615 |
The number `280` is too big to fit in our 1-byte range of 0 to 255. 1 greater than the largest number of the type is 256. Therefore, we divide 280 by 256, getting 1 remainder 24. The remainder of 24 is what is stored.

a lot of devs agree that you should just avoid unsigned ints:
- it is much easier to overflow than with an signed int
- mixing signed and unsigned ints we can easily get undefined behaviour

Favor signed numbers over unsigned numbers for holding quantities (even quantities that should be non-negative) and mathematical operations. Avoid mixing signed and unsigned numbers.

when should you use unsigend?
- bit manipulation/ when actual wrap around behaviour is wanted
- array indexing will use unsigned
- embedded systems it is more common and accepted

## fixed width ints and size_t
we cant always assume the size of an int on architecture where an int is 16 bits we will have too little space
but on if we go by 16 bits we will only be using half the memory on other architecture

*in a lot of cases this isnt a big deal when it is destroyed afterwards but when instantiating millions this will matter*

| Name          | Fixed Size      | Fixed Range                                             | Notes                                                          |
| ------------- | --------------- | ------------------------------------------------------- | -------------------------------------------------------------- |
| std::int8_t   | 1 byte signed   | -128 to 127                                             | Treated like a signed char on many systems. See note below.    |
| std::uint8_t  | 1 byte unsigned | 0 to 255                                                | Treated like an unsigned char on many systems. See note below. |
| std::int16_t  | 2 byte signed   | -32,768 to 32,767                                       |                                                                |
| std::uint16_t | 2 byte unsigned | 0 to 65,535                                             |                                                                |
| std::int32_t  | 4 byte signed   | -2,147,483,648 to 2,147,483,647                         |                                                                |
| std::uint32_t | 4 byte unsigned | 0 to 4,294,967,295                                      |                                                                |
| std::int64_t  | 8 byte signed   | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |                                                                |
| std::uint64_t | 8 byte unsigned | 0 to 18,446,744,073,709,551,615                         |                                                                |
```cpp
#include <cstdint> // for fixed-width integers
#include <iostream>

int main()
{
    std::int32_t x { 32767 }; // x is always a 32-bit integer
    x = x + 1;                // so 32768 will always fit
    std::cout << x << '\n';

    return 0;
}
```

The 8-bit fixed-width integer types are often treated like chars instead of integer values (and this may vary per system). The 16-bit and wider integral types are not subject to this issue.

The fixed-width integers have some potential downsides:
- there is a chance that the fixed width is not actually supported since these are just aliases for other things like a long
- it isnt always faster if the system is better at using 64 bit ints it will be slower when using 32 bit

The fast types (std::int_fast#_t and std::uint_fast#_t) provide the fastest signed/unsigned integer type with a width of at least # bits (where # = 8, 16, 32, or 64). For example, `std::int_fast32_t` will give you the fastest signed integer type that’s at least 32-bits. By fastest, we mean the integral type that can be processed most quickly by the CPU.

Avoid the fast and least integral types because they may exhibit different behaviors on architectures where they resolve to different sizes.

Best practice

- Prefer `int` when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether `int` is 16-bits or 32-bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
- Prefer `std::int#_t` when storing a quantity that needs a guaranteed range.
- Prefer `std::uint#_t` when doing bit manipulation or well-defined wrap-around behavior is required (e.g. for cryptography or random number generation).

Avoid the following when possible:

- `short` and `long` integers (prefer a fixed-width integer type instead).
- The fast and least integral types (prefer a fixed-width integer type instead).
- Unsigned types for holding quantities (prefer a signed integer type instead).
- The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type instead).
- Any compiler-specific fixed-width integers (for example, Visual Studio defines __int8, __int16, etc…)

std::size_t
`sizeof` returns a value of type `std::size_t`. **std::size_t** is an alias for an implementation-defined unsigned integral type. In other words, the compiler decides if `std::size_t` is an unsigned int, an unsigned long, an unsigned long long, etc…

Best practice

If you use `std::size_t` explicitly in your code, #include one of the headers that defines `std::size_t` (we recommend <cstddef>).

Using `sizeof` does not require a header (even though it returns a value whose type is `std::size_t`).

How to convert decimal numbers to scientific notation

Use the following procedure:

- Your exponent starts at zero.
- If the number has no explicit decimal point (e.g. `123`), it is implicitly on the right end (e.g. `123.`)
- Slide the decimal point left or right so there is only one non-zero digit to the left of the decimal.
    - Each place you slide the decimal point to the left increases the exponent by 1.
    - Each place you slide the decimal point to the right decreases the exponent by 1.
- Trim off any leading zeros (on the left end of the significand)
- Trim off any trailing zeros (on the right end of the significand) only if the original number had no decimal point. We’re assuming they’re not significant. If you have additional information to suggest they are significant, you can keep them.