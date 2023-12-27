# Chapter 2 Fundamentals

This chapter is an introduction to several basic concepts that we will need in order to write a small program.

In this chapter we will cover:
- 2.1 How to compile and link a C program
- 2.2 How to generalise the program
- 2.3 How to add comments
- 2.4 Introduction to variables
- 2.5 How to use _scanf_ to read data into a variable

## 2.1 Writing a Simple Program

### Printing a Pun

Below we have written a program that prints out a bad pun every time it is run.
```c
pun.c

#include <stdio.h>

int main(void)
{
    printf("To C, or not to C: that is the question\n");
    return 0;
}
```

The line below is needed in order to have information about C's standard I/O library.
```c
#include <stdio.h>
```

The programs executable code goes inside _main_ which represents the "main" program. In our case above the only line inside _main_ is a command to display the desired message. _printf_ is a function from the standard I/O library.

The "\n" part tells _printf_ to go to the next line after printing the message.

The return 0; line "returns" the value 0 to the operating system when the program terminates.

### Compiling and Linking

In order to run the above program we need to create a file with the .c extension. Next we need to convert the program into a form so that the machine can execuite it and for a C program there are usually 3 steps involved:

- **Preprocessing:** The program is first given to a **preprocessor** which looks at commands that begin with "#" (known as **directive**) such as #include in the example above. The preprocessor can add things to the program and make modifications.
- **Compiling:** Next the modified program goes to the **compiler** where it is turned into machine instructions.
- **Linking:** Finally a **linker** combines the object code produced by the complier with any additional code needed. This additional code includes library functions like _printf_ that are used in the program.

Fortunantly the compiler will handle all of this for us and we dont have to do these steps. All we have to do in order to complie our code above is:
```
gcc -o pun pun.c
```


## 2.2 The General Form of a Simple Program

A simple C program has the form:
```c
directives

int main(void)
{
    statements
}
```

Even the simplest C program relies on three key language features:
- Directive (editing commands that modify the program prior to compilation)
- Functions (named blocks of executable code of which main is an example)
- Statements (commands to be performed when the program is run)

### Directives

Before a C progam is complied it is first edited by the preprocessor. Commands that are intended for the preprocessor are known as directives. In our pun example above #include is a directive.
```c
#include <stdio.h>
```
This directive states that the information in <stdio.h> should be included in the program before it is complied. C has a number of **headers** like <stdio.h> that can be used in a program.

### Functions

**Functions** are like "procedures" or "subroutines" in other programming languages. They are the building blocks form which programs are constructed. There are two types of functions, one which is written by the programmer and the second which is provided as part of the C implementation. We refer the second one as **library functions**.

Let's look at our pun.c example again:
```c
#include <stdio.h>

int main(void)
{
    printf("To C, or not to C: that is the question\n");
    return 0;
}
```
The word _int_ before _main_ indicates that main returns integer value and the word _void_ inside the braces indicates that _main_ does not take any arguments. The return 0; has two effects, one is that it causes _main_ to terminate (which ends the program) and two it indicates that the _main_ function returns a value of 0. For now we have main return 0 which indicates a normal program termination.
There there is no _return_ statement at the end of _main_ function, the program will still terminate but some compilers might throw an error.


### Statements

A **statment** is a command that will executed when the program is run. Our pun.c has two statements, one is the return statement and the other is known as a **function call**. Asking a function to perform it's assigned taks is know as **calling** the function. In our example we are calling the _printf_ function to display a message on the screen.


## Comments

We use /* to indicate the beginning of a comment and */ to show where the comment ends for a multi line comment.
```c
/* This is a comment */
```
Also in C99 we can write a single line comment with // such as:
```c
// This is a single line comment
```


## 2.4 Variables and Assignment

Not every program is as simple as our example above. Other programs might need to perform a series of calculations before producing an output. We will need a way to store that data temporarily during program execution. We can do this with what is know as a **variables**

### Type

Every variable must have a type which specifies what kind of data that variable will hold. In this section we will only focus on the _int_ and _float_ type. Choosing the correct type is important as it affects how the variable is stored and what kind of operations are performed on it. The type also indicates the smallest and largest value that can be stored in it and it also indicates whether digits after the decimal point are allowed or not.


### Declarations

Variables must be declared before they can be used. To declare a variable we first specify it's type and then give it a name:
```c
int height;
float profit;
```

If for example several veriables have the same type, then their declarations can be combined:
```c
int height, lenght, width, volume;
float profit;
```

### Assignment

A variable can be given a value by means of **assignment** such as:
```c
height = 8;
width = 12;
length = 10;
```
But before a variable can be assigned a value it needs to be declard.

Also when assigning a value to a float it's best to add the letter "f" (for float) to the end of that decimal such as:
```c
profit = 2150.48f;
```

### Printing the Value of a Variable

We can use _printf_ to display the current value of a variable:
```c
int height = 8;

printf("Height: %d\n", height);
```

%d is a placeholder that indicates where the value of _height_ needs to go when printing the output to the screen. Also note that _%d_ only works for _ints_ and if we want to print out _floats_ we have to use _%f_. By default _%f_ displays a number with 6 decimal places after the decimal point. If we want want _%f_ to display n digits after the decimal points we can put .n (where n is a number) between % and f such as:
```c
printf("Profit: %.2f\n", profit);  // This prints 2 digits after the decmial point
```

### Computing the Dimensional Weight of a Box

```c
dweight.c

#include <stdio.h>


int main(void)
{
    int height, length, width, volume, weight;

    height = 8;
    length = 12;
    width = 10;

    volume = height * length * width;
    weight = (volume + 165) / 166;

    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d", weight);

    return 0;
}
```


### Initialisation

Some variables are automatically set to zero when the program is executed but most are not. A variable that has not been given a value or doesn't have a default value is said to be **uninitialised**.

What we can do is we can declare the variable and at the same time initialise it such as:
```c
int height = 8;
```

Also any number of variables can be initialised in the same declaration:
```c
int height = 8, length = 12, width = 10;
```

Note that each variable requires it's own initialiser. In the example below only _width_ has been initialised and the rest remain _uninitialised_.
```c
int height, length, width = 10;
```

## 2.5 Reaching Input

To get input from the user we can use the _scanf_ function from the C library. _scanf_ needs to know what form the input data will be (i.e int or float or another type).

If we want to read and _int_ value we can do:
```c
scanf("%d", &i); // reads and integer and stores it in i
```

The "%d" tells _scanf_ to read an input that represents and integer and "i" is an int variable into which we want scanf to store the input.

In later chapters we will cover what the "&" symbol does.

If we want to read a float, it's will require a slightly different call to _scanf_:
```c
scanf("%f", &x); // reads a float value and stores it in x
```

"%f" only works for variables of type _float_.


### Computing the Dimensional Weight of a Box (Revisted)

The example below is an improved version of the dweight.c example we had above. In the improved version we now allow the user to give us the dimensions of the box with _scanf_. Also note that each _scanf_ is proceeded by call to _printf_. This way the user will know when to enter input and what input to enter.
```c
dweight2.c

include <stdio.h>


#define INCHES_PER_POUND 166

int main(void)
{
    int height, width, length, volume, weight;

    printf("Enter height of box: ");
    scanf("%d", &height);

    printf("Enter length of box: ");
    scanf("%d", &length);

    printf("Enter width of box: ");
    scanf("%d", &width);

    volume = height * width * length;
    weight = (volume + INCHES_PER_POUND -1) / INCHES_PER_POUND;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d", weight);

    return 0;
}
```

## 2.6 Defining Names for Constants

When a program has some constant value(s) it's a good idea to give them a name. In our examples dweight.c and dweight2.c we have the constant 166 whose meaning might not be clear to someone who is later reading the program.

We can use a feature know as **macro definition** to name a constant, in our dweight example we can do:
```c
#define INCHES_PER_POUND 166
```

_#define_ is a preprocessing directive just as _#include_ and therefore does not need a semicolon at the end of the line.

We can then use the **macro definition** as follow:
```c
weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
```

If for example our **macro definition** has operators, the expression should be enclosed in parantheses:
```c
#define RECIPROCAL_OF_PI (1.0f / 3.14159f)
```


### Converting from Fahreneheit to Celsius

The program below prompts the user to enter a temperature in Fahrenheit and then prints the equivalent in Celsius:
```c
celsius.c

#include <stdio.h>


#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main(void)
{
    float fahrenheit, celcius;

    printf("Enter Fahrenheit temperature: ");
    scanf("%f", &fahrenheit);

    celcius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;

    printf("Celcius equivalent: %.1f", celcius);

    return 0;
}
```

A point to note, the reason why we have defined SCALE_FACOTR as (5.0f / 9.0f) and not as (5 / 9) is because C truancates the results when two integers are divided and therefore in our case when 5 is divided by 9 the result would be 0 which isn't what we need.
