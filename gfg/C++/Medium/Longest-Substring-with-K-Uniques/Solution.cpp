class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int l = 0;
        int r = 0;
        int maxlen = -1;
        unordered_map<char,int>mpp;
        int n = s.size();
        
        while (r<n){
            mpp[s[r]]++;
            
            if (mpp.size()> k) {
                mpp[s[l]]--;
                if (mpp[s[l]]==0) {
                    mpp.erase(s[l]);
                }
                
                l++;
            }
            if (mpp.size()== k){
                maxlen = max (maxlen, r-l+1);
            }
            
            r++;
            
        }
        return maxlen; 
    }
};