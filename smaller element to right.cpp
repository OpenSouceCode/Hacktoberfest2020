#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node{
	int val;
	Node *left;
	Node *right;
	int cnt;
	Node(int d){
		this->val=d;
		this->cnt=1;
		this->left=this->right=nullptr;
	}
};
int insert(Node * &root1,int v){
	int smaller=0;
	Node *temp= new Node(v);
	bool connected=false;
	Node *root=root1;
	while(!connected){
		if(v<=root->val){
			root->cnt+=1;
			if(root->left==nullptr){
				root->left=temp;
				connected=true;
			}else{
				root=root->left;
			}
		}else{
			smaller+=root->cnt;
			if(root->right==nullptr){
				root->right=temp;
				connected=true;
			}else{
				root=root->right;
			}
		}
	}
	//temp->cnt+=smaller;
	return smaller;
}
vector<int> countSmaller(vector<int>v)
{
	int n=v.size();
	vector<int>ans(n,0);
	ans[n-1]=0;
	Node *root = new Node(v[n-1]);
	for(int i=n-2;i>=0;i--){
		int cnt=insert(root,v[i]);
		ans[i]=cnt;
	}
	//reverse(ans.begin(),ans.end());
	return ans;
}
int main()
{
  vector<int>v;
  v.push_back(7);
  v.push_back(2);
  v.push_back(9);
  v.push_back(6);
   v.push_back(8);
  v.push_back(1);
  vector<int>ans = countSmaller(v);
  for(int i=0;i<ans.size();i++){
  	cout<<ans[i]<<" ";
  }
 return 0;
}

