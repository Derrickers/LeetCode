class Solution {
public:
    vector<string> res;
    string row;
    int len = 0;
    void dfs(string s,int remain,int index){
        if(remain>len-index||3*remain<len-index)
            return;
        if(remain == 1){
            string sub = s.substr(index,len-index);
            if(isValid(sub)){
                row+=sub;
                res.push_back(row);
            }
            return;
        }
        string tmp = row;
        row = tmp+s[index]+'.';
        dfs(s,remain-1,index+1);
        if(s[index]!='0'){
            row = tmp+s.substr(index,2)+'.';
            dfs(s,remain-1,index+2);
            if(len-index>=3){
                string sub = s.substr(index,3);
                if(isValid(sub)){
                    row = tmp+sub+'.';
                    dfs(s,remain-1,index+3);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        len = s.size();
        dfs(s,4,0);
        return res;
    }
    bool isValid(string s){
        if(s.size()>=2&&s[0] == '0')
            return false;
        int res = 0;
        for(int i = 0;i<s.size();i++){
            res*=10;
            res+=s[i]-'0';
        }
        return res<=255&&res>=0;
    }
};