using ll = long long;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<ll> pq;
        for(auto s:stones)
            pq.push(s);

        while(pq.size()>1)
        {
            auto stone_1 = pq.top();
            pq.pop();
            auto stone_2 = pq.top();
            pq.pop();


            if(stone_1 != stone_2)
                pq.push(abs(stone_1-stone_2));
        }

        if(pq.size())
            return pq.top();
        else
            return 0;
        
    }
};
