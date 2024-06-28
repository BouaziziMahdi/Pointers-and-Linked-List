#include <vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
  TreeNode* balanceBST(TreeNode* root) {
       vector<int> nodes;
        
        // Houni, naamlou parcours en ordre (in-order) bch njam3ou les nœuds fel vecteur trié
        inorderTraversal(root, nodes);
        
        // Tawa, nbniw chajra équilibrée aala khater le vecteur trié
        return sortedArrayToBST(nodes, 0, nodes.size() - 1);
    }

private:
    // Fonction bch naamlou parcours en ordre (in-order traversal)
    void inorderTraversal(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorderTraversal(root->left, nodes); // Nparcouriw le sous-arbre gauche
        nodes.push_back(root->val);          // Nzidou la valeur ta3 l'nœud l'actuel
        inorderTraversal(root->right, nodes);// Nparcouriw le sous-arbre droit
    }

    // Fonction bch nbniw un BST équilibré aala khater un vecteur trié
    TreeNode* sortedArrayToBST(vector<int>& nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nodes[mid]); // Naamlou un nœud jdid b la valeur l'mid
        node->left = sortedArrayToBST(nodes, start, mid - 1); // Nbniw le sous-arbre gauche
        node->right = sortedArrayToBST(nodes, mid + 1, end);  // Nbniw le sous-arbre droit
        return node;
    }
};