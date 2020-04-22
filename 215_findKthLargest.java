class Solution {
    public int quickSort(int b,int e,int[] nums,int k){
        int tar = nums[b],now = b;
        int i = b,j = e;
        while(i<j){
            while(j>now&&nums[j]<=tar)
                j--;
            nums[now] = nums[j];
            nums[j] = tar;
            now = j;
            while(now>i&&nums[i]>=tar)
                i++;
            nums[now] = nums[i];
            nums[i] = tar;
            now = i;
        }
        if(k == now)
            return tar;
        else if(k>now)
            return quickSort(now+1,e,nums,k);
        else
            return quickSort(b,now-1,nums,k);
    }

    public int findKthLargest(int[] nums, int k) {
        return this.quickSort(0,nums.length-1,nums,k-1);
    }
}