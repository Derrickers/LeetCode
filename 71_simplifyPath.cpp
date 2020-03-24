class Solution {
public:
    string simplifyPath(string path) {
        string dirs[path.size()];
        int top = 0;
        for(int i = 1;i<path.size();i++){
            string dir = "";
            while(i<path.size()&&path[i]!='/')
                dir+=path[i++];
            if(dir == ".."){
                if(top>0)
                    top--;
            }else if(dir != "."&&dir!="")
                dirs[top++] = dir;
        }
        string res = "";
        if(top == 0)
            return "/";
        for(int i = 0;i<top;i++)
            res=res+"/"+dirs[i];
        return res;
    }
};