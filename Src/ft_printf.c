#include "../Includes/ft_printf.h"

int     is_format(char f)
{
    return (f == FLOAT_FORMAT || f == CHARACTER_FORMAT || f == STRING_FORMAT || 
            f == DECIMAL_FORMAT|| f == INTEGER_FORMAT || f == UNSIGNED_DECIMAL_FORMAT || 
            f == HEX_LOWER_FORMAT || f == HEX_UPPER_FORMAT || f == PERCENTAGE_FORMAT);
}

int     is_valid_input(const char *s, unsigned int nargs)
{
    int             is_valid;
    unsigned int    count_formats;

    is_valid = 1;
    count_formats = 0;
    while (*s)
    {
        if (*s == '%' && is_format(*(s + 1)))
        {
            count_formats++;
            s++;
        }
        s++;
    }
    if (count_formats > nargs || count_formats < nargs)
        is_valid = 0;
    return (is_valid);
}

void    print_string_format(char *str, unsigned int *count_read)
{
    if (str)
        ft_putstr(str);
    else
        ft_putstr("(null)");
    (*count_read) += ft_strlen(str);
}

void    print_char_format(char c, unsigned int *count_read)
{
    ft_putchar(c);
    (*count_read)++;
}

void    print_decimal_sign_format(char c, unsigned int *count_read)
{
    ft_putchar(c);
    (*count_read)++;
}


void    print_format_case(char format, unsigned int *count_read, va_list p_arguments)
{
    if (format == STRING_FORMAT)
        print_string_format((char *)va_arg(p_arguments, char *), count_read);
    else if (format == CHARACTER_FORMAT || format == PERCENTAGE_FORMAT)
        print_char_format((char)va_arg(p_arguments, int), count_read);
    else if (format == INTEGER_FORMAT || format == DECIMAL_FORMAT || format == UNSIGNED_DECIMAL_FORMAT)
    {
        count_read--;
        //print_decimal_format ((int)va_arg(p_arguments, int), format, count_read);
    }
    else if (format == POINTER_FORMAT)
        count_read++;
    else if (format == FLOAT_FORMAT)
        count_read++;
    else if (format == HEX_LOWER_FORMAT || format == HEX_UPPER_FORMAT)
        count_read++;
}

int ft_printf(char const *format, ...)
{
    va_list         p_args;
    unsigned int    count_read;

    va_start(p_args, format);
    if (!format)
        return (0);
    
    count_read = 0;
    while (*format)
    {
        if (*(format) == PERCENTAGE_FORMAT && is_format(*(format + 1)))
        {
            
            print_format_case(*(format + 1), &count_read, p_args);
            format++;
        }
        else 
        {
            ft_putchar(*format);
            count_read++;
        }
        format++;
    }
    va_end(p_args);
    return (count_read);
}

/*
#include <stdio.h>
int main()
{
    printf("jejejej\n");
    char c = 'M';
    char n[] = "brayan";
    int a = ft_printf("Nombre: %s, sexo: %c\n", n, c);
    int b = printf("Nombre: %s, sexo: %c\n", n, c);

    printf("copia: %i, original:%i\n",a,b);
    //printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    //("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    return 0;
}
*/
