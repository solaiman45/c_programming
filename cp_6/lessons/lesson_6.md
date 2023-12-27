# Chapter 6 Loops

In this chapter we will cover C's iteration statements which basically allows us to set up loops. A **loop** is a statement which essentially has one job which is reapead a statement over and over agani i.e. the **loop body**.

Every loop has a **controlling expression** so each time the loop is executied i.e. and **iteration** of the loop that controlling expression is checked and if the expression evaluates to true i.e. has a non-zero value then the loop continues to execute.

- 6.1 Covers the _while_ loop
- 6.2 Covers the _do_ loop
- 6.3 Covers the _for_ loop
- 6.4 Covers _break_, _continue_ and _goto_ statments
- 6.5 Cover the _null_ statement

The _while_ statement is used for loops whos controlling expression is tested BEOFRE the loop body is executed.

The _do_ statement is used for loops for loops whos controlling expression is tested AFTER the loop body is executed.

The _for_ statement is usefull for loops that increment or decrement a counting variable.


## 6.1 The _while_ Statement

The _while_ statment is the easiest loop to set up and most fundamental. The _while_ statment has the form:
```c
while (expression) {
    statement;
}

----------------------------------------------------------------------------------

while (i < n) {       // Controlling expression
    i = i * 2;        // loop body
}
```

When a _while_ statement is execuited the controlling expression is evaluated first and if the value is non-zero (i.e true) then the body of the statement is executed and the expression is then evaluated again. This keeps going till the expression statement has a value of zero (i.e false).

The example below uses the _while_ statement to compute the smallest power of 2 that is greater than or equal to 2
```c
i = 1;
while (i < n) {
    i *= 2;
}
```

### Infinite Loops

A _while_ statement won't terminate if the controlling expression is always a non-zero value. Some programmers actually make use of this to purposely create an **infinite loop** by using a non-zero constant as the controlling expression:
```C
while (1) {
    ....
}
```

A _while_ statment in this form will continue forever untill it's body contains a statement that transfers control out of the loop, which can be achieved with _break_, _goto_, _return_ or calls a function that causes the program to terminate.

### Printing a Table of Squares

```C
square.c

#include <stdio.h>


int main(void)
{
    int i, n;

    printf("Enter the number of entries in a table: ");
    scanf("%d", &n);

    i = 1;
    while (i <= n)
    {
        printf("%d\t%d\n", i, i * i);
        i++;
    }

    return 0;
}
```


### Summing a Series of Numbers
```C
sum.c

#include <stdio.h>


int main(void)
{
    int sum = 0, n;

    printf("Enter integers (0 to terminate): ");
    scanf("%d", &n);

    while(n != 0)
    {
        sum += n;
        scanf("%d", &n);
    }

    printf("The sum is: %d\n", sum);

    return 0;
}
```

Notice that the condition n != 0 is tested right after the number is read, which allows to terminate the loop as soon as possible. Also note that there is another call to scanf inside the _while_ statement which is hard to avoid when using a _while_ loop.


## 6.2 The _do_ Statement

The _do_ statement is related to the _while_ statment but the only difference is that with the _do_ statment the body of the statement is executed first and then the controlling expression is tested.

The _do_ statment has the form:
```C
do {
    Statement
} while (expression);
```

So as we said earlier, when the _do_ statement is executed the body of is executed first and then the controlling expression is tested. If the controlling expression is a non-zero value the loop conitnues and therefore the loop body is executed again. The _do_ statement only terminates when the controlling expression has a zero value.

We can write a countdown example as follows:

```C
i = 10;

do {
    printf("T minus %d\n", i);
    i--;
} while (i > 0);
```

As we can see the _do_ statment is very similar to the _while_ statement but the only difference is that the body of the _do_ statement is executed at least once even if the controlling expression is a zero (false) value, whereas the body of the _while_ statement never executes if the controlling expression is a zero value.

### Calculating the Number of Digits in an Integer

```C
numdigits.c

#include <stdio.h>


int main(void)
{
    int digts = 0, n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    do {
        n /= 10;
        digts++;
    } while( n > 0);

    printf("The number has %d digits\n", digts);
    
    return 0;
}
```


## 6.3 The _for_ Statement

The for statement is C's last loop. The _for_ statement is one of the best ways to write many loops. The _for_ statement is ideal for loops that have a "counting" variable but can also be used for other kind of loops.

The _for_ statement has the following form:
```C
for (expr1; expr2; expr3) {
    statment
}

// here is an example

for (int i = 10; i > 0; i--) {
    prtinf("T minus %d and counting \n", i);
}
```

When the _for_ statement is executed the variable i is set to 10, then i is tested to see if it's greater than 0 and if it is the body of the loop the printf message will be printed. Then i is decremented. Then it will start from the beginning again where i will be tested to see if it is greater than 0 and so on.


### Omitting Expressions in a _for_ Statement

The _for_ statement is quite flexible in that we can omit any or all of the expressions.

If the _first_ expression is omitted then no initialisation is performed before the loop is executed:
```C
i = 10;
for (; i > 0; i--) {
    printf("T minus %d and counting\n", i);
}
```
In the example above i has been initialised by a seperate assignment so we can omit the first expression in the _for_ statement. But note that the semi-colon has to still be there.

If we leave out the third expression we have to make sure that the body of the loop takes care that the second expression eventually becomes false. By omitting the third expression we have added i-- in the body of the loop inside the prtinf function.

```C
for (i = 10; i > 0;) {
    printf("T minus %d and counting\n", i--);
}
```

If we omit the first and third expression it's just a _while_ statement but it is clearer if we use the _while_ loop instead of doing this.

If however we omit all three expression then what we get is an infinit loop where the loop will only come to an end if it is stopped somehow in the body with say a _break_ statement:
```C
// infinite loop
for ( ; ; ) {
    ...
}
```


A variable declared by a _for_ statment can't be access outside the body of the loop, for example:
```C
for (int i = 0; i < n; i++) {
    ....
}
```

Once the _for_ statement above is terminated we can no longer access the variable i and that is because it has been declared by the _for_ statement.

If however we want to access that variable outside the _for_ statment and after the _for_ statement has been terminated then we need to declare it outside the _for_ statement:

```C
int i;
for (i = 0; i < n; i++) {
    ....
}
```

### Printing a Table of Squares (Revisted)

```C
square2.c

#include <stdio.h>


int main(void)
{
    int i, n;

    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {

        printf("%d\t%d\n", i, i*i);
    }

    return 0;
}
```


## 6.4 Exiting from a Loop

Currently we have seen that the different loops have an exit point built in them which is when they reach a specific condition the loop terminates. But what if we want to terminate the loop earlier or have some sort of exit condition in multiple places in the loop? We will look at how to do this in the coming sections.

### The _break_ Statement

The _break_ statement can be used to jump out of a _while_, _do_ and _for_ statements.

Let's say we want to write a program that check whether a number n is a prime or not. What we can do is write a _for_ statment that divides n by numbers between 2 and n -1. And as soon as we find a divisor we can break out of the loop and don't need to check the remaining numbers as we found our answer.


Once the _for_ loop has been terminated we can use and _if_ statement to check whether our number n is a prime or not

```C
int i;
int n;
for (i = 2; i < n; i++) {
    if (n % 2 == 0) {
        break;
    }
}

if (i < n) {
    printf("%d is divisable by %d\n", n, i);
} else {
    print("%d is prime\n", n);
}
```

Note that a _break_ statement transfers control out of the inner most statements. So if we have multiple nested _while_, _do_, _for_ or _switch_ statements and a break statement is execuited then it only breaks out from the innter most statment i.e. it escapes only one level of nesting:
```C
while (....) {
    switch (...) {
        ....
        break;
        ....
    }
}
// The break transfers control from the switch statement to the while statement
```


### The _continue_ Statement

The _continue_ statement is slightly different to the _break_ statement in that when the _break_ statement is executed it transfer control just past the end of the loop whereas the _continue_ statement when executed still says within the loop and transfers control to a point just before the end of the loop.

_continue_ can only be used in _while_, _do_ and _for_ statements whereas _break_ can also be used in _switch_ statements.

We can write a program that propts the user for a series of numbers and computes their sum. The loop terminates when 10 non-zero numbers have been read so whenever a 0 is read the _continue_ statement is executed skipping the rest of the body but remaining inside the loop:

```C
int n = 0;
int sum = 0;

while (n < 10) {
    scanf("%d", &n);
    if (n == 0) {
        continue;
    }
    sum += n;
    n++;
    
    // When continue is executed it jumps control to here
    // it skips sum += n and n++
}
```

If we didn't have a _continue_ we could have written the above example as follows:
```C
int n = 0;
int sum = 0;

while (n < 10) {
    scanf("%d", &n);
    if (n != 0) {
        sum += n;
        n++;
    }
}
```


### The _goto_ statement

As we have seen above the _break_ and _continue_ statements are jump statements where one jumps to a point just at the end of a loop and the other jumps to a point end point inside the loop.

Where the _goto_ statement differes is that _goto_ can jump to any statement in a function provided that the statement has a **label**.

A label is just an identifier places at the beginning of a statement:
```C
identifier : statment
```

When transferring control to the statement that follows the label we have to ensure that the statement is within the same function as the _goto_ statement. We can use it as follows:

```C
for (d = 2; d < n; d++) {
    if (n % d == 0) {
        goto done;
    }
}
done:
if (d < n ) {
    ...
} else {
    ...
}
```


### Balancing a Checkbook

```C
checking.c

#include <stdio.h>


int main(void)
{
    int cmd;
    float balance = 0.0f, credit, debit;


    printf("\t*** ACME check-book balancing program ***\n");
    printf("Commands: 0=clear, 1=creidt, 2=debit, 3=balance, 4=exit\n\n");

    for (;;)
    {
        printf("Enter command: ");
        scanf("%d", &cmd);

        switch(cmd) {
            case 0:
            balance = 0.0f;
            break;

            case 1:
            printf("Enter amount of credit: ");
            scanf("%f", &credit);
            balance += credit;
            break;

            case 2:
            printf("Enter amount of debit: ");
            scanf("%f", &debit);
            balance -= debit;
            break;

            case 3:
            printf("Current balance: %.2f\n", balance);
            break;

            case 4:
            return 0;

            default:
            printf("Commands: 0=clear, 1=creidt, 2=debit, 3=balance, 4=exit\n\n");
            break;
        }
    }
}
```


## 6.5 The NULL Statement

