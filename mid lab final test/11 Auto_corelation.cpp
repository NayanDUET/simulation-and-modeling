#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Auto-Corelation Test with LCG\n"<<endl;

    int a = 13;
    int c = 0;
    int x0 = 3;
    int m = 641;

    int start = x0;
    int cnt = 1;
    vector<double> numbers;

    cout << "Seed = " << x0 << "\n\n";

    while (true)
    {
        int x = (a * x0 + c) % m;
        double rn = (double)x ;
        cout << "RN"<<cnt<<" = " << rn/m << endl;
        numbers.push_back(rn/m);

        if (x == start || x == 0)
            break;

        x0 = x;
        cnt++;
    }


    cout << "Total " << cnt << " number generated." << endl;

    // sort(numbers.begin(), numbers.end());
    cout<<" =============================="<<endl;
    /*
    numbers.clear();
    numbers = {
        0.12, 0.01, 0.23, 0.28, 0.89, 0.31, 0.64, 0.28, 0.83, 0.93,
        0.99, 0.15, 0.33, 0.35, 0.91, 0.41, 0.60, 0.27, 0.75, 0.88,
        0.68, 0.49, 0.05, 0.43, 0.95, 0.58, 0.19, 0.36, 0.69, 0.87
    };
    cnt = numbers.size();
    */
    for(auto i: numbers)
        cout<<i<<" ";
    cout<<endl;

    double M ;
    int i , m1;
    i = 3;
    m1 = 5;

    M = floor( ((cnt - i)/m1)-1 );
    cout<<"M: "<<M<<endl;

    double prod = 0.0;

    for(int k = i, j=0; j<floor((cnt - i)/m1); k=k+m1, j++)
    {
        cout<<numbers[k-1]<<" "<<numbers[k+m1-1]<<endl;
        prod += numbers[k-1]*numbers[k+m1-1];
    }

    double p = (1/(M+1)) * ( prod ) - 0.25;
    double sigma = (sqrt((13*M)+7))/(12*(M+1));

    cout<<"p="<<p<<" "<<"sigma="<<sigma<<endl;

    double z = p / sigma;
    cout<<"z="<<z<<endl;
    double z_a = 1.96;

    if(z>=-z_a && z<=z_a)
        cout<<"Independence, the hypothesis is not rejected"<<endl;
    else
        cout<<"Not Independence, the hypothesis is rejected"<<endl;

    return 0;
}
