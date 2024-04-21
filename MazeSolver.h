
#include "Queue.h"
#pragma once
class MazeSolver {

private:
    Queue *queue;
    static const int maxSize = 100;
    Queue *path;
public:

    MazeSolver();

    bool isValid(int x, int y, int nrLines, int nrCols);

    void solve(int maze[maxSize][maxSize] , int nrLines , int nrCols , int startLine , int startCol);
};



