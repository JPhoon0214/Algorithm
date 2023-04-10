#include <iostream>
#include <vector>

using namespace std;

const int dx[4]={1, 0, -1, 0};
const int dy[4]={0, -1, 0, 1};

int boardSize;

bool dfs(vector<vector<char>>& board, int y, int x, int direction) {
    if(x<0 || x>boardSize-1 || y<0 || y>boardSize-1) {
        return true;
    }
    
    if(board[y][x]=='S') {
        return false;
    }
    else if(board[y][x]=='O') {
        return true;
    }
    else {
        return dfs(board, y+dy[direction], x+dx[direction], direction);
    }
}

bool checkAvail(vector<vector<char>>& board) {
    for(int i=0; i<boardSize; i++) {
        for(int j=0; j<boardSize; j++) {
            for(int direction=0; direction<4; direction++) {
                if(board[i][j]!='T') {
                    continue;
                }                
                if(!dfs(board, i, j, direction)) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool putBlocks(vector<vector<char>>& board, int remainToChoose, int y, int x) {
    if(remainToChoose==0) {
        return checkAvail(board);
    }
    if(x==boardSize) {
        x=0; y++;
    }
    if(y==boardSize) {
        return false;
    }

    if(board[y][x]!='X') {
        return putBlocks(board, remainToChoose, y, x+1);
    }

    bool ret=false;
    
    board[y][x]='O';
    ret=ret || putBlocks(board, remainToChoose-1, y, x+1);
    
    board[y][x]='X';
    ret=ret || putBlocks(board, remainToChoose, y, x+1);
    
    return  ret;
}

int main() {
    cin>>boardSize;
    vector<vector<char>> board(boardSize, vector<char>(boardSize));

    for(int i=0; i<boardSize; i++) {
        for(int j=0; j<boardSize; j++) {
            cin>>board[i][j];
        }
    }
    if(putBlocks(board, 3, 0, 0)) {
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
}