//
//  이분그래프1707.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/02.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> a[20001];
int check[20001];

void dfs(int x,int c){
    check[x] = c;
    
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(check[y] == false){
            dfs(y,3-c);
        }
    }
}


int main(void){
    int t;
    cin >> t;
    
    while(t--){
        int n,m;
        cin >> n >> m;
        
        for(int k=1; k<n; k++){
            a[k].clear();
            check[k] = 0;
            
        }
        
        for(int i=0; i<m; i++){
            int u,v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        
        for(int j=1; j<=n; j++){
            if(check[j] == 0){
                dfs(j,1);
            }
        }
        bool res = true;
        for(int i=1; i<=n; i++){
            for(int j=0; j<a[i].size(); j++){
                int k = a[i][j];
                if(check[i] == check[k]){
                    res = false;
                }
            }
        }
        cout << (res ? "YES" : "NO") << '\n';
    }
    
    
}
