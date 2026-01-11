#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Kolmogorov-Smirnov(KS) Test with LCG"<<endl;
    cout << "Linear Congruential Generator (LCG)\n";
    int a = 13;
    int c = 0;
    int x0 = 3;
    int m = 64;

    int start = x0;
    int cnt = 0;
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

    sort(numbers.begin(), numbers.end());
    cout<<" =============================="<<endl;
    for(auto i: numbers)
        cout<<i<<" ";
    cout<<endl;

    vector<float> Dplus(cnt), Dminus(cnt);

    for(int i=0; i<cnt; i++)
    {
        Dplus[i] = ( ((i+1)/float(cnt)) - numbers[i]);
        Dminus[i] = ( numbers[i] - ((i)/float(cnt)) );
    }
    float maxDplus  = *max_element(Dplus.begin(), Dplus.end());
    float maxDminus = *max_element(Dminus.begin(), Dminus.end());

    float Dval = max(maxDplus, maxDminus);

    float alpha = 0.05, c_alpha = 1.36;
    float D_a = c_alpha / sqrt(cnt) ;

    if(Dval < D_a)
        cout<<"The numbers are Uniformly distributed\nThe Null Hypothesis can't be rejected."<<endl;
    else
        cout<<"The numbers are not Uniformly distributed\nThe Null Hypothesis is rejected."<<endl;

    return 0;
}
