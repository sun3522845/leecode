class Solution {
public:
    int singleNumber(int A[], int n) {
       int  result = A[0]; 
       if(n == 1)
       return result; 
       for(int i = 1; i < n; i++) 
       result ^= A[i]; 
       return result; 
    }
};