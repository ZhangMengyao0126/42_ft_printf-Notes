#include "ft_printf.h"
//Subfunction for ft_check_format: Used to print the arguments associated with the specific format.
static int ft_check_specifier(char spec, va_list ap)
//char spec: Since we have already obtained the value of the format, we can just use a character variable.
{
    int len;
    len = 0;
    if(spec == 'c')
    {
        len = ft_print_character(va_arg(ap, int));
    }
    return (len);
}

//Subfunction for ft_printf: used to check '%format' and print other normal characters.
//static function: The function can only be used in the the file it is declared.
///////////////////It is useful for internal implementation details and avoiding naming conflicts.
///////////////////Eg.ft_check_format is a subfunction of ft_printf. ft_printf, as a versatile function,
//////////////////////can be an global function used everywhere. However, its subfunctions are not.
static int ft_check_format(const char *format, va_list ap, int len)
{
//int len: Since the value of len is going to change directly in this function, we declare it as a variable.
    int i;
    int j;
//i : for the loop;
//j : for the increment in each loop of len.

    i = 0;
    while(format[i] != '\0')
    {
        if(format[i] == '%')
        {
            if(!format[i + 1])
                return (len);
            j = ft_check_specifier(format[++i], ap);
            if(j == -1)
                return (-1);
            //ap: The variadic variable can be passed directly between different functions.
            //++i: 1.first +1, the get the new value of i ; 
            ///////2.cause we want the pointer move to the character after '%', which is the format.
            len += j;
            //len will increase the number of j, which is the lenth of the specific argument.
        }
        else
        {
            if(ft_print_character(format[i]) != 1)
                return (-1);
            len++;
            //len will increase 1, since everytime ft_printf_character runs successfully, we'll output 1 character.
        }
        i++;
        //move the pointer to the character after the format.  
    }
    return (len);
}
//return(-1): This error comes directly from the basic output functions. 
//////////////Therefore, we need to check for it everytime when those basic functions are used


//The main function
int ft_printf(const char *format,...)
{
    va_list ap;
    int     len;
    len = 0;
    va_start(ap, format);
    len += ft_check_format(format, ap, len);
    va_end(ap);
    return (len);
    //The return value of the printf function is the number of characters successfully output.
    //In that case, all the subfunctions of ft_printf should care about the same return value, 'len'.
}
//Variadic variables: Check README.md