//
//  로봇청소기.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/09.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int map[51][51];
int dirNorth[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int dirEast[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int dirSouth[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int dirWest[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
int n,m = 0;
int r,c,d = 0;
void bfs(int r, int c);
void cleanCheck(int cnt, int dx,int dy);
bool rotation(int mx,int my,int i);
int ans = 0;
// 후진 하는 경우
int res = 0;
void robot_print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 2){
                res +=1;
            }
        }
    }
    
    cout << res << '\n';
}

void cleanCheck(int cnt, int dx,int dy){
    bool check=false;
    if(cnt == 4){
        
        if(d == 0){
            // 후진시 막혀있지않으면
            if(map[dx][dy+1] == 0){
                if(dx >= 0 && dx < n && dy+1 >= 0 && dy+1 < m){
                    bfs(dx,dy+1);
                    check = true;
                }
            }
        }else if(d == 1){
            // 후진시 막혀있지않으면
            if(map[dx-1][dy] == 0){
                if(dx-1 >= 0 && dx-1 < n && dy >= 0 && dy < m){
                    bfs(dx-1,dy);
                    check = true;
                }
            }
        }else if(d == 2){
            // 후진시 막혀있지않으면
            if(map[dx][dy-1] == 0){
                if(dx >= 0 && dx < n && dy-1 >= 0 && dy-1 < m){
                    bfs(dx,dy-1);
                    check = true;
                }
            }
        }else {
            // 후진시 막혀있지않으면
            if(map[dx+1][dy] == 0){
                if(dx+1 >= 0 && dx+1 < n && dy >= 0 && dy < m){
                    bfs(dx+1,dy);
                    check = true;
                }
            }
        }
    }
    
    // 뒤쪽방향이 벽이라 후진도 할수없는 상황일때 작동을 멈춘다.
    if(check == false){
        robot_print();
        //cout << ans << '\n';
        return;
    }
}
bool rotation(int mx,int my,int i){
    bool check = false;
    // 방향 회전
    
    if(d == 0){
        if(i == 0){
            d = 3;      //  L
        }
        // 서쪽
        else if(i == 1){
            d = 2;     // S
        }
        // 남쪽
        else if(i == 2){
            d = 1;      // R
        }
        // 동쪽
        else if(i == 3){
            d = 0;   // N
        }
    }else if(d == 1){
        if(i == 0){
            d = 0;      //  L
        }
        else if(i == 1){
            d = 3;     // S
        }
        else if(i == 2){
            d = 2;      // R
        }
        else if(i == 3){
            d = 1;   // N
        }
    }else if(d == 2){
        // 북쪽
        if(i == 0){
            d = 1;      //  L
        }
        // 서쪽
        else if(i == 1){
            d = 0;     // S
        }
        // 남쪽
        else if(i == 2){
            d = 3;      // R
        }
        // 동쪽
        else if(i == 3){
            d = 2;   // N
        }
    }else {
        if(i == 0){
            d = 2;
        }
        else if(i == 1){
            d = 1;
        }
        else if(i == 2){
            d = 0;
        }
        else if(i == 3){
            d = 3;
        }
    }
    
    
    // 청소할 공간이 있을때
    if(map[mx][my] == 0){
        check = true;
    }
    // 청소할 공간이 없을때
    else if(map[mx][my] == 1 || map[mx][my] == 2){
        check = false;
    }
    
    return check;
    
    
}
void printMap(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
}
int cnt_ans = 0;
// 로봇청소기 청소하기
void bfs(int r, int c){
    
    //printMap();
    
    queue<pair<int,int>> q;
    q.push({r,c});
    // 현재 위치 청소한다 청소된곳은 2로 표시
    map[r][c] = 2;
    
    // 모두 청소가 되어있는 경우
    if(cnt_ans == 4){
        
        if(d == 0){
            // 후진시 막혀있지않으면
            if(map[r][c+1] == 0){
                if(r >= 0 && r < n && c+1 >= 0 && c+1 < m){
                    bfs(r,c+1);
                }
            }
        }else if(d == 1){
            // 후진시 막혀있지않으면
            if(map[r-1][c] == 0){
                if(r-1 >= 0 && r-1 < n && c >= 0 && c < m){
                    bfs(r-1,c);
                }
            }
        }else if(d == 2){
            // 후진시 막혀있지않으면
            if(map[r][c-1] == 0){
                if(r >= 0 && r < n && c-1 >= 0 && c-1 < m){
                    bfs(r,c-1);
                    
                }
            }
        }else {
            // 후진시 막혀있지않으면
            if(map[r+1][c] == 0){
                if(r+1 >= 0 && r+1 < n && c >= 0 && c < m){
                    bfs(r+1,c);
                }
            }
        }
        // 뒤쪽방향이 벽이라 후진도 할수없는 상황일때 작동을 멈춘다.
        robot_print();
        //cout << ans << '\n';
        cout << ans;
        
        return;
    }
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        int cnt = 0;
        // 현재 로봇청소기의 위치 (dx, dy)
        if(d == 0){
            for(int i=0; i<4; i++){
                int mx = dx + dirNorth[i][0];
                int my = dy + dirNorth[i][1];
                if(mx >= 0 && mx < n && my >= 0 && my < m){
                    // 청소할 공간이 있는 경우
                    if(rotation(mx,my,i) == true){
                        // 그 방향으로 회전 하고 하낰 전진하고 1번으로 돌아간다.
                        ans++;
                        bfs(mx, my);
                        
                        
                    }
                    // 청소할 공간이 없는 경우
                    else {
                        // 그 방향으로 회전하고 2번으로 돌아간다.
                        bfs(dx,dy);
                        cnt++;
                    }
                }
            }
            cnt_ans = cnt;
        }else if(d == 1){
            for(int i=0; i<4; i++){
                int mx = dx + dirEast[i][0];
                int my = dy + dirEast[i][1];
                if(mx >= 0 && mx < n && my >= 0 && my < m){
                    // 청소할 공간이 있는 경우
                    // 청소할 공간이 있는 경우
                    if(rotation(mx,my,i) == true){
                        // 그 방향으로 회전 하고 하낰 전진하고 1번으로 돌아간다.
                        ans++;
                        bfs(mx, my);
                    }
                    // 청소할 공간이 없는 경우
                    else {
                        // 그 방향으로 회전하고 2번으로 돌아간다.
                        bfs(dx,dy);
                        cnt++;
                    }
                }
                
            }
            // 모두 청소가 되어있는 경우
            cnt_ans = cnt;
            
        }else if(d == 2){
            for(int i=0; i<4; i++){
                int mx = dx + dirSouth[i][0];
                int my = dy + dirSouth[i][1];
                if(mx >= 0 && mx < n && my >= 0 && my < m){
                    // 청소할 공간이 있는 경우
                    if(rotation(mx,my,i) == true){
                        // 그 방향으로 회전 하고 하낰 전진하고 1번으로 돌아간다.
                        ans++;
                        bfs(mx, my);
                    }
                    // 청소할 공간이 없는 경우
                    else {
                        // 그 방향으로 회전하고 2번으로 돌아간다.
                        bfs(dx,dy);
                        cnt++;
                    }
                }
            }
            cnt_ans = cnt;
            
        }else if(d == 3){
            for(int i=0; i<4; i++){
                int mx = dx + dirWest[i][0];
                int my = dy + dirWest[i][1];
                if(mx >= 0 && mx < n && my >= 0 && my < m){
                    // 청소할 공간이 있는 경우
                    if(rotation(mx,my,i) == true){
                        // 그 방향으로 회전 하고 하낰 전진하고 1번으로 돌아간다.
                        ans++;
                        bfs(mx, my);
                    }
                    // 청소할 공간이 없는 경우
                    else {
                        // 그 방향으로 회전하고 2번으로 돌아간다.
                        bfs(dx,dy);
                        cnt++;
                    }
                }
            }
            // 모두 청소가 되어있는 경우
            cnt_ans = cnt;
        }
    }
}


int main(void){
    
    cin >> n >> m;
    cin >> r >> c >> d;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    bfs(r,c);
    return 0;
}
