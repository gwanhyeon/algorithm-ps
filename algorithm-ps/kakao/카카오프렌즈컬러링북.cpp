//
//  카카오프렌즈컬러링북.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/27.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int check[101][101];
int dist[101][101];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n = 4;
int m = 6;
vector<int> area_ans;
void bfs(int x,int y,vector<vector<int>> picture){
    queue<pair<int,int>> q;
    
    check[x][y] = 1;
    dist[x][y] = 0;
    q.push({x,y});
    int picture_area = 0;
    picture_area+=1;
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            if(mx >= 0 && mx < m && my >=0 && my < n){
                if(check[mx][my] == 0 && picture[dx][dy] == picture[mx][my]){
                    dist[mx][my] = dist[dx][dy] +1;
                    check[mx][my] = 1;
                    picture_area+=1;
                    q.push({mx,my});
                }
            }
        }
    }
    area_ans.push_back(picture_area);
}

int main(void){
    vector<vector<int>> picture{{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    memset(check,0,sizeof(check));
    memset(dist,0,sizeof(dist));
    area_ans = {0,};
    
    vector<int> answer(2);
    int picture_size = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(check[i][j]== 0 && picture[i][j] != 0){
                bfs(i,j,picture);
                picture_size += 1;
            }
        }
    }
    int max_area = *max_element(area_ans.begin(), area_ans.end());
    
    answer[0] = picture_size;
    answer[1] = max_area;
    
    cout << answer[0] << answer[1];
}
