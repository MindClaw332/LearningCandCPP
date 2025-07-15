“foo” is a meaningless word that is often used as a placeholder name for a function or variable when the name is unimportant to the demonstration of some concept. Such words are called [metasyntactic variables](https://en.wikipedia.org/wiki/Metasyntactic_variable) (though in common language they’re often called “placeholder names” since nobody can remember the term “metasyntactic variable”). Other common metasyntactic variables in C++ include “bar”, “baz”, and 3-letter words that end in “oo”, such as “goo”, “moo”, and “boo”).

For those interested in etymology (how words evolve), [RFC 3092](https://datatracker.ietf.org/doc/html/rfc3092) is an interesting read.

Follow DRY: “Don’t repeat yourself”. If you need to do something more than once, consider how to modify your code to remove as much redundancy as possible. Variables can be used to store the results of calculations that need to be used more than once (so we don’t have to repeat the calculation). Functions can be used to define a sequence of statements we want to execute more than once. And loops (which we’ll cover in a later chapter) can be used to execute a statement more than once.

Like all best practices, DRY is meant to be a guideline, not an absolute. Reader Yariv has [noted](https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/#comment-593257) that DRY can harm overall comprehension when code is broken into pieces that are too small.

