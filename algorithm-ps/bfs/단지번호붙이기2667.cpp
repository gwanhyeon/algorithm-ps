//
//  단지번호붙이기2667.cpp
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
int n;
int map[25][25];
int check[25][25];
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int ans[25*25];

void bfs(int x,int y, int cnt){
    queue<pair<int,int>> q;
    check[x][y] = cnt;
    q.push({x,y});
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int a = dx + dir[i][0];
            int b = dy + dir[i][1];
            
            // 범위내 벗어나지 않았을때
            if(a >= 0 && a < n && b >= 0 && b < n){
                
                // 체크되지 않고, 맵이 1일 경우
                if(check[a][b] == 0 && map[a][b] == 1){
                    check[a][b] = cnt;
                    q.push({a,b});
                }
            }
        }
    }
}
int main(void){
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 1이면서 체크되지않는경우
            if(map[i][j] == 1 && check[i][j] == 0){
                bfs(i,j,++cnt);
            
            }
        }
    }
    // 총 단지수
    cout << cnt << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[check[i][j]] += 1;
        }
    }
    sort(ans+1, ans+cnt);
    // 단지마다 단지수 출력
    for(int i=1; i<=cnt; i++){
        cout << ans[i] << '\n';
    }
    
    return 0;
}
