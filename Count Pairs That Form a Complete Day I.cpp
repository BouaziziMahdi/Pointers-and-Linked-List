#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int countCompleteDayPairs(std::vector<int>& hours) {
        int i=0 ;
        int j=0 ;
        int res=0;
        for(i;i<hours.size();i++){
            if(hours[i]%2){
                res = 1 ;
            } else 
                i++ ;
            for (j;j<hours.size();j++){
                 if(hours[j]%2){
                res = 1 ;
            } else 
                j++ ;
            }
            }
        while(i<j){
            res =hours[i] + hours[j];
        }
        return res;
    }
        
};