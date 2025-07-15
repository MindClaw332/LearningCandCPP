a literal is a value directly inserted into the source code

types of arity:
- unary a sign only used for one operand : -5
- binary: works on two operands: 4+5
- ternary: three operands conditional operator
- nullary: the throw operator
these can be chained for example 2* 4 - 5

In general programming, an **expression** is a non-empty sequence of literals, variables, operators, and function calls that calculates a value. The process of executing an expression is called **evaluation**, and the resulting value produced is called the **result** of the expression (also sometimes called the **return value**).
In C++, the result of an expression is one of the following:

- A value (most commonly)
- An object or a function. We discuss expressions that return objects in lesson [12.2 -- Value categories (lvalues and rvalues)](https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/).
- Nothing. These are the result of non-value returning function calls (covered in lesson [2.3 -- Void functions (non-value returning functions)](https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/)) that are called only for their side effects
```cpp
2               // 2 is a literal that evaluates to value 2
2 + 3           // 2 + 3 uses operator+ to evaluate to value 5
x = 4 + 5       // 4 + 5 evaluates to value 9, which is then assigned to variable x
```
