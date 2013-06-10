#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <cstdlib>

using namespace std;

class NotIntException{
    public:
        string what(){
            return "The value is not an integer";
        }
};
class FileError{
    public:
        string what(){
            return "Cannot open the file";
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

class BazaDanych {
    private:
        list<Osoba> osoby;

    public:
        BazaDanych(){
            cout << "Database has been created" << endl;
        }

        void deletePerson(string who){
            list<Osoba>::iterator o = osoby.begin();
            string imie, nazwisko;
            while( o != osoby.end()){ imie = o->getFirstName();
                nazwisko = o->getSenondName();
                if(string::npos != imie.find(who) || string::npos != nazwisko.find(who)){
                    osoby.erase(o++);
                }
                else{
                    ++o;
                }
            }
        }

        void readFromFile(string filename){
            int currentLine = 0;
            string imie, nazwisko;
            int wiek;
            ifstream myfile(filename.c_str());
            string line;
            if (!myfile.is_open()) 
                throw FileError();
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

        void saveToFile(string filename){
            ofstream tempfile;
            tempfile.open(filename.c_str());
            for(list<Osoba>::iterator o = osoby.begin(); o != osoby.end(); ++o){
                tempfile << o->getFirstName() << endl;
                tempfile << o->getSenondName() << endl;
                tempfile << o->getAge() << endl;
            }
            tempfile.close();
        }

        void addPerson(string imie, string nazwisko, string wiek){
            int temp = 0;
            while(wiek[temp] != 0){
                if('0' > wiek[temp] || wiek[temp] > '9')
                    throw NotIntException();
                temp++;
            }
            int newWiek = 0;
            newWiek = atoi(wiek.c_str());
            osoby.push_back(Osoba(imie, nazwisko, newWiek));
        }   

        void printDatabase(){
            for(list<Osoba>::iterator o = osoby.begin(); o != osoby.end(); ++o){
                cout << o->getFirstName() << " ";
                cout << o->getSenondName() << " ";
                cout << o->getAge() << endl;
            }
        }   
};



int main(int argc, char const* argv[])
{
    BazaDanych *database = new BazaDanych();
    string answer;
    string filename;
    string imie, nazwisko, tempWiek;
    string searched;
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
                    database->addPerson(imie, nazwisko, tempWiek);
                }
                catch(NotIntException &e){
                    cerr << "An error occurred: " << e.what() << endl;
                }

                break;

            case 'p':
                database->printDatabase();
                break;

            case 's':
                cout << "Give the name of the file to create\n>";
                cin >> filename;
                database->saveToFile(filename);
                break;

            case 'r':
                cout << "Give the name of the file to open\n>";
                cin >> filename;
                try{
                    database->readFromFile(filename);
                }
                catch(FileError &e){
                    cerr << "An error occurred: " << e.what() << endl;
                }
                break;

            case 'd':
                cout << "Give phrase to match >";
                cin >> searched;
                database->deletePerson(searched);
                break;

            case 'q':
                quit=true;

            default:
                continue;
        }
    }
    return 0;
}
