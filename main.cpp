#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

const int MAX_SIDE_LENGTH = 75;

int main(int argc, char **argv)
{

	if( !(argc == 2 || argc == 3) )
	{
		printf("Nieodpowiednia liczba argumentów!\nUżycie: ./lab1 długość_boku [seed_value]");
		return 1;
	}

	if (argc == 3)
		srand(atoi(argv[2]));
	else
		srand(time(NULL));

	int n = -1;
	n = atoi(argv[1]);
	if(n < 1 || n > MAX_SIDE_LENGTH + 1)
	{
		printf("Długość boku musi być zawarta w przedziale <1, %d>", MAX_SIDE_LENGTH);
		return 2;
	}

	drawCharSquare(charSquare(n), n);
}	

char **charSquare(int n)
{
	char **square;
	square = new char*[n];

	//Tworzenie
	for(int i = 0; i < n; i++)
		square[i] = new char[n];

	//Wypełnienie kwadratu
	for(int i = 0; i < n*n; i++)
	{
		square[i/n][i%n] = (char)('a' + rand()%('z'-'a' + 1) );
	}

	return square;
}

void drawCharSquare(char **square, int n)
{	
	for(int i = 0; i < n*n; i++)
	{
		printf("%c%c", square[i/n][i%n], (i%n == n-1) ? '\n' : ' ');
	}

	//Usuwanie kwadratu
	for(int i = 0; i < n; i++)
		delete[] square[i];
	delete[] square;	
}