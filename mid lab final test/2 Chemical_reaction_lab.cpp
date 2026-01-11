#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"Chemical Reaction"<<endl;

    double k1 = 0.008, k2 = 0.002, a=100, b = 50, c=0, T=5*60, dt = 0.1, temp=dt;

    cout<<"a(t) \t b(t) \t c(t)"<<endl;
    int cnt = 1;
    while(temp<=T)
    {
        cout<<cnt++<<"-> "<<a<<"\t "<< b<<"\t "<<c<<endl;
        // cout<<a<<" \t "<< b<<" \t "<<c<<endl;
        a = a+( (k2*c) - (k1*a*b) )*dt;
        b = b+( (k2*c) - (k1*a*b) )*dt;
        c = c+( (2*k1*a*b) - (2*k2*c) )*dt;
        temp += dt;

    }


    return 0;
}
