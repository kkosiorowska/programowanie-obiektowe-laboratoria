
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <cstdlib>

int gcd (int a, int b) ;

struct fraction
{
  int nominator;
  int denominator ;


  bool is_correct()
  {
    return (denominator!= 0) &&  ( abs(nominator) < abs(denominator) ) ;

  }
   void shorten()
   {
     int d = gcd (nominator , denominator) ;
     nominator = nominator /  d ;
     denominator = denominator /  d ;

   }

};

int main(int argc, char **argv)
{
  int n;
  n = atoi (argv[1]);

  srand(time(NULL)); //uruchomienie czasu

  fraction *fractions = new fraction [n] ;

  for(int i =0 ; i < n ; i++)
  {
    do{
          fractions[i] = { rand() % 19 -9 , rand() % 19 -9 } ;

    }while(fractions[i].is_correct() == 0 ) ;

   fractions[i].shorten();

  }



	for (int i = 0; i < n; assert(fractions[i++].is_correct()))
		printf("[%i] %2i / %2i\n",
    i,
    fractions[i].nominator,
    fractions[i].denominator);


     delete[] fractions ;

}

int gcd (int a, int b)
{
   do
   {
      if(a>b) a=a-b;

       else b=b-a;

    } while(a != b);

 return a ;
}
