#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Kolmogorov-Smirnov(KS) Test\n"<<endl;
    int seed = 5720;
    int x0 = seed;
    int cnt = 0;

    vector<float> numbers;

    string seed_str = to_string(seed);
    while (true)
    {

        int sqr = x0 * x0;
        cout << "Square: " << sqr << endl;

        string sqr_str  = to_string(sqr);

        int need = seed_str.length() * 2 - sqr_str.length();
        cout << "Need 0: " << need << endl;

        string padded = string(max(0, need), '0') + sqr_str;

        string mid = padded.substr(2, 4);
        int final_rand = stoi(mid);
        float rnd = final_rand/float(pow(10,seed_str.length())) ;
        cout << "Random: " << rnd << endl;

        if (final_rand == seed || final_rand == 0 || find(numbers.begin(), numbers.end(), final_rand) != numbers.end())
        {
            break;
        }

        numbers.push_back( final_rand );
        x0 = final_rand;
        cnt++;

        cout << "-------------------------------" << endl;
    }

    cout << "Total " << cnt << " number generated." << endl;

    for(int i=0; i<cnt; i++)
        numbers[i] = numbers[i]/float(pow(10,seed_str.length())) ;
    cout<<endl;


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
