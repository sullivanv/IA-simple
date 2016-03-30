#include "rien.h"


char **create_tab(int ligne, int colonne)
{ 
  int i; 
  char **tab;
  
  tab = malloc(ligne * sizeof(*tab));
  if (tab == NULL)
    my_putstr("Erreur de malloc !\n");
  for(i = 0; i < colonne; i++)
    {
      tab[i] = malloc(colonne * sizeof(**tab));
      if (tab[i] == NULL) 
	my_putstr("Erreur de malloc !\n");
    }
  return tab;
}

char *open_file(char *argv)
{
  char *buffer;
  int fp;
  char c;
  int y;
  int file;

  y = 0;
  fp = open(argv, O_RDONLY);
  while (read(fp, &c, sizeof(c)) > 0)
    y++;
  buffer = malloc(sizeof(char)*y);
  file = open(argv, O_RDONLY);
  read(file,buffer, y);
  return(buffer);
}

int init_y(char *argv)
{
  int fp;
  char c;
  int y;

  y = 0;
  fp = open(argv, O_RDONLY);
  while (read(fp, &c, sizeof(c)) > 0)
    y++;
  return(y);
}

char** print_tab(char **tab, char *buffer, int nbLin, int nbCol)
{
  int x;
  int y;
  int i;

  x = 0;
  y = 0;
  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == '\n')
	{
	  tab[x][y] = '\0';
	  i++;
	  x++;
	  y = 0;
	}
      tab[x][y] = buffer[i];
      y++;
      i++;
    }
  return (tab);
}

char **openfile(char **tab, int nbLin, int nbCol, char *argv)
{ 
  char *buffer;
  int i;
  int y;
  int o;

  o = 0;
  y = init_y(argv);
  i = 0;
  buffer = open_file(argv);
  while (i != y)
    {
      if (buffer[i] == '\n')
	nbLin++;
      for (nbCol = 0; buffer[nbCol] != '\n'; nbCol++);
      i++;
    }
  tab = create_tab(nbLin,nbCol);
  tab = print_tab(tab, buffer, nbLin, nbCol);
 return (tab);
}

int main(int argc, char **argv)
{	
  char **tab;
  int nbLin;
  int nbCol;

  if (argc != 4 || my_getnbr(argv[1]) <= 0 || my_getnbr(argv[2]) <= 0)
    {
      my_putstr("Veuillez entrez : ./solve point_de_vie vie_ressource exemple");
      my_putstr(".txt (les points de vies et ressource doivent etre positifs)\n");
      return (0);
    }
  nbLin = 1;
  nbCol = 0;
  tab = openfile(tab, nbLin, nbCol, argv[3]);
  if (tab[0] ==  NULL)
    {
      my_putstr("Votre map n'existe pas ou le format n'est pas bon !\n");
      return (0);
    }
  my_algo(tab, argv);
  return (0);
}
