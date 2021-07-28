#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

bool isPaintingPossible(int *C,int A,int timeLimit,int timePerArtist,int arraySize){
    int time=0;
    int painters=1;
    int totalTime=0;
    
    for(int i=0;i<arraySize;i++){
       if(totalTime + (timePerArtist*C[i])<=timeLimit){
           totalTime+=timePerArtist*C[i];
       }
       else{
           painters++;
           totalTime=timePerArtist*C[i];
       }
    }
    cout<<timeLimit<<" "<<painters<<endl;
    return painters<=A;
}

int main(){
    int A,B;
    cin>>A>>B;
    int C[]={1,8,11,3};
    int sum=0,l=INT_MIN;
    int n = sizeof(C)/sizeof(C[0]);
    for(int i=0;i<n;i++){
        sum=sum+C[i]*B;
        l=max(l,C[i]*B);
    }
    
    sort(C,C+n);
    int h=sum,res=-1,mid;
    while(l<=h){
        mid = (l+h)/2;
        if(isPaintingPossible(C,A,mid,B,n)){
            res=mid;
            h=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<res%10000003;

}