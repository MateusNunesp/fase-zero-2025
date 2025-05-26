#include <iostream>
using namespace std;

int main()
{
    int c, g;
    
    cin >> c;
    cin >> g;
    
    if (c) {
        cout << "vivo e morto";
    }
    else if (g) {
        cout << "vivo";
    }
    else {
        cout << "morto";
    }

    return 0;
}