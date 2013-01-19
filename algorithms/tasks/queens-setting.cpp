/* T is a two-dimensional array representing chessboard of size MxM, check if it's possible to insert N queens in the way
 * they cannot attack themselves */

#include <iostream>
using namespace std;

#define CB_SIZE 8 // rozmiar szachownicy
#define FOUND 1 // to samo co true
#define DONTFOUND 0 // to samo co false
#define EMPTY 0 // pustym elementom nadaje wartość 0
#define QUEEN 1 // tam gdzie jest królowa 1
#define TAKEN 2 // tam gdzie jej nie może być 2

void take(int chessboard[CB_SIZE][CB_SIZE], int row, int column){

    for(int i = column + 1; i < CB_SIZE; i++) // right
        chessboard[row][i] = TAKEN;

    for(int i = column - 1; i >= 0; i--) // left
        chessboard[row][i] = TAKEN;

    for(int i = row + 1; i < CB_SIZE; i++) // down
        chessboard[i][column] = TAKEN;

    for(int i = row - 1; i >= 0; i--) // up
        chessboard[i][column] = TAKEN;

    for(int i = row + 1, j = column + 1; i < CB_SIZE && j < CB_SIZE; i++, j++) // down - right
        chessboard[i][j] = TAKEN;

    for(int i = row - 1, j = column + 1; i >= 0 && j < CB_SIZE; i--, j++) // up - right
        chessboard[i][j] = TAKEN;

    for(int i = row + 1, j = column - 1; i < CB_SIZE && j >= 0; i++, j--) // up - left
        chessboard[i][j] = TAKEN;

    for(int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) // down - left
        chessboard[i][j] = TAKEN;

}


bool set(int chessboard[CB_SIZE][CB_SIZE], const int row, const int column, const int occurrences, int found, const bool start){
    /*
     * IC:
     *     - chessboard - two-dimensional array of integers of size MxM
     *     - 0 <= row, column < M - try to put queen here; at initialization values are not important - used when
     *       recursion occurs.  
     *     - occurrences - how many times (N) queen should be set on chessboard
     *     - found - counter of set queens; at initialization found = 0 
     *     - at initialization start = true
     * PC:
     *     - if return true - chessboard is array which contains information where queens could be placed (queens are
     *       marked as 1;
     *     - if return false - it's not possible to put N queens on chessboard of given size
     *
     * TC:
     *     O(N^N) - depends on size of array
     */

    if(start){ // jeśli funkcja została wywołana przez inną oznacz wszystkie pola jako puste
        for(int i = 0; i < CB_SIZE; i++){
            for(int j = 0; j < CB_SIZE; j++){
                chessboard[i][j] = EMPTY;
            }
        }
        found = 0; // dla pewności zeruje licznik wystąpień
    }
    else{ // jeśli nastąpiło wywołanie rekurencyjne (rozróżnienie jest potrzebne, gdyż na początku funkcja operuje na tablicy podanej jako pierwszy argument 
        chessboard[row][column] = QUEEN;  // oznacza podany element jako królową - jeżeli stało by się to na początkowej tablicy, na podstawie której tworzone są tymczasowe tablice, to pierwsza królowa mogła by zostać umieszczona tylko na pozycji podanej jako drugi i trzeci argument (row i column)
        found++; // zwiększa licznik wystąpień
        take(chessboard, row, column); // oznacza elementy w pionie, poziomie i po przekątnych jako te, na których nie można postawić królowej
    }

    int (*temp)[CB_SIZE] = new int[CB_SIZE][CB_SIZE]; // tworzy tymczasową dwuwymiarową tablicę

    for(int i = 0; i < CB_SIZE; i++){ // sprawdza każdy element z tablicy podanej w pierwszym argumencie
        for(int j = 0; j < CB_SIZE; j++){ 
            if(chessboard[i][j] == EMPTY){ // jeżeli jest on pusty (można wstawić królową)
                for(int m = 0; m < CB_SIZE; m++){ // kopiuje obecną tablicę do tymczasowej
                    for(int n = 0; n < CB_SIZE; n++){ 
                        temp[m][n] = chessboard[m][n];
                    }
                }
                if(set(temp, i, j, occurrences, found, false) == FOUND){ // wywołanie rekurencyjne - jeśli któreś z następnych wywołań wstawiło odpowiednią ilość królowych
                    for(int i = 0; i < CB_SIZE; i++){ // kopiuje pola z tego wywołania do obecnej tablicy - jeśli jest to pierwsze wywołanie funkcji to obecną tablicą jest ta podana jako pierwszy argument funkcji
                        for(int j = 0; j < CB_SIZE; j++){
                            chessboard[i][j] = temp[i][j];
                        }
                    }
                    delete [] temp; // informacje znajdujące się w tymczasowej tablicy (temp) są już zachowane w obecnej (chessboard) - tej do której dostęp ma poprzednie wywołanie; więc zmienną tymczasową można już zwolnić
                    return FOUND; // przekazuje informację do poprzedniego wywołania, że w obecnej tablicy znajdują się prawidłowe wartości, więc nie trzeba sprawdzać już kolejnych wolnych miejsc - funkcja wraca przez poprzednie wywołania aż do pierwszego
                }
            }
        }
    }
    if(found == occurrences){ // jeśli wstawiono N królowych, zwraca informację do poprzedniego wywołania, że w obecnej tablicy znajdują się prawidłowe wartości; w tym momencie musiało nastąpić co najmniej N wywołań funkcji; poprzednie "return FOUND" służy jedynie do przekazywania informacji z tego wywołania 
        return FOUND;
    }
    delete [] temp; // jeśli w obecnej tablicy sprawdzono wszystkie miejsca gdzie można wstawić królową i żadnego nie znaleziono to kolejne wywołanie funkcji nawet nie nastąpiło, więc w tymczasowej tablicy nie ma nic ciekawego i można ją usunąć 
    return DONTFOUND; // zwraca informację do poprzedniego wywołania, że nie znaleziono odpowiedniego układu i można sprawdzić kolejne wolne miejsce (w tablicy poprzedniego wywołania)
}

/*
 * (0) na początku mamy pustą tablicę
 *
 * 0 0 0
 * 0 0 0
 * 0 0 0
 *
 * (1) załóżmy, że trzeba wstawić 3 królowe; na początku sprawdzany jest element o indeksie [0][0] z tego elementu następuje
 * wywołanie rekurencyjne na tym elemencie w którym na początku królowa oznaczona jest przez 1
 *
 *>0 0 0
 * 0 0 0
 * 0 0 0
 *
 * (2) elementy w których nie można królowej oznaczane są przez 2
 * 1 2 2
 * 2 2 0
 * 2 0 2
 *
 * (3) wyszukiwany jest element w który można wstawić królową
 *
 * 1 2 2
 * 2 2>0
 * 2 0 2
 *
 * (4) i następuje kolejne wywołanie, skierowane na ten element 
 * 1 2 2
 * 2 2 1
 * 2 2 2
 *
 * (5) gdyby trzeba było wstawić 2 królowe to w tym momencie efektem działania funkcji była by prawda
 * ale nie jest, następuje powrót do stanu (3) i wyszukiwany jest kolejny element 
 *
 * 1 2 2
 * 2 2 0
 * 2>0 2
 *
 * (6) i na niego wywoływana jest ponownie funkcja set
 *
 * 1 2 2
 * 2 2 2
 * 2 1 2
 *
 * (7) znowu funkcja zwraca fałsz; więc następuje powrót do stanu (0)
 *
 * 0>0 0
 * 0 0 0
 * 0 0 0
 *
 * (8) i po wywołaniu funkcji set:
 *
 * 2 1 2
 * 2 2 2
 * 0 2 0
 *
 * i tak dalej...
 * 
 * schemat wywołań funkcji
 *
 * - (1) set(...)
 *   > (3) set(...)
 *     * (4) return DONTFOUND
 *   > (5) set(...)
 *     * (6) return DONTFOUND
 * - (7) set(...)
 *   > (8) set(...)
 *     * ...
 *   > ...
 * .
 * .
 * .
 *     * return DONTFOUND
 *   > return DONTFOUND
 * - return DONTFOUND
 *
 * gdyby trzeba było znaleźć 2 miejsca w których można wstawić królową:
 *
 * - (1) set(...)
 *   > (3) set(...)
 *     * (4) return FOUND
 *   > return FOUND
 * - return FOUND
 */ 

int main(int argc, char const* argv[])
{
    int temp[CB_SIZE][CB_SIZE];
    
    set(temp, 0, 0, 8, 0, true); // przykładowe wywołanie funkcji

    char fig;
    for(int i = 0; i < CB_SIZE; i++){
        for(int j = 0; j < CB_SIZE; j++){
            int x = temp[i][j];
            switch (x) {
                case QUEEN:
                    fig = 'x';
                    break;
                case TAKEN:
                    fig = 'o';
                    break;
                case EMPTY:
                    fig = '0';
            }
            cout << fig << ' ';

        }
        cout << endl;
    }
     
    return 0;
}
