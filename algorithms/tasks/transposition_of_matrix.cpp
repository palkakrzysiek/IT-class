/* 1. Let T be a square two dimensional array of a natural numbers MxM. Perform in-place transposition of T. */

#include <iostream>

int main(int argc, char const* argv[])
{
    int matrix[4][4] = {{1, 2, 3, 4},
					  {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}}; // tworzy macierz kwadratową 4x4
    
    int M = 4;

    for (int i = 0; i < M; i++){
        for (int j = 0; j < M; j++){
            std::cout << matrix[i][j] << ' '; // (dla sprawdzenia) wyświetla ją
        }
        std::cout << std::endl;
    }
    

    for (int i = 0; i < M; i++){ // i przyjmuje po kolei numer każdej linii
        for (int j = i + 1; j < M; j++){ // j przyjmuje po kolei numer wiersza, tak aby zamiana odbywała się po skosie
            int temp = matrix[i][j]; // zmienna tymczasowa, aby odzyskać nadpisaną wartość
            matrix[i][j] = matrix[j][i]; 
            matrix[j][i] = temp;
        }
    }
    /* pętla będzie przyjmie dla 'i' i 'j' elementy oznaczone przez 'x'
     *
     *  o x x x
     *  o o x x
     *  o o o x
     *  o o o o
     *
     *  Po skosie zamiana jest po prostu niepotrzebna, a gdyby zamiana zadziałała na elementach pod przekątną, to
     *  wróciły by one na swoje miejsce np. na początku zamienione zostały by matrix[0][1] z matrix[1][0], a gdyby
     *  zamiana dotyczyła wszystkich elementów, to dla i = 1 i j = 0 nastąpiła by ponowna zamiana matrix[1][0] z
     *  matrix[0][1]. 
     */

    for (int i = 0; i < M; i++){
        for (int j = 0; j < M; j++){
            std::cout << matrix[i][j] << ' '; // (dla sprawdzenia) wyświetla transponowaną macierz 

        }
        std::cout << std::endl;
    }

    return 0;
}
