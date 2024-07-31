//This function is used to print characters.
#include "ft_printf.h"

int ft_print_character(int c)
///int c: 1. All characters can be transferred into int.
//////////2. The range of int is wider than char, including special return values like EOF (-1). 
//////////For function like printf, may need to handle such kind of value.
//////////3. It follows the basic C language standard.
{
    if((write(1, &c, 1)!= 1))
    //this part will execute the content within the bracket first, then check the condition
        return (-1);
    //the return value -1 is used for the 'errno' situation
    //'errno' is a global variable. It is used in combination with other functions like 'strerror' and 'perror' to check for errors.
    return (1);
    //? why does it return 1 instead of return 0?
    //- Because we want to calculate the 'len',
    ////And for this function, everytime it runs successfully, we'll output 1 character.
}