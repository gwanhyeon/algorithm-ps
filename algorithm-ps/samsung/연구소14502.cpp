//
//  연구소14502.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/07.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
bool check[10001][10001];
int map[10001][10001];
int dist[10001][10001];
int n,m = 0;
int dir[4][2]={{0,1},{-1,0},{1,0},{0,-1}};
vector<int> res;

void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = 1;
    dist[x][y] = map[x][y];
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(check[mx][my] == 0 && dist[mx][my] == 0){
                    check[mx][my] = 1;
                    dist[mx][my] = 2;
                    //dist[mx][my] = map[dx][dy] + 1;
                    //dist[mx][my] = dist[dx][dy] + map[mx][my];
                    q.push({mx,my});
                }
            }
            
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j] == 0 && dist[i][j] == 0){
                cnt += 1;
            }
        }
    }
    res.push_back(cnt);
}
int main(void){
    
    // empty 0 wall 1 virus 2
    cin >> n >> m;
    memset(check,0,sizeof(check));
    memset(map,0,sizeof(map));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    vector<int> wall;
    for(int i=0; i<3; i++){
        wall.push_back(1);
    }
    for(int i=0; i<n*m-3; i++){
        wall.push_back(0);
    }
    sort(wall.begin(), wall.end());
    
    // 벽세우기
    do {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<n*m; k++){
                    int div_x = i+1;
                    int div_y = j+1;
                    int x = wall.size() / n;
                    int y = wall.size() % m;
                    if(wall[k] == 1){
                        check[x][y] = 1;
                    }
                }
                // bfs
                if(map[i][j] == 2 && check[i][j] == 0){
                    bfs(i,j);
                }
                
          
            }
        }
//        memset(check,0,sizeof(check));
//        memset(dist,0,sizeof(dist));
        
    } while (next_permutation(wall.begin(), wall.end()));
    
     // 영역 체크 값 max
    long long max = *max_element(res.begin(), res.end());
    
    // 결과 값
    cout << max << '\n';
    return 0;
    
}
