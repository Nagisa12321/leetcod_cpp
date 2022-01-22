#include "leetcode.h"

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& __board) {
        int __num_x = 0, __num_o = 0;
        for (const string & __s : __board) 
            for (char __c : __s)
                if (__c == 'X') ++__num_x;
                else if (__c == 'O') ++__num_o;
        int __sub = __num_x - __num_o;
        if (__sub < 0 || __sub > 1) return false;

        int __x_win = 0, __o_win = 0;
        for (int __i = 0; __i < 3; ++__i) {
            if (__board[__i] == "XXX") {
                if (__sub != 1)
                    return false;
                __x_win = 1;
            }
            else if (__board[__i] == "OOO") {
                if (__sub != 0)
                    return false;
                __o_win = 1;
            }
            string __tmp;
            __tmp.push_back(__board[0][__i]);
            __tmp.push_back(__board[1][__i]);
            __tmp.push_back(__board[2][__i]);
            if (__tmp == "XXX") {
                if (__sub != 1)
                    return false;
                __x_win = 1;
            }
            else if (__tmp == "OOO") {
                if (__sub != 0)
                    return false;
                __o_win = 1;
            }
        }

        string __lhs, __rhs;
        __lhs.push_back(__board[0][0]);
        __lhs.push_back(__board[1][1]);
        __lhs.push_back(__board[2][2]);
        if (__lhs == "XXX") {
            if (__sub != 1)
                return false;
            __x_win = 1;
        }
        else if (__lhs == "OOO") {
            if (__sub != 0)
                return false;
            __o_win = 1;
        }
        __rhs.push_back(__board[0][2]);
        __rhs.push_back(__board[1][1]);
        __rhs.push_back(__board[2][0]);
        if (__rhs == "XXX") {
            if (__sub != 1)
                return false;
            __x_win = 1;
        }
        else if (__rhs == "OOO") {
            if (__sub != 0)
                return false;
            __o_win = 1;
        }
        
        return __x_win * __o_win == 0;
    }
};