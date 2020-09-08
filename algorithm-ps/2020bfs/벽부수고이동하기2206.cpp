//
//  벽부수고이동하기2206.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/06.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int n,m;
int map[1001][1001];
int check[1001][1001][2];
int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
int main(void){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    queue<tuple<int,int,int>> q;
    check[0][0][0] = 1;
    
    q.push(make_tuple(0,0,0));
    while(!q.empty()){
        int dx,dy,dz;
        tie(dx,dy,dz) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && my < n && my >=0 && my < m){
               // 벽부수지 않는 경우
                
                if(map[mx][my] == 0 && check[mx][my][dz] == 0){
                    check[mx][my][dz] = check[dx][dy][dz] + 1;
                    q.push(make_tuple(mx,my,dz));
                }
                
                //벽 부순경우
                if(dz == 0 && map[mx][my] == 1 && check[mx][my][dz+1] == 0){
                    check[mx][my][dz+1] = check[dx][dy][dz] + 1;
                    q.push(make_tuple(mx,my,dz+1));
                }
                
            }
        }
    }
    
    // 벽부순경우와 벽부수지 않는 경우 가장 작은값 출력
    if(check[n-1][m-1][0] != 0 && check[n-1][m-1][1] != 0){
        cout << min(check[n-1][m-1][0], check[n-1][m-1][1]);
    }
    // 벽만 부수지 않은 경우
    else if(check[n-1][m-1][0] != 0){
        cout << check[n-1][m-1][0];
    }
    // 벽만 뿌순경우
    else if(check[n-1][m-1][1] != 0){
        cout << check[n-1][m-1][1];
    }else {
        cout << "-1" << '\n';
    }
    cout << '\n';
    return 0;
}
