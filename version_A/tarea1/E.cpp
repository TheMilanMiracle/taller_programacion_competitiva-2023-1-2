#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        int op, num;
        bool isStack = true, isQ = true, isPQ = true;

        for(int i = 0; i < n; i++){
            cin >> op >> num;
            if(op == 1){
                q.push(num);
                pq.push(num);
                s.push(num);
            }
            else{
                if(q.empty() || num != q.front()){
                    isQ = false;
                }
                else if (num == q.front())
                {
                    q.pop();
                }
                if(pq.empty() || num != pq.top()){
                    isPQ = false;
                }
                else if (num == pq.top())
                {
                    pq.pop();
                }
                if(s.empty() || num != s.top()){
                    isStack = false;
                }
                else if (num == s.top())
                {
                    s.pop();
                }
                
            }
        }

        if((isQ == true) && (isPQ == false) && (isStack == false)){
            cout << "queue" << endl;
        }
        else if((isQ == false) && (isPQ == true) && (isStack == false)){
            cout << "priority queue" << endl;
        }
        else if((isQ == false) && (isPQ == false) && (isStack == true)){
            cout << "stack" << endl;
        }
        else if((isQ == false) && (isPQ == false) && (isStack == false)){
            cout << "impossible" << endl;
        }
        else{
            cout << "not sure" << endl;
        }

    }
}