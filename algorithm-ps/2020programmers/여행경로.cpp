//
//  여행경로.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/10/06.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool dfs(string start, vector<vector<string>> &tickets, vector<bool> &check, vector<string> &answer, int cnt){
    
    answer.push_back(start);
    if(cnt == tickets.size()){
        return true;
    }

    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0] == start && check[i] == false){
            check[i] = true;
            
            bool tf = dfs(tickets[i][1], tickets, check,answer,cnt+1);
            if(tf == true){
                return true;
            }
            check[i] = false;
        }
    }
    answer.pop_back();
    return false;
}
int main(void){
    vector<vector<string>> tickets{{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    
    vector<string> answer;
    vector<bool> check(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, check, answer, 0);
    for(int i=0; i<answer.size(); i++){
        cout <<answer[i];
    }
    return 0;
}
