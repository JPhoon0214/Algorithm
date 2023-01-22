#include <iostream>
#include <vector>

using namespace std;

//type 0:완전 네모 1:위가 삐져나온 네모 2:아래가 삐져나온 네모
int getCaseNum(vector<vector<int>>& cache, vector<vector<int>>& cost, int index, int width, int type, int availCover) {
    if(index==width-1) {
        if(type==0) {
            if(cost[index][0]+cost[index][1]<=availCover) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else {
            return 1;
        }
    }
    if(index==width) {
        return 0;
    }
    
    int& ret=cache[index][type];
    if(ret!=-1) {
        return ret;
    }
    
    ret=987654321;
    if(type==0) {
        if(cost[index][0]+cost[index+1][0]<=availCover || cost[index][1]+cost[index+1][1]<=availCover) {
            if(cost[index][0]+cost[index+1][0]<=availCover && cost[index][1]+cost[index+1][1]<=availCover) {
                ret=min(ret, 2+getCaseNum(cache, cost, index+2, width, 0, availCover));
            }
            if(cost[index][0]+cost[index+1][0]<=availCover) {
                ret=min(ret, 2+getCaseNum(cache, cost, index+1, width, 2, availCover));
            }
            if(cost[index][1]+cost[index+1][1]<=availCover) {
                ret=min(ret, 2+getCaseNum(cache, cost, index+1, width, 1, availCover));
            }
        }
        if(cost[index][0]+cost[index][1]<=availCover) {
            ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 0, availCover));
        }
        else {
            ret=min(ret, 2+getCaseNum(cache, cost, index+1, width, 0, availCover));
        }
    }
    else if(type==1) {
        if(cost[index][0]+cost[index+1][0]<=availCover) {
            ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 2, availCover));
        }
        ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 0, availCover));
    }
    else {
        if(cost[index][1]+cost[index+1][1]<=availCover) {
            ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 1, availCover));
        }
        ret=min(ret, 1+getCaseNum(cache, cost, index+1, width, 0, availCover));
    }
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase;
    cin>>testCase;
    for(; testCase>0; testCase--) {
        int width, availCover;
        cin>>width>>availCover;
        vector<vector<int>> cost(width, vector<int>(2));
        for(int i=0; i<width; i++) {
            cin>>cost[i][0];
        }
        for(int i=0; i<width; i++) {
            cin>>cost[i][1];
        }
        
        vector<vector<int>> cache(10000, vector<int>(3, -1));
        int ret=getCaseNum(cache, cost, 0, width, 0, availCover);

        if(width>1 && (cost[0][0]+cost[width-1][0]<=availCover || cost[0][1]+cost[width-1][1]<=availCover)) {
            if(cost[0][0]+cost[width-1][0]<=availCover && cost[0][1]+cost[width-1][1]<=availCover) {
                int tempCost[2][2];
                tempCost[0][0]=cost[0][0]; tempCost[1][0]=cost[width-1][0];
                tempCost[0][1]=cost[0][1]; tempCost[1][1]=cost[width-1][1];
                cost[0][0]=cost[0][1]=cost[width-1][0]=cost[width-1][1]=availCover;
                
                cache=vector<vector<int>>(10000, vector<int>(3, -1));
                ret=min(ret, getCaseNum(cache, cost, 0, width, 0, availCover)-2);
                
                cost[0][0]=tempCost[0][0]; cost[width-1][0]=tempCost[1][0];
                cost[0][1]=tempCost[0][1]; cost[width-1][1]=tempCost[1][1];
            }
            if(cost[0][0]+cost[width-1][0]<=availCover) {
                int tempCost[2];
                tempCost[0]=cost[0][0]; tempCost[1]=cost[width-1][0];
                cost[0][0]=cost[width-1][0]=availCover;

                cache=vector<vector<int>>(10000, vector<int>(3, -1));
                ret=min(ret, getCaseNum(cache, cost, 0, width, 0, availCover)-1);

                cost[0][0]=tempCost[0]; cost[width-1][0]=tempCost[1];
            }
            if(cost[0][1]+cost[width-1][1]<=availCover) {
                int tempCost[2];
                tempCost[0]=cost[0][1]; tempCost[1]=cost[width-1][1];
                cost[0][1]=cost[width-1][1]=availCover;

                cache=vector<vector<int>>(10000, vector<int>(3, -1));

                ret=min(ret, getCaseNum(cache, cost, 0, width, 0, availCover)-1);

                cost[0][1]=tempCost[0]; cost[width-1][1]=tempCost[1];
            }
        }
        cout<<ret<<"\n";
    }
}