1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* left;
7    Node* right;
8    Node* next;
9
10    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
11
12    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
13
14    Node(int _val, Node* _left, Node* _right, Node* _next)
15        : val(_val), left(_left), right(_right), next(_next) {}
16};
17*/
18
19class Solution {
20    Node*ConnectTree(Node*root){
21        if(!root) return root; // we have to skip null nodes Here leaf node will not skips
22
23        if(root->left && root->right) root->left->next = root->right;
24
25        Node*child = (root->right) ? root->right : root->left;
26        if(child){
27        
28            Node*temp = root->next;
29            while(temp){
30                if(temp->left){
31                    child->next = temp->left;
32                    break;
33                }
34                if(temp->right){
35                    child->next = temp->right;
36                    break; // We Found the next node so we just break the loop
37                }
38                temp = temp->next; // Go to the next side of current next tree
39            }
40        }
41
42        ConnectTree(root->right);
43        ConnectTree(root->left);
44
45        return root;
46    }
47public:
48    Node* connect(Node* root) {
49        return ConnectTree(root);
50    }
51};