//
//  뱀3190.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/22.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int left_dir[4][2];
int right_dir[4][2];
int map[101][101];
int check[101][101];
int snake_size = 1;
vector<pair<int,char>> snake;
int n;      // 맵 개수
int a;      // 사과 개수
int s;      // 뱀 행동
int game_second = 0;
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = 1;
    map[x][y] = 2;      // 뱀 넣어주기
    
    
    int snake_sec;
    char snake_dir;
    
    vector<pair<int,int>> head;
    vector<pair<int,int>> tail;
    
    head.push_back({x,y});      // 머리
    tail.push_back({x,y});      // 꼬리
    
    int mx = 0;
    int my = 0;
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<snake.size(); i++){
            snake_sec = snake[i].first;
            snake_dir = snake[i].second;
            if(snake_sec == game_second){
                break;
            }
        }
 
        // 오른쪽
        if(snake_dir == 'D' && snake_sec == game_second){
            mx = dx + 0;
            my = dy + -1;
        }
        // 왼쪽
        else if(snake_dir == 'C' && snake_sec == game_second){
            mx = dx + 0;
            my = dy + 1;
        }else {
            mx = dx + 1;
            my = dy + 0;
        }

        // 범위 벗어나지않을 경우
        if(mx >= 0 && mx < n && my >= 0 && my < n){
            game_second++; // 시간초
            snake_size++; // 뱀길이 증가
            head.pop_back();
            head.push_back({mx,my});
            
            // 체크안되어있고 사과있다면
            if(check[mx][my] == 0 && map[mx][my] == 1){
                check[mx][my] = 1;
                map[mx][my] = 2;
            }else if(check[mx][my] == 0 && map[mx][my] == 0){
                check[mx][my] = 1;
                
                int z = tail.front().first;
                int x = tail.front().second;
                map[z][x] = 0;   // 값 비워주기
                check[z][x] = 0; // 기존꼬리 체크지워주기
                
                // 오른쪽
                if(snake_dir == 'D'){
                    z = z + 0;
                    x = x + -1;
                }
                // 왼쪽
                else if(snake_dir == 'C'){
                    z = z + 0;
                    x = x + 1;
                }else {
                    z = z + 1;
                    x = x + 0;
                }
                check[z][x] = 1;        //
                tail.pop_back();
                tail.push_back({z,x});
            }
            q.push({mx,my});
        }
//        if(map[mx][my] == 2 && check[mx][my] == 1){
//            break;
//        }
//
        
    }
}

int main(void){
    
    cin >> n;
    
    
    cin >> a;
    for(int i=0; i<a; i++){
        int x,y;
        cin >> x >> y;
        map[x-1][y-1] = 1;
    }
    
    cin >> s;
    for(int i=0; i<s; i++){
        int x;
        char y;
        cin >> x >> y;
        snake.push_back({x,y});
    }
    bfs(0,0);
    cout << game_second;
    return 0;
}
