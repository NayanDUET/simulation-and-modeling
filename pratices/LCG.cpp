
#include<bits/stdc++.h>
using namespace std;


int main(){

   int a = 13,c=0,x0=3,m=64;
   int start = x0;

   vector<double>n;
   int cnt=0;

   while(true){

         int x = (a*x0+c)%m;

         double rn = (double)x;
         double r = rn/float(m);
         cout<<r<<endl;
         n.push_back(rn/float(m));
         if(x == 0 || x == start) break;

         x0 = x;
         cnt++;
   }


  //KS test part

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
