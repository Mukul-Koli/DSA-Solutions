#include <vector>
using namespace std;

/* Structure of a Binary Search Tree node */

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    void find(Node* r1, int val, vector<int>& vec) {
        if (r1 == nullptr) return;
        
        if ((r1->data) < (val)) {
            find(r1->right, val, vec);
        }
        else if ((r1->data) > (val)) {
            find(r1->left, val, vec);
        }
        else {
            vec.push_back(val);
        }
    }
    void traverse(Node* r1, Node* r2, vector<int> &vec) {
        if (r2 == nullptr) return;
        traverse(r1, r2->left, vec);
        find(r1,r2->data,vec);
        traverse(r1, r2->right, vec);
    }
    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> vec;
        traverse(r1, r2, vec);
        return vec;
    }
};