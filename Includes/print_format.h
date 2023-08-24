#ifndef PRINT_FORMAT_H
# define PRINT_FORMAT_H

/* INCLUDES */
# include <stdarg.h>
#include "libft.h"
#include "constants.h"
#include "util.h"

/* FUNCTIONS */
void    print_string_format(char *str, unsigned int *count_read);
void    print_char_format(char c, unsigned int *count_read);
void    print_int_format(int number, unsigned int *count_read);
void    print_unsigned_int_format(unsigned int number, unsigned int *count_read, unsigned int base_number, char *content_base);
void    print_format(char format, unsigned int *count_read, va_list p_arguments);

#endif