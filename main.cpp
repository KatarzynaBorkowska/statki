#include "widok.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;
int main()
{
    widok S;
 	S.statki();
    // tworzenie planszy A
    S.plansza_tworzenie(0);// widzi swoja gracz A
    S.plansza_tworzenie(1);  // ta widzi gracz B
    S.uzupelnianie(0);
    Sleep(2000);
    system("cls");
    cout << "Oddaj plansze przeciwnikowi\n";
    Sleep(5000);
    cout << "\n";
    system("cls");
    
    // tworzenie planszy B
    S.plansza_tworzenie(2); // widzi swoja gracz B
    S.plansza_tworzenie(3); // ta widzi gracz A
    S.uzupelnianie(2);		


    return 0;
}
