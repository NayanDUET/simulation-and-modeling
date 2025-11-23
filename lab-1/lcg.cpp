#include <bits/stdc++.h>
using namespace std;

unsigned long long LCG(unsigned long long seed,
unsigned long long a,unsigned long long c,unsigned long long m)
{
    return (a * seed + c) % m;
}

int main() {

    unsigned long long seed, a, c, m;
    int n;

    cout << "Enter seed value: ";
    cin >> seed;
    cout << "Enter multiplier (a): ";
    cin >> a;
    cout << "Enter increment (c): ";
    cin >> c;
    cout << "Enter modulus (m): ";
    cin >> m;

    cout << "How many random numbers to generate? ";
    cin >> n;

    unsigned long long x = seed;

    cout << "\nGenerated Random Numbers:\n";
    for (int i = 0; i < n; i++) {
        x = LCG(x, a, c, m);
        cout << x/100.0 << endl;
    }

    return 0;
}
