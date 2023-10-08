#include <iostream>
#include "queue"
#include "stack"

using namespace std;

int main(){
    queue<int> q1,q2;
    int cnt = 0;
    for (int i = 0; i < 5; ++i) {
        int x;
        cin>>x;
        q1.push(x);
    }
    for (int i = 0; i < 5; ++i) {
        int y;
        cin>>y;
        q2.push(y);
    }
    while(true){
        if (q1.size() ==0 and q2.size()==10){
            cout<<"Nursik "<<cnt;
            break;
        } else if(q2.size() ==0 and q1.size()==10){
            cout<<"Boris "<<cnt;
            break;
        }

        if (q1.front() == 0 and q2.front() == 9){
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
            q1.push(q2.front());
            q2.pop();
            cnt +=1;
        }
        else if(q1.front() == 9 and q2.front() == 0){
            int temp = q2.front();
            q2.pop();
            q2.push(q1.front());
            q2.push(temp);
            q1.pop();
            cnt +=1;

        }
        else if (q1.front() > q2.front()){
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
            q1.push(q2.front());
            q2.pop();
            cnt +=1;
        }
        else if(q1.front() < q2.front()){
            int temp = q2.front();
            q2.pop();
            q2.push(q1.front());
            q2.push(temp);
            q1.pop();
            cnt +=1;
        }
    }

    return 0;
}