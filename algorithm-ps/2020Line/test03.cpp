//
//  test03.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/29.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int n = 2;
int ans = -1;
void dfs(int idx,int sum,vector<int> products){
    
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
    
    for(int i=idx; i<products.size(); i++){
        dfs(i*2, sum+products[i], products);
        dfs(i+1, sum, products);
    }
}
int main(void){
    
    vector<vector<int>> products{{10, 3, 2}, {15, 2, 5}};
    for(int i=0; i<products.size(); i++){
        dfs(0,0,products[i]);
        
    }
    cout << ans;
    return 0;
}
