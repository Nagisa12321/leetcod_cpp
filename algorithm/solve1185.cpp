#include "leetcode.h"
using namespace std;

class Solution {
public:
    vector<string> days{
        "Sunday", "Monday", "Tuesday", 
        "Wednesday", "Thursday", "Friday", 
        "Saturday", 
    };
    vector<int> monthv{
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
    };
    vector<int> month_leapv{
        0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30,
    };
    string dayOfTheWeek(int day, int month, int year) {
        if (less(day, month, year, 31, 8, 2019)) {
            int d = distance(day, month, year, 31, 8, 2019);        
            return days[(6 + (d % 7)) % 7];
        } else {
            int d = distance(31, 8, 2019, day, month, year);
            return days[(13 - (d % 7)) % 7];
        }
    }

    int distance(int d1, int m1, int y1, int d2, int m2, int y2) {
        int days1 = dayOfTheYear(d1, m2, y1);
        int days2 = dayOfTheYear(d2, m2, y2);
        int res = 0;
        for (int i = y1; i < y2; ++i) {
            if (leap(i)) res += 365;
            else res += 364;
        }
        res += days2 - days1;
        return res;
    }

    int dayOfTheYear(int day, int month, int year) {
        if (leap(year)) {
            return monthv[month - 1] + day; 
        } else {
            return month_leapv[month - 1] + day;
        }
    }

    bool less(int d1, int m1, int y1, int d2, int m2, int y2) {
        if (y1 != y2)
            return y1 < y2;
        else if (m1 != m2)
            return m2 < m2;
        else 
            return d1 < d2;
    }

    // 1971 - 2100 so .... 
    bool leap(int year) {
        return year % 4 == 0;
    }
};

int main() {
    Solution solve;
    string res = solve.dayOfTheWeek(31, 8, 2019);
    cout << res << endl;
}

