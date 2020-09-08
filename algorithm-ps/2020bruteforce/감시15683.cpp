//
//  감시15683.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/19.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int arr[8][8];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};        // 동서남북

void bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    
}

int main(void){
    
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int num=0;
            cin >> num;
            arr[i][j] = num;
            cout << arr[i][j];
        }
        cout << '\n';
        
    }
    
    // cctv 1~5 방향처리, 6벽, cctv뚫기
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           
            
            // cctv 1-5 경우
            if(arr[i][j] == 1){
                // 한방향만 동서남북4가지
                
            }else if(arr[i][j] == 2){
                // 위아래 직각 수직 수평2가지
                
            }else if(arr[i][j] == 3){
                // 수직의 경우 4가지
                
            }else if(arr[i][j] == 4){
                // 한가지 방향(양옆) 4가지
                
            }else if(arr[i][j] == 5){
                // 모든 방향 1가지
            }

        }
    }
    
    
    
    
    
    
    
    
    
    
    bfs();
    

    
    return 0;
}
