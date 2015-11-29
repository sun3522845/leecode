class Solution {
public:
    int majorityElement(vector<int> &num) {
     
       
	  if (num.size()==1)
			  {
		  	  return num[0];
			  }
       map<int,int> keyMap;
       for(vector<int>::iterator it=num.begin();it!=num.end();it++)
       {

           if(keyMap.count(*it)==0)
           {
        	   keyMap[*it]=1;
           }
           else
           {
        	   keyMap[*it]++;

           }
       }

       for(map<int,int>::iterator it = keyMap.begin();it!=keyMap.end();it++)
       {
    	   if(it->second > num.size()/2)
    	   {
    		   return it->first;
    	   }

       }
       return 0;
    }
};