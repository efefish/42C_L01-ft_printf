# 42Cursus project Level1 "ft_printf"

## *Description

    I recoded the libc’s printf function. but it must not do the buffer management like the real printf.
    We must use the command ar to create our librairy, using the command libtool is forbidden.
    you can use precision and field width but not Length modifier.

## *Available Functions

    malloc, free, write, va_start, va_arg, va_copy, va_end

## *Prototype

```c
int   get_next_line(int fd, char **line);
```

## *flag

|  flag  | |
|:----:|:----:|
| 0 |   |
| - |   |

## *Return Value
|  Return Value  | |
|:----:|:----:|
| 1 | A line has been read |
| 0 | EOF has been reached |
|-1 | An error happened    |
