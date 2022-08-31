// To print prime numbers in a given range
#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
bool sieve[N + 1];
void createSieve()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }
    for(int i=2; i*i <= N; i++){
        if(sieve[i]==true){
            for(int j = i*i; j<=N; j=j+i){
                sieve[j] = false;
            }
        }
    }
}
vector<int> generatePrimes(int N){
    vector<int>ds;
    for(int i = 2;i<=N;i++){
        if(sieve[i]==true){
            ds.push_back(i);
        }
    }
    return ds;
}
int main(){
    createSieve();
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        //step1: generate all primes till sqrt(r)
        vector<int>primes = generatePrimes(sqrt(r));

        //step2: create a dummy array of size r-l+1 and make everyone as 1
        if(l<=1){
            l = 2;
        }
        int dummy[r-l+1];
        for(int i=0; i<r-l+1;i++){
           dummy[i] = 1;
        }

        //step3: For all prime no(s), mark its multiples as false
        for(auto pr :primes){
            
            int firstMultiple = (l/pr)*pr;
            if(firstMultiple<l){
                firstMultiple +=pr;
            }
            for(int j= max(firstMultiple,pr*pr); j<=r; j+=pr){
                dummy[j-l] = 0;
            }
        }

        //step4: get all the primes
        for(int i = l; i<=r; i++){
            if(dummy[i-l]==1){
                cout<<i<<" ";
            }
        }cout<<"\n";
    }
    return 0;
}
