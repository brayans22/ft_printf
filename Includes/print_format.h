#ifndef PRINT_FORMAT_H
# define PRINT_FORMAT_H

/* INCLUDES */
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "constants.h"
#include "util.h"

/* FUNCTIONS */
void    print_char(char c, unsigned int *count_read);
void    print_format(char format, unsigned int *count_read, va_list p_arguments);
int     is_format(char f);
#endif