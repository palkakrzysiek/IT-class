/*
W Binarii rozpoczęło się właśnie lato, co równoważne jest z typową dla tamtego klimatu falą upałów. Niestety jeden z gatunków permutorów szczególnie źle znosi wysokie temperatury, w związku z czym ich populacja drastycznie się zmniejszyła. Ekolodzy binarscy zagospodarowali odpowiednią ilość przestrzeni, żeby zmieściły się w niej wszystkie permutory, a następnie zabudowali ją tworząc dla tych niezwykłych zwierząt imitację ich środowiska z możliwością kontroli temperatury i wilgotności. Pozostało jedynie przywrócić pierwotną liczbę osobników. Permutory są jednak wybredne w doborze partnerów - nie zadowolą się byle kim. Partnerzy muszą mieć przynajmniej jedną cechę wspólną, inaczej nie raczą nawet na siebie spojrzeć. Jako miłośnik permutorów zgłosiłeś się na ochotnika do napisania programu, który wyliczy ilość wszystkich możliwych par permutorów.

Wejście
W pierwszej linii wejścia pojawia się liczba permutorów p (p≤105). Każda z następnych p linii zawiera ciąg znaków 'a'..'z' oznaczających cechy danego permutora (każda litera odpowiada unikalnej cesze). Długość ciągu nie przekracza 26 znaków. Ponadto, Twój program powinien być odporny na błędy, jako że w życiu różnie bywa, więc litery w ciągu mogą się powtarzać (powtarzające się litery program powinien ignorować). Dodatkowo, nieczęsto zdarza się, aby było wiele permutorów o takich samych cechach.

Wyjście
Pierwsza i jedyna linia wyjścia powinna zawierać jedną liczbę będącą ilością możliwych par permutorów, które można utworzyć.

Przykład
Wejście:
3
aabc
cde
eba

Wyjście:
3

Wyjaśnienie przykładu: możliwe pary to aabc+cde (wspólna cecha 'c'), cde+eba (wspólna cecha 'e') oraz eba+aabc (wspólne cechy 'a' i 'b').
*/ 

#include <stdio.h>
int main(int argc, char const* argv[])
{
    int permutanty;
    scanf("%d", &permutanty);
    int iloscPermutantow = permutanty;
    char permutant[permutanty][26];
    while(permutanty--){
        scanf("%26s", permutant[permutanty]);
    }
    int iloscPar = 0;
    int n, k, l, m;
    for (n = 0; n < iloscPermutantow; ++n){
        for(k = n +1; k < iloscPermutantow; ++k){
            l = 0;
            while(permutant[n][l] != 0){
                m = 0;
                while(permutant[k][m] != 0){
                    if(permutant[n][l] == permutant[k][m]){
                        ++iloscPar;
                        goto kolejnyPermutant;
                    }
                    ++m;
                }
                ++l;
            }
            kolejnyPermutant:
            continue;
        }
    }
    printf("%d\n", iloscPar);
    return 0;
}
