#ifndef CONSTANTS_H
# define CONTANTS_H

/* FORMATS CONSTANTS */
#define DECIMAL_FORMAT              'd'
#define CHARACTER_FORMAT            'c'
#define INTEGER_FORMAT              'i'
#define STRING_FORMAT               's'
#define POINTER_FORMAT              'p'
#define UNSIGNED_DECIMAL_FORMAT     'u'
#define HEX_LOWER_FORMAT            'x'
#define HEX_UPPER_FORMAT            'X'
#define PERCENTAGE_FORMAT           '%'

/* BASE CONTANTS */
#define DECIMAL_NB                  10
#define HEX_NB                      16
#define UPPER_HEX_BASE              "0123456789ABCDEF"
#define LOWER_HEX_BASE              "0123456789abcdef"
#define DEC_BASE                    "0123456789"

/* OTHERS */
#define PTR_NIL                         "(nil)"
#define STR_NULL                        "(null)"
#define ZERO_ADDRESS                    "0x"
#define LEN_ZERO_ADDRESS                2
#define LEN_NIL_WORD                    5
#define LEN_NULL_WORD                   6
#define MIN_RANGE_INT_IN_STR_FORMAT     "-2147483648"
#define LEN_MIN_RANGE_INT               11

#endif