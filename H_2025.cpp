#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string para_binario(long long n) {
    if (n == 0) return "0";
    string binario;
    while (n > 0) {
        binario = (n % 2 == 0 ? "0" : "1") + binario;
        n /= 2;
    }
    return binario;
}

long long para_long_long(const string& s) {
    long long resultado = 0;
    long long potencia = 1;
    if (s.length() > 63) return -2;

    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '1') {
            resultado += potencia;
        }
        if (i > 0 && potencia > (__LONG_LONG_MAX__ / 2)) return -2;
        potencia *= 2;
    }
    return resultado;
}

string construir_string_palindromo(string metade, bool comprimento_impar) {
    string reverso = metade;
    reverse(reverso.begin(), reverso.end());
    if (comprimento_impar && !metade.empty()) {
        return metade + reverso.substr(1);
    } else {
        return metade + reverso;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X;
    cin >> X;

    string sX = para_binario(X);
    int L = sX.length();
    long long maiorY = 0;

    int L_menos_1 = L - 1;
    if (L_menos_1 > 0) {
        string metade_L1( (L_menos_1 + 1) / 2 , '1');
        string p_L1_str = construir_string_palindromo(metade_L1, L_menos_1 % 2 != 0);
        maiorY = para_long_long(p_L1_str);
    } else {
        maiorY = 0;
    }
    
    if (X == 1) maiorY = 1;


    int comp_metade = (L + 1) / 2;
    string s_metade_X = sX.substr(0, comp_metade);
    long long metade_X_val = para_long_long(s_metade_X);

    string p_L_str = construir_string_palindromo(s_metade_X, L % 2 != 0);
    long long Y1 = para_long_long(p_L_str);

    if (Y1 > X || Y1 < 0) {
        string metade_menor_str = para_binario(metade_X_val - 1);
        
        if (metade_X_val - 1 == 0 && comp_metade > 1) {
             metade_menor_str = string(comp_metade -1, '0');
        }


        if (metade_menor_str.length() == comp_metade || (metade_X_val -1 == 0 && comp_metade ==1) || (metade_X_val -1 > 0 && metade_menor_str.length() < comp_metade) ) {
             while(metade_menor_str.length() < comp_metade && comp_metade > 0) {
                if (metade_X_val -1 == 0 && metade_menor_str.empty() && comp_metade == 1) break;
                metade_menor_str = "0" + metade_menor_str;
            }
             if (metade_X_val -1 == 0 && metade_menor_str.empty() && comp_metade == 1) {
                 Y1 = 0;
             } else if (metade_menor_str.empty() && comp_metade > 0){
                 Y1 = 0;
             }
             else {
                string p_L_menor_str = construir_string_palindromo(metade_menor_str, L % 2 != 0);
                Y1 = para_long_long(p_L_menor_str);
             }
        } else {
            Y1 = 0;
        }
    }

    if (Y1 > 0 && Y1 <= X) {
         maiorY = max(maiorY, Y1);
    }
    
    if (maiorY == 0 && X > 0) {
        maiorY = 1;
    }


    cout << maiorY << endl;

    return 0;
}
