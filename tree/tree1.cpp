////////////////Binary Tree construction///////////////
#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createTree(node *root)
{

    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data to insert in left of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter the data to insert in right of data" << data << endl;
    root->right = createTree(root->right);
    return root;
}

// level order traversal

void BFS(node *root)
{

     if(root == NULL) return;
    queue<node *> q;
    q.push(root);
    q.push(NULL); // to know when a level is finished

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

//reverse level order traversal

void reverseLevelOrder(node* root){

       if(root == NULL) return;
       stack<node*>s;
       queue<node*>q;

       q.push(root);

       while(!q.empty()){
     
          node*temp = q.front();
          s.push(temp);
          q.pop();
          if(temp->right)q.push(temp->right);
          if(temp->left)q.push(temp->left);

       }

       while(!s.empty()){
            cout<<s.top()->data<<" ";
            s.pop();
       }
}





int main()
{

    node *root = NULL;
    root = createTree(root);

    // 8 3 4 -1 -1 1 -1 -1 7 5 -1 -1 6 -1 -1

    cout << "Level order traversal" << endl;
    BFS(root);
    cout << "Reverse Level order traversal" << endl;
    reverseLevelOrder(root);

    return 0;
}