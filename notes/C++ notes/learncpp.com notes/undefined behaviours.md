- using an unitialized variable -> you never know what it will be thus giving random behaviour that is hard to debug -> always init your variable
- a value-returning function without a return statement will create undefined behaviour -> main is the exception it will implicitly return 0

### implementation-defined and unspecified behaviour
your compiler/implementation can decide certain rules try to avoid this
