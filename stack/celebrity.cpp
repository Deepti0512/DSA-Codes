#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n){
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(M[a][b]==1){
            s.push(b);
        }
        else s.push(a);
    }
    int ans = s.top();
    
    //final step: verify if the element obtained is celebrity or not 
    
    for(int j = 0; j<n; j++){
        if(M[ans][j] == 1){
            return -1;
        }
    }
    for(int i = 0; i<n; i++){
        if(i!=ans){
            if(M[i][ans] == 0){
                return -1;
            }
        }
    }
    return ans;
}

int main()
{
	int n;
	cin>>n;
	vector< vector<int>> M(n, vector<int> (n));
// 	vector<vetor<int>>M(n,n)
	for(int i=0; i<n; i++){
	    for(int j = 0; j<n; j++){
	        cin>>M[i][j];
	    }
	}
	int ans = celebrity(M,n);
	cout<<ans<<endl;
	return 0;
}
