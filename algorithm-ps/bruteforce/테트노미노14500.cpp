//
//  테트노미노14500.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/07/24.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int arr[501][501];

int main(void){
    int n,m = 0;
    int ans = 0;
    cin >> n >> m;
    
    // 맵 값 채우기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // ㅡ ㅡ ㅡ ㅡ
            if(j+3 < m){
                int result = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
                if(result > ans){
                    ans = result;
                }
            }
            /*
             |
             |
             |
             |
             */
            
            if(i+3 < n){
                int result = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
                if(result > ans){
                    ans = result;
                }
            }
            
            // |
            // ㅡ ㅡ ㅡ
            
            if(i+1 < n && j+2 < m){
                int result = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
                if(result > ans){
                    ans = result;
                }
                
            }
            
            // |
            // |
            // | ㅡ
            
            if(i+2 < n && j+1 < m){
                int result = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1];
                if(result > ans){
                    ans = result;
                }
            }
            
            // | ㅡ ㅡ
            // |
            
            if(i+1 < n && j+2 < m){
                int result = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j];
                if(result > ans){
                    ans = result;
                }
            }
            
            // ㅡ ㅡ
            //   |
            //   |
            
            if(i+2 < n && j+1 < m){
                int result = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1];
                if(result > ans){
                    ans = result;
                }
            }
            
            //      |
            // ㅡ ㅡ ㅡ
            
            if(i+1 < n && j+2 < m){
                int result = arr[i][j+2] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2];
                if(result > ans){
                    ans = result;
                }
            }
            
            //     ㅡ
            //     ㅡ
            //  ㅡ ㅡ
            
            if(i+2 < n && j-1 < m){
                int result = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j-1];
                if(result > ans){
                    ans = result;
                }
            }
            
            // ㅡ ㅡ ㅡ
            //      ㅡ
            
            if(i+1 < n && j+2 < m){
                int result = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2];
                if(result > ans){
                    ans = result;
                }
            }
            
            // ㅡ ㅡ
            // ㅡ
            // ㅡ
            if(i+2 < n && j+1 < m){
                int result = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+2][j];
                if(result > ans){
                    ans = result;
                }
            }
            
            // | |
            // | |
            if (i+1 < n && j+1 < m) {
                int result = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
                if (ans < result) ans = result;
            }
             //    ㅡ ㅡ
            //  ㅡ ㅡ
            if (i-1 >= 0 && j+2 < m) {
                int result = arr[i][j] + arr[i][j+1] + arr[i-1][j+1] + arr[i-1][j+2];
                if (ans < result) ans = result;
            }
            // |
            // | |
            //   |
            if (i+2 < n && j+1 < m) {
                int result = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
                if (ans < result) ans = result;
            }
            // ㅡ ㅡ
            //    ㅡ ㅡ
            if (i+1 < n && j+2 < m) {
                int result = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
                if (ans < result) ans = result;
            }
            //     |
            //   | |
            //   |
            if (i+2 < n && j-1 >= 0) {
                int result = arr[i][j] + arr[i+1][j] + arr[i+1][j-1] + arr[i+2][j-1];
                if (ans < result) ans = result;
            }
            
            //  ㅡ ㅡ ㅡ
            
            if(j+2 < m){
                int result = arr[i][j] + arr[i][j+1] + arr[i][j+2];
                  //    |
                  // ㅡ ㅡ ㅡ
                if(i-1 >= 0){
                    int result2 = result + arr[i-1][j+1];
                    if(result2 > ans){
                        ans = result2;
                    }
                }
                // ㅡ ㅡ ㅡ
                //    |
                if(i+1 < n){
                    int result2 = result + arr[i+1][j+1];
                    if(result2 > ans){
                        ans = result2;
                    }
                }
            }
            
            
            // ㅡ
            // ㅡ
            // ㅡ
            if(i+2 < n){
                int result = arr[i][j] + arr[i+1][j] + arr[i+2][j];
                //   ㅡ
                //ㅡ ㅡ
                //   ㅡ
                if(j-1 >= 0){
                    int result2 = result + arr[i+1][j-1];
                    if(result2 > ans){
                        ans = result2;
                    }
                }
                
                // ㅡ
                // ㅡ ㅡ
                // ㅡ
                if(j+1 < m){
                    int result2 = result + arr[i+1][j+1];
                    if(result2 > ans){
                        ans = result2;
                    }
                }
                
            }
        }
    }
    cout << ans << '\n';
    
    
    return 0;
}
