//
//  퇴사14501.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/29.
//  Copyright © 2020 kgh. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans = -1;
int n = 0;

void dfs(int idx, int sum, vector<int> day, vector<int> price){
    
    if(idx == n){
        if(sum > ans){
            ans = sum;
        }
        return;
    }
    if(idx > n){
        return;
    }
    dfs(idx+day[idx], sum+price[idx], day, price);
    dfs(idx+1, sum, day, price);
    
}

int main(void){
    cin >>n;
    vector<int> day(n);
    vector<int> price(n);
    
    for(int i=0; i<n; i++){
        cin >> day[i] >> price[i];
    }
    
    dfs(0, 0, day, price);
    cout << ans << '\n';
    return 0;
}
*/


#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int n = 0;
int ans = -1;
void dfs(int idx,int sum,vector<int> t, vector<int> p){
    
    // basement
    if(idx == n){
        
        if(sum > ans){
            ans = sum;
        }
        return;
    }
    if(idx > n){
        return;
    }
    
    dfs(idx+t[idx], sum+p[idx], t, p);      // 상담을 한다
    dfs(idx+1, sum, t, p);                  // 상담을 하지 않는다.
}
int main(void){
    
    vector<int> t(n);
    vector<int> p(n);
    
    for(int i=0; i<n; i++){
        cin >> t[i] >> p[i];
    }
    
    dfs(0,0,t,p);
    
    
    
    
    return 0;
}
