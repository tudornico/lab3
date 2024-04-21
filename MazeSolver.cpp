//
// Created by tudor on 21/04/2024.
//

#include <iostream>
#include "MazeSolver.h"
/**
 * our matrix will have 0 for empty spaces and 1 for walls
 */

/**
 * pre: maze , nrLines , nrCols , startLine , startCol
 * post : visited array
 function MazeSolver(maze, nrLines, nrCols, startLine, startCol):
    // Initialize arrays to keep track of visited cells and distances
    visited[nrLines][nrCols] = false
    distance[nrLines][nrCols] = 0

    // Create a queue for BFS
    queue = empty queue
    queue.push((startLine, startCol))
    visited[startLine][startCol] = true

    // Perform BFS
    while queue is not empty:
        x, y = queue.pop()

        // Check four directions: up, down, left, right
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nx = x + dx
            ny = y + dy

            // Check if the next cell is within bounds and not a wall
            if nx >= 0 and nx < nrLines and ny >= 0 and ny < nrCols and maze[nx][ny] == 0 and not visited[nx][ny]:
                visited[nx][ny] = true
                distance[nx][ny] = distance[x][y] + 1
                queue.push((nx, ny))

    // Output the shortest path from the start point to all other cells
    for i from 0 to nrLines:
        for j from 0 to nrCols:
            if visited[i][j]:
                print distance[i][j], " "
            else:
                print "INF ",
        print newline
 */
MazeSolver::MazeSolver() {
    this->queue = new  Queue();
    this->path = new Queue();
}

void MazeSolver::solve(int (*maze)[100], int nrLines, int nrCols, int startLine, int startCol) {
    // Arrays to keep track of visited cells and parent cell for each cell
    bool visited[maxSize][maxSize] = {false};
    pair<int, int> parent[maxSize][maxSize];



    // Add starting point to the queue
    this->queue->push({startLine, startCol});
    visited[startLine][startCol] = true;
    parent[startLine][startCol] = {-1, -1}; // No parent for starting point

    // Possible moves: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Perform BFS
    while (!this->queue->isEmpty()) {
        pair<int, int> current = this->queue->top();
        this->queue->pop();

        // Check if current point is on the boundary
        if (current.first == 0 || current.first == nrLines - 1 || current.second == 0 || current.second == nrCols - 1) {
            cout << "Shortest path found!" << endl;
            // Reconstruct and print path
            while (parent[current.first][current.second].first != -1 && parent[current.first][current.second].second != -1) {
                cout << "(" << current.first << ", " << current.second << ") <- ";
                current = parent[current.first][current.second];
            }
            cout << "(" << startLine << ", " << startCol << ")" << endl;
            return;
        }

        // Try all possible moves
        for (int i = 0; i < 4; ++i) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (isValid(nx, ny, nrLines, nrCols) && maze[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx][ny] = current;
                this->queue->push({nx, ny});
            }
        }
    }


    // If no path is found
    cout << "No path found!" << endl;
}

bool MazeSolver::isValid(int x, int y, int nrLines, int nrCols) {
    return (x >= 0 && x < nrLines && y >= 0 && y < nrCols);
}
