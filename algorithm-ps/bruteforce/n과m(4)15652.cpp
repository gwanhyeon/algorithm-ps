//
//  n과m(4)15652.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/22.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
bool check[9];

void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=idx; i<=n; i++){
         v.push_back(i);
        dfs(i, cnt+1);
        v.pop_back();
    }
}
int main(void){
    cin >> n >> m;
    dfs(1,0);
    
    return 0;
}
