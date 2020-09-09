//
//  연구소14502.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/07.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m = 0;
const int MAX = 8;
int map[MAX][MAX];
int copy_map[MAX][MAX];
vector<pair<int,int>> empty;
vector<pair<int,int>> virus;

int empty_size = 0;
int check[MAX*MAX];     // size를 MAX * MAX를 해준이유는 빈칸이 N*M까지 나올 수 있기 때문입니다.
int visited[MAX][MAX];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int ans = -1;
void bfs(int x,int y){
    
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(visited[mx][my] == 0 && copy_map[mx][my] == 0){
                    visited[mx][my] = 1;
                    copy_map[mx][my] = 2;
                    q.push({mx,my});
                }
            }
            
        }
        
    }
    
}
    
    
void dfs(int idx,int cnt){
    
    if(cnt == 3){
        memset(visited, 0, sizeof(visited));
        // 기존의 맵을 변경시키면 안되기때문에 값을 카피시켜줍니다.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                copy_map[i][j] = map[i][j];
            }
        }
        
        // 벽을 세우기 하나의 경우마다의 벽을 세워야함.
        int count = 0;
        for(int i=0; i<empty_size; i++){
            if(count == 3){
                break;
            }
            if(check[i] == 1){
                int x = empty[i].first;
                int y = empty[i].second;
                copy_map[x][y] = 1;
                count +=1;
            }
        }
        
        // virus 전염시키기
        for(int i=0; i<virus.size(); i++){
            int x = virus[i].first;
            int y = virus[i].second;
            bfs(x,y);
        }
        
        int safe_size = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(copy_map[i][j] == 0){
                    safe_size++;
                }
            }
            
        }
        
        if(ans < safe_size){
            ans = safe_size;
        }
        return;
    }
    
    // 조합의 형식으로 3개가 뽑힐때까지 뽑았다가 종료되는 시점에 그 값을 다시 false로 만들고 다시 조합의 경우를 뽑습니다.
    for(int i=idx; i<empty_size; i++){
        if(check[i] == 1){
            continue;
        }
        check[i] = 1;
        dfs(i, cnt+1);
        check[i] = 0;
    }
    
}
int main(void){
    cin >> n >> m;
    
    // 값을 입력받고 빈칸과 바이러스의 좌표를 담고 있는 벡터에 해당 값들을 넣어주게 된다.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            // 0: 빈칸
            if(map[i][j] == 0){
                empty.push_back({i,j});
            }
            // 2: 바이러스
            else if(map[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }
    // 빈칸을 기준으로 DFS를 수행한다. 따라서,조합의 경우라고 생각하면 됩니다. N(빈칸의 개수중)에서 3개를 뽑는 경우의 수라고 생각을 합니다.
    empty_size = empty.size();
    dfs(0,0);
    cout << ans;
    return 0;
}


/*
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 8
using namespace std;
int n,m;

int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int map[MAX][MAX];
int copy_map[MAX][MAX];
int check[MAX*MAX];
int visited[MAX][MAX];

vector<pair<int,int>> empty;
vector<pair<int,int>> virus;
int size_empty=0;
int max_check=0;

void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = 1;
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            if(mx >= 0 && my >= 0 && mx < n && my < m){
                if(copy_map[mx][my] == 0 && visited[mx][my] == 0){
                    visited[mx][my] = 1;
                    copy_map[mx][my] = 2;
                    q.push(make_pair(mx,my));
                }
            }
            
        }
    }
    
}
void recursive(int idx, int cnt){
    
    if(cnt == 3){
        memset(visited, 0, sizeof(visited));
        // 맵 카피
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                copy_map[i][j] = map[i][j];
            }
        }
        // 벽세우기
        int count = 0;
        for(int i=0; i<size_empty; i++){
            if(count == 3){
                break;
            }
            if(check[i] == 1){
                int x = empty[i].first;
                int y = empty[i].second;
                copy_map[x][y] = 1;
                count++;
            }
        }
        
        
        // 전염 시킨다.
        for(int i=0; i<virus.size(); i++){
            int x = virus[i].first;
            int y = virus[i].second;
            bfs(x,y);
        }
        int max_cnt=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(copy_map[i][j] == 0){
                    max_cnt+=1;
                    
                }
            }
        }
        if(max_check < max_cnt){
            max_check = max_cnt;
        }
        
        
        return;
    }
    
    for(int i=idx; i<size_empty; i++){
        if(check[i] == 1){
            continue;
        }
        check[i] = 1;
        recursive(i,cnt+1);
        check[i] = 0;
    }
}
int main(void){
    cin >> n >> m;
    
    // 1. 맵을 입력받는다.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0){
                empty.push_back({i,j});
            }else if(map[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }
    size_empty = empty.size();

    // 2. 벽을 세운다 (Recursive) 0인 개수중 3개를 뽑는다. Recursive(0,0); 시작
    recursive(0,0);
    cout << max_check;
    // 3. 맵을 카피한다.
    // 4. 전염시킨다. 전파
    // 5. 개수를 확인한다.
    
    
}

*/








/*
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
bool check[10001][10001];
int map[10001][10001];
int dist[10001][10001];
int n,m = 0;
int dir[4][2]={{0,1},{-1,0},{1,0},{0,-1}};
vector<int> res;

void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = 1;
    dist[x][y] = map[x][y];
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(check[mx][my] == 0 && dist[mx][my] == 0){
                    check[mx][my] = 1;
                    dist[mx][my] = 2;
                    //dist[mx][my] = map[dx][dy] + 1;
                    //dist[mx][my] = dist[dx][dy] + map[mx][my];
                    q.push({mx,my});
                }
            }
            
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j] == 0 && dist[i][j] == 0){
                cnt += 1;
            }
        }
    }
    res.push_back(cnt);
}
int main(void){
    
    // empty 0 wall 1 virus 2
    cin >> n >> m;
    memset(check,0,sizeof(check));
    memset(map,0,sizeof(map));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    vector<int> wall;
    for(int i=0; i<3; i++){
        wall.push_back(1);
    }
    for(int i=0; i<n*m-3; i++){
        wall.push_back(0);
    }
    sort(wall.begin(), wall.end());
    
    // 벽세우기
    do {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<n*m; k++){
                    int div_x = i+1;
                    int div_y = j+1;
                    int x = wall.size() / n;
                    int y = wall.size() % m;
                    if(wall[k] == 1){
                        check[x][y] = 1;
                    }
                }
                // bfs
                if(map[i][j] == 2 && check[i][j] == 0){
                    bfs(i,j);
                }
                
          
            }
        }
//        memset(check,0,sizeof(check));
//        memset(dist,0,sizeof(dist));
        
    } while (next_permutation(wall.begin(), wall.end()));
    
     // 영역 체크 값 max
    long long max = *max_element(res.begin(), res.end());
    
    // 결과 값
    cout << max << '\n';
    return 0;
    
}
*/

