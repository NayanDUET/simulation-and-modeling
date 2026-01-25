#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N = 8;

    vector<int> AT = {0, 10, 15, 35, 30, 10, 5, 5};
    vector<int> ST = {20, 15, 10, 5, 15, 15, 10, 10};

   // vector<int> AT = {0, 10, 15, 20, 25, 10, 10, 5};
   // vector<int> ST  = {20, 15, 15, 10, 5, 15, 10, 10};


    vector<int> CAT(N);
    CAT[0] = AT[0];
    for (int i = 1; i < N; i++)
        CAT[i] = CAT[i - 1] + AT[i];

    vector<int> CDT(N);
    vector<int> QL(N, 0);
    vector<int> IDT(N, 0);

    int I = 1;
    int J = 0;

    int NAT = CAT[1];
    int NDT = ST[0];
    CDT[0] = ST[0];
    int CLOCK = 0;

    int DIF;
    while(true)
    {
        if (I > N )
        {
            CLOCK = NDT;
            CDT[J+1] = CDT[J] + ST[J+1];
            NDT = CDT[J+1];
            J++;

            if(J>=N)
            {
                cout << "\nCAT: ";
                for (int x : CAT) cout << x << " ";

                cout << "\nCDT: ";
                for (int x : CDT) cout << x << " ";

                cout << "\nQL : ";
                for (int x : QL) cout << x << " ";

                cout << "\nIDT: ";
                for (int x : IDT) cout << x << " ";

                cout << "\n\nSimulation ends at time = " << CDT[N - 1] << endl;
                break;
            }
            else
            {
                continue;
            }

        }
        else
        {
            DIF = NAT - NDT;

            if (DIF < 0)
            {
                CLOCK = NAT;
                NAT = CAT[I+1];
                QL[I] = I - J;
                I++;
            }

            else if (DIF == 0)
            {
                QL[I] = QL[I - 1];
                CLOCK = NAT;
                NAT = CAT[I+1];
                CDT[J + 1] = CAT[I] + ST[J + 1];
                NDT = CDT[J + 1];

                I++;
                J++;
            }

            else if (DIF > 0 )
            {
                if((I-J)>1)
                {
                    CLOCK = NDT;
                    CDT[J+1] = CDT[J] + ST[J+1];
                    NDT = CDT[J+1];
                    J++;
                    if(J>=N)
                    {
                        cout << "\nCAT: ";
                        for (int x : CAT) cout << x << " ";

                        cout << "\nCDT: ";
                        for (int x : CDT) cout << x << " ";

                        cout << "\nQL : ";
                        for (int x : QL) cout << x << " ";

                        cout << "\nIDT: ";
                        for (int x : IDT) cout << x << " ";

                        cout << "\n\nSimulation ends at time = " << CDT[N - 1] << endl;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    IDT[I] = DIF;

                    CLOCK = NAT;
                    NAT = CAT[I+1];
                    CDT[J+1] = CAT[I] + ST[J+1];
                    NDT = CDT[J+1];
                    J++;
                    I++;
                    if(J>=N)
                    {
                        cout << "\nCAT: ";
                        for (int x : CAT) cout << x << " ";

                        cout << "\nCDT: ";
                        for (int x : CDT) cout << x << " ";

                        cout << "\nQL : ";
                        for (int x : QL) cout << x << " ";

                        cout << "\nIDT: ";
                        for (int x : IDT) cout << x << " ";

                        cout << "\n\nSimulation ends at time = " << CDT[N - 1] << endl;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
    }



    return 0;
}
