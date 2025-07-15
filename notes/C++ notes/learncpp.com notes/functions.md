A **function** is a reusable sequence of statements designed to do a particular job. Functions written by yourself are user-defined functions
The function initiating the function call is the **caller**, and the function being **called** (executed) is the **callee**. A function call is also sometimes called an **invocation**, with the caller **invoking** the callee.

the first part of a function -> function header
```cpp
returnType functionName() // This is the function header (tells the compiler about the existence of the function)
{
    // This is the function body (tells the compiler what the function does)
}
```
functions can call other functions but you cant nest them

to return something we use the return statement with the return keyword what we return is called the return expression
When the return statement is executed:

- The return expression is evaluated to produce a value.
- The value produced by the return expression is copied back to the caller. This copy is called the **return value** of the function.
- The function exits, and control returns to the caller.
this is called **return by value** 

two rules for **main**:
- must return an int
- cant be called explicitly
global variables execute before main

the int we return is a status code or an exit code -> 0 if nothing went wrong 

parameter -> a value used in the function header
an argument -> the actual value we pass to a function call

## local variables
variables defined inside of a function are local variables, parameters are too
they are destroyed in the opposite order of creation after the function ends

Much like a person’s lifetime is defined to be the time between their birth and death, an object’s **lifetime** is defined to be the time between its creation and destruction. Note that variable creation and destruction happen when the program is running (called runtime), not at compile time. Therefore, lifetime is a runtime property.

when something gets destroyed nothing really happens the object just becomes invalid. after a while this memory gets deallocated

there is also a thing called temporary objects because they only gert stored for a short time for example print(getinput()) where is getinput stored? these are destroyed before the next statement and have no scope

## forward functions
when a function gets called before it is defined we will get a compile error

how do we solve this?
- reorganize code structure
- a forward declaration
this allows us to say there is a indentifier before actually declaring it
```cpp
#include <iostream>

int add(int x, int y); // forward declaration of add() (using a function declaration)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
    return 0;
}

int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}
```
`this will compile without the first add it wouldnt`

we use this primarily when the function is in another file because we cant just reorder the code then, but this might also help with readability
can also be done with types and vars
declaration: hey this exists
definition: this exists and does this

| Term                    | Technical Meaning                                                                         | Examples                                                                                                                                       |
| ----------------------- | ----------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| Declaration (prototype) | Tells compiler about an identifier and its associated type information.                   | void foo(); // function forward declaration (no body)  <br>void goo() {}; // function definition (has body)  <br>int x; // variable definition |
| Definition              | Implements a function or instantiates a variable.  <br>Definitions are also declarations. | void foo() { } // function definition (has body)  <br>int x; // variable definition                                                            |
| Pure declaration        | A declaration that isn’t a definition.                                                    | void foo(); // function forward declaration (no body)                                                                                          |
| Initialization          | Provides an initial value for a defined object.                                           | int x { 2 }; // x is initialized to value 2                                                                                                    |

The one definition rule (ODR)[](https://www.learncpp.com/cpp-tutorial/forward-declarations/#ODR)

The **one definition rule** (or ODR for short) is a well-known rule in C++. The ODR has three parts:

1. Within a _file_, each function, variable, type, or template in a given scope can only have one definition. Definitions occurring in different scopes (e.g. local variables defined inside different functions, or functions defined inside different namespaces) do not violate this rule.
2. Within a _program_, each function or variable in a given scope can only have one definition. This rule exists because programs can have more than one file. Functions and variables not visible to the linker are excluded from this rule
3. Types, templates, inline functions, and inline variables are allowed to have duplicate definitions in different files, so long as each definition is identical. 
Violating part 1 of the ODR will cause the compiler to issue a redefinition error. Violating ODR part 2 will cause the linker to issue a redefinition error. Violating ODR part 3 will cause undefined behavior.