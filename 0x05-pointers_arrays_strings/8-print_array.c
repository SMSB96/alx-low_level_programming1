#include "main.h"

/**
 * main - check the code for
 *
 * Return: Always 0.
 */
int main(void)
{
int array[5];

array[0] = 98;
array[1] = 402;
array[2] = -198;
array[3] = 298;
array[4] = -1024;
print_array(array, 5);
return (0);
}
root@edb2e835798f:/alx-low_level_programming/0x05-pointers_arrays_strings# cat 8-print_array.c
#include "main.h"
#include <stdio.h>

/**
 * print_array - Prints n elements of an array of integers
 * @a: The array of integers
 * @n: The number of elements to print
 * Return: void
 */
void print_array(int *a, int n)
{
int i;

for (i = 0; i < n; i++)
{
printf("%d", a[i]);
if (i != (n - 1))
{
printf(", ");
}
}
printf("\n");
}
