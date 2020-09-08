//
//  n과m(2)15650.cpp
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
int check[8];
vector<int> v;

void dfs(int idx, int cnt){
    
    // 종료 조건
    if(cnt == m){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    for(int i=idx; i<=n; i++){
        
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        v.push_back(i);
        dfs(i, cnt+1);
        check[i] = false;
        v.pop_back();

    }
    
    
}
int main(void){
    cin >> n >> m;
    dfs(1,0);       // index, cnt
    return 0;
}
