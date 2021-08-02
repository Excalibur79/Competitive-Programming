#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
         int t;
    cin>>t;
    while(t--){
        ll W,H;
        cin>>W>>H;
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int w,h;
        cin>>w>>h; //(x1,y1) (x2,y1) (x1,y2) (x2,y2)
        //chechking left side
        bool canBePlaced = false;
        if(x1>=w && h<=H)
            canBePlaced =true;
        else if(W-x2>=w && h<=H)//right side
            canBePlaced =true;
        else if(H-y2>=h && w<=W)//top
            canBePlaced = true;
        else if(y1>=h && w<=W)
            canBePlaced=true;


    }
    return 0;
}