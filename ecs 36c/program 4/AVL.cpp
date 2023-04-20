#include "AVL.h"

#include <cassert>
#include <iostream>
#include <string>
#include <queue>

#include "json.hpp"

AVLTree::AVLTree(){
    size = 0;
    height = 0;
}

void AVLTree::Insert(int key){
    tree.Insert(key);
    BalanceTree(tree.root_);
}

int AVLTree::BalanceTree(std::shared_ptr<BSTNode> node){
    int balanceFactor;
    if(node->IsLeaf()){
        return 0;
    }else if(node->HasRightChild() && node->HasLeftChild()){
        int leftBalance = BalanceTree(node->left_);
        int rightBalance = BalanceTree(node->right_);
        int leftHeight = GetHeight(node->left_);
        int rightHeight = GetHeight(node->right_);
        balanceFactor = rightHeight - leftHeight;
        if(balanceFactor >=2){
            if(rightBalance >= 0){
                llRotate(node);
            }else{
                lrRotate(node);
            }
        }else if(balanceFactor <= -2){
            if(leftBalance <= 0){
                rrRotate(node);
            }else{
                rlRotate(node);
            }
        }
    }else if(node->HasRightChild()){
        int rightBalance = BalanceTree(node->right_);
        int rightHeight = GetHeight(node->right_);
        balanceFactor = rightHeight + 1;
        if(balanceFactor >= 2){
            if(rightBalance >= 0){
                llRotate(node);
                balanceFactor = BalanceTree(node);
            }else{
                lrRotate(node);
                balanceFactor = BalanceTree(node);
            }
        }
    }else{
        int leftBalance = BalanceTree(node->left_);
        int leftHeight = GetHeight(node->left_);
        balanceFactor = -1 - leftHeight;
        if(balanceFactor <= -2){
            if(leftBalance <= 0){
                rrRotate(node);
                balanceFactor = BalanceTree(node);
            }else{
                rlRotate(node);
                balanceFactor = BalanceTree(node);
            }
        }
    }
    return balanceFactor;
}

void AVLTree::llRotate(std::shared_ptr<BSTNode> z){
    std::shared_ptr<BSTNode> y = z->right_;
    std::shared_ptr<BSTNode> x = y->right_;
    std::shared_ptr<BSTNode> t2 = y->left_;
    std::shared_ptr<BSTNode> z_parent = z->parent_.lock();
    if(z_parent != nullptr){
        if(z_parent->right_ == z){
            z_parent->right_ = y;
        }else{
            z_parent->left_ = y;
        }
    }
    y->parent_ = z_parent;
    z->right_ = t2;
    if(y->left_ != nullptr){
        t2->parent_ = z;
    }
    y->left_ = z;
    y->right_ = x;
    z->parent_ = y;
    x->parent_ = y;

    if(tree.root_ == z){
        tree.root_ = y;
    }
}

void AVLTree::lrRotate(std::shared_ptr<BSTNode> z){
    std::shared_ptr<BSTNode> y = z->right_;
    std::shared_ptr<BSTNode> x = y->left_;
    std::shared_ptr<BSTNode> z_parent = z->parent_.lock();
    std::shared_ptr<BSTNode> t2 = x->left_;
    std::shared_ptr<BSTNode> t3 = x->right_;
    if(z_parent != nullptr){
        if(z_parent->right_ == z){
            z_parent->right_ = x;
        }else{
            z_parent->left_ = x;
        }
    }
    x->parent_ = z_parent;
    z->right_ = t2;
    if(t2 != nullptr){
        t2->parent_ = z;
    }
    y->left_ = t3;
    if(t3 != nullptr){
        t3->parent_ = y;
    }
    x->left_ = z;
    x->right_ = y;
    z->parent_ = x;
    y->parent_ = x;
    if(tree.root_ == z){
        tree.root_ = x;
    }
}

void AVLTree::rrRotate(std::shared_ptr<BSTNode> z){
    std::shared_ptr<BSTNode> y = z->left_;
    std::shared_ptr<BSTNode> x = y->left_;
    std::shared_ptr<BSTNode> z_parent = z->parent_.lock();
    std::shared_ptr<BSTNode> t3 = y->right_;
    if(z_parent != nullptr){
        if(z_parent->right_ == z){
            z_parent->right_ = y;
        }else{
            z_parent->left_ = y;
        }
    }
    y->parent_ = z_parent;
    z->left_ = t3;
    if(y->right_ != nullptr){
        t3->parent_ = z;
    }
    y->left_ = x;
    y->right_ = z;
    z->parent_ = y;
    x->parent_ = y;
    if(tree.root_ == z){
        tree.root_ = y;
    }
}

void AVLTree::rlRotate(std::shared_ptr<BSTNode> z){ // 604
    std::shared_ptr<BSTNode> y = z->left_; // 447
    std::shared_ptr<BSTNode> x = y->right_; //562
    std::shared_ptr<BSTNode> z_parent = z->parent_.lock();
    std::shared_ptr<BSTNode> t2 = x->left_;
    std::shared_ptr<BSTNode> t3 = x->left_;
    if(z_parent != nullptr){
        if(z_parent->right_ == z){
            z_parent->right_ = x;
        }else{
            z_parent->left_ = x;
        }
    }
    x->parent_ = z_parent;
    y->right_ = t2;
    if(x->right_ != nullptr){
        t2->parent_ = y;
    }
    z->left_ = t3;
    if(x->left_ != nullptr){
        t3->parent_ = z;
    }
    x->left_ = y;
    x->right_ = z;
    z->parent_ = x;
    y->parent_ = x;
    if(tree.root_ == z){
        tree.root_ = x;
    }
}

int AVLTree::GetHeight(std::shared_ptr<BSTNode> node){
    if(node->HasRightChild() && node->HasLeftChild()){
        int leftHeight = GetHeight(node->left_);
        int rightHeight = GetHeight(node->right_);
        if(leftHeight > rightHeight){
            return leftHeight + 1;
        }else{
            return rightHeight + 1;
        }
    }else if(node->IsLeaf()){
        return 0;
    }else if(node->HasRightChild()){
        return GetHeight(node->right_) + 1;
    }else{
        return GetHeight(node->left_) + 1;
    }
}

void AVLTree::JSON(){
    nlohmann::json treeJSON = tree.JSON();
    treeJSON = getHeights(treeJSON, tree.root_);
    std::cout << treeJSON.dump(2) << "\n";
}

nlohmann::json  AVLTree::getHeights(nlohmann::json results, std::shared_ptr<BSTNode> node){
    std::string key = std::to_string(node->key_);
    if(node->IsLeaf()){
        results[key]["height"] = 0;
        results[key]["balance factor"] = 0;
    }else if(node->HasRightChild() && node->HasLeftChild()){
        std::string rightKey = std::to_string(node->right_->key_);
        std::string leftKey = std::to_string(node->left_->key_);
        results = getHeights(results, node->right_);
        results = getHeights(results, node->left_);
        if(int(results[rightKey]["height"]) > int(results[leftKey]["height"])){
            results[key]["height"] = int(results[rightKey]["height"]) + 1;
        }else{
            results[key]["height"] = int(results[leftKey]["height"]) + 1;
        }
        results[key]["balance factor"] = int(results[rightKey]["height"]) - int(results[leftKey]["height"]);
    }else if(node->HasRightChild()){
        std::string rightKey = std::to_string(node->right_->key_);
        results = getHeights(results, node->right_);
        results[key]["height"] = int(results[rightKey]["height"]) + 1;
        results[key]["balance factor"] = int(results[rightKey]["height"]) + 1;
    }else{
        std::string leftKey = std::to_string(node->left_->key_);
        results = getHeights(results, node->left_);
        results[key]["height"] = int(results[leftKey]["height"]) + 1;
        results[key]["balance factor"] = -1 - int(results[leftKey]["height"]);
    }
    if(node == tree.root_){
        results["height"] = results[key]["height"];
    }
    return results;
}
