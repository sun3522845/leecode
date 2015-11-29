class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> tt;
        for(int i=0;i<s.size();i++){
            
            if(tt.count(s[i])){
                tt[s[i]]++;
            }else{
                tt[s[i]]=1;
            }
        }
        for(int i=0;i<t.size();i++){
            if(tt.count(t[i])){
                tt[t[i]]--;
                
            }else{
                return false;
            }
        }
        for(map<char,int>::iterator it=tt.begin();it!=tt.end();it++){
            if(it->second!=0)
            return false;
        }
        return true;
    }
};