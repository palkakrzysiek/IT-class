#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Liczba{
    public:
        int wartosc;

    Liczba(int val){
        this->wartosc = val;
    }

    int getVal(){
        return this->wartosc;
    }
};

int main(int argc, char const* argv[])
{
    vector<Liczba> numbers;
    string answer;
    string filename;
    int num;

    while(true){
        cout << "Add new number? [y/n]\n>";
        cin >> answer;
        if(answer[0] == 'y'){
            cout << "Give an integer number\n>";
            cin >> num;
            numbers.push_back(num);
        }
        else
            break;
    }

    if(numbers.size() == 0){
        cout << "The list of nubers is empty" << endl;
        return 0;
    }


    cout << "Give the name of the file to create\n>";
    cin >> filename;

    ofstream tempfile;
    tempfile.open(filename.c_str());

    for(int i = 0; i < numbers.size(); ++i){
        if(10000 > numbers[i].getVal() && numbers[i].getVal() > 999){
            if(numbers[i].getVal()/1000 + (numbers[i].getVal() % 1000) /100 == (numbers[i].getVal() % 100)/10 + (numbers[i].getVal() % 10))

            tempfile << numbers[i].getVal() << ' ';
        }
    }

    tempfile.close();

    ifstream myfile(filename.c_str());
    string line;
    if (myfile.is_open()) {
        while ( myfile.good() ) {
          getline (myfile,line);
          cout << line << endl;
        }
        myfile.close();
     }

     else cout << "Unable to open file"; 
    return 0;
}
