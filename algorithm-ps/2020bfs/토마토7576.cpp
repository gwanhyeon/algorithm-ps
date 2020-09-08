//
//  토마토7576.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/03.
//  Copyright © 2020 kgh. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001];
int check[1001][1001];
int dir[4][2] = {{-1,0},{1,0}, {0,-1}, {0,1}};


int main(void){
    int n,m;
    cin >> n >> m;
    
    queue<pair<int,int>> q;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            check[i][j] = -1;
            cin >> map[i][j];
            if(map[i][j] == 1){
                check[i][j] = 0;
                q.push({i,j});
            }
            
        }
    }
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            if(dx >= 0 && dx < m && dy >= 0 && dy < n){
                if(check[mx][my] == -1 && map[mx][my] != -1){
                    q.push({mx,my});
                    check[mx][my] = check[dx][dy] + 1;
                }
            }
        }
    }
    
    int res = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
     
            
            if(check[i][j] > res){
                res = check[i][j];
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == -1 && map[i][j] == 0){
                res = -1;
                
            }
        }
    }
    
    
    
    cout << res;
    
    
    
}
