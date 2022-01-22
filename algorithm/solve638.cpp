// io
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

// containers
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <forward_list>

// algorithm
#include <algorithm>
#include <iterator>
#include <numeric>

// memory
#include <memory>

using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, 
                       vector<vector<int>>& special, 
                       vector<int>& needs) {
        return shoppingOffers(price, special, needs, 0);
    }

private:
    int shoppingOffers(vector<int>& price, 
                       vector<vector<int>>& special, 
                       vector<int>& needs,
                       int spend) {
        int _min = spend;
        for (int i = 0; i < needs.size(); ++i)
            _min += needs[i] * price[i];
        
        for (const vector<int> &spec : special) {
            vector<int> next_needs(needs.size());
            bool _continue = false;
            for (int i = 0; i < needs.size(); ++i) {
                int next_need = needs[i] - spec[i];
                if (next_need < 0) {
                    _continue = true;
                    break;
                }
                next_needs[i] = next_need;
            }
            if (_continue) continue;
            _min = min(_min, shoppingOffers(price, special, 
                                            next_needs, spend + spec.back()));
        }

        return _min;
    }
};