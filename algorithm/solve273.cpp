#include <string>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        if (num <= 999)
            return formal_numberToWords(num);
        else if (num <= 999999) {
            string res;
            res += formal_numberToWords(num / 1000) + " Thousand";
            if (num % 1000)
                res += " " + formal_numberToWords(num % 1000);
            return res;
        } else if (num <= 999999999) {
            string res;
            res += formal_numberToWords(num / 1000000) + " Million";
            if (num % 1000000 / 1000)
                res += " " + formal_numberToWords(num % 1000000 / 1000) + " Thousand";
            if (num % 1000)
                res += " " + formal_numberToWords(num % 1000);
            return res;
        } else {
            string res;
            res += formal_numberToWords(num / 1000000000) + " Billion";
            if (num % 1000000000 / 1000000)
                res += " " + formal_numberToWords(num % 1000000000 / 1000000) + " Million";
            if (num % 1000000 / 1000)
                res += " " + formal_numberToWords(num % 1000000 / 1000) + " Thousand";
            if (num % 1000)
                res += " " + formal_numberToWords(num % 1000);
            return res;
        }
    }

private:
    string bits_1[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                         "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string bits_2[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string formal_numberToWords(int num) {
        string res;
        
        int hund = num / 100;
        if (hund) res += bits_1[hund] + " Hundred ";

        int teen = (num / 10) % 10;
        if (teen <= 1) {
            if (num % 100)
                res += bits_1[num % 100] + " ";
        } else {
            if (teen)
                res += bits_2[teen] + " ";
            int ten = num % 10;
            if (ten)
                res += bits_1[num % 10] + " ";
        }
        if (!res.empty() && res[res.size() - 1] == ' ')
            res.pop_back();
        return res;
    }
};