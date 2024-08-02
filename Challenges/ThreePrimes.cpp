#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll i, j;
ll primo[1000000];

int ThreeDivisors(ll n){
    double sqrt_n = sqrt(n);
    if(sqrt_n == int(sqrt_n)){return 1;}
    else{ return 0;}
}


void calculate_primo(){
    primo[0] = primo[1] = 1;
    for(i=2;i<1000000;i++){
        if (primo[i]==0){
            for(j=i*i;j<1000000;j+=i){primo[j] = 1;}
        }
    }
}

int main(){
    calculate_primo();
    ll n, num;
    cin>>n;

    for(i=0;i<n;i++){

        cin>>num;

        if (num%2==0 and num!=4){ cout<<"NO"<<endl;}

        else if (num==4){ cout<<"YES"<<endl;}
        else if(ThreeDivisors(num)==1 && primo[int(sqrt(num))]==0)
            { cout<<"YES"<<endl; }
        else{
            cout<<"NO"<<endl;
        }
    }
}