class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        vector<int>::iterator lt = nums.begin();
		 int result=0;
		 for(vector<int>::iterator it=nums.begin();it!=nums.end();)
		 {
			 if(lt==it)
			 {
				it++;
				result++;
			 }
			else if(*lt==*it)
			{
				it=nums.erase(it);	
			}
			else
			{
			
				lt=it;
				
			}
		 }
		 return result;

    }
};