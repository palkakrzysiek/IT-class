#include<iostream>
using namespace std;

int count_chars(char *text){
    int i = 0;
    while (text[i] != 0){
        ++i;
    }
    return i;
}

int compare(char *txt1, char *txt2){
    int r, i = 0;
    do{
        r = txt2[i] - txt1[i];
        i++;
    } while( (r==0) && ((txt1[i] != 0) || (txt2[i] != 0)) );
    return r;
}

int main(){
    char txt[12] = "Hello world";
    cout << txt << ": " << count_chars(txt) << endl;
    txt[5] = 0;
    cout << txt << ": " << count_chars(txt) << endl;
    cout << txt+6 << ": " << count_chars(txt+6) << endl;

    char text1[256], text2[256];
    cin >> text1;
    cin >> text2;
    cout << compare(text1, text2) << endl;
    return 0;
}

