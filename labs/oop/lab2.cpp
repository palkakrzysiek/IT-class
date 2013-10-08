// Debug with: g++ -D_DEBUG -o lab2.o lab2.cpp && ./lab2.o

// Write a program that writes a single statement that for random integer
// performs the specified task (with if or switch):

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;


#ifdef _DEBUG
const int ARRAY_SIZE = 6; // easier to validate
#else
const int ARRAY_SIZE = 20;
#endif
const int MIN_ARRAY_VALUE = -100;
const int MAX_ARRAY_VALUE = 100;
const int NUM_OF_VALS_TO_CHANGE = 2;
const int isArraySizeOdd = ARRAY_SIZE % 2;

int* getRandomArray(int n, int min, int max);
void printarray(int* A, int n);

int main(int argc, char const* argv[])
{
    srandom(time(0));
    int option = (random() % 3) + 4; // values from 4 to 6

    cout << "Option: " << option << endl;

    int *mainArray, *tempArray1, *tempArray2, *tempArray3, *tempArray4;
    int sum, sum_odd, sum_even;
    int tempVal = 0;


    switch (option) {
        case 4:
            // • when the random value is equal 4, creates one-dimensional
            // array with 20 elements and initializes it with random integer.
            // The program return: sum of all elements of this array, sum only
            // of odd elements and sum of even elements

            mainArray = getRandomArray(ARRAY_SIZE, MIN_ARRAY_VALUE, 
                    MAX_ARRAY_VALUE);

            cout << "The array has been created and initialized with "
                 << "following values:\n";
            printarray(mainArray, ARRAY_SIZE);

            sum = sum_odd = sum_even = 0;

            for (int i = 0; i < ARRAY_SIZE; i++) {
                sum += mainArray[i];
                if (i % 2 == 0)
                    sum_even += mainArray[i];
                else
                    sum_odd += mainArray[i];
            }

            cout << "Sum of all elements: " << sum <<
                 "\nSum of odd elements: " << sum_odd <<
                 "\nSum of even elements: " << sum_even << endl; 

            delete [] mainArray;
            break;

        case 5:
            // when the random value is equal 5, creates one-dimensional array
            // with 20 elements and initializes it with random integer. The
            // program enters two indexes of array from
            // user and change the values of these elements.
            
            mainArray = getRandomArray(ARRAY_SIZE, MIN_ARRAY_VALUE, 
                    MAX_ARRAY_VALUE);

            cout << "The array has been created and initialized with "
                 << "following values:\n";
            printarray(mainArray, ARRAY_SIZE);
            for (int i = 0; i < NUM_OF_VALS_TO_CHANGE; i++) {
                cout << "Give the index of value to change: ";
                if (!(cin >> tempVal)) {
                    cout << "Wrong input. Value unchanged or overflowed\n";
                    cin.clear(); // delete eof and failbit
                    // delete all remaining characters in the buffer
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    //             maximum buffer size ^^  or new line sign ^^
                }
                else {
                    if (tempVal < 0 || tempVal >= ARRAY_SIZE) {
                        cout << "Index not in the domain, the value will remain unchanged\n";
                    }
                    else {
                        cout << "Give the value of " << tempVal << ". element: ";
                        if (!(cin >> mainArray[tempVal])) {
                            cout << "Wrong input. Value unchanged or overflowed\n";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                }
            }

            cout << "Now the array looks like:\n";
            printarray(mainArray, ARRAY_SIZE);

            delete [] mainArray;
            break;

        case 6:
            // when the random value is equal 6, creates two one-dimensional
            // array with 20 elements and one of them
            // initializes it with random integer. The program sets elements
            // to the second array from the first one in
            // the following way:

            mainArray = getRandomArray(ARRAY_SIZE, MIN_ARRAY_VALUE, 
                    MAX_ARRAY_VALUE);

            cout << "The array has been created and initialized with "
                 << "following values:\n";
            printarray(mainArray, ARRAY_SIZE);
            
            tempArray1 = new int[ARRAY_SIZE];
            tempArray2 = new int[ARRAY_SIZE];
            tempArray3 = new int[ARRAY_SIZE];
            tempArray4 = new int[ARRAY_SIZE];
            tempVal = 0;

            for (int i = 0; i < ARRAY_SIZE; i++) {

                // o exactly the same;
                tempArray1[i] = mainArray[i];

                // o in opposite way;
                tempArray2[ARRAY_SIZE - i - 1] = mainArray[i];

                // o at first elements with odd indexes, then with even
                // indexes;
                tempArray3[i] = 
                    mainArray[(2 * i + 1) % (ARRAY_SIZE + !isArraySizeOdd)];

                // o put to array sum of two neighbor elements (f.e. A = {1,
                // 2, 3, 4, 5, 6, 7, 8, 9}, then in the second array
                // we will have on the first position sum of first and second
                // element, on second position – sum of
                // second and third element and so on, and the last position
                // sum of the last and first element, thus B =
                // {3, 5, 7, 9, 11, 13, 15, 17, 10}.
                tempArray4[i] = mainArray[i] + mainArray[(i + 1) % ARRAY_SIZE];
            }

            cout << "Copy:\n";
            printarray(tempArray1, ARRAY_SIZE);
            cout << "Reverse:\n";
            printarray(tempArray2, ARRAY_SIZE);
            cout << "Odd indexes first:\n";
            printarray(tempArray3, ARRAY_SIZE);
            cout << "Sum of itself and succeeding neighbor:\n";
            printarray(tempArray4, ARRAY_SIZE);

            delete [] tempArray1;
            delete [] tempArray2;
            delete [] tempArray3;
            delete [] tempArray4;

            delete [] mainArray;
            break;
    }

    return 0;
}

void printarray(int *A, int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << ' ';
    }
    cout.put('\n');
}

int* getRandomArray(int n, int min, int max){
    srandom(time(0));
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = random() % (max - min + 1) + min;
    }
    return arr;
}
