#include <bits/stdc++.h>
using namespace std;

struct Node{
    char name;
    Node *leftchild;
    Node *rightchild;
};

Node* buildTree(int start_num, int end_num, char inorder[], map<char,int> preorder){
    
    int tmp_num = preorder[inorder[start_num]];
    int root_num;
    char root_char;
    for(int i = start_num; i < end_num;i++){
        if(preorder[inorder[i]] <= tmp_num){
            tmp_num = preorder[inorder[i]];
            root_char = inorder[i];
            root_num = i;
        }
    }
    Node *node = new Node;
    node->name = root_char;
    node->leftchild = NULL;
    node->rightchild = NULL;
    
    if(root_num-start_num > 0){
        node->leftchild = buildTree(start_num,root_num,inorder,preorder);
    }
    if(end_num-root_num-1 > 0){
        node->rightchild = buildTree(root_num+1,end_num,inorder,preorder);
    }
    
    return node;
}

void postorder(struct Node *root){
    if(root->leftchild != NULL){
        postorder(root->leftchild);
    }
    if(root->rightchild != NULL){
        postorder(root->rightchild);
    }
    cout << root->name << " ";
    return;
}


int main()
{
    int num,input_length;
    char tmp;
    int root_num;
    map <char,int> preorder;
    cin >> num;
    while(num--){
        cin >> input_length;
        preorder.clear();
        char inorder[input_length+1];
        struct Node root;
        for(int i = 0; i <input_length ; i++){
            cin >> tmp;
            preorder[tmp] = i;
            if(i == 0)
                root.name = tmp;
        }
        for(int i = 0; i <input_length ; i++){
            cin >> inorder[i];
            if(inorder[i] == root.name)
                root_num = i;
        }
        root.leftchild = NULL;
        root.rightchild = NULL;
        if(root_num > 0){
            root.leftchild = buildTree(0,root_num,inorder,preorder);
        }
        if(input_length-root_num-1 > 0){
            root.rightchild = buildTree(root_num+1,input_length,inorder,preorder);
        }
        
        postorder(&root);
        cout << endl;
    }

    return 0;
}

// 複習了一下Map
// 記得func裡的struct要 new ，然後用指標 Node *node = new Node;