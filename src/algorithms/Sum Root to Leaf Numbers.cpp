/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

vector<string> getNodeStringVec(TreeNode *root)
{
	vector<string> result;
	
	
	if(root)
	{
		char digit = '0'+root->val;
		vector<string> leftresult=getNodeStringVec(root->left) ;
		vector<string> rightresult=getNodeStringVec(root->right) ;
		if(leftresult.empty()&&rightresult.empty())
		{
			string tmp ;
			tmp+=digit;
			result.push_back(tmp);
		}
		else
		{
		for(vector<string>::iterator it =leftresult.begin();it!=leftresult.end();it++)
			{
				*it=digit+*it;
				result.push_back(*it);
			}
			for(vector<string>::iterator it =rightresult.begin();it!=rightresult.end();it++)
			{
				*it=digit+*it;
				result.push_back(*it);
			}
		}
	}

	return result;
	
}
int strToNum(string str)
{
	int num=0;
	for(string::size_type st=0;st<str.size();st++)
	{
		int tmp= str[st]-'0';
		num=num*10+tmp;
	}
	return num;
}
int sumNumbers(TreeNode *root) {
        vector<string> result = getNodeStringVec(root);
		int sum=0;
		for( vector<string>::iterator it = result.begin();it!=result.end();it++)
		{
			sum=sum+strToNum(*it);
		}
		return sum;
}



};