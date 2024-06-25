#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
public:
   bool MakeBouqets(int day, std::vector<int>& bloomDay, int m, int k) {
        int c = 0;
        int res = 0;
        for (auto &bd : bloomDay) {
            if (bd <= day) {
                c++;
                if (c == k) {
                    res++;
                    c = 0;
                }
            } else {
                c = 0;
            }
        }
        return res >= m;
    }

    int minDays(std::vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if ((long long)m * k > n) {
            return -1;
        }
        int l = 1;
        int r = 1e9;
        while (l < r) {
            int md = l + (r - l) / 2;
            if (MakeBouqets(md, bloomDay, m, k)) {
                r = md;
            } else {
                l = md + 1;
            }
        }
        return l;
    }
};