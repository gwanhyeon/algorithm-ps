//
//  치킨배달15686.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/21.
//  Copyright © 2020 kgh. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
int map[51][51];
bool check[51];
int n,m = 0;
const int MAX = 100001;
int ans = MAX;
void dfs(int idx,int cnt){
    // 치킨 사이즈를 넘게되었을 경우
    if(idx > chicken.size()){
        return;
    }
    // 치킨집 m개를 선택하였을때
    if(cnt == m){
        int chicken_street = 0;
        for(int i=0; i<house.size(); i++){
            int dist = MAX;
            for(int j=0; j<chicken.size(); j++){
                if(check[j] == true){
                    int ax = house[i].first;
                    int ay = house[i].second;
                    int bx = chicken[j].first;
                    int by = chicken[j].second;
                    
                    int distance = abs(ax-bx) + abs(ay-by);
                    dist = min(dist,distance);
                }
            }
            chicken_street += dist;
        }
        ans = min(ans, chicken_street);
        return;
    }
    // 치킨 선택
    check[idx] = true;
    dfs(idx+1, cnt+1);
    // 치킨 미선택
    check[idx] = false;
    dfs(idx+1, cnt);
}
int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                house.push_back({i,j});
            }
            if(map[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    }
    dfs(0,0);
    cout << ans << '\n';
    return 0;
}
/* bfs와 dfs 짬뽕문제인줄 좌표문제가 나왔기때문에 동서남북을 처리해야하는줄 알았다
 하지만 dfs로 해당좌표에 값들가지고 놀면되는문제였다. 치킨집을 선택하는지 선택안하는지를 처리하고 치킨거리를 구해주면 되었다.*/


/*
 치킨거리 |r1-r2| + |c1-c2|
 각자의 집 치킨거리를 구해야한다.
 치킨집중 1~M개중에서 도시의 치킨거리를 구한다
 가장 최소가 되는 치킨집을 골라서 return
 치킨집 <-> 집간의 치킨거리를 모두 구한다
 
 집이 기준이고 치킨집으로 가는거리를 뜻한다
 M개를 선택1개를 선택하였을때, 2개를 선택하였을때 모든 치킨의 거리수를 구해준다.
 */
/*
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[51][51];
int check[51][51];
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int n,m = 0;
int dis_check[51];
vector<int> v;
void bfs(int x,int y,int cnt){
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = 1;
    int start = x;
    int end = y;
    int distance = 0;
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            if(mx >= 0 && mx < n && my >= 0 && my < n){
                if(map[mx][my] != 2 && check[mx][my] == 0){
                    check[mx][my] = 1;
                    q.push({mx,my});
                }
                
                // 방문하지 않은 치킨집 일 경우
                if(map[mx][my] == 2 && check[mx][my] == 0){
                    // 치킨거리를 구하자
                    distance += abs((start+1)-(mx+1)) + abs((end+1)-(my+1));
                    //cout << distance << ' ';
//                    if(dis_check[cnt] > distance){
//                        dis_check[cnt] = distance;
//                    }
//                    cnt++;
                    
                    check[mx][my] = 1;
                    q.push({mx,my});
                }
                
                
            }
        }
    }
    v.push_back(distance);
}
//void dfs(int idx, int cnt){
//
//    //m개이하를 골랐을 경우
//    if(cnt <= m){
//
//        for(int i=0; i<v.size(); i++){
//
//
//        }
////        for(int k=0; k<chicken.size(); k++){
////            if(chicken_check[k] == 1){
////                for(int i=0; i<n; i++){
////                      for(int j=0; j<n; j++){
////                          // 집일 경우
////                          if(map[i][j] == 1){
////                              bfs(i,j);
////                          }
////                      }
////                  }
////
////            }
////        }
//        return;
//    }
//
//
//
//    for(int i=idx; i<chicken.size(); i++){
//        int x = chicken.front().first;
//        int y = chicken.front().second;
//        // 치킨의 위치
//        v.push_back({x,y});
//        dfs(idx+i, cnt+1);
//        v.pop_back();
//    }
//}

int main(void){
    
    cin >> n >> m;
    // 맵 입력하기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<m; i++){
        dis_check[i] = 1000001;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt = 0;
            memset(check,0,sizeof(check));
            // 집일 경우
            if(map[i][j] == 1 ){
                bfs(i,j,cnt);
            }
            //int min = *min_element(v.begin(), v.end());
            //cout << min;
        }
    }
    
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    
//    for(int i=0; i<m; i++){
//        cout << dis_check[i];
//    }
    //cout << *min_element(v.begin(), v.end());
    return 0;
}


// 집일 경우->bfs->치킨집을 만나면 i,j값 도출 -> 치킨값

*/
