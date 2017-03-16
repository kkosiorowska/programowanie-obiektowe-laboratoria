#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n );
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n;
  int seed ;
  n = atoi(argv[1]);
  seed = atoi(argv[2]);

  srand(seed); //uruchomienie czasu

  //Uruchomienei funkcji rysujacej tablice i tworzacej

	drawCharSquare(charSquare(n), n);

}
char **charSquare(int n)
{

  char ** square = new char *[n];

    for(int i=0 ; i < n ; i++)
    {
      square[i]= new char [n];

    }

    //wypelnienie funkcji

    for(int i=0 ; i < (n*n) ; i++)
    {
      square[i/n][i%n]= 97 + rand() % (127-97) ;

    }

	return square;
}

void drawCharSquare(char **square, int n)
{

  for(int i=0 ; i < (n*n) ; i++)
  {

    printf( " %c" , square[i/n][i%n] ) ;

    if( i% n == n-1) printf("\n") ; //przechodzenie do  nowej linii

  }


/*
stare wyswitlanie
  for(int i=0 ; i < n ; i++)
  {

    for(int j=0 ; j <n ; j++)
    {
      printf(" %c ", square[i][j]);
    }
    printf("\n");

  } */

  //zwalnianie pamieci
  for(int i=0 ; i <n ; i++)
     delete [] square [i];

 delete [] square ;


}
