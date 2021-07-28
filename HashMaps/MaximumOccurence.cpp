#include<iostream>
#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;
int main(){
	unordered_map<char,int> m;
	string s;
    getline(cin,s);
	char ansChar;
	int maxValue = INT_MIN;
	for(auto value : s){
		m[value]++;
		if(m[value]>maxValue){
			maxValue = m[value];
			ansChar = value;
		}
        if(m[value]==maxValue && value<ansChar){
            maxValue = m[value];
			ansChar = value;     
        }
	}
	cout<<ansChar<<" "<<maxValue;
	// for(auto value : m)
	// 	cout<<value.first<<" "<<value.second<<endl;


	return 0;
}