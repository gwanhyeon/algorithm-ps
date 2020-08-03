//
//  연결요소의개수11724.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/02.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int x){
    check[x] = true;
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(check[y]==false){
            dfs(y);
        }
    }
}

int main(void){
    int n,m;
    cin >> n >> m;
    // 노드 간선의 개수
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(check[i] == false){
            dfs(i);
            cnt+=1;
        }
    }
    cout << cnt << '\n';
    return 0;
}
