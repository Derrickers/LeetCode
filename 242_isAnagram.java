class Solution {
    public boolean isAnagram(String s, String t) {
        int[] alphs = new int[26];
        int[] alpht = new int[26];
        for(int i = 0;i<26;i++){
            alphs[i] = 0;
            alpht[i] = 0;
        }
        for(int i = 0;i<s.length();i++){
            alphs[s.charAt(i)-'a']++;
        }
        for(int i = 0;i<t.length();i++){
            alpht[t.charAt(i)-'a']++;
        }
        for(int i = 0;i<26;i++){
            if(alphs[i]!=alpht[i])
                return false;
        }
        return true;
    }
}