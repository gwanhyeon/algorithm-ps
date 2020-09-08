//
//  미로탐색2178.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/03.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,m = 0;
int map[101][101];
int check[101][101];
int dir[4][2] = {{-1,0},{1,0}, {0,-1}, {0,1}};
int cnt = 0;
void bfs(int x,int y){
    queue<pair<int,int>> q;
    check[x][y] = 1;
    q.push({x,y});
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            if(mx == n && my == m){
                break;
            }
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(check[mx][my] == 0 && map[mx][my] == 1){
                    map[mx][my] = map[dx][dy] + 1;
                    check[mx][my] = 1;
                    q.push({mx,my});
                }
            }
        }
    }
}

int main(void){
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    bfs(0,0);
    cout << map[n-1][m-1] << '\n';
    return 0;
}
