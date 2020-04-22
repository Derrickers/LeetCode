class Solution {
    List<List<Integer>> res = new ArrayList<>();
    LinkedList<Integer> row = new LinkedList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        dfs(1,k,n);
        return res;
    }

    private void dfs(int index,int k, int n) {
        if(k == 0&&n == 0) {
            res.add(new ArrayList<>(row));
            return;
        }
        if(9*k<n||index*k>n)
            return;
        for(int i = index;i<=9;i++){
            row.addLast(i);
            dfs(i+1,k-1,n-i);
            row.removeLast();
        }
    }
}