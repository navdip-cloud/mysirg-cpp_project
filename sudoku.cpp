#include<iostream>
using namespace std;
const int N=9;
void print_grid(int grid[N][N])
{
    int i,j; // i's will be rows and j's will be columns
    for(i=0; i<N; i++)
    {
        if(i%3==0)
            cout<<"-------------------------"<<endl;;
        for(j=0; j<N; j++)
        {
            if(j%3==0)
                cout<<"| ";
            cout<<grid[i][j]<<" ";
            if(j==N-1)
                cout<<"|";
        }
        if(i==N-1)
            cout<<endl<<"-------------------------";
        cout<<endl;
    }
}
bool is_safe(int grid[N][N],int row, int col, int num)
{
    for(int j=0; j<N; j++) //checking rows
        if(grid[row][j]==num)
            return false;//break;
    //if(j==N)
        //grid[row][col]=num;
    for(int i=0; i<N; i++) //checking columns
        if(grid[i][col]==num)
            return false;
    
    int start_row=row-row%3; //checking grids (3X3)
    int start_col=col-col%3;
    for(int i=start_row; i<start_row+3; i++)
        for(int j=start_col; j<start_col+3; j++)
            if(grid[i][j]==num)
                return false;
    //grid[row][col]=num;
    return true;
}
bool solve_sudoku(int grid[N][N])
{
    int row, col;
    bool empty_cell=false;
    for(row=0; row<N; row++)
    {
        for(col=0; col<N; col++)
        {
            if(grid[row][col]==0)
            {
                empty_cell=true;
                break;
            }
        }
        if(empty_cell)
            break;
    }
    if(!empty_cell)
        return true;
    
    for(int num=1; num<=N; num++)
    {
        if(is_safe(grid,row,col,num))
        {
            grid[row][col]=num;
            if(solve_sudoku(grid))
                return true;

            grid[row][col]=0;
        }
    }
    return false;
}
int main()
{
    int grid[N][N]={

        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    print_grid(grid);
    cout<<endl;
    if(solve_sudoku(grid))
    {
        cout<<"Sudoku Solved: "<<endl;
        print_grid(grid);
    }
    else
        cout<<"No solution exists"<<endl;
    return 0;
}