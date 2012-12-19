#include <cstdio>
#include<string.h>

struct SAdress{
    char city[128];
    char street[128];
    int flat;
};
struct SPerson{
    char NameSurname[128];
    SAdress adress;
    int id;
    double account;
};

int main(int argc, char const* argv[])
{
    
    SPerson person;
    strcpy(person.NameSurname, "John Smith");
    strcpy(person.adress.city, "doudon");
    person.adress.flat= 15;
    person.id= 1284372;
    person.account = 32731;

    printf("person.NameSurname: %s\nperson.adress.city: %s\n", person.NameSurname, person.adress.city);

    return 0;
}
