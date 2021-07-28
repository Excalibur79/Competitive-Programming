#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int i=0,j=0,sum=0;
    while(j<k){
        sum+=arr[j];
        j++;
    }
    j--; 
    int Max=sum;
    while(true){ 
        i++;
        j++;   
        if(j==n)
            break;   
        sum=sum-arr[i-1]+arr[j];      
        Max=max(sum,Max);       
    }
    cout<<Max;
    return 0;
}