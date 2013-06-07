#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <cstdlib>

using namespace std;

class sytWyj{
    public:
        sytWyj(string e){
            cout << e << endl;
        }
};

class Osoba{
    private:
        string imie;
        string nazwisko;
        int wiek;

    public:
    Osoba(string im, string naz, int wie){
        this->imie = im;
        this->nazwisko = naz;
        this->wiek = wie;
    }

    string getFirstName(){
        return this->imie;
    }
    string getSenondName(){
        return this->nazwisko;
    }
    int getAge(){
        return this->wiek;
    }

    void setFirstName(string value){
        this->imie = value;
    }
    void setSecondName(string value){
        this->nazwisko = value;
    }
    void setAge(int value){
        this->wiek = value;
    }
};

void readFromFile(list<Osoba> &osoby){
    string filename;
    int currentLine = 0;
    string imie, nazwisko;
    int wiek;
    cout << "Give the name of the file to open\n>";
    cin >> filename;

    ifstream myfile(filename.c_str());
    string line;
    try{
        if (!myfile.is_open()) 
            throw sytWyj("Unable to open a file");
        while ( myfile.good() ) {
          getline (myfile,line);
          if (currentLine % 3 == 0){
              imie = line;
          }
          if (currentLine % 3 == 1){
              nazwisko = line;
          }
          if (currentLine % 3 == 2){
              wiek = atoi(line.c_str());
              cout << "add\n";
              osoby.push_back(Osoba(imie, nazwisko, wiek));
          }
          currentLine++;
        }
        myfile.close();
    }
    catch (sytWyj &e){
        cout << "Unable to open file";
    }
}

void saveToFile(list<Osoba> &osoby){
    string filename;
    cout << "Give the name of the file to create\n>";
    cin >> filename;

    ofstream tempfile;
    tempfile.open(filename.c_str());
    for(list<Osoba>::iterator o = osoby.begin(); o != osoby.end(); ++o){
        tempfile << o->getFirstName() << endl;
        tempfile << o->getSenondName() << endl;
        tempfile << o->getAge() << endl;
    }
    tempfile.close();
}


void deletePerson(list<Osoba> &osoby){
    string decision;
    string searched;
    string imie, nazwisko;
    cout << "What do you want to do?\n\
    1. Delete people with given first name\n\
    2. Delete people with given second name\n\
    3. Delete people with given part of first or second name\n\
    > ";
    cin >> decision;
    cout << "Give phrase to match >";
    cin >> searched;
    list<Osoba>::iterator o = osoby.begin();
    if (decision[0] == '1'){
        while( o != osoby.end()){
            if(o->getFirstName() == searched){
                osoby.erase(o++);
            }
            else{
                ++o;
            }
        }
    }
    if (decision[0] == '2'){
        while( o != osoby.end()){
            if(o->getSenondName() == searched){
                osoby.erase(o++);
            }
            else{
                ++o;
            }
        }
    }
    if (decision[0] == '3'){
        while( o != osoby.end()){
            imie = o->getFirstName();
            nazwisko = o->getSenondName();
            if(string::npos != imie.find(searched) || string::npos != nazwisko.find(searched)){
                osoby.erase(o++);
            }
            else{
                ++o;
            }
        }
    }
}

int main(int argc, char const* argv[])
{
    list<Osoba> osoby;
    string answer;
    string filename;
    string imie, nazwisko;
    ofstream tempfile;
    string line;
    string tempWiek;
    int currentline = 0;
    int wiek;
    bool quit = false;
    while(!quit){
        cout << "What do you want to do? ";
        cin >> answer;
        switch(answer[0]){
            case 'a':
                cout << "give the first name: ";
                cin >> imie;
                cout << "give the second name: ";
                cin >> nazwisko;
                cout << "give the age: ";
                cin >> tempWiek;
                try{
                    int temp = 0;
                    while(tempWiek[temp] != 0){
                        cout << tempWiek[temp];
                        if('0' > tempWiek[temp] || tempWiek[temp] > '9')
                            throw "not a number";
                        temp++;
                    }
                    wiek = atoi(tempWiek.c_str());
                    osoby.push_back(Osoba(imie, nazwisko, wiek));
                }
                catch(char const* e){
                    cout << e;
                }

                break;

            case 'p':
                for(list<Osoba>::iterator o = osoby.begin(); o != osoby.end(); ++o){
                    cout << o->getFirstName() << " ";
                    cout << o->getSenondName() << " ";
                    cout << o->getAge() << endl;
                }
                break;

            case 's':
                saveToFile(osoby);
                break;

            case 'r':
                readFromFile(osoby);
                break;

            case 'd':
                deletePerson(osoby);
                break;

            case 'q':
                quit=true;

            default:
                continue;
        }
    }
    return 0;
}
