/*
** fonction.c for Algo in /Users/vitiel_s/code/Algo_IA
** 
** Made by VITIELLO Sullivan
** Login   <vitiel_s@etna-alternance.net>
** 
** Started on  Wed Mar  2 17:34:57 2016 VITIELLO Sullivan
** Last update Fri Mar  4 11:56:19 2016 VITIELLO Sullivan
*/

#include "rien.h"

int	my_getnbr(char *str)
{
  int	i;
  int	s;
  int	r;

  r = 0;
  i = 0;
  s = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	s++;
      i++;
    }
  if (str[i] < 48 || str[i] > 57)
    return (0);
  while (str[i] > 47 && str[i] < 58)
    {
      r = r * 10 + (str[i] - 48);
      i++;
    }
  if (s % 2 == 1)
    return (-r);
  return (r);
}

int	my_position(char **tab, char to_find)
{
  int i;
  int j;
  int x;

  i = 0;
  x = 0;
  j = 0;
  while (1)
    {
      while (tab[i][j])
	{
	  if (tab[i][j] == to_find)
	    break;
	  x++;
	  j++;
	}
      if (tab[i][j] == to_find)
	break;
      i++;
      if (tab[i][0] == '\0')
	return(-1);
      x++;
      j = 0;
    }
  return(x);
}

int my_taille(char **tab)
{
  int i;

  i = 0;
  while (tab[0][i])
    i++;
  return(i + 1);
}

int	my_abs(int x)
{
  if (x > 0)
    return(x);
  else
    return(-x);
}

int	my_man(int pos, int exit, int pv, int taille)
{
  int xa;
  int xb;
  int ya;
  int yb;

  xa = pos / taille;
  xb = pos % taille;
  ya = exit / taille;
  yb = exit % taille;
  ya = ya - xa;
  xa = yb - xb;
  xa = my_abs(xa);
  ya = my_abs(ya);
  xa = xa + ya;
  return (xa);
}

int	my_find_ress(char **tab, int pos, int pv, int taille, int exit)
{
  int p;
  int y;
  int man;
  int real_p;
  int i;
  int j;

  i = 0;
  j = 0;
  y = 1000;
  p = 0;
  while (tab[i][0] != '\0')
    {
      while (tab[i][j])
	{
	  if (tab[i][j] == '+')
	    {
	      man = my_man(p, pos, pv, taille) + my_man(p, exit, pv, taille);
	      if (man < y)
		{
		  real_p = p;
		  y = man;
		}
	    }
	  j++;
	  p++;
	}
      j = 0;
      i++;
      p++;
    }
  return(real_p);
}

int	my_find(char **tab, int pos, int pv, int taille)
{
  int i;
  int j;
  int p;

  p = 0;
  i = 0;
  j = 0;
  while (tab[i][0] != '\0')
    {
      while (tab[i][j])
	{
	  if (tab[i][j] == '+' && my_man(pos, p, pv, taille) <= pv)
	    {
	      //	      my_putstr("\n\nmanathan :");
	      //      my_put_nbr(my_man(pos, p, pv, taille));
	      //my_putchar('\n');
	      return(p);
	    }
	  j++;
	  p++;
	}
      j = 0;
      i++;
      p++;
    }
  return(-1);
}

char	**my_rm_ress(char **tab, int pos)
{
  int i;
  int j;
  int p;

  p = 0;
  i = 0;
  j = 0;
  while (tab[i][0] != '\0')
    {
      while (tab[i][j])
	{
	  if (p == pos)
	    {
	      tab[i][j] = ' ';
	      return (tab);
	    }
	  j++;
	  p++;
	}
      j = 0;
      i++;
      p++;
    }
  return(tab);
}

void	my_algo(char **tab, char **argv)
{
  int pos;
  int exit;
  int pv;
  int ressource;
  int taille;

  taille = my_taille(tab);
  pv = my_getnbr(argv[1]);
  ressource = my_getnbr(argv[2]);
  exit = my_position(tab, '#');
  pos = my_position(tab, '@');
  if (exit == -1 || pos == -1)
    {
      my_putstr("La map ne contient pas d'entree ou de sortie");
      return;
    }
  while (pv > 0)
    if (my_man(pos, exit, pv, taille) <= pv)
    {
      my_putstr("OK\n");
      return;
    }
    else if (my_man(my_find_ress(tab, pos, pv, taille, exit), pos, pv, taille) <= pv)
      {
	//	my_putstr("\n<--Ancien pv :");
	//	my_put_nbr(pv);
	pv = pv - my_man(my_find_ress(tab, pos, pv, taille, exit), pos, pv, taille) + ressource;
	//	my_putstr("\nNouveau pv :");
	//	my_put_nbr(pv);
	//	my_putstr("\nAncien pos :");
	//	my_put_nbr(pos);
	pos = my_find_ress(tab, pos, pv, taille, exit);
	//	my_putstr("\nnew pos :");
	//	my_put_nbr(pos);
	my_rm_ress(tab, pos);
	}/*
    else if (my_man(my_find(tab, pos, pv, taille), pos, pv, taille) <= pv)
      {
		my_putstr("\nNew pos");
		my_put_nbr(my_find(tab, pos, pv, taille));
		my_putstr("\navec pv :");
		my_put_nbr(pv);
	pv = pv - my_man(my_find(tab, pos, pv, taille), pos, pv, taille) + ressource;
	//	my_putstr("\nNouveau pv :");
	//my_put_nbr(pv);
	//my_putstr("\nAncien pos :");
	//my_put_nbr(pos);
	pos = my_find(tab, pos, pv, taille);
	//my_putstr("\new pos :");
	//my_put_nbr(pos);
	my_rm_ress(tab, pos);
	}*/
    else 
      {
	my_putstr("KO\n");
	return;
      }
}
