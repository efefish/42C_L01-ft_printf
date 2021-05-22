# 42Cursus project Level1 "ft_printf"

## *Description

    I recoded the libc’s printf function. but it must not do the buffer management like the real printf.
    We must use the command ar to create our librairy, using the command libtool is forbidden.
    you can use precision and field width but not length modifier.

## *Available Functions

    malloc, free, write, va_start, va_arg, va_copy, va_end

## *flag

|  flag  | Output format |
|:----:|:----:|
| 0 | Fill the left side of the converted value with zeros instead of spaces.              |
| - | Left-justify the transformed value at field boundaries. (default is right-justified) |

## *Available Conversion Specifiers

|  Specifiers  | Argument | Output format |
|:----:|:----:|:----:|
| c   | character    | unsinged char. |
| s   | string       | Characters are displayed up to the first '\0' or until the precision value is reached. |
| p   | pointer type | Display the argument as an address in hexadecimal digits. |
| u   | integer      | Unsigned decimal integer.                                 |
| d,i | integer      | Signed decimal integer.                                   |
| x,X | integer      | Unsigned hexadecimal integer. x:"abcdef" X:"ABCDEF"       |
