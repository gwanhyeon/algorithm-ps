//
//  단지번호붙이기2667(dfs).cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/03.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int map[25][25];
int check[25][25];
int n;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int ans[25*25];
void dfs(int x,int y, int cnt){
    check[x][y] = cnt;
    
    for(int i=0; i<4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        
        if(dx >= 0 && dx < n && dy >=0 && dy < n){
            if(check[dx][dy] == 0 && map[dx][dy] == 1){
                dfs(dx,dy,cnt);
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
            if(map[i][j] == 1 && check[i][j] == 0){
                cnt +=1;
                dfs(i,j,cnt);
            }
        }
    }
    cout << cnt << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[check[i][j]] += 1;
        }
    }
    
    sort(ans+1, ans+cnt+1);
    for(int i=1; i<=cnt; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
