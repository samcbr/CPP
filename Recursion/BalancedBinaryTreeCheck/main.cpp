#include <iostream>

using namespace std;

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

Problem - Leetcode 110
https://leetcode.com/problems/balanced-binary-tree/
*/

/*
Approach- Recursion

We will use two recursive functions

1. int findHeight(TreeNode* root)
This function is used to find height of given tree. Basically, using this function we will find out height of left and right subtree of given tree.

1.a Base case
 root==NULL or root is leaf then height will be zero

1.b Hypothesis
 findHeight returns height of the given tree

1.c Induction
 height of a given tree is 1 plus max of height of left subtree and height of right subtree

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

2. boolean isBalanced(TreeNode* root)
This function basically tells if the given tree is balanced or not
A tree is balanced if all its subtrees are also balance along with it

2.a Base Case
 root==NULL then tree is balanced

2.b Hypothesis
 isBalanced returns whether a given tree is balanced or not

2.c Induction
 If all subtrees are balanced then check whether the given tree is balanced or not using findHeight function to find the difference in height of left subtree and right subtree
 else return false
*/

//Used to determine the height of a binary tree
int findHeight(TreeNode* root)  //Hypothesis
{
        if(root==NULL)  //Base case 1
        {
            return 0;
        }
        if(root->left==NULL&&root->right==NULL) //Base case 2
        {
            return 0;
        }
        else
        {
            return 1+max(findHeight(root->left),findHeight(root->right));   //Induction Step
        }
}

//Used to check whether a binary tree is balanced or not
//This function goes in depth and finds out if any subtree of the given tree is imbalanced or not
//If all subtrees are balanced then true is returned else false is returned
bool isBalanced(TreeNode* root)
{
        if(root==NULL)  //Base Condition
        {
            return true;
        }
        //Induction
        //If all subtrees are balanced
        if(isBalanced(root->left)&&isBalanced(root->right)) //Recursive call to go depth first on all subtrees to find whether all of them are balanced
        {

            //check whether the tree is balanced
            int leftHeight=0;
            int rightHeight=0;
            if(root->left!=NULL)
                leftHeight=1+findHeight(root->left);
            else
                leftHeight=findHeight(root->left);

            if(root->right!=NULL)
            {
                rightHeight=1+findHeight(root->right);
            }
            else
            {
                rightHeight=findHeight(root->right);
            }
            cout<<leftHeight<<" "<<rightHeight;
            return abs(leftHeight-rightHeight)<=1;  //return true or false
        }
        return false;   //return false if any subtree is imbalanced

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
