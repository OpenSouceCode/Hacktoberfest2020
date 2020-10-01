#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,gap;
	cout<<"Enter size of the array\n";
	cin>>n;
	cout<<"Enter gap between the values\n";
	cin>>gap;
	vector<int> act;
	for(int i=0;i<n;i++)
	{
		act.push_back(i+1);
	}
	vector<int> calc; 
	calc.assign(act.begin(),act.end());
	int i;
	int start=gap-1;
//	cout<<calc.size();
	while(act.size()>1)
	{
		for(i=start;i<act.size();i+=gap)
		{
			auto it=find(calc.begin(),calc.end(),act[i]);
//			if(it!=calc.end())
			calc.erase(it);
		}
		start=i-act.size();
		act.clear();
		act.assign(calc.begin(),calc.end());
	}
	for(auto &j:act)
		cout<<j;	
}
