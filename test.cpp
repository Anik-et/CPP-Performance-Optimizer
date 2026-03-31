#include <iostream>
using namespace std;

int main() {
    long long sum = 0;
    for(int i = 0; i < 1e7; i++) sum += i;
    cout << sum;
    return 0; // Good practice to include return 0 in C++
}