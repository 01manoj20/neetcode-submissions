class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;

        sort(hand.begin(),hand.end());

        map<int,int> mp;
        for(auto elm:hand)
            mp[elm]++;
    
        int cur_elm = hand[0];
        int count = 0;
        int next_elm = -1;

        while(count <n)
        {
            if(next_elm!=-1){
                cur_elm = next_elm;
                next_elm = -1;
                // cout<<"here\n"<<next_elm<<endl;
            }
            else{
                // cout<<"here2\n";
                for(auto e:hand)
                {
                    if(mp[e]){
                        cout<<e<<" "<<mp[e]<<endl;
                        cur_elm = e;
                        break;
                    }
                }
            }
            // cout<<cur_elm<<":\n";
            for(int i=0;i<groupSize;i++)
            {
                if(mp[cur_elm+i] > 0){
                    count++;
                    mp[cur_elm+i]-=1;

                    // cout<<cur_elm+i<<" "<<mp[cur_elm+i]<<" "<<((mp[cur_elm+i]>0) && (next_elm == -1))<<endl;

                    if((mp[cur_elm+i]>0) && (next_elm == -1))
                        next_elm = cur_elm+i;
                }
                    
                else    return false;       
            }
            // cout<<endl;
        }

        return true;

    }
};
