#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<int> B(N);
    for(int i = 0; i < N; i++){
    long long fase = A[i];
    B[i] = -1; 
    for (int j = 0; j < N; j++) {
        int pos = (i + j) % N;

        if (fase > A[pos]) {
            B[i] = pos + 1;
            break;
        }

        fase += K;
    }

    
    if (B[i] == -1) B[i] = i + 1; 
}

    for(int i = 0; i < N; i++){
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}