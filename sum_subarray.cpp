#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int FindMaximumSum(vector<int>arr){
	//n complexity kadane's algorithm
	int max_so_far=INT_MIN,max_ending_here=0;
	for(int i=0;i<arr.size();i++){
		max_ending_here+=arr[i];
		if(max_ending_here>max_so_far)
			max_so_far=max_ending_here;
		if(max_ending_here<0)
			max_ending_here=0;
	}
	return max_so_far;
}
int FindMaximumSum(vector<int>arr){
	//n^2 implementation
	int size=arr.size();
	int max=0,sum=0;
	if(size>1)
	for(int i=0;i<size;i++)
		for(int j=i+1;j<size;j++){
			sum+=arr[j];
			if(sum>max){
				max=sum;
				sum=0;
			}
		}
	else{
		max=arr[0];
	}
	return max;
}
int FindMaximumSum(vector<int>arr){
	//n^3 implementation
	int size=arr.size();
	int max=0,sum=0;
	if(size>1)
	for(int i=0;i<size;i++)
		for(int j=i+1;j<size;j++){
			for(int k=i;k<=j;k++){
				sum+=arr[k];
			}
			if(sum>max)
				max=sum;
			sum=0;
		}
	else{
		max=arr[0];
	}
	return max;
}
int main(){
	vector<int>arr{-2,1,-3,4,-1,2,1,-5,4};
	cout<<FindMaximumSum(arr);
}