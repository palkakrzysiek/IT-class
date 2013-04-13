#include <iostream>
using namespace std;
int M1[3][3] = {{0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}};

int M2[3][3] = {{0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}};

int M3[3][3] = {{0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}};

int main(int argc, char const* argv[])
{
    bool quit = false;
    bool result = false;
    char response = 'c';


    while(!quit){

    cout << "\E[H\E[2J";

        if(result){
            cout << "Result:" << endl;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << M3[i][j] << " ";
                }
                cout << endl;
            }

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    M1[i][j] =  M3[i][j];
                }
            }

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    M2[i][j] = 0;
                }
            }

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    M3[i][j] = 0;
                }
            }

            result = false;
            cout << "Press enter to continue...";
            cin.get();
            continue;
        }
        else{
            cout << "Matrix 1:" << endl;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << M1[i][j] << " ";
                }
                cout << endl;
            }

            cout << "Matrix 2:" << endl;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << M2[i][j] << " ";
                }
                cout << endl;
            }
        }

        cout << "Menu:\n";
        cout << "1 - insert values into matrix 1" << endl;
        cout << "2 - insert values into matrix 2" << endl;
        cout << "m - multiply matrices" << endl;
        cout << "q - quit" << endl;
        
        response = cin.get();

        switch(response){
            case '1':
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        cout << "[" << i << "][" << j << "] (" << M1[i][j] << ") < ";
                        cin >> M1[i][j];
                    }
                }
                result = false;
                break;

            case '2':
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        cout << "[" << i << "][" << j << "] (" << M2[i][j] << ") < ";
                        cin >> M2[i][j];
                    }
                }
                result = false;
                break;

            case 'm':
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        for(int k = 0; k < 3; k++){
                            M3[i][j] += M1[i][k] * M2[k][j];
                        }
                    }
                }
                result = true;
                break;
                


            case 'q':
                quit = true;
                break;
        }


    }
    
    return 0;
}
