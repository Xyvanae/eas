#include<iostream>
using namespace std;
 
void sito(bool *tab, unsigned int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (!tab[i])
        {
            for (int j = i * i; j <= n; j += i)
                tab[j] = true;
        }
    }
}
 
// 1. wypisz liczby bliźniacze
void wypiszBlizniacze(bool *tab, int n)
{
    for (int i = 2; i <= n - 2; i++)
    {
        if (!tab[i] && !tab[i + 2])
        {
            cout << "(" << i << ", " << i + 2 << ") ";
        }
    }
    cout << endl;
}
 
// 2. policz ile ich jest
int ileBlizniaczych(bool *tab, int n)
{
    int licznik = 0;
    for (int i = 2; i <= n - 2; i++)
    {
        if (!tab[i] && !tab[i + 2])
        {
            licznik++;
        }
    }
    return licznik;
}
 
// 3. suma liczb bliźniaczych (sumujemy wszystkie liczby z par)
long long sumaBlizniaczych(bool *tab, int n)
{
    long long suma = 0;
    for (int i = 2; i <= n - 2; i++)
    {
        if (!tab[i] && !tab[i + 2])
        {
            suma += i + (i + 2);
        }
    }
    return suma;
}
 
int main()
{
    int n = 1000000;
 
    bool *tab = new bool[n + 1];
 
    for (int i = 0; i <= n; i++)
        tab[i] = false;
 
    tab[0] = tab[1] = true;
 
    sito(tab, n);
 
     cout << "Liczby Bliźniacze - 28.04.2026" << endl << endl;
 
    cout << "Liczby bliźniacze:\n";
    wypiszBlizniacze(tab, n);
 
    cout << "\nIle par: " << ileBlizniaczych(tab, n) << endl;
 
    cout << "Suma liczb bliźniaczych: " << sumaBlizniaczych(tab, n) << endl;
 
    delete[] tab;
    return 0;
}