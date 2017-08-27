/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void pathSumrecur(TreeNode *root, int sum_left, vector<int> &current, 
vector<vector<int> > &res) 
{
    if (root == NULL) 
    return;

    sum_left-= root->val;
    current.push_back(root->val);

    if (root->left == NULL && root->right == NULL) {
        if (sum_left == 0) {
            res.push_back(current);
        }
        current.pop_back();
        return;
    }


    pathSumrecur(root->left, sum_left, current, res);
    pathSumrecur(root->right, sum_left, current, res);

    current.pop_back();
    return;
}
 
 
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > res;
    vector<int> current;
    pathSumrecur(root, sum, current, res);
    return res;
}
