#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

//Putchar
int _putchar(char c)
{
	return (write(1, &c, 1));
}

//Custom printf
int _printf(const char *format, ...){

    char c;   // store char if flag is %c
    char *s;   //store char if flag is %s
	size_t format_size; 
	va_list ls;  //variable arguments list 
	va_start(ls, format); 

    while (*format != '\0')
    {
        //check if it has a % flag
        if(*format == '%'){
            //if it does, go to the next char of the format array
            format++;
            //if the next char is a 'c' replace with character from va_list ls
            if(*format == 'c')
            {
                //save the char in variable c
                c = va_arg(ls, int);
                _putchar(c);
                format++; //move to next char
            }
            if(*format == 's')
            {
                //save the char in variable c
                s = va_arg(ls, char *);
                while (*s != '\0')
                {
                    _putchar(*s);
                    s++;
                }
                format++;
            }
        }
        _putchar(*format);
        format++;
    }

	va_end(ls);

	return 0;
}

void main(){
    _printf("Code a %s here\n", "word");
}