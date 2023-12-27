# Chapter 3 Formatted Input/Output

In this chapter we will cover:
- 3.1 Describing _printf_
- 3.2 Covering _scanf_


## 3.1 The _printf_ Function

The _printf_ function is created so that it can display a string also known as **format string** with different values possibly instereted at specific points in the string. The format string can contain ordinary characters and **conversion speficiations** which begin with the "%" character. The conversion speficiation is just a place holder for the actual value that needs to go in it place during printing. The letter that then follows "%" specifies how the value is converted from its internal form (binary) to printed form (characters).

For example the conversion specification "%d" specifies that an _int_ value from binary is converted to a string of decimal digits and "%f" does it for floats.

```c
int i = 10;

printf("i is: %d\n", i);
```

### Conversion Specifications

A conversion specification can have the form " %m.pX " or " %-m.pX " where _m_ and _p_ are integer constants and _X_ is a letter.

Both _m_ and _p_ are optional. If _p_ is left out then the "." that separates _m_ and _p_ will be dropped

In the conversion specification " %10.2f ":
- m is 10
- p is 2
- X is f

The **minimum field width** " m " specifies the minimum number of characters to be printed. If the value that is printed has less than " m " characters, that then means it is right-justified within the field.

For example the specification " %4d " would print "123" as " 123". And putting a minus sign infront of " m " causes left-justification so " %-4d " would print "123" as "123 ".

The most commong conversion specifiers for numbers are:
- d ¬ Displays an integer in decimal form. " p " indicates the minimum number of digits to display. So if we have " %.4d " and our number is "123" which means our number is shorter than the minimum required digits to be displayed it then adds and extra " 0 " at the beginning of our number so it will look like "0123" when it is printed.

- e ¬ Displays a float in exponential form. In this case " p " indicates how many numbers should be printed after the decimal point. The default is 6 digits. However if " p " is 0 the decimal point is not displayed.

- f ¬ Displays a float in "fixed-number" without the exponent. Here " p " has the same meaning as for the e specifier.

- g ¬ Displays a float in either exponent or fixed-number format depending on the numbers size. In this case here " p " has a different meaning which means the minimum number of significant digits to be displayed. 


### Escape Sequences

Escape sequene can be used in strings where it otherwise would cause an error for the compiler. The "\n" we have been using is an escape sequence. Here is a small list (we will see a more comprehensive list later in the chapters):
- Alert (bell)       \a
- Backspace          \b
- New line           \n
- Horizontal tab     \t

Another escape sequence is the ' backslash " ' , which represents the ' " ' character. This is because the ' " ' character represents the beginning and end of a string so it cant appear within the string without causing a prblem. We can do:

```c
printf(" \"Hello, World\" ");

// This will print "Hello, World"
```

Also you cant put a single \ in a string as the complier will assume it is the beginning of a escape sequence, so what you have to do is put two of them \ \ back to back with no space.


## 3.2 The _scanf_ Function

_scanf_ reads an input according to a particular format. Like _printf_, _scanf_ can also contain both ordinary characters and conversion specifications. The conversions allowed in _scanf_ are the same as the ones used in _printf_.

In most cases _scanf_ will only contain the conversion spefication such as:
```c
int i, j;
float x, y;

scanf("%d%d%f%f", &i, &j, &x, &y);
```

Also note that when you call _scanf_ and it reads characters, what happens when it reaches the end is that it "peeks" at the final new-line character without reading it. This new like will be the first character read by the next call of _scanf_.