//#include <iostream>
#include <stdlib.h>

//using namespace std;

int addition(int a, int b)
{
	return a+b ;
}

int produit(int a, int b)
{
	return a*b ;
}   

int opp(int a, int b, int (*f)(int, int))
{
	return (*f)(a,b) ;
}

int main(int argc, char *argv[])
{
	int k = opp(4,7, addition) ;  // appel de la fonction passée en param
	printf(":: %d\n", k) ;

	printf("------------------\n" ) ;


	int ((*f)(int, int)) ;    // f: pointeur de fonction
	f = addition ;            // affecfation

	int r = (*f)(1,4) ;       // appel de la fonction pointée
	printf(":: %d\n", r) ;

	printf("------------------\n" ) ; 

	int ((*tabfun[10])(int, int)) ;   // tableau de pointeurs de fonctions

	for (int i=0 ; i<10 ; i++)
	{
		if (i%2) 
			tabfun[i] = produit ;
		else
			tabfun[i] = addition ;
	}

	int temp ;
	for (int i=0 ; i<10 ; i++)
	{
		temp = tabfun[i](4,3) ;   // appel des fonctions pointées par le tableau
		printf(":: %d\n", temp) ;
	}

	//system("PAUSE" );
	return 0;
}
