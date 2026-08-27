class Vertex
{
    public:
        int next[26];
        bool output;
        Vertex()
        {
            for(int i=0;i<26;i++)
                next[i] = -1;
            output = false;
        }

};

class WordDictionary {
public:
    vector<Vertex> root;
    WordDictionary() {
        root.emplace_back();
    }   
    
    void addWord(string word) {
        int v = 0;
        for(auto ch: word)
        {
            int c = ch-'a';
            if(root[v].next[c]==-1)
            {
                root[v].next[c] = root.size();
                root.emplace_back();
            }   
            v = root[v].next[c];
        }
        root[v].output = true;
    }

    bool search_helper(string word,int ind, int v)
    {

        if(ind == word.size())
            return root[v].output;

        char ch = word[ind];

        if(ch == '.')
        {
            for(int k=0;k<26;k++)
            {
                if(root[v].next[k]!=-1)
                {
                    if(search_helper(word,ind+1,root[v].next[k]))
                        return true;
                }
            }

            return false;
        }
        else{
            int c = word[ind] - 'a';
            if(root[v].next[c] == -1)
                return false;

            return search_helper(word,ind+1,root[v].next[c]);
        }
    }
    
    bool search(string word) {
        return search_helper(word,0,0);
    }
};
