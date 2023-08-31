#include <bits/stdc++.h>
using namespace std;

main(){
    int N, K, R = 0, count = 0;

    
    cin >> N >> K;    
    vector<pair<int,int>> stars;
    vector<int> a(N, 0);
    vector<vector<int>> visited(N, a);
    
    if(K == 1){cout << "Infinity" << endl;
        return 0;}
    else{
        for(int n = 0; n < N; n++){
            int x, y;
            cin >> x >> y;
            pair<int, int> star(x,y);
            stars.push_back(star);
            }
        for(int i = 0; i < N; i++){
            int xi = stars[i].first, yi = stars[i].second;
            for(int j = i+1; j < N; j++){
				vector<int> points(0,0);
                int xj = stars[j].first, yj = stars[j].second;
                if(!visited[i][j]){
                    count = 2;
                    
                    points.push_back(i);
                    points.push_back(j);
                    
                    for (int k = j+1; k < N ; k++){
                        int xk = stars[k].first, yk = stars[k].second;
                        if((yk - yi)*(xi - xj) == (yi - yj)*(xk - xi)){
                            count ++;
                            points.push_back(k);
                            }
                        }
                    for(int p = 0; p < count; p++){
                        for(int q = p+1; q < count; q++){
                            visited[points[p]][points[q]] = 1;
                            }
                        }
					if(count >= K){R += 1;}
					}
                }
            }
        cout << R << endl;
        return 0;
        }
    }
