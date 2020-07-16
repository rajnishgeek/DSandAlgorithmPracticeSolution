#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//it will check is the current cell is safe to go in next cell
//that is current cell is 1
bool isCellSafe(int maze[][5], int n, int i, int j)
{
	if (maze[i][j] == 1 && i >= 0 && i < n && j >= 0 && j < n)
		return true;
	return false;
}

//it is recursion function
bool pathInMazeUtil(int maze[][5], int n, int x, int y, int solution[][5])
{
	//base case
	if (x == n - 1 && y == n - 1)
	{
		solution[x][y] = 1;  //mark the cell 1 that is path possible from this cell
		return true;
	}

	//here check is the given cell safe if safe
	//then call function to move down and right
	if (isCellSafe(maze, n, x, y))
	{
		solution[x][y] = 1; //this 2D array will store the possible path

		//check for down celll
		if (pathInMazeUtil(maze, n, x + 1, y, solution))
			return true;

        //check for right cell
		if (pathInMazeUtil(maze, n, x, y + 1, solution))
			return true;

        //this is important command. it is backtracking case
        //mark 0 that is path not possible from this cell
		solution[x][y] = 0;
		return false;
	}
	return false;
}
void printPath(int solution[][5], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << solution[i][j] << " ";
		cout << endl;
	}
}
bool pathInMaze(int maze[][5], int n, int x, int y)
{
	int solution[5][5] = {0};
	if (!pathInMazeUtil(maze, n, x, y, solution))
		return false;
	printPath(solution,n);
	return true;
}
int main()
{
	int maze[5][5] = {{1, 1, 1, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}};
	int n = 5;
	pathInMaze(maze, n, 0, 0) ? cout << "path possible" << endl : cout << "path not possible" << endl;

	return 0;
}
