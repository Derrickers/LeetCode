class WordDictionary {
public:
    WordDictionary *node[26];
    bool isEnd = false;
    /** Initialize your data structure here. */
    WordDictionary() {
        for(int i = 0;i<26;i++)
            node[i] = NULL;
        isEnd = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *now = this;
        for(int i = 0;i<word.size();i++){
            int ind = word[i]-'a';
            if(now->node[ind]==NULL)
                now->node[ind] = new WordDictionary();
            now = now->node[ind];
        }
        now->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(0,word,this);
    }
    bool dfs(int i,string word,WordDictionary *now){
        if(i == word.size()){
            return now->isEnd;
        }
        if(word[i]=='.'){
            for(int j = 0;j<26;j++){
                if(now->node[j]!=NULL){
                    if(dfs(i+1,word,now->node[j]))
                        return true;
                }
            }
            return false;
        }
        int index = word[i]-'a';
        if(now->node[index] == NULL)
            return false;
        else 
            return dfs(i+1,word,now->node[index]);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */