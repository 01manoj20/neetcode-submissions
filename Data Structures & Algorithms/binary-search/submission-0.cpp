class Solution {
public:
    int search(vector<int>& A, int target) {
        
        int l = 0;
        int r = A.size();

        while(l<=r)
        {
            int mid = (l+r)/2;

            if(A[mid] == target)
            {
                int ans = mid;
                return ans;
            }
            if(A[mid]>target)
                r = mid-1;
            else
                l = mid+1;
        }

        return -1;
    }
};
