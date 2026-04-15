using ll = long long;

class KthLargest {
public:
    
    priority_queue <ll> less_pq;
    ll kth;


    KthLargest(int k, vector<int>& nums) {


        kth = k;

        for(auto num:nums)
            less_pq.push(-num);

        cout<<less_pq.size()<<endl;

        while(less_pq.size()>k)
        {
            auto top = less_pq.top();
            less_pq.pop();
        }

       // cout<<less_pq.size()<<" "<<less_pq.top()<<endl;
    }
    
    int add(int val) {

        ll top = -1e9;

        if(less_pq.size()>0)
            top = -less_pq.top();
        

        cout<<top<<endl;

        if(val<=top)
            return top;
        else{
            less_pq.push(-val);
        }

        if(less_pq.size()>kth)
            less_pq.pop();


        
        return -less_pq.top();

    }
};
