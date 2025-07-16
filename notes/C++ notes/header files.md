to make your stuff scaleable when you for example need 20 forward declarations we have header files

header files have .h extension also sometime .hpp or none
Prefer a .h suffix when naming your header files (unless your project already follows some other convention).

This is a longstanding convention for C++ header files, and most IDEs still default to .h over other options.

If a header file is paired with a code file (e.g. add.h with add.cpp), they should both have the same base name (add).

```cpp
#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
```

add.cpp:

```cpp
#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.

int add(int x, int y)
{
    return x + y;
}
```

add.h:

```cpp
// We really should have a header guard here, but will omit it for simplicity (we'll cover header guards in the next lesson)

// This is the content of the .h file, which is where the declarations go
int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!
```

source files should include their header

Unfortunately, this doesn’t work if it is a parameter with a different type instead of a return type. This is because C++ supports overloaded functions (functions with the same name but different parameter types), so the compiler will assume a function with a mismatched parameter type is a different overload. Can’t win em all.

Avoid #including .cpp files. 

we use <> for files we didnt write ourselves
"" is used so the preprocessor knows to look in our directories

| Header type           | Naming convention | Example    | Identifiers placed in namespace                             |
| --------------------- | ----------------- | ---------- | ----------------------------------------------------------- |
| C++ specific (new)    | <xxx>             | iostream   | `std` namespace                                             |
| C compatibility (new) | <cxxx>            | cstddef    | `std` namespace (required)  <br>global namespace (optional) |
| C++ specific (old)    | <xxx.h>           | iostream.h | Global namespace                                            |
| C compatibility (old) | <xxx.h>           | stddef.h   | Global namespace (required)  <br>`std` namespace (optional) |

Use the standard library header files without the .h extension. User-defined headers should still use a .h extension.

to include other directories 
In your _tasks.json_ configuration file, add a new line in the _“Args”_ section:  
`"-I./source/includes",`

There is no space after the `-I`. For a full path (rather than a relative path), remove the `.` after `-I`.

transitive includes are when header files contain other header files since these are now implicitly part of your code
Each file should explicitly #include all of the header files it needs to compile. Do not rely on headers included transitively from other headers.

To maximize the chance that missing includes will be flagged by compiler, order your #includes as follows (skipping any that are not relevant):

- The paired header file for this code file (e.g. `add.cpp` should `#include "add.h"`)
- Other headers from the same project (e.g. `#include "mymath.h"`)
- 3rd party library headers (e.g. `#include <boost/tuple/tuple.hpp>`)
- Standard library headers (e.g. `#include <iostream>`)

The headers for each grouping should be sorted alphabetically (unless the documentation for a 3rd party library instructs you to do otherwise).

That way, if one of your user-defined headers is missing an #include for a 3rd party library or standard library header, it’s more likely to cause a compile error so you can fix it.

### best practices 
- always have it contain header guards (seen below)
- Give a header file the same name as the source file it’s associated with (e.g. `grades.h` is paired with `grades.cpp`).
- Each header file should have a specific job, and be as independent as possible. For example, you might put all your declarations related to functionality A in A.h and all your declarations related to functionality B in B.h. That way if you only care about A later, you can just include A.h and not get any of the stuff related to B.
- Be mindful of which headers you need to explicitly include for the functionality that you are using in your code files, to avoid inadvertent transitive includes.
- A header file should #include any other headers containing functionality it needs. Such a header should compile successfully when #included into a .cpp file by itself.
- Only #include what you need (don’t include everything just because you can).
- Do not #include .cpp files.
- Prefer putting documentation on what something does or how to use it in the header. It’s more likely to be seen there. Documentation describing how something works should remain in the source files.
## header guards
**header guard**s (also called an **include guard**) are conditional compilation directives that take the following form:
```cpp
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// your declarations (and certain types of definitions) here

#endif
```
Summary

Header guards are designed to ensure that the contents of a given header file are not copied more than once into any single file, in order to prevent duplicate definitions.

Duplicate _declarations_ are fine -- but even if your header file is composed of all declarations (no definitions) it’s still a best practice to include header guards.

Note that header guards do _not_ prevent the contents of a header file from being copied (once) into separate project files. This is a good thing, because we often need to reference the contents of a given header from different project files.