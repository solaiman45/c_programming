# Chapter 9 Functions

This section covers:

- 9.1 How to define and call functions
- 9.2 Function declarations and how they differ from function definition
- 9.3 How arguments are passed to functions
- 9.4 Return statement
- 9.5 Issues relating to program termination
- 9.6 Recursion


## 9.1 Defining and Calling Functions

If we often need to do something, like say compute the average of two double values how would we do this? We know the C library doesn't have an "average" function but what we can do is define our own, such as:
```C
double average(double a, double b)
{
    return (a + b) / 2;
}
```

The word _double_ at the beginning is _average's_ **return type** which is the type of data that the _average_ function returns everyt time it is called. The letters 'a' and 'b' are know as identifiers or function **parameters** and will represent the two numbers that will be supplied when _average_ is called. Parameters must have a type (just like every variable has a type), in our case both 'a' and 'b' have a type **double**.

The body of the average function has a single return statement. The value of (a + b) / 2 will be returned by the function to the statement that called it.

To call a function all you have to do is write the function name followed by a list of **Parameters** that the function takes. In our example above we can call the average function as follows; _average(x, y)_. The arguments that get supplied into the function provie it with information and in the example above average needs to know which two numbers to average.

How calling average(x, y) works is that the function copies the values of x and y into the parameters a and b and then executes the body of the function.

We can call the average function any where we need the return value, for example;
```c
printf("Average: %g\n", average(x, y));
```
In the example above the return value of average becomes a parameter of printf. Also once printf usess the return value of average it discards it as it is not saved anywhere. To save the return value we can capture it in a variable;
```c
avg = average(x, y);
```

Let's have a look at an example of how we can use our average function.

```c
#include <stdio.h>


double average(double a, double b)
{
    return (a + b) / 2;
}


int main(void)
{
    double x, y, z;

    printf("Enter three numbers: ");
    scanf("%lf%lf%lf", &x, &y, &z);

    printf("Average of %g and %g: %g\n", x, y, average(x, y));
    printf("Average of %g and %g: %g\n", x, z, average(x, z));
    printf("Average of %g and %g: %g\n", y, z, average(y, z));

    return 0;
}
```

Note that the definition of _average_ placed before _main_. In the next section we will see why putting _average_ after _main_ causes problems.


It has to be noted that not every function returns a value. For example a function that produces an output does not need to return anything. We can use **void** on any function to indicate that it has no return value.

Let's look at an example where the message "T minus _n_ and counting" is printed where _n_ is supplied when the function is called.

```c
void print_count(int n)
{
    printf("T minus %d and counting\n", n);
}
```

_print_count_ has one parameter n of type int and returns nothing and therefore has _void_ as its return type. Since _print_count_ doesnt return a value, we can't call it like we did with the _average_ function. Instead a call of _print_count_ must appear in a statement by itself:
```c
print_count(i);
```

Let's look at an example where a program calls print_count 10 times in a loop.

```c
#include <stdio.h>


void print_count(int n)
{
    printf("T minus %d and counting\n", n);
}


int main(void)
{
    for (int i = 10; i > 0; i--) {
        print_count(i);
    }

    return 0;
}
```


Some function also have no parameters. Let's look at an example:
```c
void print_pun(void)
{
    printf("To C or not to C: that is the question\n");
}
```

By placing **void** in the parantheses it indicates that _print_pun_ has no arguments. To call a function with no arguments we write the functions name followed by empty parantheses.
```c
print_pun();
```

Let's look at an example:
```c
pun2.c

#include <stdio.h>


void print_pun(void)
{
    printf("To C or not to C: that is the question\n");
}

int main(void)
{
    print_pun();
    return 0;
}
```



### Function Definitions

The general form of a function is as follows:
```
return-type function-name (parameters)
{
    declarations
    statements
}
```

The return type is the type of value that the function returns, below is a list that govern the return type:
- The only restriction on return type is that functions can not return arrays, otherwise no other restriction.
- Specifying that the return type is _void_ indicates that the function doesn't return a value.
- In C89 if the return type is ommitted it is assumed it returns a value of type _int_ but in C99 you CAN NOT leave out the return type.


After the function name comes a list of parameters in the parantheses. Each parameter should speficy it's type and parameters should be separated by commas. If however the function takes in no parameters the word _void_ should be placed inside the parantheses. Each parameter should have it's own type even if the parameters are of the same type.

```c
double average(double a, b)       /*** WRONG ***/
{
    return (a + b) / 2;
}
```

The body of a function can have both declarations and statements, for example:

```c
double average(double a, double b)
{
    double sum;              /* declaration */

    sum = a + b;           /* statement */
    return sum / 2;       /* statement */
}
```

Variables declared inside of a function belog exclusively to that function and can therefore not be examined or modified by other functions. In C89 variable declarations must come first before all statements in the function, however in C99 variable declarations and statements can be mixed as long as the variable is declared before it is used by the first statement.

A function with a return type of **void** can have an empty body. This is useful in program development when we need to create the function but not have the logic in place yet. We can then come back later and finish the body of the function and if we need to we can change the return type too from **void** to any of the other types.
```c
void example_function(void)
{ 
}
```


### Function Calls

To call a function we write the name followed by a list of arguments in parantheses.
```c
average(x, y)
print_count(i)
print_pun()
```

Calling a **void** function must always be followed by a semicolon to turn it into a statement:
```c
print_count(i);
print_pun();
```

A call to a non-**void** function produces a value that can be stored in a variable, tested, printed or used in some other way:

```c
avg = average(x , y);           /* storing return value in a variable */

if (average(x, y) > 0) {        /* return value tested for something */
    printf("Average is positive\n");
}

printf("The average is %g\n", average(x, y));   /* return value printed */
```


Lets now look at how functions can make programs easier to understand. Below we have a program that tests whether a number is prime. Instead of putting the "prime testting" details in **main** we will define a separate function that returns **true** or **false**

```c
prime.c

#include <stdbool.h>
#include <stdio.h>


bool is_prime(int n)
{
    int divisor;

    if (n <= 1) {
        return false;
    }
    for (divisor = 2; divisor * divisor <= n; divisor++) {
        if (n % divisor == 0) {
            return false;
        }
    }

    return true;
}


int main(void)
{   
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    if (is_prime(n)) {
        printf("Prime\n");
    } else {
        printf("Not Prime\n");
    }

    return 0;
}
```

As _is_prime_ is showing a function can have more than one return statement. However we can only execute one of these return statements during a call to the function because as soon as it hits the return statement the function terminates and returns the value to where it was called.



## 9.2 Function Declarations

In the previous section when we created a function we placed it above the point it was called. For example we placed the _average_ function above the _mani_ function. However C doesn't really require the function to be defined before it is called.

Let's say we put the _average_ function after the _main_ function. When the compiler enounters the first call of _average_ inside of _main_ it has no information on _average_:
- It doesnt know how many parameters average takes
- What type the parameters are
- What kind of values _average_ returns

This then produces an error later down the program when the complier encounters the definiton of _average_

The solution to this problem will be to declare a function before calling it. This is know as a **function declaration** and it provides the compiler a glips of the function where the full definiton will appear later. A function declaration looks like a function definition with a semicolon added at the end.
```c
return-type function-name (parameters);
```

Here is an example of how it would look in a program:

```c
#include <stdio.h>

double average(double a, double b);       /* Declaration */

int main(void)
{
    double x, y, z;

    printf("Enter three numbers: ");
    scanf("%lf%lf%lf", &x, &y, &z);

    printf("Average of %g and %g: %g\n", x, y, average(x, y));
    printf("Average of %g and %g: %g\n", x, z, average(x, z));
    printf("Average of %g and %g: %g\n", y, z, average(y, z));

    return 0;
}

double average(double a, double b)      /* Definition */
{
    return (a + b) / 2;
}
```


## 9.3 Arguments

The difference between a _parameter_ and an _argument_ is that _parameters_ appear in the function definiton in that they are dummy names that represent values to be inputted when the function is called. _Arguments_ on the other hand are expressions that appear in the function inside the parantheses when the function is called.

Arguments are **passed by value** which means when a function is called, each argument is evaluated and it's value is assigned to the correspondong parameter. The parameters contain a copy of the argument's value that has been passed into the function. Therefore any changes made to the parameter during execution does affect the arguments value.

### Array Arguments

Arrays can be used and most of the time are used  as arugments as function parameters. When the array is one dimensional the length of the array is usually left unspecified.
```c
int f(int a[])      /* no length speficied */
{
    ...
}
```
There is one problem, how will f know what the lenght of the array is? There is no easy way in C for the function to know the array size so what we have to do is provide the length of the array as a second argument if the function needs it.

Below is an example of a function with a one-dimensional array as its argument. The function _sum_array_ takes an array 'a' of int values and then returns the sum of the elements. As we mentioned above the _sum_array_ function will need to know the length of array 'a' and therefore we will supply it as a second argument. 
```c
int sum_array(int a[], int n)
{
    int sum;
    
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum;
}
```

The prototype for sum_array has the following appearance:
```c
 int sum_array(int a[], int n);
 ```

 If we want to we can also leave out the parameter names:
 ```c
 int sum_array(int [], int);
 ```

 When _sum_array_ is called the first argument will be the name of the array and the second will be its length:

```c
#define LEN 100

iint main(void)
{
    int b[LEN], total;

    total = sum_array(b, LEN);
    ....
}
```

Remember that you don't put brackets after the array name when passing it into a function:
```c
total = sum_array(b[], LEN);    /*** WRONG ***/
```

An important point to note is that a function has no way to check whether we have passed it the correct array length. We can exploit this by passing a smaller array size to a the function than it really is. If we pass in array length 50 instead of the actual 100 then _sum_array_ will only sum the first 50 values the array b.

However if you provide a **larger** number then the actual size then the function will go beyond the actual array size and this can cause undefined behaviour.

Another important point to note is that a function is allowed to change the elements of an array parameter and the change is then reflected in the corresponding argument. The example below is a function that modifies an array by storing zero's into each of its elements:
```c
void store_zeros(int a[], n)
{
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
}
```
The call:
```c
store_zeros(b, 100);
```

The function will store 0 in the first 100 elemtns of array b. Remember ealier in the chapter we said that functions take arguments by value and therefore can not change them, however in the _store_zeros_ the function is modifying the elements of the array arguments. This is not a contradiction and we will see why in chapter 12.3.

If the parameter of a function is a multi-dimensional array then we can leave out the length of the first dimension. If we revist the _sum_array_ function again we now have a two-dimensional array as a parameter what we can do is we can leave out the number of **rows** but we have the specify the number of **columns**.

```c
#define LEN 100;

int sum_array(int a[][LEN], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < LEN; j++) {
            sum += a[i][j];
        }
    }

    return sum;
}
```

Not being able to pass multi-dimensional arrays with an arbitrary number of columns can be frustrating. However there is a work-around by using arrays of points or C99's variable-length arrays can provide an even better solution.


### Variable-Length Array Parameters

C99 has a feature called variable-length arrays (VLAs) that allows the length of an array to be specified with a non-constant expression. Variable-length arrays can also be used as parameters in functions.

If we look back at the _sum_array_ function we had earlier:
```c
int sum_array(int a[], n)
{
    ...
}
```
As it stands there is currently no link between "n" and the length of array "a". Even though the function treats "n" as the length for the array, the actual length of the array could the larger or smaller than "n".

Using a variable-length array parameter we can explicitly state that a's length is n:
```c
int sum_array(int n, int a[n])
{
    ...
}
```
The value of the first parameter "n" specifies the length of the second parameter "a". Notice here that we have switched the order of the parameters. This is important when variable-length array parameters are used.

This way would be incorrect:
```c
int sum_array(int a[n], int n)    /*** WRONG ***/
{
    ...
}
```

Now there are several ways in which we can write the prototype of the _sum_array_ function:
```c
int sum_array(int n, int a[n]);         /* Version 1 */

int sum_array(int n, int a[*]);       /* Version 2a */
```

The reason that in Version 2 we replaced the array length with a '*' is that parameter names are optional in function declarations. This means that if the name of the first parameter in our case "n" is omitted then it wouldn't be possible to state that the length of the array is "n" but the "*" provides a clue that the length of the array is related to parameters that come earlier in the list.

```c
int sum_array(int, int [*]);        /* Version 2b */
```

It turns out that variable-length arrays have limited use cases in single-dimension arrays but are really handy when it comes to multi-dimensional arrays. In one of the previous examples we tried to sum the elements of a two-dimensional array but the function was limited to a fixed number of columns. Therefore we can use a variable-length array parameter to specify any number of columns:
```c
int sum_two_dimensional_array(int n, int m, int a[n][m])
{
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
    }

    return sum;
}
```


### Using _static_ in Array Parameter Declarations

In C99 it is allowed to use the _static_ keyword in the declaration of array parameters. In our example below putting _static_ infront of the number 3 indicates that the length of _a_ is guaranteed to be atleast 3:

```c
int sum_array(in a[static 3], int n)
{
    ...
}
```

However if an array parameter has more than one dimension then _static_ can only be used in the first dimension.


## 94. The _return_ Statement

Any non-void function must use the **return** statement to specify what value it will return, such as return 0; 

More complex expressions are possible too such as return n >= 0 ? n : 0;

If the type of the expression in a _return_ statement doesn't match the return type of the function then the expression of the _return_ statement will be implicitly converted to the return type of the function. For example if a function returns an "int" but the return statement within the function returns a "double" then the return statement will be converted to an "int".

You can use _return_ in a function whose return type is "void" but you have to make sure the return has no expression otherwise you will get a compile error:
```c
return;
```
Let's look at the example below, when a negative value is given the return statement causes the function to return immediately:
```c
void print_int(int i)
{
    if (i < 0) {
        return;
    }
    printf("%d", i);
}
```

If a non-void function reaches the end of it's body, that is it fails to execute a return statement the behaviour of the program becomes undefined if it attempts to use the value returned by the function.


## 9.5 Program Termination

### The _exit_ Function

Using the _return_ statement in _main_ is one way to terminate a program. Another way we could achieve this is to use the _exit_ function which belongs to the <stdlib.h> library.
```c
exit(0);        /* normal termination */
```

C also allowes to pass in EXIT_SUCCESS and EXIT_FAILURE which are macros defined in <stdlib.h>
```c
exit(EXIT_SUCCESS);             /* normal termination */
exit(EXIT_FAILURE);            /* abnormal termination */
```

The main difference between _exit_ and _return_ is that _exit_ causes the program to terminate regardless of which function calls it. The _return_ statement causes program termination only if it called in the _main_ function.


## 9.6 Recursion

A function is **recursive** if it calls itself. For example, the following function computes n! recurisvely using the formula n! = n * (n - 1)!
```c
int fact(n - 1)
{
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}
```

To see how recursion works let's trace the execution of the statement:
```c
i = fact(3);
```

Where is what happens:
- fact(3) finds that 3 is not less than or equal to 1, so it calls
  - fact(2), which finds that 2 is not less than or equal to 1, so it calls
    - fact(1), which finds that 1 is less than or equal to 1 so it returns 1, causing
  - fact(2) to return 2 * 1 = 2, causing
- fact(3) to return 3 * 2 = 6

The "fact" calls that have not been finished pile up untill "fact" is passed 1 in which case the old "fact" calls begin to unwind one by one untill the original call of "fact(3)" returns the answer of 6.

Here is another example of recursion where a function computes x^n, using the formula x^n = x * x^n-1

```c
int power(int x, int n)
{
    if (n == 0) {
        return 1;
    } else {
        return x * power(x, n - 1);
    }
}
```

The call power(5, 3) will execute as follows:
- power(5, 3) finds that 3 is not equal to 0, so it calls
  - power(5, 2), which finds that 2 is not equal to 0, so it calls
    - power(5, 1) which finds that 1 is not equal to 0, so it calls
      - power(5, 0) which finds that 0 is equal to 0 so it returns 1, causing
    - power(5, 1) to return 5 * 1 = 5, causing
  - power(5, 2) to return 5 * 5 = 25, causing
- power(5, 3) to return 5 * 25 = 125

One point to note is that every recurisve function needs some sort of termination condition in order to prevent infinite recursions. In both our example we have a termination condition check. In power(int x, int n) the termination condition checks if the second parameter in our case "n" is equal to "0".


### The Quicksort Algorithm

An algorithm design technique known as **divide-and-conquer** makes use of recursion as it arises naturally. Here a problem is broken down into smaller parts which are then tackled by the same algorithm. The **Quicksort** algorithm is an example that makes use of the divide-and-conquire strategy.

The algorithm goes as follows (for simplicity we assume the array being sorted is indexed from 1 to n):
1. Choose an array element e (the "partitioning element"), then rearrange the array so that elements 1,....,i-1 are less than or equal to e, element i contains e, and elements i + 1,....,n are greater than or equal to e.
2. Sort elements 1,.....,i-1 by using Quicksort recursively.
3. Sort elements i + 1,.....,n by using Quicksort recurisively.

After step 1, the element e is in its proper location. Since the elements to the left of e are all than or equal to it, they'll be in their proper places once they've been sorted in step 2; similar reasnong applies to the elements to the right of e.

Step 1 of the Quicksort algorithm is very critical. There are numerous methods to partition an array, some much better than others. We will use a technique that is easy to understand but not particularly efficient.

Lets look at how the algorithm works:

The algorithm needs two markers _low_ and _high_ which keep track of the positions in the array. When the algo starts _low_ points to the first element and _high_ points to the last element in the array. We then copy the first element which will be our partitioning element to a temporary location elsewhere, leaving an "empty" space in the array.

Next we move _high_ across the array from right to left until it points to an element that's smaller than the partitioning element. We then copy the element into the "empty" space that _low_ points to which then creates a new "empty" space that _high_ points to.

Now we move _low_ from left to right looking for an element that's larger than the partitioning element. When we find one we copy it into the "empty" space _high_ points to.

The process repeats with _low_ and _high_ taking turns until they meet somewhere in the middle of the array. At that time both will point to the "empty" space, all we now need to do is copy the partitioning element inot the hole.


Let's start with an array containing seven elements. _Low_ points to the first element and high to the last one.
```c
 [12, 3, 6, 18, 7, 15, 10]
  ^                    ^
 Low                  High
```

The first element, 12 is the partitioning element. Copy it somewhere else leaves an empty space at the beginning of the array.
```c
[  , 3, 6, 18, 7, 15, 10]           p = 12
  ^                    ^
 Low                  High
```

We now compare the element pointed to by _high_ with 12. Since 10 is smaller than 12, it's on the wrong side of the array so we move it to the "empty" space and shift _low_ to the right.
```c
[10, 3, 6, 18, 7, 15,  ]           p = 12
     ^                ^
    Low              High
```

_low_ points to the number 3, which is less than 12 and therefore doesn't need to be moved. We shift _low_ to the right instead.
```c
[10, 3, 6, 18, 7, 15,  ]           p = 12
        ^             ^
       Low           High
```

Since 6 is also less than 12 we shift _low_ again.
```c
[10, 3, 6, 18, 7, 15,  ]           p = 12
           ^          ^
          Low        High
```

_low_ now points to 18, which is larger than 12 and therefore out of position. We than move 18 to the "empty" space _high_ points to and shift _high_ to the left.
```c
[10, 3, 6,  , 7, 15, 18]           p = 12
           ^      ^
          Low    High
```

_high_ points to 15, which is greater than 12 and thus doesn't need to be moved. We shift _high_ to the left and continue.
```c
[10, 3, 6,  , 7, 15, 18]           p = 12
           ^  ^
         Low High
```

_high_ points to 7, which is less than 12 and therefore out of position. After moving 7 to the "empty" space we shift _low_ to the right.
```c
[10, 3, 6, 7,   , 15, 18]           p = 12
              ^
          Low High
```

_low_ and _high_ are now equal so we move the partitioning element to the "empty" space.
```c
[10, 3, 6, 7, 12, 15, 18]
```

We have now reached our objective in that all the elements to the left of the partitioning element are less than or equal to 12 and all elements to the right are greater than or equal to 12. Now that the array has been partitioned we can use Quicksort recursively to sort the first four elements (10, 3, 5, 7) and the last two (15, 18).

