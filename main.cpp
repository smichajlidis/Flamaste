/*FLAMASTE - Flamaster

Autor: Michał Franczak

Kasia niedawno poznała wszystkie literki w szkole. Z wielką pasją potrafiła całe dnie spędzać na pisaniu
długich słów swoim ulubionym flamastrem. Pisała i pisała "tasiemce" tak długo, aż flamaster wypisał się.
Kasia posmutniała. Z trudem, ale udało jej się uprosić swoją mamę, aby kupiła jej nowy pisak.
Musiała jednak obiecać, że tym razem będzie bardziej oszczędna przy jego używaniu żeby wystarczył na
dłużej. Kasia zaczęła zastanawiać się w jaki sposób będzie mogła zrealizować obietnicę daną mamie.

Postanowiła, że aby zaoszczędzić wkład flamastra będzie wypisywała skróconą wersję wymyślanych wyrazów.
Jeśli miała zamiar napisać więcej niż dwie takie same literki obok siebie w wyrazie, to teraz napisze
literkę a następnie liczbę, określającą ilość wystąpień tej literki.

Zadanie

Twoim zadaniem jest dla zadanego wyrazu, który wymyśliła Kasia, podanie skróconej wersji tego wyrazu.

Wejście
W pierwszej linijce wejścia znajduje się liczba naturalna C, 1 ≤ C ≤ 50, oznaczająca ilość zestawów danych.
W kolejnych C wierszach wejścia znajdują się zestawy danych. Każdy zestaw składa się z niepustego wyrazu
złożonego z samych dużych liter alfabetu amerykańskiego. Długość wyrazu nie przekracza 200 znaków.

Wyjście
Dla każdego zestawu danych, dla zadanego wyrazu, na wyjściu powinna znaleźć się jego skrócona wersja.

Przykład

Dla danych wejściowych:
4
OPSS
ABCDEF
ABBCCCDDDDEEEEEFGGHIIJKKKL
AAAAAAAAAABBBBBBBBBBBBBBBB

prawidłowym rozwiązaniem jest:

OPSS
ABCDEF
ABBC3D4E5FGGHIIJK3L
A10B16*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void int_to_char(int, vector <string> &array, const int &j);

int main() {
    
    int how_many {};
    
    do {
    cin >> how_many;
    } while (how_many < 1 || how_many > 50);
    
    vector <string> array(how_many);
    string word {};
    
    for (int j {0}; j < how_many; j++) {
        
        do {
            cin >> word; 
        } while (word.length() < 1 || word.length() > 200);
        
        char character_1 {'a'};
        int count {0};
        
        for (size_t i {0}; i < word.length(); i++) {
            
            if (word[i] != character_1 && count == 0) {
                character_1 = word[i];
                array[j].push_back(word[i]);
            }
            else if (word[i] != character_1 && count > 1) {
                
                int_to_char(count, array, j); 
                array[j].push_back(word[i]);
                character_1 = word[i];
                count = 0;
            }
            else if (word[i] != character_1 && count == 1) {
                array[j].push_back(character_1);
                array[j].push_back(word[i]);
                count = 0;
            }
            else if (word[i] == character_1) {
                
                if (i == word.length()-1 && count > 1)
                
                  int_to_char(count, array, j);
                    
    
    
                    
                else if (i == word.length()-1 && count == 1)
                    array[j].push_back(word[i]);
                else if (count >= 0)
                    count ++;
            }
    
        }
    }
    
    for(auto n: array)
        cout << n << "\n";

    return 0;
}

void int_to_char(int count, vector <string> &array, const int &j) {
                           count++;
    if (count < 10)
        array[j].push_back(count + '0');
    else if (count < 100) {
        array[j].push_back(floor(count/10) + '0');
        array[j].push_back(count%10 + '0');
    }
    else if (count > 100 && count < 199) {
        array[j].push_back(1+'0');
        array[j].push_back(floor((count-100)/10) + '0');
        array[j].push_back(count%10 + '0');
    }
    else {
        array[j].push_back(2+'0');
        array[j].push_back(0+'0');
        array[j].push_back(0+'0');
    }
}