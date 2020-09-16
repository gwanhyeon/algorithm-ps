//
//  아기상어16236.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/16.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 21;
int map[MAX][MAX];
int check[MAX][MAX];
int n = 0;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int shark_size = 2;
vector<pair<int,int>> fish;


void bfs(int x,int y){
    // 초기진입시 상어 위치 체크
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            if(mx >= 0 && mx < n && my >= 0 && my < n){
                int size = fish.size();
                // 더 이상 먹을수 있는 물고기가 공간에 없다면
                if(size == 0){
                    // 엄마 상어한테 요청하기
                    return;
                }
                // 물고기 사이즈체크(물고기 1마리 일 경우)
                else if(size == 1){
                    bfs(mx,my);
                }
                // 물고기 사이즈 체크(물고기가 많을 경우)
                else if(size > 1){
                    // 거리가 가까운 물고기 먹으러 가기
                }
            }
        }
        
    }
}

int main(void){
    cin >> n;
    
    int start = 0;
    int end = 0;
    
    // O(n^2)
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            // 1.아기상어 위치 저장
            if(map[i][j] == 9){
                start = i;
                start = j;
            }else if(map[i][j] != 0){
                fish.push_back({i,j});
            }
        }
    }
    
    
    // 2. 아기상어 위치로 부터 BFS시작
    bfs(start,end);
    
    
    
    return 0;
}
