#include "main.h"

            if(*format == '%')
            {
            write(1, format, 1);
            chara_print++;
            }

               else if (*format == 'c')
               {

                       char c = va_arg(mylist_of_args, int);
                       write(1, &c, 1);
                       chara_print++;
               }

            else if (*format == 's')
            {
                    char *str = va_arg(mylist_of_args, char*);
            int str_len = 0;


           while(str[str_len] != '\0')
                   str_len++;
           write(1, str, str_len);
           chara_print += str_len;
        }
}
format++;
}
va_end(mylist_of_args);
return chara_print;
}
"_printf.c" 55L, 879C                                                                                              55,1          Bot            if(*format == '%')
            {
            write(1, format, 1);
            chara_print++;
            }

               else if (*format == 'c')
               {

                       char c = va_arg(mylist_of_args, int);
                       write(1, &c, 1);
                       chara_print++;
               }

            else if (*format == 's')
            {
                    char *str = va_arg(mylist_of_args, char*);
            int str_len = 0;


           while(str[str_len] != '\0')
                   str_len++;
           write(1, str, str_len);
           chara_print += str_len;
        }
}
format++;
}
va_end(mylist_of_args);
return chara_print;
}
"_printf.c" 55L, 879C                                                                                              55,1          Bot            if(*format == '%')
            {
            write(1, format, 1);
            chara_print++;
            }

               else if (*format == 'c')
               {

                       char c = va_arg(mylist_of_args, int);
                       write(1, &c, 1);
                       chara_print++;
               }

            else if (*format == 's')
            {
                    char *str = va_arg(mylist_of_args, char*);
            int str_len = 0;


           while(str[str_len] != '\0')
                   str_len++;
           write(1, str, str_len);
           chara_print += str_len;
        }
}
format++;
}
va_end(mylist_of_args);
return chara_print;
}
"_printf.c" 55L, 879C                                                                                              55,1          Bot"int _printf(const char *format, ...)
{

	int chara_print = 0;
       va_list mylist_of_args;

   if(format == NULL)
      return (-1);

   va_start(mylist_of_args, format); 

  while(*format)
  {
     if(*format != '%'){
	write(1, format, 1);
	chara_print++;	
	}
	else
       	{
		format++;
            if(*format == '\0')
		    break;
	    if(*format == '%')
	    {
	    write(1, format, 1);
	    chara_print++;
	    }

               else if (*format == 'c')
	       {

		       char c = va_arg(mylist_of_args, int);
		       write(1, &c, 1);
		       chara_print++;
	       }

	    else if (*format == 's')
	    {
		    char *str = va_arg(mylist_of_args, char*);
	    int str_len = 0;
	
  
	   while(str[str_len] != '\0')
		   str_len++;
	   write(1, str, str_len);
	   chara_print += str_len;
	}
}
format++;
}
va_end(mylist_of_args);
return chara_print;
}
