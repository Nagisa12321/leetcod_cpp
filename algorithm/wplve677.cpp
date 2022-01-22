#include "leetcode.h"
using namespace std;

struct tire {
public:
    tire() : t_vec(26), val(0) {}; 
    ~tire() {
        for (tire *t : t_vec)
            if (t) delete t;
    }
    int val;
    vector<tire *> t_vec;
};

class MapSum {
public:
    MapSum() : t(new tire) {}
    
    void insert(string key, int val) {
        tire *cur = t;
        for (char c : key) {
            if (!cur->t_vec[c - 'a'])
                cur->t_vec[c - 'a'] = new tire;
            cur = cur->t_vec[c - 'a'];
        } 
        cur->val = val;
    }
    
    int sum(string prefix) {
        tire *cur = t;
        for (char c : prefix) {
            if (!cur->t_vec[c - 'a'])
                return 0;
            cur = cur->t_vec[c - 'a'];
        }
        int _res = 0;
        dfs(cur, _res);
        return _res;
    }

private:
    tire *t;

    void dfs(tire *node, int &res) {
        if (!node) return;

        res += node->val;
        for (int i = 0; i < 26; ++i) {
            dfs(node->t_vec[i], res);
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */