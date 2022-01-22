
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <forward_list>

using namespace std;

//   Below is the interface for Iterator, which is already defined for you.
//   **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int> &nums) :
        Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        n = Iterator::next();
        hn = Iterator::hasNext();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return n;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int tmp = n;
        
        if (Iterator::hasNext()) {
            hn = true;
            n = Iterator::next();
        } else {
            hn = false;
            n = -1;
        }

        return tmp;
    }

    bool hasNext() const {
        return hn;
    }
private:
    int n;
    bool hn;
};