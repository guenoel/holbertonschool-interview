#include "palindrome.h"

/**
 * is_palindrome - Check if an unsigned integer is a palindrome
 * @n: The unsigned integer to check
 * Return: 1 if n is a palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long original = n;
	unsigned long reversed = 0;

	while (n != 0)
	{
		/* add last digit at the right of reversed number*/
		reversed = reversed * 10 + n % 10;
		/* next left digit of n */
		n /= 10;
	}

	return (original == reversed) ? 1 : 0;
}
