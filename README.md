# 0x1B. C - Sorting algorithms & Big O

## Description

### Big O Notaiton
Quick note, this is almost certainly confusing Big O notation (which is an upper bound) with Theta notation "Θ" (which is a two-side bound). In my experience, this is actually typical of discussions in non-academic settings. Apologies for any confusion caused.


## Environment

Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC version 4.8.4

## Instructions

### Resources:books:
Read or watch:
* [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
* [Big O notation](https://stackoverflow.com/questions/487258/what-is-a-plain-english-explanation-of-big-o-notation)
* [Sorting algorithms animations](https://www.toptal.com/developers/sorting-algorithms)
* [15 sorting algorithms in 6 minutes](https://www.youtube.com/watch?v=kPRA0W1kECg)


### Learning Objectives:bulb:
What you should learn from this project:

* At least four different sorting algorithms
* What is the Big O notation, and how to evaluate the time complexity of an algorithm
* How to select the best sorting algorithm for a given input
* What is a stable sorting algorithm

### Intructions basics

-   Compiling the program: `gcc -Wall -Werror -Wextra -pedantic *.c -o <namefile>`

## Example
```
vagrant@vagrant-ubuntu-trusty-64:~/sorting_algorithms$
vagrant@vagrant-ubuntu-trusty-64:~/sorting_algorithms$ gcc -Wall -Wextra -Werror -pedantic 0-bubble_sort.c 0-main.c print_array.c -o bubble
vagrant@vagrant-ubuntu-trusty-64:~/sorting_algorithms$ ./bubble
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 71, 99, 13, 52, 96, 73, 86, 7
19, 48, 71, 13, 99, 52, 96, 73, 86, 7
19, 48, 71, 13, 52, 99, 96, 73, 86, 7
19, 48, 71, 13, 52, 96, 99, 73, 86, 7
19, 48, 71, 13, 52, 96, 73, 99, 86, 7
19, 48, 71, 13, 52, 96, 73, 86, 99, 7
19, 48, 71, 13, 52, 96, 73, 86, 7, 99
19, 48, 13, 71, 52, 96, 73, 86, 7, 99
19, 48, 13, 52, 71, 96, 73, 86, 7, 99
19, 48, 13, 52, 71, 73, 96, 86, 7, 99
19, 48, 13, 52, 71, 73, 86, 96, 7, 99
19, 48, 13, 52, 71, 73, 86, 7, 96, 99
19, 13, 48, 52, 71, 73, 86, 7, 96, 99
19, 13, 48, 52, 71, 73, 7, 86, 96, 99
13, 19, 48, 52, 71, 73, 7, 86, 96, 99
13, 19, 48, 52, 71, 7, 73, 86, 96, 99
13, 19, 48, 52, 7, 71, 73, 86, 96, 99
13, 19, 48, 7, 52, 71, 73, 86, 96, 99
13, 19, 7, 48, 52, 71, 73, 86, 96, 99
13, 7, 19, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
vagrant@vagrant-ubuntu-trusty-64:~/sorting_algorithms$
```

## Respository Contenst

Monty Files:

| File | Description
| ------------- |:-------------:|
| sort.h | Header file that contains all the functions and standard C library header file
| 0-bubble_sort.c | Contains the
| 0-O | It contains the function
| 1-insertion_sort_list.c | Contains functions math :
| 1-O |  Contains functions
| 2-selection_sort.c | It contains other functions
| 2-O | Contains
| 3-quick_sort | It is a
| 3-O | Directory with files test in the program
| 100-shell_sort |  Contains functions
| 101-cocktail_sort_list.c | Contains functions

 ## Requirements project

-  Allowed editors: vi, vim, emacs
-   All your files will be compiled on Ubuntu 14.04 LTS
-   CompilingYour programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
-   All your files should end with a new line
-   A README.md file, at the root of the folder of the project, is mandatory
-   AllYour code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
-   AllYou are not allowed to use global variables
-   AllNo more than 5 functions per file
-   Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like printf, puts, … is totally forbidden.
-   In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called sort.h
-   Don’t forget to push your header file
-   UnlessAll your header files should be include guarded
-   AllNo list/array does not need to be sorted if its size is less than 2.

## Tasks

### 0. Bubble sort
-   Write a function that sorts an array of integers in ascending order using the Bubble sort algorithm

-   CompilingPrototype: void bubble_sort(int *array, size_t size);
-   You’re expected to print the array after each time you swap two elements (See example below)
-   Write in the file 0-O, the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:

### 1. Insertion sort

-   Write a function that sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm

-   Compiling Prototype: void insertion_sort_list(listint_t **list);
-   You are not allowed to modify the integer n of a node. -    You have to swap the nodes themselves.
-   You’re expected to print the list after each time you swap two elements (See example below)

### 2. Selection sort
-   Write a function that sorts an array of integers in ascending order using the Selection sort algorithm

-   Prototype: void selection_sort(int *array, size_t size);
-   You’re expected to print the array after each time you swap two elements (See example below)

### 3. Quick sort
-   Write a function that sorts an array of integers in ascending order using the Quick sort algorithm

-   Compiling Prototype: void quick_sort(int *array, size_t size);
-   You must implement the Lomuto partition scheme.
-   The pivot should always be the last element of the partition being sorted.

### 4. Shell sort - Knuth Sequence
-   Write a function that sorts an array of integers in ascending order using the Shell sort algorithm, using the Knuth sequenc

### 5. Cocktail shaker sort
-   Write a function that sorts a doubly linked list of integers in ascending order using the Cocktail shaker sort algorithm


## Autors

-   ***Daniela Lopera Hernandez - https://github.com/danielaloperahernandez***

-   ***Deiwin Ignacio Monsalve Altamar - <https://github.com/Deiwin-Ignacio-Monsalve-Altamar>***
