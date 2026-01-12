
#include<bits/stdc++.h>
using namespace std;


int main(){

   int a = 13,c=0,x0=3,m=641;
   int start = x0;

   vector<double>n;
   int cnt=0;

   while(true){

         int x = (a*x0+c)%m;

         double rn = (double)x;
         double r = rn/(m);
         cout<<r<<endl;
         n.push_back(rn/float(m));
         if(x == 0 || x == start) break;

         x0 = x;
         cnt++;
   }

   cout<<"Total numebrs generated: "<<cnt<<endl;
  //chai squar part

  vector<int>obs_cnt(10);

    for(auto num: n)
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

    double exp = (cnt+1)/10;

    double result;

    for(int i=1;i<=10;i++){

         double cal = pow((obs_cnt[i-1]-exp),2)/exp;
    }

    if(result < 16.919) cout<<"Numbers are Uniformly Distributed"<<endl;
    else cout<<"Numbers are not Uniformly Distributed"<<endl;





return 0;
}

