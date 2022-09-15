#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

int main()
{
	/* ex03 */
	/* Check general behavior */
	assert(ft_atoi("12345") == 12345);
	assert(ft_atoi("  \t--+-95173135") == -95173135);
	
	/* Check INT_MAX | INT_MAX */
	assert(ft_atoi("+-++--2147483648--12123") == INT32_MIN);
	assert(ft_atoi("+2147483647++53151") == INT32_MAX);

	/* ex04 */
	printf("==========ex04=========\n"),
	printf("answer\nyour answser\n");
	/* Check Valid base */
	printf("NO PRINT\n");
	ft_putnbr_base(123456789, "");
	printf("\n\n");
	printf("NO PRINT\n");
	ft_putnbr_base(123456789, "-abc");
	printf("\n\n");
	printf("NO PRINT\n");
	ft_putnbr_base(123456789, "aba");
	printf("\n\n");
	/* General behavior */
	printf("925715\n");
	ft_putnbr_base(925715, "0123456789");
	printf("\n\n");
	printf("-2147483648\n");
	ft_putnbr_base(-2147483648, "0123456789");
	printf("\n\n");
	printf("-10000000000000000000000000000000\n");
	ft_putnbr_base(INT_MIN, "01");
	printf("\n\n");
	printf("1111111111111111111111111111111\n");
	ft_putnbr_base(INT_MAX, "01");
	printf("\n\n");
	printf("-baaaaaaa\n");
	ft_putnbr_base(-128, "ab");
	printf("\n\n");
	printf("-baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	ft_putnbr_base(INT_MIN, "ab");
	printf("\n\n");
	printf("baaa\n");
	ft_putnbr_base(8, "ab");
	printf("\n\n");
	printf("ca\n");
	ft_putnbr_base(8, "abcd");
	printf("\n\n");
	/* Check Segumantation Fault  */
	printf("don't care output\n");
	ft_putnbr_base(INT_MIN, "qwertyuiop1234567890asdfghjklzxcvbnm,.");
	printf("\n\n");
	printf("don't care output\n");
	ft_putnbr_base(INT_MAX, "qwertyuiop1234567890asdfghjklzxcvbnm,.");
	printf("\n\n");
	printf("don't care output\n");
	ft_putnbr_base(INT_MIN, "!@#$%^&*()1234567890qwertyuiopasdfghjklzxcvbnm,./");
	printf("\n\n");
	printf("don't care output\n");
	ft_putnbr_base(INT_MAX, "!@#$%^&*()1234567890qwertyuiopasdfghjklzxcvbnm,./");
	printf("\n\n");

	/* ex05 */

	assert(ft_atoi_base("", "") == 0); // empty base
	assert(ft_atoi_base("", "a") == 0); // base length 1
	assert(ft_atoi_base("", "abcdefa") == 0); // same character
	assert(ft_atoi_base("", "abcdef+") == 0); // invalid character
	assert(ft_atoi_base("", "abcdef-") == 0); // invalid character
	assert(ft_atoi_base("", "abcdef\t") == 0); // invalid character

	assert(ft_atoi_base("  12345", "0123456789") == 12345);
	assert(ft_atoi_base("abcdef", "abcdef") == 1865);
	
	assert(ft_atoi_base(" \t\n---+edcba", "abcdefghij") == -43210);

	assert(ft_atoi_base("  +-++--2147483648--12123", "0123456789") == INT32_MIN);
	assert(ft_atoi_base("+2147483647++53151", "0123456789") == INT32_MAX);

	assert(ft_atoi_base("", "abc") == 0);
	assert(ft_atoi_base("  ---", "abc") == 0);
	assert(ft_atoi_base("---+abc", "abc") == -5);
	assert(ft_atoi_base("---+123", "abc") == 0);

	assert(ft_atoi_base("  abc", "qwertyuiop1234567890asdfghjklzxcvbnm,.") == 30165);
	
	return 0;
}
