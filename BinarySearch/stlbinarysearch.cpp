#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    vector<int> arr={true,true,true,false,false};
    bool found = binary_search(arr.begin(),arr.end(),false);
    cout<<(found?"found":"not found");
}