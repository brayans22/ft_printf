#include "../Includes/ft_printf.h"

int             is_format(char f)
{
    return (f == FLOAT_FORMAT || f == CHARACTER_FORMAT || f == STRING_FORMAT || 
            f == DECIMAL_FORMAT|| f == INTEGER_FORMAT || f == UNSIGNED_DECIMAL_FORMAT || 
            f == HEX_LOWER_FORMAT || f == HEX_UPPER_FORMAT || f == PERCENTAGE_FORMAT);
}

void    print_string_format(char *str, unsigned int *count_read)
{
    if (!str)
        str = "(null)";
    ft_putstr(str);
    (*count_read) += ft_strlen(str);
}

void    print_char_format(char c, unsigned int *count_read)
{
    ft_putchar(c);
    (*count_read)++;
}

void    print_number_format(int number, unsigned int *count_read)
{
    ft_putnbr_base_signed(number, DECIMAL_BASE);
    (*count_read) += ft_number_len_signed(number, DECIMAL_BASE);
}

void    print_unsigned_int_format(unsigned int number, unsigned int *count_read)
{
    ft_putnbr_base_unsigned(number, DECIMAL_BASE);
    (*count_read) += ft_number_len_unsigned(number, DECIMAL_BASE);
}

void    print_format(char format, unsigned int *count_read, va_list p_arguments)
{
    if (format == STRING_FORMAT)
        print_string_format(va_arg(p_arguments, char *), count_read);
    else if (format == CHARACTER_FORMAT)
        print_char_format((char)va_arg(p_arguments, int), count_read);
    else if (format == INTEGER_FORMAT || format == DECIMAL_FORMAT)
        print_number_format(va_arg(p_arguments, int), count_read);
    else if (format == UNSIGNED_DECIMAL_FORMAT)
        print_unsigned_int_format(va_arg(p_arguments, unsigned int), count_read);
    else
        print_char_format(PERCENTAGE_FORMAT, count_read);
    /*
    else if (format == POINTER_FORMAT)
        count_read++;
    else if (format == FLOAT_FORMAT)
        count_read++;
    else if (format == HEX_LOWER_FORMAT || format == HEX_UPPER_FORMAT)
        count_read++;
    */
}

int ft_printf(char const *format, ...)
{
    va_list         p_args;
    unsigned int    count_read;

    if (!format)
        return (0);
    va_start(p_args, format);
    count_read = 0;
    while (*format)
    {
        if (*(format) == PERCENTAGE_FORMAT && is_format(*(format + 1)))
        {
            print_format(*(format + 1), &count_read, p_args);
            format++;
        }
        else 
            print_char_format(*format, &count_read);
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
    int a = ft_printf("Nombre: %s, sexo: %c, numero sin signo: %u\n", n, c, -1);
    int b = printf("Nombre: %s, sexo: %c, numero sin signo: %u\n", n, c, -1);

    printf("copia: %i, original:%i\n",a,b);
    
    return 0;
}
*/