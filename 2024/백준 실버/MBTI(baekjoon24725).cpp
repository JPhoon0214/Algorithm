#include <iostream>
#include <vector>

using namespace std;

const int dxs[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int dys[8]={1, 1, 0, -1, -1, -1, 0, 1};

const string mbti[16]={
    "INFP", "INFJ", "INTP", "INTJ", "ISFP", "ISFJ", "ISTP", "ISTJ", 
    "ENFP", "ENFJ", "ENTP", "ENTJ", "ESFP", "ESFJ", "ESTP", "ESTJ"
};

int height, width;

bool isMBTI(string& curr) {
    for(int i=0; i<16; i++) {
        if(mbti[i]==curr) return true;
    }
    return false;
}

bool check(int x, int y, int dx, int dy, string& curr, vector<string>& map) {
    if(curr.size()==4) return isMBTI(curr);
    if(x<0 || x>width-1 || y<0 || y>height-1) return false;

    curr.push_back(map[y][x]);
    return check(x+dx, y+dy, dx, dy, curr, map);
}

int getCnt(vector<string>& map) {
    int cnt=0;

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            for(int k=0; k<8; k++) {
                string mbtiStr="";
                if(check(j, i, dxs[k], dys[k], mbtiStr, map)) cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin>>height>>width;

    vector<string> map(height);
    for(int i=0; i<height; i++) cin>>map[i];

    cout<<getCnt(map);
}