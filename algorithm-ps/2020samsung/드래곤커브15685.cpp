//
//  드래곤커브.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/16.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;

int n = 0;
int x,y,d,g = 0;
int map[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
vector<int> dir_info;
void dragon_curve();
void sqaure_find();

// g세대까지 드래곤커브를 진행합니다.
void dragonCurve(){
    int size = dir_info.size();
    for(int i=size-1; i >= 0; i--){
        int nDir = (dir_info[i] + 1) % 4;
        x = x + dx[nDir];
        y = y + dy[nDir];
        map[x][y] = 1;
        
        dir_info.push_back(nDir);
    }
    
}
int sqaureFind(){
    int cnt = 0;
    
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            
            if(map[i][j] == 1 && map[i+1][j] == 1 && map[i+1][j+1] == 1 && map[i][j+1] == 1){
                cnt++;
            }
        }
    }
    return cnt;
    
}

int main(void){
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y >> d >> g;
        
        // 맨 처음 시작지점 체크
        map[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        map[x][y] = 1;
        dir_info.clear();
        // 방향을 체크해서 저장시켜놔야지 나중에 역순+1을 시켜줄 수 있다.
        dir_info.push_back(d);
        // 다음 세대의 추가되는 선분의 방향정보 = 이전 세대의 방향정보를 역순으로 탐색하면서 + 1 % 4 를 한 것이 된다.
        for(int j=0; j<g; j++){
            // function dragon curve
            dragonCurve();
        }
    }
    int answer = sqaureFind();
    cout << answer << '\n';
    return 0;
}

