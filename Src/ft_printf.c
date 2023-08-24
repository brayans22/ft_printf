#include "../Includes/ft_printf.h"

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
            print_char(*format, &count_read);
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
    char *p = 0;
    int a = ft_printf("Nombre: %s, sexo: %c, numero sin signo: %u, ptr: %p\n", n, c, -1, p);
    int b = printf("Nombre: %s, sexo: %c, numero sin signo: %u, ptr: %p\n", n, c, -1, p);

    printf("copia: %i, original:%i\n",a,b);
    return 0;
}
*/