class Solution {
public:
    double Solve(vector<int>& A, vector<int>& B, int s, int e, int m, int n){
        int x=s+(e-s)/2, y=(m+n+1)/2-x, al, bl, ar, br;
        al=(x>0) ? A[x-1]:INT_MIN;
        bl=(y>0) ? B[y-1]:INT_MIN;
        ar=(x<m) ? A[x]:INT_MAX;
        br=(y<n) ? B[y]:INT_MAX;
        if(al<=br && bl<=ar){
            if((m+n)&1)
             return (max(al, bl)+min(ar, br))/2.0;
        }
        else if(al<=br)
            return Solve(A, B, x+1, e, m, n);
        else
            return Solve(A, B, s, x-1, m, n);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        if(!m && n){
            if(n&1)
                return nums2[n/2];
            return (nums2[n/2]+nums2[n/2-1])/2.0;
        }
        else if(m && !n){
            if(m&1)
                return nums1[m/2];
            return (nums1[m/2]+nums1[m/2-1])/2.0;
        }
        if(m<n)
            return Solve(nums1, nums2, 0, m-1, m, n);
        return Solve(nums2, nums1, 0, n-1, n, m);
    }
};
