/**
解法1:双二分查找法，对行和行内元素分别两次二分
**/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0||matrix[0].size() == 0)
            return false;
        int m = matrix.size(),n = matrix[0].size();
        int b = 0,e = m-1;
        int row,mid;
        while(b<=e){
            row = (b+e)/2;
            if(matrix[row][0] == target)
                return true;
            else if(matrix[row][0]<target){
                if(row+1 == m||matrix[row+1][0]>target)
                    break;
                else{
                    b = row+1;
                }
            }else{
                e = row-1;
            }
        }
        b = 0;
        e = n-1;
        while(b<=e){
            mid = (b+e)/2;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] < target)
                b = mid+1;
            else    
                e = mid-1;
        }
        return false;
    }
};
/**
解法2:一次二分
将矩阵映射为一个一维数组
**/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0||matrix[0].size() == 0)
            return false;
        int m = matrix.size(),n = matrix[0].size();
        int b = 0,e = m*n-1;
        int mid;
        int row,col;
        while(b<=e){
            mid = (b+e)/2;
            row = mid/n;
            col = mid%n;
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col]<target)
                b = mid+1;
            else
                e = mid-1;
        }
        return false;
    }
};