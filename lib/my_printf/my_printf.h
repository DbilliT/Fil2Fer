#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>

typedef struct	s_func
{
  char		format;
  int		(*function)(va_list, char *);
}		t_func;

void	my_putchar(char);
void	my_putnchar(char, int);
void	my_putstr(char *);
void	my_putnstr(char *, int);
int	my_atoi(const char *);
char	*my_charcat(char *, char);
int	my_strlen(const char *);
int	my_intlen(int);
char	*my_strndup(char *, int);
char	*my_strncpy(char *, const char *, int);
int	putstr(va_list, char *);
int	putchr(va_list, char *);
int	putnbr(va_list, char *);
int	putnbroct(va_list, char *);
int	putnbrhex(va_list, char *);
int	putnbrbin(va_list, char *);
int	putunsinbr(va_list, char *);
int	putnbrhexup(va_list, char *);
int	putstrprintable(va_list, char *);
int	putpointer(va_list, char *);
int     my_printf(const char *, ...);

#endif /* !MY_PRINTF_H_ */
