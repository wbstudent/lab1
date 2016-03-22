#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

bool allocating_error = 0;//0, gdy wszystko przebiegło w porządku, 1, gdy wystąpił błąd przy tworzeniu kwadratu
const int max_side_length = 75;

int main(int argc, char **argv)
{
	int n = -1;
	if( !(argc == 2 || argc == 3) )
	{
		printf("Nieodpowiednia liczba argumentów!\nUżycie: ./lab1 długość_boku [seed_value]");
		return 1;
	}

	if (argc == 3)
		srand(atoi(argv[2]));
	else
		srand(time(NULL));

	n = atoi(argv[1]);
	if(n < 1 || n > max_side_length + 1)
	{
		printf("Długość boku musi być zawarta w przedziale <1, %d>", max_side_length);
		return 2;
	}

	drawCharSquare(charSquare(n), n);

	if(allocating_error == 0)
		return 0;
	return 3;
}	

char **charSquare(int n)
{
	char **square;
	square = new char*[n];
	if(square == NULL)
		return NULL;

	//alokowanie pamięci na kwadrat
	for(int i = 0; i < n; i++)
	{
		square[i] = new char[n];
		if(square[i] == NULL)
			return NULL;
	}

	//wypełnienie kwadratu
	for(int i = 0; i < n*n; i++)
	{
		square[i/n][i%n] = (char)('a' + rand()%('z'-'a' + 1));
	}

	return square;
}

void drawCharSquare(char **square, int n)
{	
	if(square == NULL)
	{
		printf("Nastąpił błąd przy tworzeniu kwadratu.\n");
		allocating_error = 1;
		return;
	}
	for(int i = 0; i < n*n; i++)
	{
		printf("%c%c", square[i/n][i%n], (i%n == n-1) ? '\n' : ' ');
	}

	for(int i = 0; i < n; i++)
		delete[] square[i];
	delete[] square;	
}