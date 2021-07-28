#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

void printStacks(multiset<ll> &stacks){
    for(auto value:stacks)
        cout<<value<<" ";
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<ll> discs;
	    for(int i=0;i<n;i++){
	        ll x;
	        cin>>x;
	        discs.push_back(x);
	    }
	    multiset<ll> stacks;
	    for(int i=0;i<n;i++){           
	        if(stacks.size()>0){
	          auto it = stacks.upper_bound(discs[i]);
	          if(it!=stacks.end()){
	              stacks.erase(it);
                  stacks.insert(discs[i]);
	          }
	          else{
	              stacks.insert(discs[i]);
	          }
	        }
	        else{
	            stacks.insert(discs[i]);
	        }
	    }
        cout<<stacks.size()<<" ";
	    printStacks(stacks);
	}
	return 0;
}
