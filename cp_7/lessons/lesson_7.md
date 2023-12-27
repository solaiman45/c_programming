# Chapter 7 Basic Types

So far we have see two of C's **basic** (built-in) **types**: int and float. We have also seen _Bool which is a basic type in C99. In this chapter we will cover the remaining types and the issues types have.

In this chapter we will cover:
- 7.1 Introduces the full rage of integer types
- 7.2 Introduces the double and long double types
- 7.3 Covers the Char type
- 7.4 Covers the topic of converting one type to another type
- 7.5 Show how to use typedef to define new types
- 7.6 Describes the sizeof operator


## 7.1 Integer Types

Integer types are divided into two groups
- signed
- unsigned

The _int_ type is usually 32 bits. If we need to store numbers that are too large to be stored in an _int_, C provides us the _long_ integers. However in other cases if we want to store a smaller number and conserve memory space we can use what is called a _short_ integer.

The following six combinations produce different types:
- short int
- unsigned short int
- int
- unsigned int
- long int
- unsigned long int

Also the combination "signed int" is the same as "int" so we don't specific the "signed" part.

We can also shorten some of the type names by dropping the "int" part so instead of calling it "short int" we can just call it "short" or instead of calling it "long int" we can just call it "long". This convention is widely used.

The table below shows the range of values each type covers:
```C
32-bit machine
------------------------------------------------------------------------------
|        Type         |   Smallest Value           |   Largest Value         |
------------------------------------------------------------------------------
| short int           |  -32,768                   |   32,768                |
| unsigned short int  |   0                        |   65,535                |
| int                 |  -2,147,483,648            |   2,147,483,648         |
| unsigned int        |   0                        |   4,294,967,295         |
| long int            |  -2,147,483,648            |   2,147,483,648         |
| unsigned long int   |   0                        |   4,294,967,295         |
------------------------------------------------------------------------------
```

### Summing a Series of Numbers (Revisited)

```C
sum2.c

#include <stdio.h>


int main(void)
{
    long n, sum = 0;

    printf("This program sums a series of integers\n");
    printf("Enter integers (0 to terminate): ");
    
    scanf("%ld", &n);

    while (n != 0)
    {
        sum += n;
        scanf("%ld", &n);
    }

    printf("The sum is: %ld\n", sum);

    return 0;
}
```


## 7.2 Floating Types

If we don't want to store whole numbers and need to store numbers with digits after the decimal point what we can do is use the **floating types**:
```c

float                   Single-precision floating-point
double                  Double-precision floating-point
long double             Extended-precision floating-point
```


## 7.3 Character Types

The last basic type that is left is the _chart_ type.

A variable of type _char_ can be assigned any single character:
```C
char ch;

ch = 'a';
ch = 'A';
ch = '0';
ch = ' ';

// character constants are enclosed in single quotes and not double.
```

### Operations on Characters

Working with characters is easy in C as it treats it to be small integers. Therefore the character 'a' has the value of 97, the character 'A' has the value of 65 and so on.

When a character appears in a computation, C simply uses its integer value. Lets look at the following example which assumes the ASCII character set:

```C
char ch;
int i;

i = 'a';                // i is now 97
ch = 65;                // ch is now 'A'
ch = ch + 1;            // ch is now 'B'
ch++;                   // ch is now 'C'  
```

Characters can be compared just as numbers can. The following example checks whether ch contains a lower-case letter and if so converts it into a upper case:

```C
if ('a' <= ch && ch <= 'z') {
    ch = ch - 'a' + 'A';
}
```

Since characters have the same properties as number has its own advantages, this is because if we use a _for_ statement where its control variable steps through all the upper case letters in the alphabet:
```C
for (ch = 'A'; ch <= 'Z'; ch++) {
    ....
}
```


### Reading and Writing Characters using _scanf_ and _printf_

The %c conversion specification allows _scanf_ and _printf_ to read and write single characters:

```C
char ch;
scanf("%c", &ch);           // Reads a single character
printf("%c", ch);           // Write a single character
```

You should not that _scanf_ does NOT skip white-space characters before reading a character. So if the next unread character is a space, then the variable ch in the example above will contain a space after after _scanf_ returns.

To make _scanf_ skip white space before reading a character put a space in its format string:
```C
scanf(" %c", &ch);         // Skips white-space and then reads ch
```

Since _scanf_ doesn't normally skip white space it becomes easy to detect the end of an input line: check to see if the character just read is the new-line character. The example below will read and ignore all remaining characters in the current input line:
```C
do {
    scanf("%c", &ch);
} while (ch != '\n');
```

So when _scanf_ is called next time, it will read the first character on the next input line.


### Reading and Writing Characters using _getchar_ and _putchar_

We can use the _getchar_ and _putchar_ functions to read or write a single character instead of using _scanf_ and _printf_

To write a single character we can do:
```C
putchar(c);
```

Each time we call _getchar_ it reads one character and returns it. If we want to save the character we must store it in a variable:
```C
ch = getchar();                 // Reads a character and stores it in ch
```

We have to note that _getchar_ returns and _int_ value and not a _char_ value, we will discuss the reasoning behind this in later chapters.

Using _getchar_ and _putchar_ over _scanf_ and _printf_ saves time when running the program. _getchar_ and _putchar_ are faster to execute.

_getchar_ has an advantage over _scanf_ in that it returns the character it reads and therefore lends itself to various C idioms such as loops to search for a character or to skip over all occurances of a character.

Let look at an example where we use a _scanf_ loop to skip the rest of the input line:

```C
do {
    scnaf("%c", &ch);
} while (ch != '\n');
```

Rewriting this loop using _getchar_ gives us:

```C
do {
    ch = getchar();
} while (ch != '\n');
```

We can condense the loop if we move the call of _getchar_ into the controlling expression:

```C
while (ch = getchar() != '\n') {
    ...
}
```

We can condense it even further as we don't really need the ch variable as we can just compare the return value of _getchar_:

```C
while (getchar() != '\n') {
    ...
}
```

We can also use _getchar_ to skip and idefinite number of white-space:
```C
while ((ch = getchar()) == ' ') {
    ...
}
```

When the loop terminates ch will have the first non-blank character that _getchar_ found.

### Determining the Length of a Message

```C
length.c

#include <stdio.h>


int main(void)
{
    int length = 0;

    printf("Enter a message: ");

    while(getchar() != '\n')
    {
        length++;
    }

    printf("Your message was %d character(s) long.\n", length);

    return 0;
}
```

## 7.4 Type Conversion

TODO ....


## 7.5 Type Definitions

If you recall in chapter 5 we used the #define directive to create a macro that we could use as a Boolean type.
```C
#define BOOL int
```
However there is a better way to set up a Boolean type with a feature known as **type definition*:
```C
typedef int Bool;
```

Using _typedef_ to define _Bool_ causes the complier to add _Bool_ to the list of type names that it recognises. _Bool_ can now be used in the same way as the built-in type names:
- in variable declarations
- cast expressions

For example we can now use _Bool_ to declare variables:
```C
Bool flag;      // same as int flag
```

## 7.6 The _sizeof_ Operator

The _sizeof_ operator allows a program to determine how much memory is required to store values of a particular type. It tells use the number of bytes required to store a value beloning to _type-name_:
```C
sizeof(type-name);
```
- 8 bits = 1 byte
- 32 bits = 4 byte (8 * 4)