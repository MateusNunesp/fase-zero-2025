#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double M;
    cin >> M;
    double bits;
    bits = M * 1000000 * 8;
    int q;
    q = log2(bits) + 1;
    cout << q;
    return 0;
}
