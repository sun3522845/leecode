class Solution {
public:
    int climbStairs(int n) {
        int s[2]={1,1};
        for(int i=1;i<n;i++)
        {
            int tmp=s[1];
            s[1]=s[1]+s[0];
            s[0]=tmp;
        }
        return s[1];
    }
};