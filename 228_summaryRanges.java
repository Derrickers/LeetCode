class Solution {
    public List<String> summaryRanges(int[] nums) {
        int index = 0;
        List<String> res = new ArrayList<>();
        int b,e;
        while(index<nums.length){
            b = nums[index];
            e = nums[index++];
            while(index<nums.length&&nums[index] == e+1){
                index++;
                e++;
            }
            if(e == b){
                res.add(b+"");
            }else{
                res.add(b+"->"+e);
            }
        }
        return res;
    }
}