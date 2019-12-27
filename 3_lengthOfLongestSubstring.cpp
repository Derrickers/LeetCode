/**
 *@author:Derricker
 *@date:2019/12/25
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0,end = 0;
        int maxlen = 0;
        map<char,int> alph;//用于记录上次这个元素出现的位置
        map<char,int>::iterator iter;
        while(end<s.size()){
           iter = alph.find(s[end]);
           if(iter == alph.end()){//当前还未出现过该字符元素
                alph.insert(pair<char,int>(s[end],end));//记录第一次出现的位置
                end++;//下标移动到下一个位置
           }else{
               int lastind = iter->second;//上次出现的位置
                iter->second = end;//更新元素最近所在位置
               if(lastind>=begin){//如果出现在窗口之中，需要更新begin位置
                    maxlen = maxlen<end-begin?end-begin:maxlen;//确认当前窗口大小
                    begin = lastind+1;//移动begin
                }
                end++;
            }
        }
        return maxlen>end-begin?maxlen:end-begin;
    }
};
