class Vertex{
    public:
        int next[26];
        bool output = false;

        Vertex()
        {
            // memset(next,-1,sizeof(next));
            for(int i=0;i<26;i++)
                next[i] = -1;
            
            output = false;
        }
};


class PrefixTree {
public:
    vector<Vertex> root;
    
    PrefixTree() {
        root.emplace_back();
    }
    
    void insert(string word) {
        int v = 0;
        for(auto ch:word)
        {
            int c = ch-'a';
            if(root[v].next[c] == -1)
            {
                root[v].next[c] = root.size();
                root.emplace_back();
            }
            
            v = root[v].next[c];
        }

        root[v].output = true;
    }
    
    bool search(string word) {
        int v = 0;
        for(auto ch:word)
        {
            int c = ch-'a';
            if(root[v].next[c] == -1)
                return false;
            
            v = root[v].next[c];
        }

        return root[v].output;


    }
    
    bool startsWith(string prefix) {

        int v = 0;
        for(auto ch:prefix)
        {
            int c = ch-'a';
            if(root[v].next[c] == -1)
                return false;
            
            v = root[v].next[c];
        }

        return true;
        
    }
};
