#include <iostream>

using namespace std;

int main() {
    int linhas = 4;

    for (int i = 1; i <= linhas; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}