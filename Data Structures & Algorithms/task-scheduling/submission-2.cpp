class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(auto c:tasks){
            freq[c-'A']++;
        }

        int time = 0;


        priority_queue<pair<int,char>> pq;

        for(int i=0;i<26;i++)
        {
            if(freq[i])
                pq.push({freq[i],'A'+i});
        }

        queue<pair<int,char>> q;

        while((!q.empty()) || (!pq.empty()))
        {
            time++;
            cout<<time<<endl;
            if(!pq.empty())
            {
                auto cur = pq.top();
                freq[cur.second-'A']--;
                pq.pop();


                cout<<"processed "<<freq[cur.second-'A']<<" "<<cur.second<<" "<<pq.size()<<endl;
            
                if(freq[cur.second - 'A']>0){
                    cout<<"pushed in queue"<<freq[cur.second-'A']<<" "<<cur.second<<endl;
                    q.push({time,cur.second});
                }
            }
            

            int run = 0;
            while((!q.empty()))
            {
                auto old = q.front();
                if((time-old.first)>=n)
                {
                    cout<<"in queue "<<freq[old.second-'A']<<" "<<old.second<<endl;
                    pq.push({freq[old.second-'A'],old.second});
                    q.pop();
                }
                else
                    break;
            }

        }

        return time;

    }
};
