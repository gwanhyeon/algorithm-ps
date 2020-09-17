//
//  아기상어16236.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/16.
//  Copyright © 2020 kgh. All rights reserved.
//
/*
 - (start,end)지점을 두어서 상어의 위치에서 BFS
 - BFS를
 https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-16236-%EC%95%84%EA%B8%B0-%EC%83%81%EC%96%B4
 */
#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 401;
const int width = 21;
const int height = 21;

int map[width][height];
int check[width][height];
int shark_x = 0;
int shark_y = 0;
int shark_size = 2;
int shark_eat_size = 0;
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int n = 0;

int min_dist=0;
int min_x=0;
int min_y=0;
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = 1;
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            if(mx >= 0 && mx < n && my >= 0 && my <n ){
                // 1.자기보다 큰 상어는 지나칠 수 없음
                if(check[mx][my] != 0 || map[mx][my] > shark_size){
                    continue;
                }
                // 2. 이동거리를 갱신시켜준다.
                check[mx][my] = check[dx][dy] + 1;
            
                // 3. 먹을수 있는 물고기 인지 체크
                if(map[mx][my] != 0 && map[mx][my] < shark_size){
                    // 3.1최단 거리인지 확인
                    if(check[mx][my] < min_dist){
                        min_x = mx;
                        min_y = my;
                        min_dist = check[mx][my];
                    }
                    // 3.2최단거리가 같은게 여러개 일 경우
                    else if(check[mx][my] == min_dist){
                        // x점은 동일선상에 있어야하고 위에 있는 값중에서 최소가 되야하므로 my가 min_y보다 작은것이 최소 좌표다.
                        // 3.2.1위쪽
                        if(min_x == mx){
                            if(min_y > my){
                                min_x = mx;
                                min_y = my;
                            }
                        }
                        // 3.2.2왼쪽
                        else if(min_x > mx){
                            min_x = mx;
                            min_y = my;
                        }
                    }
                }
                q.push({mx,my});
            }
        }
    }
    
    
}
int main(void){
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                shark_x = i;
                shark_y = j;
                map[i][j] = 0;
            }
        }
    }
    int result = 0;     //이동시간
    while(true){
        min_dist = MAX;
        min_x = width;
        min_y = height;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                check[i][j] = 0;
            }
        }
        bfs(shark_x, shark_y);
        
        // 먹을수 있는 물고기를 찾은경우
        if(min_x != width && min_y != height){
            result += check[min_x][min_y];
            shark_eat_size++;
            if(shark_eat_size == shark_size){
                shark_size++;
                shark_eat_size=0;
            }
            map[min_x][min_y] = 0;
            shark_x = min_x;
            shark_y = min_y;
        }
        //엄마 상어 찾기
        else {
            break;
        }
    }
    
    cout << result << '\n';
    
    return 0;
}
/*
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 21;
int map[MAX][MAX];
int check[MAX][MAX];
int dis_check[MAX][MAX];
int n = 0;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int shark_size = 2;
int shark_eat_fish = 0;

vector<pair<int,int>> fish;

void distance_area(){
    for(int i=0; i<fish.size(); i++){
        int x = fish.front().first;
        int y = fish.front().second;
        
        queue<pair<int,int>> q;
        q.push({x,y});
        dis_check[x][y] = 1;
        while(!q.empty()){
            int dx = q.front().first;
            int dy = q.front().second;
            for(int i=0; i<4; i++){
                int mx = dx + dir[i][0];
                int my = dy + dir[i][1];
                if(mx >= 0 && mx < n && my >= 0 && my < n){
                    dis_check[mx][my] = 1;
                    q.push({mx,my});
                }
            }
        }
        
    }

}
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
                //1. 자기자신보다 큰 물고기가 있거나 맵이 비어있는 경우
                if(map[mx][my] > shark_size || map[mx][my] == 0){
                    continue;   // 다른방향 탐색
                }
                //2. (mx,my)의 이동거리를 갱신시켜준다.
                check[mx][my] = check[dx][dy] + 1;
                
                // 자기 자신과 같으면(물고기는 못먹지만 지나갈 수는 있음.
                else if(map[mx][my] == shark_size){
                    bfs(mx,my);
                }
                // 자기 자신보다 작은 사이즈만 먹을 수 있음.
                else if(map[mx][my] < shark_size){
                    shark_eat_fish++;
                    bfs(mx,my);
                }
                // 체크가 안된 경우라면
                if(check[mx][my] == 0){
                    // 거리 측정하기
                    int fish_size = fish.size();
                    // 더 이상 먹을수 있는 물고기가 공간에 없다면
                    if(fish_size == 0){
                        // 엄마 상어한테 요청하기
                        return;
                    }
                    // 물고기 사이즈체크(물고기 1마리 일 경우)
                    else if(fish_size == 1){
                        bfs(mx,my);
                    }
                    // 물고기 사이즈 체크(물고기가 많을 경우)
                    else if(fish_size > 1){
                        // 거리가 가까운 물고기 먹으러 가기
                        distance_area();
                        // 크기순으로
                    }
                }else {
                    
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
                end = j;
                map[i][j] = 0;
            }else if(map[i][j] != 0 && map[i][j] != 9){
                fish.push_back({i,j});
            }
        }
    }
    // 2. 아기상어 위치로 부터 BFS시작
    bfs(start,end);
    return 0;
}
*/


