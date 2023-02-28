## 遇到的问题
两次传入值相等的unordered_map weight,weight1
即weight==weight1
但是如果我的排序规则Compare仅仅对频率排序,没有考虑频率相等的情况
那么就有可能导致如果我范围for添加元素进入heap时,元素顺序不一致,就会导致
哈夫曼树不同,然后编码就会出问题.
解决方案1:更改排序规则如下
```cpp
struct Compare {
    bool operator()(Node *&a, Node *&b) {
        if (a->fre == b->fre) return a->val.to_ulong() > b->val.to_ulong();
        return a->fre > b->fre;
    }
};
```
解决方案2:构建哈夫曼树的处理取消使用范围for
```cpp
    priority_queue<Node *, vector<Node *>, Compare> heap;
    for(ll i=0;i<256;i++) {
        bitset<N> a(i);
        if (weight.count(a)) {
            Node *node = new Node(a, weight[a]);
            heap.push(node);
        }
    }
```