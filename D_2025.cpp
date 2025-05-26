#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    int N;
    cin >>N;
    
    string S,T;
    cin >> S;
    cin >> T;
    
    int contador_superposicao = 0;
    int contador_colapsados = 0;
    for (int a = 0; a < N; a++){
        if (S[a] == '*'){
            contador_superposicao++;
            if (T[a] != '*'){
                contador_colapsados++;
            }
        }
    }
    double taxa = (double)contador_colapsados / contador_superposicao;
    
    cout << taxa << endl;
    
    return 0;
}
