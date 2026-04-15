class Solution {
public:
    int dif(string word1, string word2)
    {
        int len1 = word1.length();
        int len2 = word2.length();

        if(len1!=len2)
            return 1e9;

        int ans = 0;

        for(int i=0;i<len1;i++)
        {
            if(word1[i]!=word2[i])
                ans++;
        }

        return ans;
    }

    


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        

        if(beginWord == endWord)
            return 0;

        

        int strt = -1,end = -1;

        for(int i=0;i<n;i++)
        {
            // cout<<(wordList[i] == beginWord)<<" "<<(wordList[i] == endWord)<<endl;

            if(wordList[i] == beginWord)
                strt = i;

            if(wordList[i] == endWord)
                end = i;
        }

        if(end == -1)
            return 0;
        
        if(strt == -1){
            wordList.push_back(beginWord);
            strt = n;
            n++;
        }

        

        cout<<strt<<" "<<end<<endl;

        vector<int> distance(n,1e9);
        vector<vector<int>> G(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dif(wordList[i],wordList[j]) == 1)
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }

        

        queue<int> q;
        q.push(strt);
        distance[strt] = 0;


        while(!q.empty())
        {
            auto cur = q.front();

            for(auto neigh:G[cur])
            {
                if(distance[neigh]>1+distance[cur])
                {
                    distance[neigh] = 1 + distance[cur];
                    q.push(neigh);
                }
            }
            q.pop();
        }

        for(int i=0;i<n;i++)
            cout<<distance[i]<<" ";
        cout<<endl;

        if(distance[end]!=1e9)
            return distance[end]+1;
        else
            return 0;


    }
};
