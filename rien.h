#ifndef __rien_h__
#define __rien_h__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void my_putchar(char c);
int	my_strcmp(char *s1, char *s2);
void    my_putstr(char *str);
void    my_put_nbr(int n);
char	*my_strcpy(char *dest, char *src);
void	my_algo(char **tab, char **argv);
int     my_getnbr(char *str);

#endif
