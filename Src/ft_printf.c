#include "../Includes/ft_printf.h"

int     is_format(char f)
{
    return (f == CHARACTER_FORMAT || f == STRING_FORMAT     || f == HEX_UPPER_FORMAT ||
            f == INTEGER_FORMAT   || f == PERCENTAGE_FORMAT || f == DECIMAL_FORMAT   || 
            f == UNSIGNED_DECIMAL_FORMAT || f == HEX_LOWER_FORMAT);
}

int     ft_printf(char const *format, ...)
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