#ifndef _HEADER_
#define _HEADER_
#include "header.hpp"
#endif

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class BinaryTreeUtils {
private:
    vector<string> input() {
        string input;
        cin >> input;
        input = input.substr(1, input.length() - 2);
        vector<string> data;
        if (input.empty()) return data;
        int i = -1, j;
        do {
            input = input.substr(i + 1);
            j = input.find(",");
            data.push_back(input.substr(0, j));
            i = j;
        } while (i != -1);
        return data;
    }
    
    void dfs(TreeNode*& root, vector<string>& data, int index) {
        int l = 2 * (index + 1) - 1, r = l + 1;
        if (l < data.size()) {
            string str = data[l];
            if (str != "null") {
                TreeNode* t = new TreeNode(stoi(str));
                root->left = t;
                dfs(root->left, data, l);
            }
        }
        if (r < data.size()) {
            string str = data[r];
            if (str != "null") {
                TreeNode* t = new TreeNode(stoi(str));
                root->right = t;
                dfs(root->right, data, r);
            }
        }
    }

public:
    TreeNode* buildTreeDFS() {
        /**
         * 以完全二叉树形式输入数据
         * 如[1,2,3,null,4,5]
         */
        vector<string> data = input();
        if (data.empty()) return nullptr;
        TreeNode* root = new TreeNode(stoi(data[0]));
        dfs(root, data, 0);
        return root;
    }

    TreeNode* buildTree() {
        /**
         * 简化输入, 只需输入每个节点的左右孩子即可
         * 如[1,null,2,null,3,null,4]为一个仅有右孩子的链
         */
        vector<string> data = input();
        if (data.empty()) return nullptr;
        TreeNode* root = new TreeNode(stoi(data[0]));
        queue<TreeNode*> qu;
        qu.push(root);
        int i = 1;
        while (i < data.size()) {
            string ldata = data[i++];
            string rdata = data[i++];
            if (rdata.empty()) rdata.assign("null");
            TreeNode* t = qu.front();
            qu.pop();
            if (ldata != "null") {
                t->left = new TreeNode(stoi(ldata));
                qu.push(t->left);
            }
            if (rdata != "null") {
                t->right = new TreeNode(stoi(rdata));
                qu.push(t->right);
            }
        }
        return root;
    }

    void destroyTree(TreeNode*& root) {
        if (!root) return;
        else {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
            root = nullptr;
        }
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        else {
            int l = maxDepth(root->left);
            int r = maxDepth(root->right);
            return max(l, r) + 1;
        }
    }
};

// int main(int argc, char* argv[]) {
//     BinaryTreeUtils util;
//     TreeNode* root = util.buildTree();
//     util.destroyTree(root);
//     return 0;
// }