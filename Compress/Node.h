//
// Created by Sundy on 2023/2/28.
//
#ifndef LAB_NODE_H
#define LAB_NODE_H

#include <bitset>
using namespace  std;
const int N = 8;

struct Node {
    Node() {
        lchild = nullptr;
        rchild = nullptr;
    }

    Node(bitset <N> a, long long b) : val(a), fre(b) {
        lchild = nullptr;
        rchild = nullptr;
    }

    Node *lchild, *rchild;
    long long fre;
    bitset <N> val;
};

#endif //LAB_NODE_H
