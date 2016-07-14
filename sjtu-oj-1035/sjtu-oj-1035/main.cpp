//
//  main.cpp
//  sjtu-oj-1035
//
//  Created by vivi on 6/27/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

struct stock {
    int num;
    int val;
};

bool operator<(stock a1, stock a2) {
    return (a1.val > a2.val) || (a1.val == a2.val && a1.num > a2.num);
}

bool operator!=(stock a1, stock a2) {
    return (a1.num != a2.num);
}

bool operator==(stock a1, stock a2) {
    return (a1.num == a2.num);
}

template<class T>
struct node {
    node* l;
    node* r;
    node* p;
    T key;
    int fix;
    int count;
    
    node(T key, node* p, node* l, node* r) {
        this->l = l;
        this->r = r;
        this->p = p;
        this->key = key;
        this->fix = rand();
        this->count = 1;
    }
    
    node(T key, node* p) {
        this->l = this->r = NULL;
        this->p = p;
        this->key = key;
        this->fix = rand();
        this->count = 1;
    }
    
    node(T key) {
        this->l = this->r = this->p = NULL;
        this->key = key;
        this->fix = rand();
        this->count = 1;
    }
};

template<class T>
class treap {
public:
    node<T>* root;
    
    treap() { srand((unsigned int)time(NULL)); root = NULL; }
    
    void r_rotate(node<T>* p) {
        node<T>* d = p->p;
        node<T>* l = p->l;
        
        p->l = l->r;
        if (l->r) l->r->p = p;
        
        if (d && d->l == p) { d->l = l; }
        else if (d) { d->r = l;}
        l->p = d;
        
        l->r = p; p->p = l;
        
        if (!l->p) this->root = l;
        
        p->count = (p->l ? p->l->count : 0) + (p->r ? p->r->count : 0) + 1;
        l->count = (l->l ? l->l->count : 0) + (l->r ? l->r->count : 0) + 1;
    }
    
    void l_rotate(node<T>* p) {
        node<T>* d = p->p;
        node<T>* r = p->r;
        
        p->r = r->l;
        if (r->l) r->l->p = p;
        
        if (d && d->l == p) d->l = r;
        else if (d) d->r = r;
        r->p = d;
        
        r->l = p; p->p = r;
        
        if (!r->p) this->root = r;
        
        p->count = (p->l ? p->l->count : 0) + (p->r ? p->r->count : 0) + 1;
        r->count = (r->l ? r->l->count : 0) + (r->r ? r->r->count : 0) + 1;
    }
    
    void insert(T val) {
        if (!this->root) {
            this->root = new node<T>(val);
            return;
        }
        
        node<T>* n = NULL;
        for (node<T>* i = root; i;) {
            n = i; 
            ++n->count;
            i = (val < n->key ? n->l : n->r);
        }
        if (val < n->key) { 
            n->l = new node<T>(val, n);
            n = n->l;
        }
        else { 
            n->r = new node<T>(val, n);
            n = n->r;
        }
        
        while (n->p && n->fix > n->p->fix) {
            if (n->p->l == n) r_rotate(n->p);
            else l_rotate(n->p);
        }
    }
    
    node<T>* find(T val) {
        node<T>* r;
        for (r = root; r && r->key != val; r = (val < r->key ? r->l : r->r));
        return r;
    }
    
    void del(node<T>* r) {
        if (!r->l || !r->r) {
            node<T>* son = (r->l ? r->l : r->r);
            
            if (son) son->p = r->p;
            if (r->p && r->p->l == r) r->p->l = son;
            else if (r->p) r->p->r = son;
            
            for (node<T>* i = r; i; i = i->p) --i->count;
            
            if (r == root) root = son;
            
            delete r;
        }
        else {
            node<T>* successor = r->r;
            while (successor->l) successor = successor->l;
            
            r->key = successor->key;
            del(successor);
        }
    }
    
    void del(int val) {
        node* r = find(val);
        if (r) del(r);
    }
    
    bool test(node<T>* r) {
        if (!r) return true;
        
        int l_count = (r->l ? r->l->count : 0);
        int r_count = (r->r ? r->r->count : 0);
        bool count_bool = (l_count + r_count + 1 == r->count);
        bool val_bool = (!r->l || r->l->key <= r->key) && (!r->r || r->r->key >= r->key);
        if (!count_bool) {
            printf("Count Error in %d(%d)--> l_count = %d, r_count = %d\n", r->key,r->count, l_count, r_count);
            exit(-1);
        }
        else if (!val_bool) {
            printf("Value Error in %d(%d)\n", r->key, r->count);
            if (r->l) 
                printf("l has key: %d\n", r->l->key);
            else
                printf("l is null\n");
            if (r->r)
                printf("r has key: %d\n", r->r->key);
            else
                printf("r is null\n");
        }
        
        return count_bool && val_bool && test(r->l) && test(r->r);
    }
    
    int get_index(T val) {
        node<T>* r;
        int count = 0;
        for (r = root; r; ) {
            if (r->key == val)
                return count + 
        }
    }
};

int main(int argc, const char * argv[]) {
    using namespace std;
    
    treap<stock> t;
    stock temp;
    
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        temp.num = i; cin >> temp.val;
        t.insert(temp);
    }
    
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        char c; cin >> c;
        if (c == 'Q') {
            int r; cin >> r;
            for (int i = 0; i < )
        }
    }
}
