class Solution {
public:
    string convertToTitle(int n) {
        
       string result="";
        while(n>26)
        {
        	int mod = n%26;
        	if(!mod)
        	{
        		result.insert(result.begin(),'Z');
        		n=(n/26-1);
        	}
        	else
        	{
        		result.insert(result.begin(),'A'+mod-1);
        		n=n/26;
        	}



        }
        if(n==0)
        {
        	result.insert(result.begin(),'Z');
        }
        else
        {
        	result.insert(result.begin(),'A'+n-1);
        }
        return result;
        
    }
};