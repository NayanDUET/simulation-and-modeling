#include<bits/stdc++.h>
using namespace std;


int main(){

  int seed = 5720;
  int x0 = seed;
  int len = 4;
  int cnt = 0;

  vector<int>nums;
  vector<float>n;

  while(true){


      int sq = x0*x0;
      string str = to_string(sq);

      int need = (8-str.size());

      string padded = string(max(0,need),'0')+str;

      string mid = padded.substr(2,4);

      int fnl = stoi(mid);

      float rnd = fnl/float(pow(10,4));
      n.push_back(rnd);

      cout<<rnd<<endl;

      if(fnl == seed || fnl == 0 || find(nums.begin(),nums.end(),fnl) != nums.end())
        break;

      nums.push_back(fnl);

      x0 = fnl;
      cnt++;
  }

   cout<<"Total number generated: "<<cnt<<endl;

   sort(n.begin(),n.end());

   vector<float>Dplus(cnt),Dminus(cnt);


   for(int i=1;i<=n.size();i++){

        Dplus[i-1] = (i/float(cnt))-n[i-1];
        Dminus[i-1] = (n[i-1]-(i-1)/float(cnt));

   }

   float Dmax = *max_element(Dplus.begin(),Dplus.end());
   float Dmmax = *max_element(Dminus.begin(),Dminus.end());

   float D = max(Dmax,Dmmax);
   float c_alpha = 1.36;

   float D_a = c_alpha/sqrt(cnt);

   if(D<D_a) cout<<"The numbers are Uniformly distributed";
   else cout<<"The numbers are not Uniformly distributed";




return 0;
}
