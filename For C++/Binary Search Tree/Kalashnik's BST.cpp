/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C++
 */

#include <iostream>
using namespace std;

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }
    
    int distanceToAncestor(BSTNode* ancestor, BSTNode* node) {
        int dist = 0;
        while (node != ancestor) {
            if (node->key < ancestor->key) {
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
            dist++;
        }
        return dist;
    }
    
    int distanceBetweenNodes(BSTNode* root, BSTNode* p, BSTNode* q) {
        BSTNode* lca = findLCA(root, p, q);
        int dist1 = distanceToAncestor(lca, p);
        int dist2 = distanceToAncestor(lca, q);
        return dist1 + dist2;
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }
    
    BSTNode* search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }


private:
    // Utility Function
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }
    
    BSTNode* findLCA(BSTNode* root, BSTNode* p, BSTNode* q) {
        if (root == NULL || p == root || q == root) {
            return root;
        }
        BSTNode* left = findLCA(root->left, p, q);
        BSTNode* right = findLCA(root->right, p, q);
        if (left != NULL && right != NULL) {
            return root;
        }
        return (left != NULL) ? left : right;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

 int getHeight(BSTNode *root) {
        if (root == nullptr) {
            return -1;  // Base case for empty tree
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return 1 + max(leftHeight, rightHeight); // add one to the maximum height of the left and right subtrees
}

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    set.insert(6);
    set.insert(1);
    set.insert(8);
    set.insert(12);
    set.insert(1);
    set.insert(3);
    set.insert(7);

    set.traverseInorder();
    puts("");

    cout << getHeight(set._root) << endl;
    
    BSTNode* node1 = set.search(set._root, 8);
    BSTNode* node2 = set.search(set._root, 12);

    int dist = set.distanceBetweenNodes(set._root, node1, node2);
    cout << "Distance between " << node1->key << " and " << node2->key << " is " << dist << endl;
    return 0;
}
