#include <string>
class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]){    // O(n)
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        int freq[26] = {0};
        for(int i=0; i<s1.length(); i++){    // O(n)
            freq[s1[i] - 'a']++;
        }
        int windowSize = s1.length();
        
        for(int i=0; i<s2.length(); i++){
            int windowIdx = 0, idx = i;
            int windFreq[26] = {0};

            while(windowIdx < windowSize && idx < s2.length()){
                windFreq[s2[idx] - 'a']++;
                windowIdx++; idx++;
            }

            if(isFreqSame(freq, windFreq)) return true;
        }
        return false;
    }
};
