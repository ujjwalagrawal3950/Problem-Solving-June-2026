bool isSame(TreeNode*p , TreeNode*q){
    if(p == NULL && q == NULL){return true;}
    if(p == NULL || q == NULL){return false;}
    if(p->val == q->val){return true;}  // BUG: This returns true just because values match, without checking children
    if(isSame(p->left, q->left) && isSame(p->right, q->right)){
        return true;
    }
    return false;
}