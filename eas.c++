#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
// funkcja wykonująca całe zadanie
void sortowanie() {
    const int N = 50000;
    int tab[N];
 
    // losowanie liczb 0-999
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        tab[i] = rand() % 1000;
    }
 
    // start czasu
    clock_t start = clock();
 
    // sortowanie kubełkowe
    int buckets[1000] = {0};
 
    // zliczanie wystąpień
    for(int i = 0; i < N; i++) {
        buckets[tab[i]]++;
    }
 
    // odtwarzanie posortowanej tablicy
    int index = 0;
    for(int i = 0; i < 1000; i++) {
        while(buckets[i] > 0) {
            tab[index] = i;
            index++;
            buckets[i]--;
        }
    }
 
    // koniec czasu
    clock_t end = clock();
    double czas = (double)(end - start) / CLOCKS_PER_SEC;
 
    // zapis do pliku
    ofstream plik("wynik.txt");
 
    for(int i = 0; i < N; i++) {
        plik << tab[i] << " ";
    }
 
    plik << endl;
    plik << "Czas: " << czas << " sekundy";
 
    plik.close();
 
    // komunikat na ekran
    cout << "Gotowe! Wynik zapisany do pliku." << endl;
    cout << "Czas: " << czas << " sekundy" << endl;
}
 
int main() {
    sortowanie(); // wywołanie funkcji
    return 0;
}