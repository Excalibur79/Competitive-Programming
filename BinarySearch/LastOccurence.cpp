#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
     vector<int> arr = {2,4,10,10,10,18,20};
    int to_find=21;
    int l=0,h=arr.size()-1,mid;
    bool found =false;
    int res=0;
    while(l<=h){
        mid = (l+h)/2;
        if(arr[mid] == to_find){
            found =true;
            res=mid;
            l=mid+1;
        }
        else if(to_find>arr[mid]){
            l=mid+1;
        }
        else
            h=mid-1;
    }
    if(found)
        cout<<res;
    else
        cout<<"NOT FOUND";
}