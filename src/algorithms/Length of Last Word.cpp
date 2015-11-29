class Solution {
public:
    int lengthOfLastWord(string s) {
    	string::size_type size = s.size();
		int count=0;
		for(int t=size-1;t>=0;t--)
		{
			if(s[t]==' ')
			{
				if(count==0)
				{
					continue;
				}
				else if(count>0)
				{
					return count;
				}
				else
				count=0;
			}
			else if(isalpha(s[t]))
			{
				if(count>=0)
				count++;
			}
			else
			{
				count=-1;
			}
		}
		if(count>0)
		    return count;
		return 0;
    }
};