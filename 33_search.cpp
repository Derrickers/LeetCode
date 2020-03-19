class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b = 0,e = nums.size()-1;
        while(b<=e){
            int mid = (b+e)/2;
            if(nums[mid] == target)
                return mid;
            if(target>nums[mid]){
                if(nums[mid]>=nums[b])
                    b = mid+1;
                else if(target<=nums[e])
                    b = mid+1;
                else
                    e = mid-1;
            }else{
                if(nums[mid]<=nums[e])
                    e = mid-1;
                else if(target>=nums[b])
                    e = mid-1;
                else
                    b = mid+1;
            }
        }
        return -1;
    }
};
