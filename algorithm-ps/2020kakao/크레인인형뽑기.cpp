//
//  크레인인형뽑기.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/24.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int main(void){
    vector<vector<int,int>> board{{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves{1,5,3,5,1,2,1,4};
    
    stack<int> s;
    int ans = 0;
    for(int k=0; k<moves.size(); k++){
        for(int j=0; j<board.size(); j++){
            // 인형 라인 번호 선택, stack이 빈게 아니면
            if(board[j][moves[k]-1] != 0){
                if(!s.empty() && board[j][moves[k]-1] == s.top()){
                    
                    ans +=2;
                    s.pop();
                }else {
                    s.push(board[j][moves[k]-1]);
                }
                // 무조건 값은 0으로 만들어주어야하기때문에 조건을 벗어나서 뽑은 경우로 체크
                board[j][moves[k]-1] = 0;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

























/*


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(int i=0; i<moves.size(); i++){
        int moves_size = moves[i]-1;
        for(int j=0; j<board.size(); j++){
            // 인형이 있는 경우
            if(board[j][moves_size] != 0){
                if(!s.empty() && s.top() == board[j][moves_size]){
                       s.pop();
                       answer +=2;
                }else {
                    s.push(board[j][moves_size]);
                }
                   board[j][moves_size] = 0;
                    break;
            }
        }
    }
    return answer;
}
*/
