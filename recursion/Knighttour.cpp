#include<iostream>
using namespace std;
#define N 8

bool isSafe(int x, int y, int soln[N][N]) {
    if(x >=0 && x < N && y >= 0 && y< N && soln[x][y] == -1)
        return true;
    return false;
}

void printSolution(int soln[N][N]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<soln[i][j]<<"____";
        }
        cout<<endl;
    }
}

int KnightTourUtil(int x, int y, int movei, int soln[N][N], int x_moves[8], int y_moves[8]) {
    if(movei == N*N)
        return 1;
    for(int i=0;i<N;i++) {
        int x_new = x+x_moves[i];
        int y_new = y+y_moves[i];
        
        if(isSafe(x_new, y_new, soln)) {
            soln[x_new][y_new] = movei;
            if(KnightTourUtil(x_new, y_new, movei+1, soln, x_moves, y_moves) == 1)
                return 1;
            soln[x_new][y_new] = -1;
        }
    }
    return 0;
}

int KnightTour() {
    int soln[N][N];
    //initialize soln
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            soln[i][j] = -1;
        }
    }
    soln[0][0] = 0;
    
    int x_moves[8] = {-2,-2,-1,-1,1,1,2,2};
    int y_moves[8] = {-1,1,-2,2,-2,2,-1,1};
    
    if(KnightTourUtil(0,0,1, soln, x_moves, y_moves) == 1) {
        printSolution(soln);
        return 1;
    } else {
        cout<<"No solution exist!";
    }
}

int main() {
    KnightTour();
    return 0;
}