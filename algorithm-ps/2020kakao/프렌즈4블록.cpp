//
//  프렌즈4블록.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/31.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    vector<string> board{"CCBDE", "AAADE", "AAABF", "CCBBF"};
    int m = 4;
    int n = 5;
    int answer = 0;
    bool flag = false;
    
    
    while(flag == false){
        vector<vector<bool>> v(m, vector<bool>(n));     // vector Init
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(board[i][j] == 0){
                    flag = true;
                    continue;
                }
                if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]){
                    v[i][j] = true;
                    v[i][j+1] = true;
                    v[i+1][j] = true;
                    v[i+1][j+1] = true;
                    flag = false;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(v[i][j] == true){
                    answer++;
                    for(int k=i-1; k>=0; k--){
                        board[k+1][j] = board[k][j];
                        board[k][j] = 0;
                    }
                }
            }
        }
    }
        
    cout << answer << '\n';

    return 0;
}
// 4    5    [CCBDE, AAADE, AAABF, CCBBF]    14
/*
int left_up_dir[3][2] = {{-1,0},{0,1},{-1,0}};
int right_up_dir[3][2] = {{0,1},{1,1},{1,0}};
int left_down_dir[3][2] = {{-1,0},{-1,-1},{0,-1}};
int right_down_dir[3][2] = {{0,-1},{1,0},{1,-1}};
int check[31][31];
int n=4,m=5;
void bfs(int x,int y,vector<string> board,int *ans){
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    check[x][y] = 1;
    while(!q.empty()){
        int mx = q.front().first;
        int my = q.front().second;
        q.pop();
        int cnt1 = 1;
        int cnt2 = 1;
        int cnt3 = 1;
        int cnt4 = 1;
        for(int i=0; i<3; i++){
            int dx1 = mx + left_up_dir[i][0];
            int dy1 = my + left_up_dir[i][1];
            int dx2 = mx + right_up_dir[i][0];
            int dy2 = my + right_up_dir[i][1];
            int dx3 = mx + left_down_dir[i][0];
            int dy3 = my + left_down_dir[i][1];
            int dx4 = mx + right_down_dir[i][0];
            int dy4 = my + right_down_dir[i][1];
            
            if(dx1 >= 0 && dx1 < m && dy1 >= 0 && dy1 < n){
                if(check[dx1][dy1] == 0 && board[dx1][dy1] == board[mx][my]){
                    check[dx1][dy1] = 1;
                    cnt1 += 1;
                    for(int j=0; j<dx1; j++){
                          board[dx1][dy1] = board[dx1-j][dy1];
                          *ans += 1;
                      }
                }
            }
            if(dx2 >= 0 && dx2 < m && dy2 >= 0 && dy2 < n){
                if(check[dx2][dy2] == 0 && board[dx2][dy2] == board[mx][my]){
                    check[dx2][dy2] = 1;
                    cnt2 += 1;
                    for(int j=0; j<dx2; j++){
                        board[dx2][dy2] = board[dx2-j][dy2];
                        *ans += 1;
                    }
                }
            }
            if(dx3 >= 0 && dx3 < m && dy3 >= 0 && dy3 < n){
                if(check[dx3][dy3] == 0 && board[dx3][dy3] == board[mx][my]){
                    check[dx3][dy3] = 1;
                    cnt3 += 1;
                    for(int j=0; j<dx3; j++){
                        board[dx3][dy3] = board[dx3-j][dy3];
                        *ans += 1;
                    }
                }
            }
            if(dx4 >= 0 && dx4 < m && dy4 >= 0 && dy4 < n){
                if(check[dx4][dy4] == 0 && board[dx4][dy4] == board[mx][my]){
                    check[dx4][dy4] = 1;
                    cnt4 += 1;
                    for(int j=0; j<dx4; j++){
                        board[dx4][dy4] = board[dx4-j][dy4];
                        *ans += 1;
                    }
                }
            }
            
            // 맵 위에 있는것들 값을 떨궈주기
//            if(cnt1 == 4){ㅔㅐ;[
//                for(int i=dy1-2; i<dy1; i++){
//                    board[dx1][dy1] = board[dx1][dy1-i];
//                    *ans += 1;
//                }
//            }
//            else if(cnt2 == 4){
//                for(int i=dy2-2; i<dy2; i++){
//                    board[dx2][dy2] = board[dx2][dy2-i];
//                    *ans += 1;
//                }
//            }else if(cnt3 == 4){
//                for(int i=dy3-2; i<dy3; i++){
//                    board[dx3][dy3] = board[dx3][dy3-i];
//                    *ans += 1;
//                }
//            }else if(cnt4 == 4){
//                for(int i=dy4-2; i<dy4; i++){
//                    board[dx4][dy4] = board[dx4][dy4-i];
//                    *ans += 1;
//                }
//            }
        }
    }
    
}

int main(void){
    
    vector<string> board{"CCBDE", "AAADE", "AAABF", "CCBBF"};
    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == 0){
                bfs(i,j,board,&ans);
            }
        }
    }
    cout << ans;
    return 0;
}

*/


