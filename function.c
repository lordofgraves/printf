#include "main.h"
#include <stdarg.h>
#include <unistd.h> 
/* for write */

int _printf(const char *format, ...)
{
	va_list args;
        va_start(args, format);

        int printed_chars = 0;
        while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char arg = va_arg(args, int);
						write(STDOUT_FILENO, &arg, 1);
						printed_chars++;
						break;
					}
                                case 's':
                                        {
                                                char *arg = va_arg(args, char*);
                                                while (*arg != '\0')
						{
							write(STDOUT_FILENO, arg, 1);
                                                        arg++;
                                                        printed_chars++;
                                                }
						break;
					}
				case '%':
					{
						write(STDOUT_FILENO, "%", 1);
						printed_chars++;
						break;
					}
				default:
					{
						break;
					}
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return printed_chars;
}
