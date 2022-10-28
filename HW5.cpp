#include<iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* Lchild;
    TreeNode* Rchild;
};

void preorder(TreeNode* root);
void inorder(TreeNode* root);
void postorder(TreeNode* root);

int main(){

    int n;
    cin >> n;
    while (n--)//execute round
    {
        int dataNum;
        cin >> dataNum;
        TreeNode Tree[1200];
        //input binary tree
        for(int i = 1; i <= dataNum; i++){
            cin >> Tree[i].data;
            if((i * 2) <= dataNum){
                Tree[i].Lchild = &Tree[i*2];
                if(i*2+1 <= dataNum){
                    Tree[i].Rchild = &Tree[i*2+1];
                }
                else{
                    Tree[i].Rchild = NULL;
                }
            }
            else{
                Tree[i].Lchild = NULL;
            }
        }

        preorder(&Tree[1]); cout << "\n";
        inorder(&Tree[1]); cout << "\n";
        postorder(&Tree[1]); cout << "\n";
    }

    return 0;
}

void preorder(TreeNode* root)
{
    if(root){
        cout << root->data << " ";
        preorder(root->Lchild);
        preorder(root->Rchild);
    }
}

void inorder(TreeNode* root)
{
    if(root){
        inorder(root->Lchild);
        cout << root->data << " ";
        inorder(root->Rchild);
    }
}

void postorder(TreeNode* root)
{
    if(root){
        postorder(root->Lchild);
        postorder(root->Rchild);
        cout << root->data << " ";
    }
}