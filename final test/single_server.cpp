#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 8;

    vector<int> AT = {0, 10, 15, 20, 25, 10, 10, 5};
    vector<int> ST  = {20, 15, 15, 10, 5, 15, 10, 10};

    vector<int> CAT(n), SST(n), CDT(n), QL(n), IDT(n);

    // Arrival Time (CAT)
    CAT[0] = AT[0];
    for (int i = 1; i < n; i++) {
        CAT[i] = CAT[i - 1] + AT[i];
    }

    // First customer
    SST[0] = CAT[0];
    CDT[0] = SST[0] + ST[0];
    QL[0] = 0;
    IDT[0] = 0;

    // Simulation
    for (int i = 1; i < n; i++) {
        SST[i] = max(CAT[i], CDT[i - 1]);
        CDT[i] = SST[i] + ST[i];

        // Queue Length (Waiting Time)
        QL[i] = max(0, CDT[i - 1] - CAT[i]);

        // Idle Time
        IDT[i] = max(0, CAT[i] - CDT[i - 1]);
    }

    // Output
    cout << "Cust\tCAT\tST\tCDT\tQL\tIDT\n";
    cout << "----------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t"
             << CAT[i] << "\t"
             << ST[i] << "\t"
             << CDT[i] << "\t"
             << QL[i] << "\t"
             << IDT[i] << endl;
    }

    cout << "\nSimulation Termination Time: " << CDT[n - 1] << endl;

    return 0;
}
