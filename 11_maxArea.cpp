class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin = 0,end = height.size()-1;
        int maxsize = -1,tmpsize;
        while(begin<end){
            tmpsize = (end-begin)*min(height[begin],height[end]);
            if(tmpsize>maxsize)
                maxsize = tmpsize;
            if(height[begin]>height[end])
                end--;
            else
                begin++;
        }
        return maxsize;
    }
};
