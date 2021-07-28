#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    vector<int> nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k;
    cin>>k;
    int i=0,j=0,ans=INT_MIN;
    while(j<nums.size()){
        if(nums[j]==1){
            ans=max(ans,j-i+1);
            j++;
        }
        else if(nums[j]==0){
            if(k>0){
                ans=max(ans,j-i+1);
                k--;
                j++;
            }
            else{
               if(nums[i]==0)
                    k++;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}