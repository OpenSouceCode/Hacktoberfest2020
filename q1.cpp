#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {
	vector<int> v;
	deque<int> dq;
	v.push_back(45);
	v.push_back(23);
	v.pop_back();
	//v.push_front(23);
	//v.pop_front();
	vector<int>::iterator it;
	for(it=v.begin();it!=v.end();it++)
		cout<<*it<<endl;
	dq.push_back(34);
	dq.push_back(44);
	dq.push_front(55);
	dq.pop_back();
	dq.pop_front();
	for(int i=0;i<dq.size();i++)
		cout<<dq[i]<<endl;
	return 0;
}

//In vector<int> back insertion is allowed front insertion is not, i.e., push_back() and pop_back(). In deque all operations are possible - push_back(), pop_back(), push_front(), pop_front().
