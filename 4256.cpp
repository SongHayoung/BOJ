#include <iostream>
using namespace std;
struct Node{
    Node* l;
    Node* r;
    int val;
};
int tc, n;
int preOrder[1000];
int inOrder[1000];
Node* initNode() {
    Node* node = new Node();
    node-> val = -1;
    node->l = node->r = nullptr;
    return node;
}
Node* buildNode(Node* node, int pStart, int pEnd, int iStart, int iEnd) {
    if(pStart > pEnd || iStart > iEnd) return nullptr;
    node = initNode();
    node->val = preOrder[pStart];
    if(pStart == pEnd) return node;
    int inOderPos;
    for(inOderPos = iStart; inOderPos <= iEnd; inOderPos++)
        if(inOrder[inOderPos] == preOrder[pStart])
            break;
    node -> l = buildNode(node->l, pStart + 1, pStart + inOderPos - iStart, iStart, inOderPos-1);
    node -> r = buildNode(node->r, pStart + inOderPos - iStart + 1, pEnd, inOderPos+1, iEnd);
    return node;
}
void postOrder(Node* node) {
    if(node->l != nullptr) postOrder(node->l);
    if(node->r != nullptr) postOrder(node->r);
    printf("%d ",node->val);
}
int main(){
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&preOrder[i]);
        for(int i = 0; i < n; i++)
            scanf("%d",&inOrder[i]);
        postOrder(buildNode(nullptr, 0, n - 1, 0, n - 1));
        printf("\n");
    }
}
