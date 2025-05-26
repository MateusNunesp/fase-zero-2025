#include <iostream>
using namespace std;
int main(){
    int N, Q;
    cin >> N;
    int soma1[N*N] = {0};
    int soma2[N*N*N*N] = {0};
    int soma = 0;
    int cont = 0;
    int cont2 = 0;
    int cont3 = 0;
    int num[N];
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    cin >> Q;
    int consulta[Q];
    for(int i = 0; i < Q; i++){
        cin >> consulta[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            soma1[cont3++] = num[i] + num[j];
        }
    }
    for(int i = 0; i < cont3; i++){
        for(int j = 0; j < cont3; j++){
            soma2[cont2++] = soma1[i] + soma1[j];
        }
    }
    for(int i = 0; i < Q; i++){
        for(int j = 0; j < cont2; j++){
            if(soma2[j] == consulta[i]){
                cont++;
            }
        }
    }
    cout << cont << endl;
    return 0;
}


