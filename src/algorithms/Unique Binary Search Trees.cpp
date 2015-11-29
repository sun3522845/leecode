class Solution {
public:
    int numTrees(int n) {
        
        if(n==1||n==0)
        return 1;
        int result=0;
        for(int i=1;i<=n;i++)
        {
           int num=numTrees(i-1)*numTrees(n-i) ;
           result+=num;
        }
        return result;
    }
};