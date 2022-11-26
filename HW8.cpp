#include<iostream>
#include<queue>
using namespace std;

struct Binode
{
    int data;
    Binode* left{0};
    Binode* right{0};
    Binode() = default;
    Binode(int x) : data(x), left(0), right(0) {};
};

void Level_order(Binode* root) {
	queue<Binode*> Q;
	Q.push(root);
	while (!Q.empty()) {
		Binode* p = Q.front();
		Q.pop();
	    cout << p->data << " ";
		if (p->left) Q.push(p->left);
		if (p->right) Q.push(p->right);
	}
    cout << endl;
}

void inorder(Binode* root, queue<Binode*> queue) 
{
    inorder(root->left, queue);
    queue.push(root);
    inorder(root->right, queue);
}

void SearchI(Binode* root, int index) 
{
    queue<Binode*> q;
    inorder(root, q);
    for(int i = 1; i < index; i++){
        q.pop();
    }
    cout << q.front() << endl;
}

void insertBST(Binode* root, int e)
{
    if(!root){
        root = new Binode(e);
    }
    else if(root->data < e){
        insertBST(root->right, e);
    }
    else if(root->data > e){
        insertBST(root->left, e);
    }
    else{
        cout << "InsertError" << endl;
    }
}

Binode* deleteBST(Binode* root, int e)
{
    if(!root){
        cout << "cannot delete" << endl;
        return root;
    }
    else if(root->data > e){
        deleteBST(root->left, e);
    }
    else if(root->data < e){
        deleteBST(root->right, e);
    }
    else{
        if(!root->left && !root->right){
            delete(root);
            return nullptr;
        }
        else if(!root->right){
            Binode* ret = root->left;
            delete(root);
            return ret;
        }
        else if(!root->left){
            Binode* ret = root->right;
            delete(root);
            return ret;
        }
        else{
            Binode* tmp = root->left;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            root->data = tmp->data;
            root->left = deleteBST(root->left, root->data);//可能有刪錯 等等檢查            
        }
    }
    return root;
}

int height(Binode* root)
{
    if(!root){
        return 0;
    }
    else{
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight >= rightHeight){
            return leftHeight + 1;
        }
        else {
            return rightHeight + 1;
        }
    }
}

int main()
{
    Binode* BST = nullptr;
    while (1)
    {
        string operation;
        cin >> operation;
        if(operation == "insert"){
            int x; 
            cin >> x;
            insertBST(BST, x);
        }
        else if(operation == "delete"){
            int x;
            cin >>x;
            deleteBST(BST, x);
        }
        else if(operation == "height") {
            cout << height(BST) << endl;
        }
        else if(operation == "search"){
            int x;
            cin >> x;
            SearchI(BST, x);
        }
        else if(operation == "traversal"){
            Level_order(BST);
            break;
        }
        else{
            cout << "Invalid operation " << endl;
        }
    }
    
    return 0;   
}