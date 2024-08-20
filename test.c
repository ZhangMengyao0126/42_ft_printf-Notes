#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int n = 14;
	int *p = &n;

	printf("sys-char_printed=%d\n", printf("%p\n", p));
	ft_printf("own-char_printed=%d\n", ft_printf("%p\n", p));
}