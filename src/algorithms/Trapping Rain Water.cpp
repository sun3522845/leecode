class Solution {
public:
     	   int trap(int A[], int n)
	   {
		   int result=0;
		   int max=-1;
		   int max2=-1;
		   stack<int> stk;
		   for(int i=0;i<n;i++)
		   {
			   if(A[i]>max)
			   {
				   while(!stk.empty()&&A[stk.top()]<max)
				   {
					   stk.pop();
				   }
				   stk.push(i);
				   max=A[i];
			   }
			   else if(A[i]>max2)
			   {
				   while(!stk.empty()&&A[stk.top()]<=max2)
				   {
					   stk.pop();
				   }
				   stk.push(i);
				   max2=A[i];
			   }
			   else if(A[i]>A[i-1])
			   {
				   while(!stk.empty()&&A[stk.top()]<A[i])
				   {
					   stk.pop();
				   }
				   stk.push(i);
			   }
		   }

		   while(stk.size()>=2)
		   {
			   int tmp1 = stk.top();
			   stk.pop();
			   int tmp2 = stk.top();
			   int k = A[tmp1]<A[tmp2]?A[tmp1]:A[tmp2];
			   for(int i=tmp2+1;i<tmp1;i++)
			   {
				   if((k-A[i])>0)
					result+=(k-A[i]);
			   }
		   }

		   return result;
        
	  }
};