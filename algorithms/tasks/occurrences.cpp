/* Let T and P be strings. Find how many times P appears in T – appearances can overlap. */
#include <cstdio>
int occurrences(char *T, int M, char *P, int N){
    if(N > M)
        return 0; // jeśli ciąg P jest dłuższy od T, to na pewno w nim nie wystąpi.
    int counter = 0;
    for(int i = 0; i < M; i++){ // sprawdza po kolei każdy znak ciągu T
        for(int j = 0; j < N; j++){ // to samo dla P
            if (T[i + j] == P[j]) {  // jeśli odpowiednie znaki się zgadzają (nie ma T[i] bo w takim wypadku za każdym razem porównywany był by ten sam znak, jeśli sprawdzany jest kolejny znak z P, to musi być sprawdzony również koleiny z T.
                if (j == N - 1) // jeśli zgadza się cały string P - jego licznik osiągnął wartość ilości jego elementów (pomniejszoną o 1 - elementy tablicy są numerowane od 0)
                    counter++; // zwiększ licznik
            }
            else
                break; // jeśli odpowiednie znaki się nie zgadzają to nie ma sensu sprawdzać dalej - następuje sprawdzenie kolejnego elementu z tablicy T.
        }
    }
    return counter;
}

int main(int argc, char const* argv[])
{
    char a[] = "abababaaba";
    char b[] = "aba";
    printf("%d\n", occurrences(a, sizeof(a) - 1, b, sizeof(b) - 1));

    return 0;
}
