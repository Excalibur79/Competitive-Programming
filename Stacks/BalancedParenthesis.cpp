#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    string str;
    cin>>str;
    stack<char> s;
    bool isBalanced=true;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            s.push(str[i]);
        else{
           if(!s.empty()){
               if((str[i]==')' && s.top()=='(') ||( str[i]=='}' && s.top()=='{' ) || ( str[i]==']' && s.top()=='[' ))
                   s.pop();               
               else{
                isBalanced=false;
                break;
               }
           }
           else{
               isBalanced=false;
               break;
           }
        }
    }
    if(s.empty() && isBalanced)
        cout<<"Balanced!";
    else 
        cout<<"Not Balanced!";
    return 0;
}