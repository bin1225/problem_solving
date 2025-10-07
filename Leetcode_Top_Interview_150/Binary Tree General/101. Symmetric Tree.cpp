/*
    time: 20min 
    success: true 
    note: 
*/
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs1(TreeNode* node, vector<int> &path) {
        if(!node) {
            path.push_back(-101);
            return;
        }
        path.push_back(node->val);
        dfs1(node->left, path);
        dfs1(node->right, path);
        return;
    }

    void dfs2(TreeNode* node, vector<int> &path) {
        if(!node) {
            path.push_back(-101);
            return;
        }
        path.push_back(node->val);
        dfs2(node->right, path);
        dfs2(node->left, path);
        return;
    }

    
    bool isSymmetric(TreeNode* root) {
        vector<int> path1;
        vector<int> path2;
        dfs1(root->left, path1);
        dfs2(root->right, path2);

        for(int i=0; i<path1.size(); i++) {
            if(path1[i] != path2[i]) return false;
        }
        
        return path1.size() == path2.size();
    }
};