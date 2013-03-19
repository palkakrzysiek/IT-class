#include <iostream>
using namespace std;

void fun1(){
    int secret = 15;
    int guess = 0;
    while (secret != guess){
        cout << "guest the number form 0 to 100: ";
        cin >> guess;
    }
}

void fun2(){
    int secret = 15;
    int guess;
    do{
        cout << "guest the number form 0 to 100: ";
        cin >> guess;
    } while(secret != guess);
}

#include <cmath>
void fun3(){
    // roots of quadratic equations
    int a, b, c;
    cin >> a, b, c;
    float delta = b*b - 4*a*c;
    if (delta < 0)
        cout << "there are no real solutions" << endl;
    else if (delta == 0)
        cout << "the single root is " << -b/(2*a) << endl;
    else
        cout << "first root is " << (-b -sqrt(delta))/(2*a) << " and the second is " << (-b -sqrt(delta))/(2*a)  << endl;
}
void fun4(){
    int secret = 15;
    int guess;
    do{
        cout << "guest the number form 0 to 100: ";
        cin >> guess;
        if (guess < secret)
            cout << "your value is too small" << endl;
        if (guess > secret)
            cout << "your value is too big" << endl;
    } while(secret != guess);
    cout << "you got it!" << endl;
}

 void fun5(){
     for(int i = 0; i < 128; i = i+1){
         if (i!=26)
             cout << " value: " << i << " character: " << char(i) << endl;
     }
 }

void fun6(){
    int given , result = 1;
    cin >> given;
    for (int i = 1; i <= given; i++)
        result *= i;
    cout << result;
}

void fun7(){
    for (int i =0; i < 100; i++){
        if (i%2) continue;
        if (i>50) break;
        cout << i << endl;
    }
}

void fun8(){
    bool quit = false;
    while (quit == false){
       cout << "Select a, b, c or q to quit: ";
       char response;
       cin >> response;
       switch(response){
           case 'a':
               cout << "You chose 'a'" << endl;
               break;
           case 'b':
               cout << "You chose 'b'" << endl;
               break;
           case 'c':
               cout << "You chose 'c'" << endl;
               break;
           case 'q':
               cout << "quitting menu" << endl;
               quit = true;
               break;
           default:
               cout << "wrong choice" << endl;
       }
    }
}

#include <ctime>
#include <stdlib.h>
void fun9(){
    cout << "Enter an integer value: " << endl;
    int a;
    cin >> a;
    srandom(time(0));
    a+=rand();
    a%=3;
    switch(a){
        case 0:
            cout << "You lose all your money" << endl;
            break;
        case 1:
            cout << "You win a TV set " << endl;
            break;
        case 2:
            cout << "You win a car" << endl;
    }
}

typedef unsigned int Ala;
void fun10(){
    Ala x = 20, y = 10;
    cout << x << " " << y << endl;
}

int main(){
    fun10();
    return 0;
}
