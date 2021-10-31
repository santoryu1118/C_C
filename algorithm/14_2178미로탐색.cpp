#include <iostream>
using namespace std;

const int MAX = 100;
int N, M;
int Map[MAX][MAX];
int Visit[MAX][MAX] = {0,};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void DFS (int x, int y, int depth){
    if (x == N-1 && y == M-1){
        if (depth < Map[x][y]){
            Map[x][y] = depth;
        }
        return;
    }

    for (int i =0 ; i<4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if ( next_x <0 || next_y <0 || next_x >= N || next_y >= M) continue;
        if (Visit[next_x][next_y] == 0 && Map[next_x][next_y] != 0){
            Visit[next_x][next_y] = 1;
            DFS(next_x, next_y, depth +1);
            Visit[next_x][next_y] = 0;
        }
    }
}

int main(){
    cin >> N >> M;

    string input;
    for (int i = 0; i < N; i ++){
        cin >> input;
        for (int j = 0; j < M; j++){
            Map[i][j] = input[j] -'0';
        }
    }

    Map[N-1][M-1] = N * M;
    DFS(0,0,1);
    cout << Map[N-1][M-1];
  
    return 0;
}

// 4 6
// 101111
// 101010
// 101011
// 111011

// 2 25
// 1011101110111011101110111
// 1110111011101110111011101

// 0123456789012345678901234