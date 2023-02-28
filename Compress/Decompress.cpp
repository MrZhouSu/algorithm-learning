#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>  //iota
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define ll long long
using namespace std;

const char *filename = "HUF//txt.bmp.huf";
const char *filename_bmp = "photo//t.bmp";


const int N = 8;
struct Head {
    char type[4];
    int length;
    int weight[256];
} head;

unordered_map<bitset<N>, ll> get_fre(int *weight, int size) {
    unordered_map<bitset<N>, ll> m;
    for (ll i = 0; i < size; i++) {
        if (weight[i]) {
            m[bitset<N>(i)] = weight[i];
        }
    }
    return m;
}

struct Compare {
    bool operator()(Node *&a, Node *&b) { return a->fre > b->fre; }
};

Node *build_huff(unordered_map<bitset<N>, ll> &weight) {    priority_queue<Node *, vector<Node *>, Compare> heap;
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
    if (root == nullptr) {
        return;
    }
    if (root->lchild == nullptr && root->rchild == nullptr) {
        huff_code[root->val] = path;
        return;
    }

    get_huffcode(root->lchild, path + "0", huff_code);
    get_huffcode(root->rchild, path + "1", huff_code);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ifstream ifs;

    ifs.open(filename, ios::in | ios::binary);

    if (!ifs.is_open()) {
        cerr << "文件不存在" << endl;
        return (0 ^ 0);
    }

    bitset<N> byte;
    vector<bitset<N>> file;

    ifs.read(reinterpret_cast<char *>(&head), sizeof head);

    ifs.read(reinterpret_cast<char *>(&byte), 1);
    while (!ifs.eof()) {
        file.push_back(byte);
        ifs.read(reinterpret_cast<char *>(&byte), 1);
    }
    ifs.close();

    auto weight = get_fre(head.weight, 256);

    Node *root = build_huff(weight);

    unordered_map<bitset<N>, string> huff_code;

    get_huffcode(root, "", huff_code);

    unordered_map<string, bitset<N>> huff_code_r;

    for (auto i: huff_code) {
        huff_code_r[i.second] = i.first;
    }
    string str;
    for (auto &i: file) {
        str += i.to_string();
    }

    ll sum = 0;
    string s;
    // vector<unsigned char> answer;
    ofstream ofs;
    ofs.open(filename_bmp, ios::out | ios::binary);
    vector<bitset<N>>file1;

    for (ll i = 0; i < str.size(); i++) {
        s += str[i];
        if (huff_code_r.count(s)) {
            file1.push_back(huff_code_r[s]);
//            ofs.flush();
            sum++;
            s.clear();
        }
        if (sum == head.length) {
//            cout<<str.size()-i<<endl;
            break;
        }
    }
    for(auto i:file1){
        ofs.write(reinterpret_cast<char*>(&i),1);
    }
//    ofs.flush();
    ofs.close();
//    for(auto &i:head.weight){
//        cout<<i<<endl;
//    }

    return (0 ^ 0);
}
