class Solution {
public:
    
    void print(int input[],int n,vector<int>output,int k,int m,set<vector<int>>&s)
{
    if(k<0)
        return;
 if(k==0)
{
    s.insert(output);
    return;
}
if(n==0)
{
return;
}
    vector<int>out1;
    print(input+1,n-1,output,k,m,s);

    
    int i;
    for( i=0;i<m;i++)
    {out1.push_back(output[i]);}
     out1.push_back(input[0]);
    //   print(input+1,n-1,out1,k-input[0],m+1);
      print(input,n,out1,k-input[0],m+1,s);
     
}
    vector<vector<int>> combinationSum(vector<int>& a, int k) {
     
         sort(a.begin(),a.end());
        int m=0, n=a.size();
        int input[n];
        for(int i=0;i<n;i++)
            input[i]=a[i];
        vector<int>out;
        set<vector<int>>s;
       
          print(input,n,out,k,m,s);
        vector<vector<int>> v;
         for (auto it = s.begin();it != s.end(); it++) 
         { 
            v.push_back(*it);
         } 
        return v;
      
    }
};