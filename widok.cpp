#include "widok.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <conio.h>
using namespace std;
string tab[4][30][30];

void widok::statki(){
	cout << "Ile statkow 2 masztowych? ";
	cin >> dwa;
	cout << "Ile statkow 3 masztowych? ";
	cin >> trzy;
	cout << "Ile statkow 4 masztowych? ";
	cin >> cztery;
	cout << "Ile statkow 5 masztowych? ";
	cin >> piec;
}
void widok::statki_u(int n, int l,string s)
{
	system("cls");
   	plansza(n);
	int x,y,i;
	char z;
	cout << "Podaj pierwsze wspolzedne statku o " << l << " masztach wiersz X kolumna: ";
	cin >> x >> y;
	if(x < 1 || x > 31 || y < 1 || y > 31){
		cout << "Nie ma takich wymiarow\n";
		Sleep(2000);
		statki_u(n,l,s);
		return ;
	}
	cout << "L - na lewo,\tP - na prawo,\tG - w gore,\tD - w dol\n";
	cin >> z;
	if(toupper(z) != 'L' && toupper(z) != 'P' && toupper(z) != 'G' && toupper(z) != 'D')
	{
		cout << "Nie ma takiego kierunku\n";
		Sleep(2000);
		statki_u(n,l,s);
		return ;
	}
cout << "Co jest?\n";
	if((x - l < 0 && toupper(z) == 'G')|| (x + l > 31 && toupper(z) == 'D') || (y - l < 0 && toupper(z) == 'L') || (y + l > 31 && toupper(z) == 'P'))
	{
		cout << "Statki sie nie zmieszcza\n";
		Sleep(2000);
		statki_u(n,l,s);
		return ;
	}
	
	x--;
	y--;
	if(tab[n][x][y] != "*")
	{
		cout << "Cos juz tam jest\n";
		Sleep(2000);
		statki_u(n,l,s);
		return ;
	}
		
	// Czy jest tam juz jakis statek
	for(i = 1;i < l;i++)
	{
		cout << "Dzialamy\n";
		if(tab[n][x-i][y] != "*" || tab[n][x+i][y] != "*" || tab[n][x][y+i] != "*" || tab[n][x][y-i] != "*")
		{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
			statki_u(n,l,s);
			return ;
		}
	}
	
	if(tab[n][x-1][y+1] != "*" || tab[n][x+1][y-1] != "*" || tab[n][x+1][y+1] != "*" || tab[n][x-1][y-1] != "*")
	{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
			statki_u(n,l,s);
			return ;
	}
	cout << "TU\n";
	
	// sprawdzam rogi
	
	if(toupper(z) == 'P')
	{
		if(tab[n][x-1][y-1] != "*" ||tab[n][x-1][y+l] != "*" ||tab[n][x+1][y-1] != "*" ||tab[n][x+1][y+l] != "*" )
		{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
			statki_u(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'L')
	{
		if(tab[n][x-1][y-l] != "*" ||tab[n][x-1][y+1] != "*" ||tab[n][x+1][y-l] != "*" ||tab[n][x+1][y+1] != "*" )
		{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
			statki_u(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'D')
	{
		if(tab[n][x-1][y-1] != "*" ||tab[n][x-1][y+1] != "*" ||tab[n][x+l][y-1] != "*" ||tab[n][x+l][y+1] != "*" )
		{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
			statki_u(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'G')
	{
		if(tab[n][x-l][y-1] != "*" ||tab[n][x-l][y+1] != "*" ||tab[n][x+1][y-1] != "*" ||tab[n][x+1][y+1] != "*" )
		{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
			statki_u(n,l,s);
			return ;
		}
	}

	cout << "Dziala\n";
	
	tab[n][x][y] = s;
	for(i = 1;i < l;i++)
	{
		if(toupper(z) == 'G')
			tab[n][x-i][y] = s;
		if(toupper(z) == 'D')
			tab[n][x+i][y] = s;
		if(toupper(z) == 'P')
			tab[n][x][y+i] = s;
		if(toupper(z) == 'L')
			tab[n][x][y-i] = s;
	}
	
		
		//Sleep(2000);
}


void widok::uzupelnianie(int n)
{
	int i;
	int s = dwa + trzy + cztery + piec;

	for(i = 0;i < dwa;i++)
	{
		statki_u(n,2,"2");	
	}
	for(i = 0;i < trzy;i++)
	{
		statki_u(n,3,"3");	
	}
	for(i = 0;i < cztery;i++)
	{
		statki_u(n,4,"4");	
	}
	for(i = 0;i < piec;i++)
	{
		statki_u(n,5,"5");	
	}
	
   	plansza(n);
}

void widok::plansza(int n)
{
	int i, j;
            
    if(n == 0)
    	cout << "A";
    else
    	cout << "B";
    cout << "  ";
    for (i = 1;i < 31;i++) {
        cout << i << " ";
        if (i < 10)
            cout << " ";
    }
    cout << "\n";

    for (i = 0;i < 30;i++)
    {
        cout << i + 1 << " ";
        if (i < 9)
            cout << " ";
        for (j = 0;j < 30;j++)
            cout << tab[n][i][j] << "  ";
        cout << endl;
    }
    
}

void widok::plansza_tworzenie(int n)
{
    int i, j;
    for (i = 0;i < 30;i++)
        for (j = 0;j < 30;j++)
            tab[n][i][j] = "*";
   
}
