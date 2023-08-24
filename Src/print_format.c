#include "../Includes/format.h"

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

void    print_int_format(int number, unsigned int *count_read)
{
    char *number_str;
    number_str = ft_itoa(number);

    if (number_str)
    {
        ft_putstr(number_str);
        (*count_read) += ft_strlen(number_str);
        free(number_str);
    }
}

void    print_unsigned_int_format(unsigned int number, unsigned int *count_read, unsigned int base_number, char *content_base)
{
    ft_putnbr_base_unsigned(number, base_number, content_base);
    (*count_read) += ft_number_len_unsigned(number, base_number);
}

void    print_format(char format, unsigned int *count_read, va_list p_arguments)
{
    if (format == STRING_FORMAT)
        print_string_format(va_arg(p_arguments, char *), count_read);
    else if (format == CHARACTER_FORMAT)
        print_char_format((char)va_arg(p_arguments, int), count_read);
    else if (format == INTEGER_FORMAT || format == DECIMAL_FORMAT)
        print_int_format(va_arg(p_arguments, int), count_read);
    else if (format == UNSIGNED_DECIMAL_FORMAT)
        print_unsigned_int_format(va_arg(p_arguments, unsigned int), count_read, 10, "0123456789");
    else if (format == HEX_UPPER_FORMAT)
        print_unsigned_int_format(va_arg(p_arguments, unsigned int), count_read, 16, "0123456789ABCDEF");
    else if (format == HEX_LOWER_FORMAT)
        print_unsigned_int_format(va_arg(p_arguments, unsigned int), count_read, 16, "0123456789abcdef");
    else if (format == POINTER_FORMAT)
        count_read++;
    else
        print_char_format(PERCENTAGE_FORMAT, count_read);
}
