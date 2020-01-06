class Solution {
public:
    vector<string> res;
    void generater(string tmp,int l,int r,int n){
        if(r == n){//递归退出
            res.push_back(tmp);
            return ;
        }
        if(l<n){//还可以加入左括号
            generater(tmp+'(',l+1,r,n);//加入左括号
            if(r<l)
                generater(tmp+')',l,r+1,n);//如果可以加入右括号则加入
        }else
            generater(tmp+')',l,r+1,n);//加入右括号
    }
    vector<string> generateParenthesis(int n) {
        generater("",0,0,n);
        return res;
    }
};
