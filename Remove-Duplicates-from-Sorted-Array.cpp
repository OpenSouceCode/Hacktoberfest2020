/*
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/

#include <iostream>
#include<stdio.h> 
#include <bits/stdc++.h> 
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include<utility>
using namespace std;
#define ll long long
#define len length()
#define vi vector<int>
#define vl vector<ll>

#define fr(i,n) for(ll i=0;i<n;i++)
ll max(ll i,ll j){
    return i>j?i:j;
}


int removeDuplicates(vector<int>& nums) {
        int ind=1;
        int n=nums.size();
        if (n<=1) return n;
        for(int i=0;i<n-1;i++){

            if(nums[i+1]!=nums[i]){
                nums[ind]=nums[i+1];
                if(ind<n)
                ind++;
            }


        }
        nums.resize(ind);
        return ind;
}

int main(){
    int n;
    cin>>n;
 vector<int> v(n,0);
  fr(i,n){
      int x; cin>>x;
      v[i]=x;
  }

 sort(v.begin(),v.end());
 removeDuplicates(v);
 return 0;

}
