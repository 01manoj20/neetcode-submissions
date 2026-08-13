class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        int max_a(-1),max_b(-1),max_c(-1);

        bool a(false),b(false),c(false);

        for(int i=0;i<n;i++)
        {
            max_a = max(max_a,triplets[i][0]);
            max_b = max(max_b,triplets[i][1]);
            max_c = max(max_c,triplets[i][2]);
            if(target[0] == triplets[i][0]){
                if((target[1] >= triplets[i][1]) && (target[2] >= triplets[i][2]))
                    a = true;
            }
            if(target[1] == triplets[i][1]){
                if((target[0] >= triplets[i][0]) && (target[2] >= triplets[i][2]))
                    b = true;
            }
            if(target[2] == triplets[i][2]){
                if((target[0] >= triplets[i][0]) && (target[1] >= triplets[i][1]))
                    c = true;
            }
            
        }

        if(a && b && c)
            return true;
        else return false;

            



    }
};
