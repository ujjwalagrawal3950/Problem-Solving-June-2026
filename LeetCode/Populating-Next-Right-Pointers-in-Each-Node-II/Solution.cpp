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
23        if(root->left) root->left->next = root->right;
24
25        Node*temp = root->next;
26
27        while(temp){
28            if(temp->left){
29
30                // Also Possible that root->right and root->left isn't exits so we have to check that as well
31
32                if(root->right) root->right->next = temp->left;
33                else if(root->left) root->left->next = temp->left;
34
35                break;
36            }
37            if(temp->right){
38
39                if(root->right) root->right->next = temp->right;
40                else if(root->left) root->left->next = temp->right;
41
42                break; // We Found the next node so we just break the loop
43            }
44
45            temp = temp->next; // Go to the next side of current next tree
46        }
47
48        ConnectTree(root->right);
49        ConnectTree(root->left);
50
51        return root;
52    }
53public:
54    Node* connect(Node* root) {
55        return ConnectTree(root);
56    }
57};