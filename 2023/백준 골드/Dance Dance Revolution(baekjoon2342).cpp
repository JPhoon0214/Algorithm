#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> cache(100000, vector<vector<int>>(5, vector<int>(5, -1)));
const int cost[5][5]={
    {1, 2, 2, 2, 2},
    {2, 1, 3, 4, 3},
    {2, 3, 1, 3, 4},
    {2, 4, 3, 1, 3},
    {2, 3, 4, 3, 1}
};

int getMinCost(pair<int, int> pos, int index, vector<int>& instructions) {
    if(index==instructions.size())
        return 0;
    if(pos.first==pos.second)
        return 987654321;
    
    int& ret=cache[index][pos.first][pos.second];
    if(ret!=-1)
        return ret;

    int target=instructions[index];
    ret=min(getMinCost({target, pos.second}, index+1, instructions)+cost[pos.first][target], getMinCost({pos.first, target}, index+1, instructions)+cost[pos.second][target]);
    return ret;
}

int main() {
    vector<int> instructions;
    while(true) {
        int input;
        cin>>input;
        if(input==0)
            break;
        instructions.push_back(input);
    }
    cout<<getMinCost({0, instructions[0]}, 1, instructions)+2;
}