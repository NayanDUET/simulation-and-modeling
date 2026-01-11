 #include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Chi-Square Test with LCG\n"<<endl;

    int a = 13;
    int c = 0;
    int x0 = 3;
    int m = 641;

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


    cout << "Total " << cnt+1 << " number generated." << endl;

    sort(numbers.begin(), numbers.end());
    cout<<" =============================="<<endl;
    for(auto i: numbers)
        cout<<i<<" ";
    cout<<endl;

    double range = numbers[numbers.size()-1] - numbers[0];
    int obs_cnt[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(auto num: numbers)
    {
        if(num >0.0 and num<=0.1)
            obs_cnt[0]++;
        else if(num >0.1 and num<=0.2)
            obs_cnt[1]++;
        else if(num >0.2 and num<=0.3)
            obs_cnt[2]++;
        else if(num >0.3 and num<=0.4)
            obs_cnt[3]++;
        else if(num >0.4 and num<=0.5)
            obs_cnt[4]++;
        else if(num >0.5 and num<=0.6)
            obs_cnt[5]++;
        else if(num >0.6 and num<=0.7)
            obs_cnt[6]++;
        else if(num >0.7 and num<=0.8)
            obs_cnt[7]++;
        else if(num >0.8 and num<=0.9)
            obs_cnt[8]++;
        else
            obs_cnt[9]++;
    }
    for(auto i: obs_cnt)
        cout<<i<<endl;
    cout<<" ================== "<<endl;
    double chi_rw[10] = {0, };
    double expect = (cnt+1)/10;
    cout<<"expectation: "<<expect<<endl;
    double result = 0.0;
    for(int i=1; i<=10; i++)
    {
        double cal = pow((obs_cnt[i-1] - expect), 2)/expect;
        cout<<"cal"<<i<<" "<<cal<<endl;
        result += cal;
    }

    cout<<result<<endl;

    if(result<16.919)
        cout<<"Numbers are Uniformly Distributed"<<endl;
    else
        cout<<"Numbers are not Uniformly Distributed"<<endl;

    return 0;
}
