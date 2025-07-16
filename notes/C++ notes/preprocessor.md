prior to compilations your file gets preprocessed -> this strips comments and ensures there are newlines

when the preprocessor is finished it creates a file called the translation unit this then gets compiled 

The entire process of preprocessing, compiling, and linking is called **translation**.
If you’re curious, here is a list of [translation phases](https://en.cppreference.com/w/cpp/language/translation_phases). As of the time of writing, preprocessing encompasses phases 1 through 4, and compilation is phases 5 through 7.
When the preprocessor runs, it scans through the code file (from top to bottom), looking for preprocessor directives. **Preprocessor directives** (often just called _directives_) are instructions that start with a _#_ symbol and end with a newline

The _#define_ directive can be used to create a macro. In C++, a **macro** is a rule that defines how input text is converted into replacement output text.There are two basic types of macros: _object-like macros_, and _function-like macros_. should avoid them

Directives are resolved before compilation, from top to bottom on a file-by-file basis.

