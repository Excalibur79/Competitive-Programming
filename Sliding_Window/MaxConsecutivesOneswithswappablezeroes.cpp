#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

int longestSubArrayLengthWithAll1sWithKAllowedToReplace(vector<int> arr,int k){
    int maxLength = 0;
    int start, end;
    start = end = 0;
    int numberOfZero = 0;
    while (end < arr.size()) {
      if (arr[end] == 0) {
        numberOfZero++;
      }

      if (numberOfZero > k) {
        if (arr[start] == 0) {
          numberOfZero--;
        }
        start++;
      }

      maxLength = max(end - start + 1, maxLength);
      end++;
    }

    return maxLength;
}

int main(){
    vector<int> arr={ 0, 1, 0, 1, 0, 1, 1, 1, 0 };
    int k=2;
    int ans=longestSubArrayLengthWithAll1sWithKAllowedToReplace(arr,k);
    cout<<ans;
}