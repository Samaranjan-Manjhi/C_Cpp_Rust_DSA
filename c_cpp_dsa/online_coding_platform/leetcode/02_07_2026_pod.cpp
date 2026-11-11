/*

3286. Find a Safe Walk Through a Grid

You are given an m x n binary matrix grid and an integer health.
You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

Example 1:
Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
Output: true
Explanation:
The final cell can be reached safely by walking along the gray cells below.

Example 2:
Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3
Output: false
Explanation:
A minimum of 4 health points is needed to reach the final cell safely.

Example 3:
Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5
Output: true
Explanation:
The final cell can be reached safely by walking along the gray cells below.
Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    2 <= m * n
    1 <= health <= m + n
    grid[i][j] is either 0 or 1.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct state 
{
     int x;
     int y;
     int health;
};

bool findSafeWalk(vector<vector<int>>& grid, int health) 
{
     int m = grid.size();
     int n = grid[0].size();

     if(grid[0][0] == 1)
          health = health - 1;

     if(health < 1)
          return false;

     queue<state> q;
     q.push({0, 0, health});

     vector<vector<int>> bestHealth(m, vector<int> (n, -1));
     bestHealth[0][0] = health;

     vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

     while(!q.empty())
     {
          state curr = q.front();
          q.pop();

          if(curr.x == m-1 && curr.y == n-1 && curr.health >= 1)
               return true;

          for(int i=0;i<4;i++)
          {
               int nx = curr.x + directions[i][0];
               int ny = curr.y + directions[i][1];

               if((nx < 0 || nx >= m) || (ny < 0 || ny >= n))
                    continue;

               int newHealth = curr.health;

               if(grid[nx][ny] == 1)
                    newHealth--;

               if(newHealth < 1)
                    continue;

               if(newHealth <= bestHealth[nx][ny])
                    continue;

               bestHealth[nx][ny] = newHealth;
               q.push({nx, ny, newHealth});
          }
     }
     return false;
}

int main()
{
     int m, n;
     cout << "Enter Matrix Size(m*n): ";
     cin >> m >> n;

     vector<vector<int>> vec(m, vector<int> (n));
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
               cin >> vec[i][j];
          }
     }

     int h;
     cout << "Enter Health Value: ";
     cin >> n;

     bool res = findSafeWalk(vec, h);
     if(res)
          cout << "   Yes\n";
     else
          cout << "   Nope\n";

     return 0;
}
