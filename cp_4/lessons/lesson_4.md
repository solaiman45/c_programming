# Chapter 4 Expressions

In this chapter we will cover:
- 4.1 Covering the arithmetic operators and operator precedence
- 4.2 Covering the assignment operators
- 4.3 Covering the increment and decrement operators
- 4.4 How C expressions are evaluated
- 4.5 Introduction to the expression statement


## 4.1 Arithmetic Operators

The arithmetic operators perform:
- Addition
- Subtraction
- Multiplication
- Division

```
---------------------------------------------------------
[     Unary       ] | [          Binary                 ]
---------------------------------------------------------
|                   |[  Additive  ] |[  Multiplicative  ]
|                   |---------------|-------------------|
|  + unary plus     | + addition    |  * multiplication |
|  - unary minus    | - subtraction |  / division       |
|                   |               |  % reminder       |
---------------------------------------------------------
```

The additive and multiplicative operators are said to be **binary** because they need 2 operands. The **unary** operators only need one operand:

```c
i = +1;          // + used as unary operator
j = -i;         //  - used as unary operator
```

The unary " + " operator doesn't really do anything except that it shows that the numeric constant is positive.

From the table above except of " % " the other ones allow either integer or floats but mixing is also possible. When mixing for example an int and float the result always has type float. For example " 9 - 2.5f " has the value of 11.5. Another example "6.7f / 2 has the value of 3.35.

However we have to use " / " and " % " with special care:


- The results of " /" can be surprising sometimes because when the two operands are integers the " / " **truncates** the result by dropping the fractional part. Thus the value of " 1 / 2 " is " 0 " and not " 0.5 ".

- The " % " operator requires that both operands are integers otherwise the program wont compile.

- Using a zero as the right operand of their " / " or " % " has undefined behaviour.

### Operator Precedence and Associativity

C uses **operator precedence** that can solve ceretin issues such as if we have the following like, " i + j * K ". Does this mean first add i and j and then times by k or does it mean times j and k and then add i.

One way to solve this issue is to use parantheses such as (i + j) * k or in the other case i + (j * k).

But if we don't want to use parantheses that's where **operator precedence** comes in:
```
Highest:   +   -   (unary)
           *   \   %
Lowest:    +   -   (binary)
```

Operators listed on the same line such as (+ and -) have the same precedence. We can use parantheses around subexpressions starting with the high-precedence operators and working down to low-precedence to see how the compiler would interpret it:
```
i + j * k      is equivalent to  i + (j * k)
-i * -j        is equivalent to (-i) * (-j)
+i + j / k     is equivalent to (-i) + (j / k)
```


### Computing a UPC Check Digit

```c
upc.c

# include <stdio.h>


int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;

    printf("Enter the first (single) digit: ");
    scanf("%1d", &d);

    printf("Enter first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

    printf("Enter second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
}
```


## 4.2 Assignment Operators

Once the value of an expression has been computed we need a way to store it in a variable. This is where C's " = " (**simple assignment**) operator is used.

### Simple Assignment

```c
i = 5;              // i is now 5    
j = i;              // j is now 5
k = 10 * i + j;     // K is now 55
```

If we have " v = e " but they don't have the same type then the value of e is converted to the type of v when the assignment takes place:
```c
int i;
float f;

i = 72.99f      // i is now 72
j = 136        //  j is now 136.0
```
We will need to know this for the later topic on conversion.


### Lvalues

Most C operators allow their operands to be variables, constants or expressions containing other operators. The assignment operator however requires an **lvalue** as its left operand.

An lvalue represents an object stored in computer memory not a constant or the result of a computation. This means that variables are lvalues but expressions such as 10 or 2 * u are not.

Currently variables are the only lvalues we know about but in later chapters we will come across other lvalues.

Since the assignment operator requires an lvalue as its left operand, it's illegal to put any other kind of expression on the left side of an assignement expression. The compiler will detect this and output an error.

```c
12 = i;         // WRONG
i + j = 0;     //  WRONG
-i = j;       //   WRONG
```

### Compound Assignment

Assignments that use the old value of a variable to compute the new value are commong in C:
```c
i = i + 2;
```

C allows us to shorten this by using the **compound assignment** operators:
```c
i += 2;     // same as i = i + 2;
```

All the compound assignment operators are:
```c
 v += e
 v -= e
 v *= e
 v /= e
 v %= e
```


## 4.3 Increment and Decrement Operators

Two of the most common operatios on a variable is to "increment" i.e add 1 or "decrement" i.e subtract 1.

C allows us to shorten the increments and decrements by using " ++ " for **increment** and " -- " for **decrement**.

The increment and decrement operators can be tricky to use. This is because " ++ " and " -- " can be used as **prefix** operators ( ++i and --i ) or **postfix** operators ( i++ and i-- ). The correctness of a program may rely on picking the proper version.

Another complication of increment and decrement is that they have side effects in that they modify the values of their operands. Evaluating the expression " ++i " (a "pre-increment") yieds i + 1 and as a side effect increments i:

```c
i = 1
printf("i is %d\n", ++i);           // prints i is 2
printf("i si %d\n", i);             // prints i is 2
```

On the other hand evaluating the expression " i++ " (a "post-increment") produces the result i, but causes i to be incremented afterwards:

```c
i = 1;
printf("i is %d\n", i++)           // prints i is 1
printf("i is %d\n", i++)           // printfs i is 2
```

As the example shows the " ++i " means "increment i immediately" while " i++ " meanse "use the old version of i for now but increment i later". Also the " -- " operator is the same.


## 4.4 Expression Evaluation

```
--------------------------------------------------------------------------------
| Precedence   |   Name               | Symbol(s)           | Associativity    |
--------------------------------------------------------------------------------
|    1         | increment (postfix)  | ++                  | left             |
|              | decrement (postfix)  | --                  |                  |
--------------------------------------------------------------------------------
|    2         | increment (prefix)   | ++                  | right            |
|              | decrement (prefix)   | --                  |                  |
|              | unary plus           | +                   |                  |
|              | unary minus          | -                   |                  |
--------------------------------------------------------------------------------
|   3          | multiplicative       | * / %               | left             |
--------------------------------------------------------------------------------
|   4          | additive             | + -                 | left             |
--------------------------------------------------------------------------------
|   5          | assignment           | = *= /= += -=       | right            |
--------------------------------------------------------------------------------
```

The table above shows a list of operators we have seen so far. The first column shows the precedence of each operator relative to the other operators in the table (the highest precedence is 1; the lowest is 5).


