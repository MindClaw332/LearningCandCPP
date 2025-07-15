this understanding is important to write memory efficient code
from educative.io

## memory
memory is simplified a bunch of adresses where we can store bytes which can then be interpreted as data.

there are generally four segments:
- global segment -> this is the segment responsible for global and static variables -> these variables survive the entire duration of the program (aka their lifetime is equal to that of the program)
- code segment -> this has the actual text and machined code of your program
- stack segment -> this is used for managing local variables -> arguments and control information such as return adresses
- heap segment -> a flexible area for storing large data structures and objects that have dynamic lifetimes. this can be allocated and deallocated during execution

also this is not the same as the data structures stack and heap
![[2025-07-15-122318_hyprshot.png]]
`An overview of the four memory segments—global, code, stack, and heap—illustrating the conventional representation of heap growing downward and stack growing upward`

```cpp
#include <iostream>

// Global Segment: Global variables are stored here
int globalVar = 42;

// Code Segment: Functions and methods are stored here
int add(int a, int b) {
    return a + b;
}

int main() {
    // Code Segment: Calling the add function
    int sum = add(globalVar, 10);
    
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
```

### stack memory
efficient storage unit -> lifo (Last In First Out) most recent data goes out first; the stack is mainly handled by the kernel so we dont have to worry about this

```cpp
#include <iostream>

// A simple function to add two numbers
int add(int a, int b) {
    // Local variables (stored in the stack)
    int sum = a + b;
    return sum;
}

int main() {
    // Local variable (stored in the stack)
    int x = 5;

    // Function call (stored in the stack)
    int result = add(x, 10);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
```
`Stack memory usage in C++: demonstrating local variables and function calls`

a block of memory (stack frame) is created when we call a function. this frame stores information related to local variables parameters and the return adress of the function. this in turn is on the stack segment

Here is the explanation of the C++ code in the order of execution:

- **Line 10:** The program starts with the `main` function, and a new stack frame is created for it.
    
- **Line 12:** The local variable `x` is assigned the value `5`.
    
- **Line 15:** The `add` the function is called with the arguments `x` and `10`.
    
- **Line 4:** A new stack frame is created for the `add` function. The control is transferred to the `add` function with local variables. `a`, `b`, and `sum`. Variables `a` and `b` are assigned the values of `x` and `10`, respectively.
    
- **Line 6:** The local variable `sum` is assigned the value of `a + b` (i.e., 5 + 10).
    
- **Line 7:** The `sum` variable's value (i.e., 15) is returned to the caller.
    
- **Line 8:** The `add` function's stack frame is popped from the stack, and all local variables ( `a`, `b`, and `sum`) are deallocated.
    
- **Line 15:** The local variable `result` on the stack frame of the `main` function is assigned the returned value (i.e., 15).
    
- **Line 17:** The value stored in the `result` variable (i.e., 15) is printed to the console using `std::cout`.
    
- **Line 19:** The `main` function returns 0, signaling successful execution.
    
- **Line 20:** The `main` function's stack frame is popped from the stack, and all local variables (`x` and `result`) are deallocated.

### key things about the stack
- fixed size -> the size is determined at the start
- speed advantage -> memory frames are contiguous(basically touching) this makes allocating and deallocating incredibly fast 
- storage for control info and variables
- limited accessibilty -> data can only be accessed in active call
- automatic -> done by the system itself

## heap memory

als known as dynamic memory. This is managed manually.its great for storing large data structures or things we dont know the size of in advance

```cpp
#include <iostream>

int main() {
    // Stack: Local variable 'value' is stored on the stack
    int value = 42;

    // Heap: Allocate memory for a single integer on the heap
    int* ptr = new int;

    // Assign the value to the allocated memory and print it
    *ptr = value;
    std::cout << "Value: " << *ptr << std::endl;

    // Deallocate memory on the heap
    delete ptr;

    return 0;
}
```
`Demonstrating heap memory allocation and usage in C++`
Here is the explanation of the C++ code in the order of execution:

- **Line 3:** The function `main` is called, and a new stack frame is created for it.
    
- **Line 5:** A local variable `value` on the stack frame is assigned the value `42`.
    
- **Line 8:** A pointer variable `ptr` is allocated the dynamically created memory for a single integer on the heap using the `new` keyword. Let's assume the address of this new memory on the heap to be 0x1000. The address of the allocated heap memory (0x1000) is stored in the pointer. `ptr`.
    
- **Line 11:** The integer value `42` is assigned to the memory location pointed to by `ptr` (heap address 0x1000).
    
- **Line 12:** The value stored at the memory location pointed to by `ptr` (`42`) is printed to the console.
    
- **Line 15:** The memory allocated on the heap at address 0x1000 is deallocated using the `delete` keyword. After this line, `ptr` becomes a dangling pointer because it still holds the address 0x1000, but that memory has been deallocated. However, we will not discuss dangling pointers in detail for this essential discussion.
    
- **Line 17:** The main function returns 0, signaling successful execution.
    
- **Line 18:** The main function's stack frame is popped from the stack, and all local variables (`value` and `ptr`) are deallocated.

### key features
- flexibility in size -> heap memory size changes throughout the lifespan of a program
- slower -> it needs to find a suitable frame and handle fragmentation thus making it slower than the stack
- dynamic objects -> heap memory stores objects and data strucures with dynamic lifespans
- persisten -> the memory stays there unless we manually delete it
- manual management -> in c++ we manage this manually thus this can lead to memory leaks or  inefficient code
## stack vs heap
- size -> stack is fixed and heap is dynamic
- speed -> the heap is slower because of the suitable memory frames whereas stack just adjusts a reference
- storage -> the stack is meant for control information heap is meant for big structures with a dynamic lifespan like you make with the new keyword
- data access -> data in stack memory is only accessible during the function call heap memory is always accessible until deleted or the program ends
- memory management -> stack is managed by the system, heap is done manually and thus has risks

### when do i use which
stack is kind of just the default HOWEVER we use heap in these cases:
- when we need to store something that we cant predict the lifespan of
- when we have a large memory requirement or we need to share large data between parts of the program
- when we allocate memory beyond the scope of a single function call

## conclusion 
Understanding the difference between stack and heap memory is crucial for any programmer seeking to write efficient and optimized code. Stack memory best suits temporary storage, local variables, and function arguments. Heap memory is ideal for large data structures and objects with dynamic lifespans. We need to choose the appropriate memory allocation method carefully; we can create programs that are efficient and perform well. Each type of memory comes with its own set of features, and it is essential to use them to ensure performance and resource utilization in our software.

potential more links
[Become a C++ Programmer](https://www.educative.io/path/cpp-for-programmers)
[C++ Fundamentals for Professionals](https://www.educative.io/courses/cpp-fundamentals-for-professionals)