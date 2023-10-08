#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n;
    cin>>n;
    stack<int> s;
    queue<int> q;


    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        q.push(x);
    }


    while(!q.empty()){
        if(s.empty()){
            cout<<"-1"<<" ";
            s.push(q.front());
            q.pop();
        }
        else if(q.front() >= s.top()){
            cout<<s.top()<<" ";
            s.push(q.front());
            q.pop();
        }
        else {s.pop();}
    }
}
