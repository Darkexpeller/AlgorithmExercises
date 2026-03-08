// 输入：grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// 输出：1
// 示例 2：

// 输入：grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// 输出：3



#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>

using namespace std;


struct VEX
{
    int x = 0;
    int y = 0;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        printf("begin\n");
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }

    void DFS(vector<vector<char>>& grid, int row, int col)
    {

        grid[row][col] = '0';
        for (VEX v = FirstAdiVex(grid, row, col); v.x >= 0; v = FirstAdiVex(grid, row, col))
        {
            printf("begin %d,%d\n", row, col);
            DFS(grid, v.x, v.y);
        }
    }
    VEX FirstAdiVex(vector<vector<char>>& grid, int row, int col)
    {
        VEX vex;
        vex.x = -1;
        //东
        if (grid[row].size() > (col + 1))
        {
            if (grid[row][col + 1] == '1')
            {
                vex.x = row;
                vex.y = col + 1;

                return vex;
            }

        }
        //南
        if (grid.size() > (row + 1))
        {
            if (grid[row + 1][col] == '1')
            {
                vex.x = row + 1;
                vex.y = col;
                return vex;
            }

        }
        //西
        if (col > 0)
        {
            if (grid[row][col - 1] == '1')
            {
                vex.x = row;
                vex.y = col - 1;
                return vex;
            }

        }
        //北
        if (row > 0)
        {
            if (grid[row - 1][col]=='1')
            {
                vex.x = row - 1;
                vex.y = col;
                return vex;
            }

        }
        return vex;
    }

    int count = 0;
};
//求极大连通子图个数

int main()
{
    vector<vector<char>> grid;
    int row, col = 0;
    scanf("%d%d", &row, &col);
    grid.resize(row);
    char in = 0;
    for (int i = 0; i < row; i++)
    {
        grid[i].resize(col);
        for (int j = 0; j < col; j++)
        {
            scanf("%s", &in);
            grid[i][j] = in;
        }

    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c", grid[i][j]);
        }

    }
    Solution so;
    printf("\n%d", so.numIslands(grid));
}