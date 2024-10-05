class Solution {
    public boolean checkInclusion(String s1, String s2) {
       if(s1.length() > s2.length()){
            return false;
        }
        
        int[] ct1 = new int[26];

        for(char it : s1.toCharArray()){
            ct1[it-'a']++;
        }

        int[] ct2 = new int[26];

        int k = s1.length();

        int i = 0;

        while(i < k){
            ct2[s2.charAt(i++) - 'a']++;
        }

        if(Arrays.equals(ct1, ct2)){
            return true;
        }

        k = s2.length();
        int j = 0;

        while(i < k){

            ct2[s2.charAt(j++)-'a']--;
            ct2[s2.charAt(i++)-'a']++;

            if(Arrays.equals(ct1, ct2)){
                return true;
            }
        }

        return false;
    }
}
