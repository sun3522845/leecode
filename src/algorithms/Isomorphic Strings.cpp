class Solution {
public:
    bool isIsomorphic(string s, string t) {
         	  if(s.length()!=t.length())
			  return false;
		  map<char,char> cm;
		  for(string::size_type i=0;i<s.length();i++)
		  {
			  if(cm.count(s[i])>0)
			  {
				if(cm[s[i]]!=t[i])
					return false;

			  }
			  else
			  {
				cm[s[i]]=t[i];
			  }
		  }
		  cm.clear();
		    for(string::size_type i=0;i<s.length();i++)
		  {
			  if(cm.count(t[i])>0)
			  {
				if(cm[t[i]]!=s[i])
					return false;

			  }
			  else
			  {
				cm[t[i]]=s[i];
			  }
		  }
		  return true;
    }
};