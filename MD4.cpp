#include <iostream>
#include <queue>

using namespace std;

void r_reverse_queue(queue<int>& q) {
    if (q.empty()) { return; }

    int t = q.front();
    q.pop();

    r_reverse_queue(q);

    q.push(t);
}

int main(int argc, char* argv[]) {
    queue<int> q;
    q.push(1); q.push(2); q.push(3); q.push(4); q.push(5);
      
    r_reverse_queue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}