#include <cstdio>
#include <stack>

bool check(char *T, int N){
    std::stack<char> stack; // tworzy stos o nazwie stack przechowujący elementy typu char

    int counter = 0;
    for (counter = 0; counter < N; counter++) { // sprawdza każdy znak
        switch(T[counter]){
            case '{':
            case '(':
            case '[':
                stack.push(T[counter]); // jeśli jest to nawias otwierający dodaje go do stosu
                break;
            case '}':
                if(!stack.empty() && stack.top() == '{'){ // (metoda top zwraca ostatnio dodany do stosu znak); jeśli stos nie jest pusty to sprawdza czy dla '}' ostatnio dodanym znakiem jest '{'
                    stack.pop(); // usuwa z wierzchu stosu ten nawias
                	break;
                }
                else
                    return 0; // jeśli nie jest to odpowiedni nawias zwraca fałsz
            case ')':
                if(!stack.empty() && stack.top() == '('){
                    stack.pop();
                    break;
                }
                else
                    return 0;
            case ']':
                if(!stack.empty() && stack.top() == '['){
                    stack.pop();
                    break;
                }
                else
                    return 0;
        }
    }
    if (stack.empty())
        return 1; // jeśli stos jest pusty zwraca prawdę
    else
        return 0; // jeśli na stosie zostały niedomknięte nawiasy zwraca fałsz

}

int main(int argc, char const* argv[])
{
    char str1[] = "{([])}"; //poprawne zagnieżdżenie 
    char str2[] = "[(])"; //niepoprawna kolejność zamykania nawiasów
    char str3[] = "{[()]"; //zostaje niedomknięty nawias
    char str4[] = "[()]}"; // jedno domknięcie za dużo
    char str5[] = "{a+[3b*(c-1)]/2}"; // poprawne zagnieżdżenie, występują inne znaki
    if(check(str1, sizeof(str1))) puts("str1 - true"); else puts("str1 - false");
    if(check(str2, sizeof(str2))) puts("str2 - true"); else puts("str2 - false");
    if(check(str3, sizeof(str3))) puts("str3 - true"); else puts("str3 - false");
    if(check(str4, sizeof(str4))) puts("str4 - true"); else puts("str4 - false");
    if(check(str5, sizeof(str5))) puts("str5 - true"); else puts("str5 - false");

    return 0;
}
