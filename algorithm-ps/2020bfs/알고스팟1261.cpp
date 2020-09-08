//
//  알고스팟1261.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/06.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int n,m = 0;
int map[101][101];
int check[101][101];
int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
void bfs(int x,int y){
    queue<pair<int,int>> q;
    queue<pair<int,int>> next_queue;
    check[x][y] = 0;
    q.push({x,y});

    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < m && my >= 0 && my < n){
                if(check[mx][my] == -1 && map[mx][my] == 0){
                    check[mx][my] = check[dx][dy];
                    q.push({mx,my});
                }
                if(check[mx][my] == -1 && map[mx][my] != 0){
                    check[mx][my] = check[dx][dy]+1;
                    next_queue.push({mx,my});
                }
                
            }
        }
        if(q.empty()){
            q = next_queue;
            next_queue = queue<pair<int,int>>();
            
        }
        
    }
    
    
    
}

int main(void){
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
            check[i][j] = -1;
        }
    }
    
    bfs(0,0);
    
    cout << check[m-1][n-1] << '\n';
    return 0;
}

