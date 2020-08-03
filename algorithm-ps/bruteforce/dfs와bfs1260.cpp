//
//  dfs와bfs1260.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/01.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[1001];
vector<int> v[1001];

void dfs(int node){
    
    check[node] = true;
    cout << node << " ";
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

void bfs(int start){
    queue<int> q;
    memset(check,false, sizeof(check));
    check[start] = true;
    q.push(start);
    
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
    }
    
}


int main(void){
    int n,m,start = 0;
    
    cin >> n >> m >> start;
    
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }
    
    dfs(start);
    cout << '\n';
    bfs(start);
    
    
    
    
    
    
    
    return 0;
}
