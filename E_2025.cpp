#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int Y, K;
    int maior = -1;
    int X = 1;
    cin >> Y >> K;
    for(int j = 0; j < K; j++){
        int a = X;
        int b = Y;
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
    X += a;
}
    cout << X << endl;
    return 0;
}