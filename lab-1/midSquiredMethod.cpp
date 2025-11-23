#include <bits/stdc++.h>
using namespace std;


int midSquare(int key, int digits) {

    long long squared = (long long)key * key;

    string s = to_string(squared);

    int len = s.length();

    int start = (len - digits) / 2;

    string mid = s.substr(start, digits);

    return stoi(mid);
}

int main() {

     int key=7182, digits=4;
     int result=1;

    while(result !=0){

        result = midSquare(key, digits);
        cout<<result/10000.0<<endl;
        key = result;
    }




    return 0;
}
