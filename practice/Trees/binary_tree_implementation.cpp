#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr), right(nullptr) {};

};
class Solution{
    private:
      void inorderHelper(TreeNode* node, vector<int>&result){
        if(node==nullptr){
            return;
        }
        inorderHelper(node->left,result);
        result.push_back(node->val);
        inorderHelper(node->right,result);
      }
      void preorderHelper(TreeNode *node, vector<int>&result){
        if (node == nullptr) {
            return;
        }
        result.push_back(node->val);
        preorderHelper(node->left,result);
        preorderHelper(node->right,result);

      }
      void postorderHelper(TreeNode *node, vector<int>&result ){
        if (node == nullptr) {
            return;
        }
        postorderHelper(node->left, result);
        postorderHelper(node->right, result);
        result.push_back(node->val);


      }

    public:
      vector<int> inorderTraverse(TreeNode *root){
        vector<int>result;
        inorderHelper(root,result);
        return result;
      }
      vector<int> preorderTraverse(TreeNode *root){
        vector<int>result;
        preorderHelper(root,result);
        return result;

      }
      vector<int> postorderTraverse(TreeNode *root){
        vector<int> result;
        postorderHelper(root, result);
        return result;

      }

};

void printVector(string title, vector<int> final){
    cout<<title<<": [ ";
    for(int i=0; i<final.size();i++){
        cout<<final[i];

        if(i<final.size()-1){
          cout<<", ";
        }

    }
    cout<<" ] ";
}

int main(){
    TreeNode *root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    Solution mySolution;

    vector<int> inorder= mySolution.inorderTraverse(root);
    printVector("Inorder",inorder);
    vector<int> preorder=mySolution.preorderTraverse(root);
    printVector("Preorder",preorder);
    vector<int> postorder=mySolution.postorderTraverse(root);
    printVector("Postorder",postorder);

    return 0;
    

}