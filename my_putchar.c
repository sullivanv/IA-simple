#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c,  1);
}
void    my_putstr(char *str)
{
  int   i;

  i = 0;
  while (*(str + i) != '\0')
    {
      my_putchar(*(str + i));
      i += 1;
    }
}
int	my_strcmp(char *s1, char *s2)
{
  int	a;

  a = 0;
  while (s1[a] != '\0' && s2[a] != '\0')
    {
      if (s1[a] < s2[a])
        {
	  return (-1);
        }
      else if (s1[a] > s2[a])
        {
          return (1);
        }
      a = a + 1;
    }
  if (s1[a] > s2[a])
    {
      return (1);
    }
  else if (s2[a] > s1[a])
    {
      return (-1);
    }
  return (0);
}

void  my_put_nbr(int nbr)
{
  if (nbr == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nbr < 0)
	{
	  nbr = nbr * (-1);
	  my_putchar('-');
	}
      if (nbr >= 10)
	{
	  my_put_nbr(nbr / 10);
	  my_put_nbr(nbr % 10);
	}
      else
	my_putchar(nbr + 48);
    }
}

char	*my_strcpy(char *dest, char *src)
{
  int	x;

  x = 0;
  while (src[x] <= '\0')
    {
      src[x] = dest[x];
      x += 1;
    }
  dest[x] = '\0';
  return dest;
}
