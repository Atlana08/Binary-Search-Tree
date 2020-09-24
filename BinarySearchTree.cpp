//
//  BinarySearchTree.cpp
//  Binary Tree
//
//  Created by Cara Drake on 1/15/20.
// Collaberators: Eden Bui, Chloe Tu, as well as assistance form TA Jason Schuchardt and Big C++ for resources on how to write a BinarySearchTree
//"I pledge that I have neither given nor received unauthorized assistance on this assignment."
//
//  Copyright © 2020 Cara Drake. All rights reserved.
//

#include "BinarySearchTree.h"
//Based off the Code in Big C++ Chapter 13
//This is the default constructor
BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}
//Based off the Code in Big C++ Chapter 13
//This is the print function that calls the print function of the nodes as well - Printing is not needed but is helpful with debugging
void BinarySearchTree::print()const{
    if(root !=nullptr){
        root->print_nodes();
    }
   
}
//Based off the Code in Big C++ Chapter 13
//Insert function takes in the new data and places it in the tree in the proper position after assigning them to a new TreeNode
void BinarySearchTree::insert(std::string data){
    TreeNode* new_node = new TreeNode();
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    //If this is the first data, it made the root
    if(root ==nullptr){
        root = new_node;
    }
    //The insert_node function will sort the inserted data into the proper location in the tree
    else{
        root->insert_node(new_node);
    }
}
//Based off the Code in Big C++ Chapter 13
//This keeps track of where things are in the BinarySearchTree
int BinarySearchTree::count(std::string data) const{
    if(root == nullptr){
        return 0;
    }
    else if(root->find(data)){
        return 1;
    }
    else{
        return 0;
    }
}
//Based off the Code in Big C++ Chapter 13
//This removes things from within the BinarySearchTree, not in the form of deleting but in the form of reassigning where things are pointing
void BinarySearchTree:: erase(std::string data){
     TreeNode* to_be_removed = root;
    TreeNode* parent = nullptr;
    bool found = false;
    while(!found && to_be_removed !=nullptr){
        if(to_be_removed->data < data){
            parent = to_be_removed;
            to_be_removed =to_be_removed->right;
        }
        else if (data < to_be_removed->data){
            parent= to_be_removed;
            to_be_removed = to_be_removed->left;
        }
        else{
            found =true;
        }
    }
    if (!found){
        return;
    }
    if(to_be_removed->left ==nullptr || to_be_removed->right ==nullptr){
        TreeNode* new_child;
        if(to_be_removed->left == nullptr){
            new_child = to_be_removed->right;
        }
        else{
            new_child = to_be_removed->left;
        }
        if(parent==nullptr){
            root= new_child;
        }
        else if (parent->left == to_be_removed){
            parent->left= new_child;
        }
        else{
            parent->right = new_child;
        }
        return;
    }
    TreeNode* smallest_parent = to_be_removed;
    TreeNode* smallest = to_be_removed->right;
    while(smallest->left != nullptr){
        smallest_parent = smallest;
        smallest = smallest->left;
    }
        to_be_removed->data =smallest->data;
        if(smallest_parent == to_be_removed){
            smallest_parent->right = smallest->right;
        }
        else{
            smallest_parent->left = smallest->right;
        }
}

//Decontructor
BinarySearchTree::~BinarySearchTree(){
    //Calls the deconstructor helper function
   kill_tree(root);
}
//Copy Constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree& other ){
    //Makes a new BinarySearchTree and then sets that equal to the root
    BinarySearchTree* replace = new BinarySearchTree();
    replace->root = copy(other.root);
    root = replace->root;
  
}
//Assignment Operator
BinarySearchTree& BinarySearchTree:: operator = (const BinarySearchTree& other){
    //If they are not already perfectly equal in their addresses of their pointers, than delete the origional and then use the copy helper to make the root equal to the other trees data
    if (this!= &other){
        kill_tree(root);
        root = nullptr;
        root = copy(other.root);
        
    }
    return *this;
}



//This is the default constructor for the TreeNode
TreeNode::TreeNode(){
    left = nullptr;
    right = nullptr;
}
//This is the constructor for the TreeNode with one value
TreeNode::TreeNode(std::string other){
    data= other;
    left = nullptr;
    right = nullptr;
}
//Based off the Code in Big C++ Chapter 13
//this insert_node will orgainze the TreeNode in the proper location based on its size
void TreeNode:: insert_node(TreeNode* new_node){
    if(new_node->data <data){
        if (left==nullptr){
            left = new_node;
        }
        else{
            left->insert_node(new_node);
        }
    }
    else if(data<new_node->data){
        if(right ==nullptr){
            right =new_node;
        }
        else{
            right->insert_node(new_node);
        }
    }
}

//Based off the Code in Big C++ Chapter 13
//This is how to know if the things are equal to what you are searching for in the tree
bool TreeNode::find(std::string value)const{
    if (value<data){
        if (left == nullptr){
            return false;
        }
        else{
            return left->find(value);
        }
    }
    else if( data < value){
        if (right == nullptr){
            return false;
        }
        else{
            return right->find(value);
        }
    }
    else{
        return true;
    }
}
//Based off the Code in Big C++ Chapter 13
//This prints each of the nodes specifically in a recursive fashion
void TreeNode::print_nodes() const{
    
    if (left!= nullptr){
        left->print_nodes();
    }
    std::cout<<data<<"\n";
    if(right!=nullptr){
        right->print_nodes();
    }
    else{
     
    }
   
}

