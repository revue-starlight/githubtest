#include<iostream>
#define ll long long
using namespace std;      
const long N = 200000;     
ll prime[N] = {0},num_prime = 0;      
int isNotPrime[N] = {1, 1};
int main()      
{        
        for(int i = 2 ; i < N ; i ++)         {if(! isNotPrime[i])prime[num_prime ++]=i;for(int j=0;j<num_prime&&i*prime[j]<N;j++)  {             isNotPrime[i*prime[j]]=1;            if(!(i % prime[j]))  break;}          }
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        bool bo=true;
        for (int i=0;i<num_prime;i++){
        if (n%prime[i]==0){
            cout<<n/prime[i]<<" "<<n-(n/prime[i])<<endl;
            bo=false;
            break;
        }
        }
        if (bo) cout<<"1 "<<n-1<<endl;
    }
    return 0;
}