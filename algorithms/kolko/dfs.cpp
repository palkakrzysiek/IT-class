#include <cstdio>
#include <vector>

using namespace std;

vector<int> graf[1000];

int n;

int main(){
    int t;
    scanf("%d", &t);
    size_t z = 2;
    for(int i = 0; i < t;i ++){
        scanf("%d", &n);
        printf("graf ma %d wierzcholkow\n", n);
        for(int j = 0; j < n; j++){
            int k,m;
            scanf("%d %d",&k,&m );
            k--;
            printf("wierzcholek %d ma %d sasiadow\n", k+1, m);
            graf[k].clear();

            for(int l=0; l<m; l++){
                int temp;
                scanf("%d", &temp);
                graf[k].push_back(temp);
            }
        }
        short next = 1;
        while(next){
            int v, j;
            scanf("%d %d", &v, &j);
            if(v == 0 && j == 0)
                next = 0;
        }

        for(int j = 0; j < n; j++){
            for(int k = 0; k < graf[j].size(); k++){
                printf("%d ", graf[j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}
