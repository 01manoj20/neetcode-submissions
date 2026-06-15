class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto n:nums)
        {
            if(pq.size()<k)
                pq.push(-n);
            else
            {
                auto cur = -pq.top();
                if(n>cur)
                {
                    pq.pop();
                    pq.push(-n);
                }
            }
        }

        return -pq.top();
    }
};
