#include "model_isinga.h"
#include <iostream>

using namespace std;

/**
 * @file
 * Główna funkcja programu.
 * Tworzy model próbki ferromagnetycznej o danej wielkości, wprowadza do niego
 * zadaną ilość energii (układ mikrokanoniczny) i oblicza statystyki
 * (temperatura, magnetyzacja itp.)
 * Obecna postać ma charakter czysto demonstracyjny,
 * ponieważ uwzględnia tylko jedną wielkość siatki i jedną wartość energii
 * docelowej. <b> Przy realizacji zadań z instrukcji należy użyć zagnieżdżonej
 * pętli po wielkościach siatki i energiach docelowych (Zadanie 1 – układ
 * mikrokanoniczny), względnie po wielkościach siatki i temperaturach (Zadanie 2
 * – układ kanoniczny).
 * </b>
 */
int main(int argc, char* argv[]) {
    int L = 10;
    for (int E = -184; E <= -24; E += 8) {
        ModelIsinga ising(L, E);
        ising.doprowadzenie_do_stanu_rownowagi(1000);
        ising.zliczanie_srednich(1000);
        printf("%d,\t%d,\t%f,\t%f,\t%f,\t%f\n", E, L,
               ising.podaj_srednia_energie_ukladu(),
               ising.podaj_srednia_energie_duszka(),
               ising.podaj_srednia_magnetyzacje(), ising.podaj_temperature());
    }
    L = 20;
    for (int E = -768; E <= -32; E += 32) {
        ModelIsinga ising(L, E);
        ising.doprowadzenie_do_stanu_rownowagi(1000);
        ising.zliczanie_srednich(1000);
        printf("%d,\t%d,\t%f,\t%f,\t%f,\t%f\n", E, L,
               ising.podaj_srednia_energie_ukladu(),
               ising.podaj_srednia_energie_duszka(),
               ising.podaj_srednia_magnetyzacje(), ising.podaj_temperature());
    }
    L = 40;
    for (int E = -3072; E <= -128; E += 128) {
        ModelIsinga ising(L, E);
        ising.doprowadzenie_do_stanu_rownowagi(1000);
        ising.zliczanie_srednich(1000);
        printf("%d,\t%d,\t%f,\t%f,\t%f,\t%f\n", E, L,
               ising.podaj_srednia_energie_ukladu(),
               ising.podaj_srednia_energie_duszka(),
               ising.podaj_srednia_magnetyzacje(), ising.podaj_temperature());
    }

    return 0;
}
