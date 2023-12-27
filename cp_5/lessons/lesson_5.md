# Chapter 5 Selection Statements

C has just a few statements an so far we have only seen the _return_ statement and the expression statement. The rest of the statements fall into three categories:
- **Selection statement**: THe _if_ and _switch_ statements allow the program to choose a particular path from a selection of alternatives
- **Iteration statement**: The _while_, _do_ and _for_ statements support iteration (looping)
- **Jump statements**: The _break_, _continue_ and _goto_ statements cause an unconditional jump to some other place in the program

The other statements in C are the compound statemetn which groups several statements into a single statement and the _null_ statement which performs no action.

In this chapter we will cover the selection statements and the compound statement.

In this chapter we will cover:
- 5.1 How logical expressions are built from the relational operators
- 5.2 Cover the _if_ statement and compound statement
- 5.3 Describes the _switch_ statement

## 5.1 Logical Expressions

In C statments such as the _if_ statment test the value of an expression to see whether it is "true" or "false". For example an _if_ statement might test the expression i < j.

In many programming languages an expression such as i < j would yield a special "Boolean" or "logical" type which would have two values true or false. However in C a comparison such as i < j yields and integer, either 0 (false) or 1 (true).

### Relational Operators

```
-----------------------------------------
| Symbol    |  Meaning                  |
-----------------------------------------
|   <       |  Less than                |
|   >       |  Greater than             |
|   <=      | less than or equal to     |
|   >=      | Greater than or equal to  |
-----------------------------------------
```

The **relational operators** produce 0 (false) or 1 (true) in an expression. The relational operators can be used to compare integers or float numbers with operands of mixed type also allowed such as 1 < 2.5 has the value 1.

The precedence of relational operators is lower than that of the arithmetic operators; i + j < k - 1 means (i + j) < (k - 1).

Relational operators are left associative which means the expression i < j < k is equivalent to (i < j) < k. It does not test whether j lies between i and k, if we wanted to do that then we need to do i < j && j < k.


### Equality Operators

```
----------------------------
| Symbol   |  Meaning      |
----------------------------
|  ==      |  equal to     |
|  !=      |  not equal to |
----------------------------  
```

Like the relational operators the quality operators also produce either 0 (false) or 1 (true) and they are also left associative but have lower precedence than relational operators, so therefore the expression i < j == j < k is equivalent to ( i < j ) == ( j < k ). which is true if i < j and j < k are either both true or both false. 


### Logical Operators

More complex logical expressions can be built with **logical operators** " and ", " or " and " not ". The ! operators is unary while && and || are binary.

```
----------------------------------
| Symbol    |  Meaning           |
----------------------------------
|   !       |  logical negation  |
|   &&      |  logical and       |
|   ||      |  logical or        |
----------------------------------
```

The logical operators also produce 0 (false) or 1 (true). The logical operators treat any nonzero operand as true and any zero operand as false.

The logical operators behave as follows:
- !expr has the value 1 if expr has the value 0  (think of it has light not on)
- expr1 && expr2 has the value 1 if the values of expr1 and expr2 are both non-zero
- expr1 || expr2 has the value 1 if either expr1 or expr2 (or both) has a non-zero value

Also a point to note is that both && and || perform a "short-circuit" evaluation.

The precedence of && and || is lower than that of the relational and equality operators.



## 5.2 The _if_ Statement

The _if_ statement lets the program choose between two paths by evaluating an expression. The _if_ statement has the following form:
```c
if (expression) {
    statement
}
```

When an _if_ statement is executed the expression is evaluated to see if it is nonzero which is true in C and if that is the case then the statment inside the _if_ statement is executed.

An example would look like:
```c
if (line_num == MAX_LINES) {
    line_num = 0;
}
```

A lot of times the expression in an _if_ statement test whether a value falls between a range 0f values, which can be done as follows:
```c
if (0 <= i && i < n) {
    ....
}
```

And to test the opposite where we want to see if i is outside the range we can do:
```c
if (i < 0 || i >= n) {
    ...
}
```

### Compound Statements

Notice in our _if_ statement template that "statement" is singular not plural:
```c
if (expression) {
    statement;
}
```

But what if we want the _if_ statement to control two or more statements? That's where the **Compound statement** comes in. A compound statement has the form { statments }, here is an example:
```c
if (line_num == MAX_LINES) {
    line_num = 0;
    page_num++;
}
```


### The _else_ Clause

An _if_ statement may have an _else_ clause:
```c
if (expression) {
    statement
} else {
    statement
}
```

An example would look like:
```c
if (i > j) {
    max = i;
} else {
    max = j;
}
```

There is no restriction on what statements go inside and _if_ statement. It is also not uncommon to have _if_ statements nested inside other _if_ statements:
```c
if (i > j) {
    if (i > k) {
        max = i;
    } else {
        max = k;
    }
} else {
    if (j > k) {
        max = j;
    } else {
        max = k;
    }
}
```


### Cascaded _if_ Statements

If we need to test a series of conditions where we stop as soon as we reach one of them to be true. Then this is where a "casdaded" if statment comes in. Here we can use the "else if" statment with our if and else statments:
```c
if (expression) {
    statment
} else if (expression) {
    statement
} else if (expression) {
    statement
} else {
    statement
}
```

We can have as many else if statments as we need.

### Calculating a Broker's Commission

```c
broker.c

#include <stdio.h>


int main(void)
{
    float value, commission;

    printf("Enter value of trade: ");
    scanf("%f", &value);

    if (value < 2500.00f)
    {
        commission = 30.00f + 0.017f * value;
    }
    else if (value < 6250.00f)
    {
        commission = 56.00f + 0.0066f * value;
    }
    else if (value < 20000.00f)
    {
        commission = 76.00f + 0.0034f * value;
    }
    else if (value < 50000.00f)
    {
        commission = 100.00f + 0.0022f * value;
    }
    else if (value < 500000.00f)
    {
        commission = 155.00f + 0.0011f * value;
    } else {
        commission = 255.00f + 0.0009f * value;
    }

    if (commission < 39.00f)
    {
        commission = 39.00f;
    }

    printf("Commission: %.2f\n", commission);
    
    return 0;
}
```


### The "Dangling _else_ Problem

When _if_ statments are nested we've got to wathc out for the notorious "dangling else" problem. Lets look at the following example:

```C
if (y != 0)
    if (x != 0)
        result = x / y;
else
    printf("Error: y is equal to 0\n");
```

The question is to which _if_ statement does the _else_ clause belong to? If we look at the indentation we would assume it belongs to the first _if_ statement so the outer one. However C follows the rule that an _else_ clause belongs to the nearest _if_ statement that has not been pair with an _else_ clause. Therefore our _else_ clause above will belong to the second _if_ statment.

One we can avoid this is by useing { } to encapsulate our innter _if_.

```c
if (y != 0) {
    if (x != 0) {
        result = x / y;
    }
} else {
    printf("Error: y is equal to 0\n");
}
```

### Boolean values in C89

In C89 the C language lacked a proper Boolean type which is what programmers can use to store _true_ or _false_ in a variable. However one way programmers have worked around this in C89 is to declare an _int_ variable and then assign it either 0 or 1:

```c
int flag;
flag = 0;
....
flag = 1;
```

This is good but doesn't help with code readability and it is not clear that flag is a boolean and that 0 means false and 1 means true.

Therefore programmers define macros with names such as TRUE and FALSE:
```c
#define TRUE 1
#define FALSE 0
```

Now we can do:
```c
flag = FALSE;
....
flag = TRUE;
// and to test whether flag is true we can do

if (flag == TRUE) {
    ...
}

// Or just (shortned verion, meaing if true)
if (flag) {
    ....
}

// to test whether a flag is false we can do
if (flag == FALSE) {
    ....
}

// or just (shortened version, meaning if NOT, the '!' means NOT)
if (!flag) {
    ...
}
```

We can take this even one step further:
```C
#define BOOL int

// BOOL can take the place of int when declaring Boolean variables

BOOL flag;
```


### Boolean Values in C99

In C99 the Boolean type has been aded which has the _Bool type. We can declare a Boolean variable by writing:
```C
_Bool flag;
```

Also in order to use the _Bool type in C99 you will need to add the header type #include <stdbool.h> when you have done that then you can do:
```c
#include <stdbool.h>

bool flag;    // same as _Bool flag;
```

The header file also supplies macors named "true" and "false" which stand for 1 and 0 making it possible to write:
```C
flag = false;
....
flag = true;
```


## 5.3 The _switch_ Statement

Sometimes we need to compare an expression against a series of values to see which one is true. In the previouse section we saw we can get it done with a cascading _if_ statment.

However an alternative to the cascading _if_ statement is the _switch_ statment.

Cascading if statment version:
```c
if (grade == 4){
    printf("Excellent");
} else if (grade == 3) {
    printf("Good");
} else if (grade == 2) {
    printf("Average");
} else if (grade == 1) {
    printf("Poor");
} else if (grade == 0) {
    printf("Failing");
} else {
    printf("Illegal grade");
}
```

The same now but with the _swithc_ statement version:
```C
switch (grade) {
    case 4: printf("Excellent");
            break;
    case 3: printf("Good");
            break;
    case 2: printf("Average");
            break;
    case 1: printf("Poor");
            break;
    case 0: printf("Failing");
            break;
    default: printf("Illegal grade");
            break;
}
```

When this statement is executed the value of " grade " is tested against 4, 3, 2, 1 and 0. If however the value of "grade" doesn't match any of the choices listed the "default" case applies.

Switch statment are easier to read than cascading _if_ statements and they are also much faster than the cascading if.


### Printing a Date in Legal Form

```c
date.c

#include <stdio.h>


int main(void)
{
    int day, month, year;

    printf("Enter date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Dated this %d", day);
    switch (day) {
        case 1: case 21: case 31:
        printf("st ");
        break;
        
        case 2: case 22:
        printf("nd ");
        break;

        case 3: case 23:
        printf("rd ");
        break;
        
        default: 
        printf("th ");
        break;
    }

    printf("day of ");
    switch(month){
        case 1: printf("January "); break;
        case 2: printf("February "); break;
        case 3: printf("March "); break;
        case 4: printf("April "); break;
        case 5: printf("May "); break;
        case 6: printf("June "); break;
        case 7: printf("July "); break;
        case 8: printf("August "); break;
        case 9: printf("September "); break;
        case 10: printf("October "); break;
        case 11: printf("November "); break;
        case 12: printf("December "); break;
    }

    printf("20%.2d", year);

    return 0;
}
```