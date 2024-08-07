#pragma once
#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>
using namespace std;

//STRUCT
struct Node {
    int key;            //for leaves: time, for internal nodes: (min time in right subtree
    int value;          //only for leaves
    int priority;
    Node* left;
    Node* right;
    int weight;             //1 if push and not currently in queue, -1 if pop, 0 if push and currently in queue
    int smax;
    int pmax;
    bool is_leaf; 
    int max_out;
    int min_in;

    Node (int k){               //for the tree of values
        key=k;
        priority=rand();
        left=nullptr;
        right=nullptr;
        //NOT USED:
        value=0;
        weight=0;
        smax=0;
        is_leaf=false;
        max_out=0;
        min_in=0;
    }
    
    Node(int k, int v, int w) {    //Leaf
        key=k;
        value=v;
        left=nullptr;
        right=nullptr;
        priority=0;             //leaves dont have priority
        is_leaf=true;
        weight=w; 
        if(w==1) {
            max_out=v;          //largest element outside q_now in subtree
            min_in=INT_MAX;     //smallest element inside q_now in subtree
        }
        else if (w==0) {
            max_out=-INT_MAX;
            min_in=v;
        }
        else {
            max_out=-INT_MAX;
            min_in=INT_MAX;
        }
        smax=0;
        pmax=0;
        //if (w == -1) pmax = 0;
        //else pmax = 1;
    }
    
    Node(int k, int w, Node* l, Node* r){   //Internal node
        key=k;
        value=INT_MAX;
        left=l;
        right=r;
        priority=rand();
        weight=w;
        is_leaf=false;
        smax=0;
        max_out=0;
        min_in=0;
    }
};

#endif
