 #include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 1000

struct State {
    int c1, c2, c3;
};

struct State queue[MAX_STATES];
int front = 0, rear = 0;


struct State parent[11][8][5];
int visited[11][8][5] = {0};  

int cap[3] = {10, 7, 4};  


void enqueue(struct State s) { queue[rear++] = s; }
struct State dequeue() { return queue[front++]; }

int isGoal(struct State s) {
    return (s.c2 == 2 || s.c3 == 2);
}


void pour(struct State src, struct State *dest, int from, int to) {
    int temp[3] = {src.c1, src.c2, src.c3};
    int amount = temp[from] < (cap[to] - temp[to]) ? temp[from] : (cap[to] - temp[to]);
    temp[from] -= amount;
    temp[to] += amount;
    dest->c1 = temp[0];
    dest->c2 = temp[1];
    dest->c3 = temp[2];
}


void printPath(struct State s) {
    if(parent[s.c1][s.c2][s.c3].c1 == -1) { // Initial state
        printf("(%d, %d, %d)\n", s.c1, s.c2, s.c3);
        return;
    }
    printPath(parent[s.c1][s.c2][s.c3]);
    printf("(%d, %d, %d)\n", s.c1, s.c2, s.c3);
}


void BFS(struct State start) {
    
    parent[start.c1][start.c2][start.c3].c1 = -1;
    parent[start.c1][start.c2][start.c3].c2 = -1;
    parent[start.c1][start.c2][start.c3].c3 = -1;

    enqueue(start);
    visited[start.c1][start.c2][start.c3] = 1;

    while(front < rear) {
        struct State cur = dequeue();

        if(isGoal(cur)) {
            printf("Goal reached!\nSequence of states:\n");
            printPath(cur);
            return;
        }

        
        for(int from = 0; from < 3; from++) {
            for(int to = 0; to < 3; to++) {
                if(from != to) {
                    struct State next;
                    pour(cur, &next, from, to);

                    if(!visited[next.c1][next.c2][next.c3]) {
                        enqueue(next);
                        visited[next.c1][next.c2][next.c3] = 1;
                        parent[next.c1][next.c2][next.c3] = cur;
                    }
                }
            }
        }
    }

    printf("No solution found.\n");
}

int main() {
    struct State start = {0, 7, 4};
    BFS(start);
    return 0;
}
