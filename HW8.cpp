#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Binode
{
    int data;
    Binode* left;
    Binode* right;
    Binode(int x) : data(x), left(NULL), right(NULL) {};
};

int max_num(Binode* node) {
	Binode* current = node;

	// get the rightmost leaf
	while (current && current->right != NULL)
		current = current->right;

	return current->data;
}

void Level_order(Binode* root) {

    if (root == NULL){
        cout << endl ;
    }

	queue<Binode*> Q;
	Q.push(root);
	while (!Q.empty()) {
		Binode* p = Q.front();
		Q.pop();
	    cout << p->data;
		if (p->left) Q.push(p->left);
		if (p->right) Q.push(p->right);
        if(!Q.empty()) cout << " ";
	}
    cout << endl;
}

Binode* insertBST(Binode* root, int e)
{
    if(root == NULL){
        return new Binode(e);
    }
    if(e < root->data){
        root->left = insertBST(root->left,e);
    }
    else if(e > root->data){
        root->right = insertBST(root->right,e);
    }
    return root;
}

Binode* deleteBST(Binode* root, int e)
{
    Binode* current = NULL;
    Binode* parent = NULL;
    bool hasLeft = false;

    // non-empty BST, find the target and its parent
    if(root){
        current = root;
        while(current){

            if(e == current->data){
                break;
            }
            hasLeft = false;
            parent = current;
            if(e > current->data){
                current = current->right;
            }
            else{
                hasLeft = true;
                current = current->left;
            }
        }
        // found the target and delete
        if(current){

            if(!current->left && !current->right){ // no both children

                if(!parent){//如果只有root,parent會戳到NULL
                    return NULL;
                }

                if(hasLeft){
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }
            }

            else if(!current->left){// only right child

                if(!parent){//如果只有root,parent會戳到NULL
                    return current->right;
                }

                if(hasLeft){
                    parent->left = current->right;
                }
                else{
                    parent->right = current->right;
                }
            }

            else if(!current->right){// only left child

                if(!parent){//如果只有root,parent會戳到NULL
                    return current->left;
                }

                if(hasLeft){
                    parent->left = current->left;
                }
                else{
                    parent->right = current->left;
                }

            }
            else{//two children

                int replaceData = max_num(current->left);
                current->data = replaceData;
                current->left = deleteBST(current->left, replaceData);
            }

            return root;           
        }
    }

    cout << "cannot delete" << endl;
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

void search(Binode* root , int index, vector<Binode*>& results)
{
    if(results.size() == index){
        cout << results.back()->data << endl;
        return;
    }

    if(root){
        search(root->left, index, results);
        results.push_back(root);
        search(root->right, index, results);
    }
}

int main()
{
    Binode* BST = NULL;
    
    while (1)
    {
        string operation;
        int x;
        cin >> operation;
        if(operation == "insert"){
            cin >> x;
            BST = insertBST(BST, x);
        }
        else if(operation == "delete"){
            cin >>x;
            BST = deleteBST(BST, x);
        }
        else if(operation == "height") {
            cout << height(BST) << endl;
        }
        else if(operation == "search"){
            vector<Binode*> temp;
            cin >> x;
            search(BST, x, temp);
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