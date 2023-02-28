#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <filesystem>  //std::filesystem::path path(filepath);
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>  //iota
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include "Node.h"
#define ll long long
using namespace std;

const char *filename = "photo//Pic.bmp";
const char *filename_huf = "HUF//txt.bmp.huf";


const int N = 8;

unordered_map<bitset<N>, ll> weight;

struct Compare {
    bool operator()(Node *&a, Node *&b) { return a->fre > b->fre; }
};

Node *build_huff(unordered_map<bitset<N>, ll> &weight) {
    priority_queue<Node *, vector<Node *>, Compare> heap;
    for(ll i=0;i<256;i++) {
        bitset<N>a(i);
        if(weight.count(a)) {
            Node *node = new Node(a, weight[a]);
            heap.push(node);
        }
    }

    while (heap.size() > 1) {
        auto l = heap.top();
        heap.pop();
        auto r = heap.top();
        heap.pop();
        Node *parent = new Node(l->val, l->fre + r->fre);
        parent->lchild = l;
        parent->rchild = r;
        heap.push(parent);
    }
    return heap.top();
}

void get_huffcode(Node *root, string path,
                  unordered_map<bitset<N>, string> &huff_code) {
    if (root == NULL) {
        return;
    }
    if (root->lchild == NULL && root->rchild == NULL) {
        huff_code[root->val] = path;
        return;
    }

    get_huffcode(root->lchild, path + "0", huff_code);
    get_huffcode(root->rchild, path + "1", huff_code);
}

struct Head {
    char type[4];
    int length;
    int weight[256];
} head;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ifstream ifs;
    ifs.open(filename, ios::in | ios::binary);

    if (!ifs.is_open()) {
        cerr << "找不到文件" << endl;
        return (0 ^ 0);
    }

    bitset<N> byte;
    vector<bitset<N>> file;

    ifs.read(reinterpret_cast<char *>(&byte), 1);
    while (!ifs.eof()) {
        file.push_back(byte);
        weight[byte]++;
        ifs.read(reinterpret_cast<char *>(&byte), 1);
    }

    ifs.close();

    Node *root = build_huff(weight);
    unordered_map<bitset<N>, string> huff_code;
    get_huffcode(root, "", huff_code);

    strcpy(head.type, "HUF");
    head.length = file.size();
    // cout << head.length << endl;
    for (ll i = 0; i < 256; i++) head.weight[i] = 0;
    for (auto i: weight) {
        head.weight[i.first.to_ullong()] = i.second;
    }

    ofstream ofs;
    ofs.open(filename_huf, ios::out | ios::binary);
    string str;
    for (auto i : file) str += huff_code[i];

    ll offset = str.size() % 8;

    if (offset)
        for (ll i = 0; i < 8 - offset; i++) str += "0";
    ofs.write(reinterpret_cast<char *>(&head), sizeof head);
    ofs.flush();
    for (ll i = 0; i < str.size(); i += 8) {
        bitset<N> bit(str.substr(i, 8));
        ofs.write(reinterpret_cast<char *>(&bit), 1);
//        ofs.flush();
    }
    // cout << sizeof(head) + str.size() / 8;
    // cout << file.size();
    ofs.close();
//    for(auto &i:head.weight){
//        cout<<i<<endl;
//    }
    // cout << sizeof(byte);
    // cout << offset << endl;
    return (0 ^ 0);
}
