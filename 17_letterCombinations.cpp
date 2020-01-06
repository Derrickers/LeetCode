class Solution {
public:
    map<int,string> alph;
    vector<string> res;
    void Add(string tmp,int ind,string d){
        if(ind == d.size()-1){
            string a = alph.find(d[ind]-'0')->second;
            for(int i = 0;i<a.size();i++){
                string b = tmp;
                tmp+=a[i];
                res.push_back(tmp);
                tmp = b;
            }
            return;
        }
        string a = alph.find(d[ind]-'0')->second;
        for(int i = 0;i<a.size();i++){
            string b = tmp;
            tmp+=a[i];
            Add(tmp,ind+1,d);
            tmp = b;
        }
    }
    vector<string> letterCombinations(string digits) {
        alph[2] = "abc";
        alph[3] = "def";
        alph[4] = "ghi";
        alph[5] = "jkl";
        alph[6] = "mno";
        alph[7] = "pqrs";
        alph[8] = "tuv";
        alph[9] = "wxyz";
        string tmp = "";
        Add(tmp,0,digits);
        return res;
    }
};
