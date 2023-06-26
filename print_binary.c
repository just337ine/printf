#include "main.h"

/**
 * print_binary - Prints a decimal number in binary format.
 * @ar: A va_list containing the decimal number to be printed.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list ar)
{
    unsigned int num = va_arg(ar, unsigned int);
    int length = 0;
    int i;

    if (num == 0)
    {
        _putchar('0');
        return 1;
    }

    unsigned int j = num;

    while (j > 0)
    {
        j = j >> 1;
        length++;
    }

    int* binary = malloc(length * sizeof(int));
    if (binary == NULL)
    {
        // Error handling if memory allocation fails
        return 0;
    }

    for (i = 0; num > 0; i++)
    {
        binary[i] = num & 1;
        num = num >> 1;
    }

    for (i = length - 1; i >= 0; i--)
    {
        _putchar('0' + binary[i]);
    }

    free(binary);

    return length;
}