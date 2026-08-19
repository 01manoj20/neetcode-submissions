class KthLargest {
public:
    priority_queue<int> pq;
    int k_g;

    KthLargest(int k, vector<int>& nums) {
        k_g = k;
        for(auto n:nums){
            pq.push(-n);

            if(pq.size()>k)
                pq.pop();
        }

        
        
    }
    
    int add(int val) {

        int top = -1e9;
        if(pq.size()>0)
            top = -pq.top();

        if(val<=top)
            return top;
        else
            pq.push(-val);

        if(pq.size()>k_g)
            pq.pop();

        return -pq.top();
        
    }
};
