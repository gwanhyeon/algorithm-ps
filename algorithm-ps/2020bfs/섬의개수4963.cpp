//
//  섬의개수4963.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/03.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int w, h = 0;
int cnt = 0;
int map[50][50];
int check[50][50];
int dir[8][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1,1}, {1,1}, {-1,-1}, {1,-1}};
void bfs(int x,int y){
    queue<pair<int,int>> q;
    map[x][y] = 1;
    q.push({x,y});
    
    while(!q.empty()){
        // q.front만해서 값 가져올것. 실수했음.
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<8; i++){
            int a = dx + dir[i][0];
            int b = dy + dir[i][1];
            
            if(a >= 0 && a < h && b >= 0 && b < w){
                if(check[a][b] == 0 && map[a][b] == 1){
                    check[a][b] = 1;
                    q.push({a,b});
                }
            }
        }
    }
    
}

int main(void){
    while(true){
        w = 0;
        h = 0;
        cnt = 0;
        cin >> w >> h;
        if(w == 0 && h == 0){
            cout << '\n';
            break;
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d", &map[i][j]);
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(check[i][j] == 0 && map[i][j] == 1){
                    
                    bfs(i,j);
                    cnt +=1;
                }
            }
        }
        
        cout << cnt << '\n';
        
        memset(check,0,sizeof(check));
        memset(map,0,sizeof(map));

    }
    
    
    return 0;
    
}
