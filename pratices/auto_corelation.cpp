
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
         double r = rn/float(m);
         cout<<r<<endl;
         n.push_back(rn/float(m));
         if(x == 0 || x == start) break;

         x0 = x;
         cnt++;
   }

  cout<<"Total number generated: "<<cnt<<endl;
  //auto-Corelation

  int i=3,m1=5;
  int M = floor((cnt-i)/m1-1);
  double prod;
  int k,j;

  for(k=i,j=0;k<floor((cnt-i)/m1);k += m1,j++){

       prod += n[k-1]*n[k+m1-1];
  }

  double p = ((1/(M+1))*prod)-0.25;
  double sigma = sqrt(13*M+7)/(12*(M+1));

  double z = p/sigma;

  double z_a = 1.96;

  if(z>= -z_a && z<= z_a) cout<<"Independance,the hypothesis is not rejected"<<endl;
  else cout<<"Not Independance,the hypothesis is rejected"<<endl;





return 0;
}

