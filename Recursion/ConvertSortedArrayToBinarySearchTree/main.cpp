#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

 Leetcode problem number: 108
 https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/
/*
Approach - Recursion(IBH)

1. Hypothesis
   void function(vector,left,right,TreeNode* t)
2. Induction
    Find the mid point of the given vector and set it as the value of the tree node.
    Also, create two new tree nodes for left and right child of given tree.Set the new tree nodes as left and right child of the given tree
    Call function recursively for left and mid-1 with tree node left and for mid+1 and right with tree node right
3. Base Case
    if left == right
        set value of tree node and return
    if left>right
        set t as NULL and return

*/
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
    {
        val=0;
        left=NULL;
        right=NULL;
    }
};
void func(vector<int>& nums,int left,int right,TreeNode* t)
{
        if(left==right)
        {
            t->val=nums[left];
            return;
        }
        else if(left>right)
        {
            t=NULL;
            return;
        }
        else
        {
            int mid=(left+right+1)/2;
            t->val=nums[mid];
            TreeNode *leftt=new TreeNode();
            TreeNode *rightt=new TreeNode();
            t->left=leftt;

            func(nums,left,mid-1,t->left);
            if((mid+1)<=right)
            {
                t->right=rightt;
                func(nums,mid+1,right,t->right);
            }

        }
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
        {
            return NULL;
        }
        TreeNode* t=new TreeNode();
        func(nums,0,nums.size()-1,t);
        return t;
    }
void printTree(TreeNode* t)
{
    if(t==NULL)
    {
        cout<<"null"<<" ";
        return;
    }
    cout<<t->val<<" ";
    printTree(t->left);
    printTree(t->right);
}
int main()
{
    int a[]={-2,-1,0,1,2,3};
    vector<int> v(a,a+6);
    TreeNode *t=sortedArrayToBST(v);
    printTree(t);
    return 0;
}
