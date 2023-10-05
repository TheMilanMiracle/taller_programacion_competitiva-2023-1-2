#include <bits/stdc++.h>
using namespace std;

int modulo = 1e9 + 7;

int main(){
    int n;
    string row;

    cin >> n;

    vector<int> a(n, 1);
    vector<vector<int>> maze(n, a);

    //read the input for the maze and iteration
    for(int i = 0; i < n; i++){
        //read the row
        cin >> row;
        for(int j = 0; j < n; j++){
            //if the cell have a bomb it is represented with a zero
            if(row[j] == '*') maze[i][j] = 0;
            //base cases
            else if (i == 0){ if(j > 0) maze[i][j] = maze[i][j-1];}
            else if (j == 0){ if(i > 0) maze[i][j] = maze[i-1][j];}
            //general case
            else maze[i][j] = (maze[i-1][j] % modulo + maze[i][j-1] % modulo) % modulo; 
        }
    }

    //the answer is in maze[n-1][n-1]
    cout << maze[n-1][n-1] << endl;

    return 0;
}