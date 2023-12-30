#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, mushrooms = 0, time = 0;
    cin >> n >> m;
    vector<pair <int,int>> marios;
    int matrix[n + 2][m + 2];
    for(int i = 0; i < n + 2; i++){
        for(int j = 0; j < m + 2; j++){
            if(i == 0 || j == 0 || i == n + 1 || j == m + 1){
                matrix[i][j] = 1000;
                continue;
            }
            cin >> matrix[i][j];
            if(matrix[i][j] == 2){
                marios.push_back({i,j});
            }
            else if(matrix[i][j] == 1){
                mushrooms++;
            }
        }
  }
  queue<pair <int,int>> q;
  for(int i = 0; i < marios.size(); i++){
    q.push({marios[i].first, marios[i].second});
  }
  while(!q.empty()){
    if(!mushrooms) break;
    int size = q.size();
    while(size--){
        pair <int,int> marioPos = q.front();
        q.pop();
        int i = marioPos.first, j = marioPos.second;
        if(matrix[i - 1][j] == 1){
            matrix[i - 1][j] = 2;
            q.push({i - 1, j});
            mushrooms --;
        }
        if(matrix[i+1][j] ==1){
            matrix[i+1][j] =2;
            q.push({i+1,j});
            mushrooms--;
        }
        if(matrix[i][j-1] == 1){
            matrix[i][j-1] = 2;
            q.push({i, j -1});
            mushrooms--;
        }
        if(matrix[i][j+1] ==1){
            matrix[i][j+1] =2;
            q.push({i,j+1});
            mushrooms--;
        }
    }
    time++;
  }
  
 if(mushrooms == 0){
    cout << time << endl;
 }
 else {
    cout << -1;
 }
}
