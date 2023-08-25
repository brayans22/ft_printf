#include "../Includes/print_format.h"

int     is_format(char f)
{
    return (f == CHARACTER_FORMAT || f == STRING_FORMAT     || f == HEX_UPPER_FORMAT ||
            f == INTEGER_FORMAT   || f == PERCENTAGE_FORMAT || f == DECIMAL_FORMAT   || 
            f == UNSIGNED_DECIMAL_FORMAT || f == HEX_LOWER_FORMAT || f == POINTER_FORMAT);
}

void    print_string(char *str, unsigned int *count_read)
{
    if (!str)
        str = STR_NULL;
    ft_putstr(str);
    (*count_read) += ft_strlen(str);
}

void    print_char(char c, unsigned int *count_read)
{
    ft_putchar(c);
    (*count_read)++;
}

void    print_int(int number, unsigned int *count_read)
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

void    print_unsigned_int(unsigned int number, unsigned int *count_read, unsigned int base_number, char *content_base)
{
    ft_putnbr_base_unsigned(number, base_number, content_base);
    (*count_read) += ft_len_unsigned_int_nb(number, base_number);
}

void    print_pointer(uintptr_t ptr, unsigned int *count_read)
{
    if (ptr == 0)
        (*count_read) += write(1, PTR_NIL, 5);
    else
    {
        write(1, HEXADECIMAL_ZERO_ADDRESS, 2);
        ft_putnbr_base_uintptr(ptr, HEX_NB, LOWER_HEX_BASE);
        (*count_read) += 2 + (ft_len_uintptr(ptr, HEX_NB));
    }
}

void    print_format(char format, unsigned int *count_read, va_list p_arguments)
{
    if (format == STRING_FORMAT)
        print_string(va_arg(p_arguments, char *), count_read);
    else if (format == CHARACTER_FORMAT)
        print_char((char)va_arg(p_arguments, int), count_read);
    else if (format == INTEGER_FORMAT || format == DECIMAL_FORMAT)
        print_int(va_arg(p_arguments, int), count_read);
    else if (format == UNSIGNED_DECIMAL_FORMAT)
        print_unsigned_int(va_arg(p_arguments, unsigned int), count_read, DECIMAL_NB, DEC_BASE);
    else if (format == HEX_UPPER_FORMAT)
        print_unsigned_int(va_arg(p_arguments, unsigned int), count_read, HEX_NB, UPPER_HEX_BASE);
    else if (format == HEX_LOWER_FORMAT)
        print_unsigned_int(va_arg(p_arguments, unsigned int), count_read, HEX_NB, LOWER_HEX_BASE);
    else if (format == POINTER_FORMAT)
        print_pointer(va_arg(p_arguments, uintptr_t), count_read);
    else
        print_char(PERCENTAGE_FORMAT, count_read);
}
