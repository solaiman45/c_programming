# Chatper 8 Arrays

So far we have seen variables that hold a single value but C also supports **aggregate** variables which essentially can store multiple values.

In this chapter we will cover:
- 8.1 How to declare and use one-dimensional arrays
- 8.2 How to declare and use multi-dimensional arrays
- 8.3 Covers C99's variable length arrays

## 8.1 One-Dimensional Arrays

An **array** is a data structure which contains a number of value all of which have the same type. The values inside the array are known as **elements** and can be individually selected by their position inside the array.

The simples array is a one dimensional array where the values are arranged one after the other in a single row.

To declare an array we need to specify the type the array's element will be and the number of elements. So to declare an array _a_ with type int and 10 elements we would do:
```C
int a[10];
```

The elements of an array can be of any type and the length of the array can be specified with any constant expression. Since sometimes the size of the array can change as the program changes we can use a macro to define the length of the array:
```C
#define N 10

int a[N];
```


### Array Subscripting

To access any element inside the array what we have to do is write the array name follow by an integer value inside square brackets. This is know as **subscripting** or **indexing** the array. Array elements are numbered starting from 0. So if we have an array of length n then the elements are indexed from 0 to n-1 such as a[0], a[1], a[2] ....

Expressions of the form a[i] are lvalues so they can be used in the same way as ordinary variables:
```C
a[0] = 1;

printf("%d\n", a[5]);

++a[i];
```

Arrays and _for_ loops go together. A for loop can be used to access each element of an array and perform some sort of operation on it. Here is an example of an array a of length N:

```C
for (int i = 0; i < N; i++) {
    a[i] = 0;                          // clears a
}
```

```C
for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);                // reads data into a
}
// notice we use the & symbol to read data into an array just like any ordinary variable.
```

```C
for (int i = 0; i < N; i++) {
    sum += a[i];                       // sums the elements of a
}
```

An array subscript may be any integer expression:
```C
a[i + j * 10] = 0;
```

The expression can even have a side effect:
```C
i = 0;
while (i < N) {
    a[i++] = 0;
}
```

Let's trace the code. After i is set to 0 the _while_ statement checks whetehr i is less than N. If it is then 0 is assigned to a[0], i is incremented and the loop repeats.

Note that a[++i] wouldn't be correct because 0 wouldn't be assigned to a[0] during the first loop iteration.


### Reversing a Series of Numbers

```C
reverse.c

#include <stdio.h>

#define ARRAY_SIZE 10


int main(void)
{
    int array[ARRAY_SIZE];

    printf("Enter %d numbers: ", ARRAY_SIZE);
    
    for(int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = ARRAY_SIZE - 1; i >= 0; i--)
    {
        printf(" %d", array[i]);
    }
    printf("\n");

    return 0;
}
```

### Array Initialisation

Arrays like any other variable can be given an initial value at the time it is declared. However it is a little bit more complicated so we will cover some of it now and others in later chapters.

The most common form of **array initialiser** is a list of constant expressions enclosed in braces and separated by commas:
```C
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

If the initialiser is shorter than the array the remaining elements are given the value 0:
```C
in a[10] = {1, 2, 3, 4, 5, 6};
// value of a is {1, 2, 3, 4, 5, 6, 0, 0, 0, 0}
```

We can use this feature to set all elements of an array to 0:
```C
int a[10] = {0};
// value of a is {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
```

Also if an initialiser is present then the length of the array can be omitted. The complier will use the length of the initialiser to determine the length of the array:
```C
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

### Designated Initialisers

What if we have large array with say 200 elements and we want for example initialise element 2 to be 29, element 9 to be 7 and element 14 to be 48 and have the rest of the elements to be just zero. We can get this one with C99's **designdated initialisers**:
```C
int a[15] = {[2] = 29, [9] = 7, [14] = 48};
``` 

Also the oders how the elements are listed in the initialiser doesn't really matter we can even do:
```C
int a[15] = {[9] = 7, [2] = 29, [14] = 48};
```

### Checking a Number for Repeated Digits

```C
repdigit.c

int main(void)
{
    int digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;

        if (digit_seen[digit]) {
            break;
        }

        digit_seen[digit] = true;
        n /= 10;
    }

    if (n > 0) {
        printf("Repeated digit\n");
    } else {
        printf("No repeated digits\n");
    }

    return 0;
}
```

### Using the _sizeof_ Operator with Arrays

The _sizeof_ operator can determine the size of an array in bytes. If _a_ is an array of 10 integers then _sizeof(a) is typically 40 if each integer is 4 bytes.

We can also use _sizeof_ to meaasure the size of an array element such as what is the size of a[0] (the element at index 0)?

If we divide the array size by the element size gives us the length of the array:
```C
sizeof(a) / sizeof(a[0]);
```

### Computing Interest

```C
interest.c

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100

int main(void)
{
    int low_rate, num_years;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);

    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (int i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (int year = 1; year <= num_years; year++) {
        printf("%3d    ", year);
        for (int i = 0; i < NUM_RATES; i++) {
            value[i] += (low_rate + i) / 100.0 * value[i];
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }
    return 0;
}
```


## 8.2 Multi-dimensional arrays

An array can have multiple dimensions. The example below creates a two-dimensional arry:

```C
int m[5][9];
```

The array has 5 rows and 9 columns. Both rows and columns are indexed from 0.

If we want to access the element in row i and column j we have to write it as:
```C
m[i][j];
```

Nested _for_ loops are great for multi-dimensional arrays. If for example we want to create an identity matrix where a 1 is on the main diagonal i.e. where the row and column index are the same and 0's everywhere else.

For this we will need to visit each element in the array in some systematic fashion. A nested _for_ loop comes in handy as one steps through every row index and one that steps through each column index:
```c
#define N 10

double a[N][N];

for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
        if (row == col) {
            a[row][col] == 1.0;
        } else {
            a[row][col] = 0.0;
        }
    }
}

```

### Initialising a Multi-dimensional Array

```C
int m[2][3] = {
    {1, 5, 9},
    {4, 3, 1},
    {7, 2, 2}
};
```

If the initialiser isn't large enough to cover all the elements in the array then the remaining elements will be given the value of 0.

```C
deal.c

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUM_SUITS 4
#define NUM_RANK 13

int main(void)
{
    bool in_hand[NUM_SUITS][NUM_RANK] = {false};

    int num_cards, suit, rank;

    const char suit_code[] = {'C', 'D', 'H', 'S'};
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand: ");

    while(num_cards > 0) {
        suit = rand() % NUM_SUITS;              // Picks a random suit
        rank = rand() % NUM_RANK;               // Pick a random rank

        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;

            printf(" %c%c", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");

    return 0;
}
```