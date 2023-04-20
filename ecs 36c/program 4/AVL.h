#include "BST.h"


class AVLTree;

class AVLTree {
    public:
        AVLTree();
        void Insert(int key);
        BST tree;
        void JSON();

    private:
        nlohmann::json getHeights(nlohmann::json results, std::shared_ptr<BSTNode> node);
        int BalanceTree(std::shared_ptr<BSTNode> node);
        size_t FindHeight(std::shared_ptr<BSTNode> node);
        void llRotate(std::shared_ptr<BSTNode> z);
        void lrRotate(std::shared_ptr<BSTNode> z);
        void rlRotate(std::shared_ptr<BSTNode> z);
        void rrRotate(std::shared_ptr<BSTNode> z);
        int GetHeight(std::shared_ptr<BSTNode> node);
        size_t height;
        size_t size;
};
