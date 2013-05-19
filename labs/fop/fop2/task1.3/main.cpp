#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
    vector<int> numbers;
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

    sort(numbers.begin(), numbers.end(), greater<int>());

    cout << "Give the name of the file to create\n>";
    cin >> filename;

    ofstream tempfile;
    tempfile.open(filename.c_str());

    for(int i = 0; i < numbers.size(); ++i){
        if(1000 > numbers[i] && numbers[i] > 99){
            if(((numbers[i] % 1000) /100 + (numbers[i] % 100)/10 + (numbers[i] % 10)) % 2 == 0)

            tempfile << numbers[i] << ' ';
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
