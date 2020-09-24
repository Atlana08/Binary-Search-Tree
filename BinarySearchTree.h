//
//  BinarySearchTree.h
//  Binary Tree
//
//  Created by Cara Drake on 1/15/20.
// Collaberators: Eden Bui, Chloe Tu, as well as assistance form TA Jason Schuchardt and Big C++ for resources on how to write a BinarySearchTree
//"I pledge that I have neither given nor received unauthorized assistance on this assignment."
//  Copyright © 2020 Cara Drake. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include <iostream>
#include <string>
class TreeNode{
public:
    //For the copy helper function to work, there needed to be more TreeNode declarations
    TreeNode();
    TreeNode(std::string data);
    void insert_node (TreeNode* new_model);
    void print_nodes() const;
    bool find(std::string value)const;
private:
    std::string data;
    TreeNode* left;
    TreeNode* right;
    friend class BinarySearchTree;
};


class BinarySearchTree{
public:
    BinarySearchTree();
    //New things added
    //Will delete the BinarySearchTree and prevent Memory Leaks
    ~BinarySearchTree();
    //Copy Constructor - will create a deep copy of the BinarySearch Tree
    BinarySearchTree(const BinarySearchTree&);
    //Assignment Operator - will set them equal and create a deep copy
    BinarySearchTree& operator=(const BinarySearchTree& other);
    
    void insert(std::string data);
    void erase(std::string data);
    int count(std::string data) const;
    void print()const;
private:
    TreeNode* root;
    //This is the destructor helper function
    void kill_tree(TreeNode* other){
        //If the other is equal to nullptr - then it is already empty and will end that part of the recurvise function
        if(other == nullptr){
            return;
        }
        //If the left side of the tree is empty it will check if the right one is as well: If both are empy then it will delete the current other pointer
        if(other->left == nullptr){
            if(other->right==nullptr){
                delete other;
                other = nullptr;
            }
            //If the right side is not empty it will recurively call this function until it is empty
            else{
                kill_tree(other->right);
            }
        }
        //If the left side is not empty it will recurively call this function until it is empty
        else{
            kill_tree(other->left);
        }
    }
    //Copy helper function- this will return a pointer that is the new root of a deep copy of the source pointer
    TreeNode* copy(const TreeNode* source){
        //if the source is a nullptr, then it will return a nullptr
        if(source ==nullptr){
            return nullptr;
        }
        //This will create a new TreeNode and a pointer to it that replicates the source's TreeNode in that position
        else{
            TreeNode* ans = new TreeNode(source->data);
            ans->left = copy (source->left);
            ans->right = copy (source->right);
            return ans;
        }
        
    }
    
    
};
#endif /* BinarySearchTree_h */
