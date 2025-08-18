syntax -> grammar
semantic -> logic
Tips:
When adding temporary debug statements, it can be helpful to not indent them. This makes them easier to find for removal later.

general approach: 
1. Find the root cause of the problem (usually the line of code that’s not working). We’ll discuss some strategies on how to do this in the next lesson.
2. Ensure you understand why the issue is occurring.
3. Determine how you’ll fix the issue.
4. Repair the issue causing the problem.
5. Retest to ensure the problem has been fixed.
6. Retest to ensure no new problems have emerged.

methodss to find bugs:
- code inspection -> nice when code is simple
- running it -> 
	1. Figure out how to reproduce the problem
	2. Run the program and gather information to narrow down where the problem is
	3. Repeat the prior step until you find the problem
- breakpoints

tactics:
- commenting out code -> remove code and watch what happens (Don’t forget which functions you’ve commented out so you can uncomment them later!)
- validating code flow -> print function name this way we know what function we are triggering or NOT triggering USE STD::CERR FOR THIS
- printing values -> print one by one this way you can see changes happen
- conditionalizing debug code - >
		use #define debug and #ifdef and #endif to make certain statements not compile
- logger -> this is writing to an external file called a log file (you can use the plog library for this)
```cpp
#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>

int getUserInput()
{
	PLOGD << "getUserInput() called"; // PLOGD is defined by the plog library

	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger

	PLOGD << "main() called"; // Step 3: Output to the log as if you were writing to the console

	int x{ getUserInput() };
	std::cout << "You entered: " << x << '\n';

	return 0;
}
```


negatives:
- statements:
	1. Debug statements clutter your code.
	2. Debug statements clutter the output of your program.
	3. Debug statements require modification of your code to both add and to remove, which can introduce new bugs.
	4. Debug statements must be removed after you’re done with them, which makes them non-reusable.


### using an actual debugger
To set up debugging, press _Ctrl+Shift+P_ and select “C/C++: Add Debug Configuration”, followed by “C/C++: g++ build and debug active file”. This should create and open the `launch.json` configuration file. Change the “stopAtEntry” to true:  
`"stopAtEntry": true,`

Then open _main.cpp_ and start debugging by pressing _F5_ or by pressing _Ctrl+Shift+P_ and selecting “Debug: Start Debugging and Stop on Entry”.

stepping: this a technique where we execute our code step by step manually

on vscode we need to make a debug file in the command pallette and then set steps to true

running and breakpoints:
- run to cursor this will run the program until it hits the expression  highlighted by your cursor you can press continue to continue execution
- breakpoint this tells the debugger to stop running when it hits the breakpoint and then dump everything
- watching a variable when debugging you can hover over a variable to see its current value in vscode you can also see this in the watch window

### Don’t make errors

Well, the best thing is to not make errors in the first place. Here’s a list of things that can help avoid making errors:

- Follow best practices.
- Don’t program when tired or frustrated. Take a break and come back later.
- Understand where the common pitfalls are in a language (all those things we warn you not to do).
- Don’t let your functions get too long.
- Prefer using the standard library to writing your own code, when possible.
- Comment your code liberally.
- Start with simple solutions, then layer in complexity incrementally.
- Avoid clever/non-obvious solutions.
- Optimize for readability and maintainability, not performance.

**Defensive programming** is a practice whereby the programmer tries to anticipate all of the ways the software could be misused, either by end-users, or by other developers (including the programmer themselves) using the code. These misuses can often be detected and then mitigated (e.g. by asking a user who entered bad input to try again).

