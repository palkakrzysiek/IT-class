#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0));
    int option;
    option = (2 + (rand() % 3))*2; // {4, 6, 8}
    cout << "Variant: " << option << endl;
    if (option == 4) {
        cout << "Enter subsequent values separated by spaces on return key\n";
        int min, max, temp = 0;
        bool init = false;
        while (cin >> temp && temp != 0) {
            if (!init) {
                init = true;
                min = max = temp;
            }
            else {
                if (temp > max)
                    max = temp;
                else if (temp < min)
                    min = temp;
            }
        }
        cout << "Wrong input character or 0 has been given\n";
        if (init) {
            cout << "Min val = " << min << ", max val = " << max << endl;
        }
        else {
            cout << "There was no input";
        }
    }
    else if (option == 6) {
        int arr[17];
        int sum = 0;
        int oddCount = 0;
        double avg = 0;

        for (int i = 0; i < 17; i++){
            arr[i] = rand();
            if (arr[i] % 2 == 1) {
                sum += arr[1];
                oddCount++;
            }
        }
        avg = double(sum) / oddCount;
        for (int i = 0; i < 17; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Avg: " << avg << endl;

        int aboveAvg, belowAvg;
		aboveAvg = belowAvg= 0;
        for (int i = 0; i < 17; i++) {
            if (arr[i] > avg)
                aboveAvg++;
            else if (arr[i] < avg)
                belowAvg++;

        }

        cout << aboveAvg << " values are greater then the average\n";
        cout << belowAvg << " values are lower then the average\n";

    }
    else {
        int arr[5][6];
        int minRow[5];
        int maxRow[5];
        int minCol[6];
        int maxCol[6];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                arr[i][j] = rand();
                if (i == 0) {
                    minCol[i] = maxCol[i] = arr[i][j];
                }
                if (j == 0) {
                    minRow[j] = maxRow[j] = arr[i][j];
                }
                if (arr[i][j] > minRow[i]) {
                    minRow[i] = arr[i][j];
                }
                if (arr[i][j] < maxRow[i]) {
                    maxRow[i] = arr[i][j];
                }
                if (arr[i][j] > minCol[j]) {
                    minCol[j] = arr[i][j];
                }
                if (arr[i][j] < maxCol[j]) {
                    maxCol[j] = arr[i][j];
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                arr[i][j] = rand();
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
        for(int i = 0; i < 5; i++){
        
        cout << "Min col" << i << ": " << minCol[i] << endl;
    	cout << "Max col" << i << ": " << maxCol[i] << endl;
    }
    for(int i = 0; i < 6; i++){
        cout << "Min row" << i << ": " << minRow[i] << endl;
    	cout << "Max row" << i << ": " << maxRow[i] << endl;
    }
    }


    return 0;
}
