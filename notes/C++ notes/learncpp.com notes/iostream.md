input/output library: input from keyboard/output to console
include it at the top

### std::cout
```c++
'#'include <iostream> // for std::cout

int main()
{
    std::cout << "Hello world!"; // print Hello world! to console

    return 0;
}
```
allows for us to output characters to conole (cout = character output)
we use the << insertion operator to insert into the output can be done multiple times

```c++
#include <iostream> // for std::cout

int main()
{
    std::cout << "Hello" << " world!";
    return 0;
}
```
kind of like a conveyor belt

THIS IS BUFFERED so unless the buffer is flushed it stays in memory if hasnt been output. this is generally faster than directly outputting
### std::endl
this is an end line 
```cpp
#include <iostream> // for std::cout and std::endl

int main()
{
    std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line
    std::cout << "My name is Alex." << std::endl;

    return 0;
}
```
it is best practice to allways append a newline after output is complete

we can and ==should== use \n this doesnt flush the buffer thus making it faster (its also more concise)

### std::cin
```cpp
#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number

    int x{};       // define variable x to hold user input (and value-initialize it)
    std::cin >> x; // get number from keyboard and store it in variable x

    std::cout << "You entered " << x << '\n';
    return 0;
}
```

character in thus this reads from input we use the extraction operator here not the insertion

by doing `std::cin >> x >> y;` we can have the user enter multiple arguments

THIS IS BUFFERED ONCE AGAIN

```cpp
#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter two numbers: ";

    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    std::cout << "You entered " << x << " and " << y << '\n';

    return 0;
}
```

if you were to enter 4 5 it would extract 4 5\n it will now not ask for the second input instead it will use the 5 since 5 is still in the buffer; if we use it normally it will ask for input

`std::cin` is buffered because it allows us to separate the entering of input from the extract of input. We can enter input once and then perform multiple extraction requests on it.

### The basic extraction process[](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/#extraction)

Here’s a simplified view of how operator `>>` works for input.

1. If `std::cin` is not in a good state (e.g. the prior extraction failed and `std::cin` has not yet been cleared), no extraction is attempted, and the extraction process aborts immediately.
2. Leading whitespace characters (spaces, tabs, and newlines at the front of the buffer) are discarded from the input buffer. This will discard an unextracted newline character remaining from a prior line of input.
3. If the input buffer is now empty, operator `>>` will wait for the user to enter more data. Any leading whitespace is discarded from the entered data.
4. operator `>>` then extracts as many consecutive characters as it can, until it encounters either a newline character (representing the end of the line of input) or a character that is not valid for the variable being extracted to.

The result of the extraction process is as follows:

- If the extraction aborted in step 1, then no extraction attempt occurred. Nothing else happens.
- If any characters were extracted in step 4 above, extraction is a success. The extracted characters are converted into a value that is then copy-assigned to the variable.
- If no characters could be extracted in step 4 above, extraction has failed. The object being extracted to is copy-assigned the value `0` (as of C++11), and any future extractions will immediately fail (until `std::cin` is cleared).

Any non-extracted characters (including newlines) remain available for the next extraction attempt.

For example, given the following snippet:

```cpp
int x{};
std::cin >> x;
```

Here’s what happens in a three different input cases:

- If the user types `5a` and enter, `5a\n` will be added to the buffer. `5` will be extracted, converted to an integer, and assigned to variable `x`. `a\n` will be left in the input buffer for the next extraction.
- If the user types ‘b’ and enter, `b\n` would be added to the buffer. Because `b` is not a valid integer, no characters can be extracted, so this is an extraction failure. Variable `x` would be set to `0`, and future extractions will fail until the input stream is cleared.
- If `std::cin` is not in a good state due to a prior failed extraction, nothing happens here. The value of variable `x` is not altered.