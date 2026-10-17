#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

static void int_to_string_signed(long long num, char *buffer, size_t buffer_size, int base, const char *digits, size_t *total_len)
{
    char temp[64];
    int i = 0, negative = 0;

    if (num < 0 && base == 10)
    {
        negative = 1;

        if (num == LLONG_MIN)
        {
            num = -(num + 1);
            temp[i++] = digits[num % base + 1];
            num /= base;
        }
        else
        {
            num = -num;
        }
    }

    do
    {
        temp[i++] = digits[num % base];
        num /= base;
    } while (num > 0);

    if (negative)
    {
        temp[i++] = '-';
    }

    while (i > 0 && *total_len + 1 < buffer_size)
    {
        if (buffer)
        {
            buffer[(*total_len)++] = temp[--i];
        }
    }

    while (i > 0)
    {
        (*total_len)++;
        i--;
    }
}

static void int_to_string_unsigned(unsigned long long num, char *buffer, size_t buffer_size, int base, const char *digits, size_t *total_len)
{
    char temp[64];
    int i = 0;

    do
    {
        temp[i++] = digits[num % base];
        num /= base;
    } while (num > 0);

    while (i > 0 && *total_len + 1 < buffer_size)
    {
        if (buffer)
        {
            buffer[(*total_len)++] = temp[--i];
        }
    }

    while (i > 0)
    {
        (*total_len)++;
        i--;
    }
}

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    size_t total_len = 0;

    const char *p = format;
    while (*p != '\0')
    {
        if (*p == '%')
        {
            p++;
            int base = 10;
            const char *digits = "0123456789abcdef";
            int long_mod = 0, short_mod = 0;
            if (*p == 'l')
            {
                long_mod = 1;
                p++;
                if (*p == 'l')
                {
                    long_mod = 2;
                    p++;
                }
            }
            else if (*p == 'h')
            {
                short_mod = 1;
                p++;
            }

            switch (*p)
            {
                case 'd':
                case 'i':
                    {
                        long long num;
                        if (long_mod == 2)
                            num = va_arg(args, long long);
                        else if (long_mod)
                            num = va_arg(args, long);
                        else if (short_mod)
                            num = (short)va_arg(args, int);
                        else
                            num = va_arg(args, int);

                        int_to_string_signed(num, str, size, base, digits, &total_len);
                        break;
                    }
                case '%':
                    {
                        if (total_len + 1 < size && str)
                        {
                            str[total_len] = '%';
                        }
                        total_len++;
                        break;
                    }
                case 'x':
                case 'o':
                    {
                        unsigned long long num;
                        base = (*p == 'x') ? 16 : 8;
                        if (long_mod == 2)
                            num = va_arg(args, unsigned long long);
                        else if (long_mod)
                            num = va_arg(args, unsigned long);
                        else if (short_mod)
                            num = (unsigned short)va_arg(args, unsigned int);
                        else
                            num = va_arg(args, unsigned int);

                        int_to_string_unsigned(num, str, size, base, digits, &total_len);
                        break;
                    }
                case 'c':
                    {
                        char c = (char)va_arg(args, int);
                        if (total_len + 1 < size && str)
                        {
                            str[total_len] = c;
                        }
                        total_len++;
                        break;
                    }
                case 's':
                    {
                        const char *s = va_arg(args, const char *);
                        while (*s && total_len + 1 < size)
                        {
                            if (str)
                            {
                                str[total_len++] = *s++;
                            }
                        }
                        while (*s++)
                        {
                            total_len++;
                        }
                        break;
                    }
                default:
                    break;
            }
        }
        else
        {
            if (total_len + 1 < size && str)
            {
                str[total_len] = *p;
            }
            total_len++;
        }
        p++;
    }

    if (size > 0 && str)
    {
        str[total_len < size - 1 ? total_len : size - 1] = '\0';
    }

    va_end(args);
    return (int)total_len;
}
