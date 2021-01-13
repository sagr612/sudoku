// A 9*9 sudoku solver
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
ifstream infile; 
ofstream outfile;
vector<vector<int>> grid;

int c=0;
void zero_count()
{
    c=0;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(grid[i][j]==0) {
                c++;
            }
        }
    }
}

// input data
void input() {
    for (int i = 0; i < 9; i++) {
        vector<int> temp;
        for (int j = 0; j < 9; j++) { 
            int val;
            infile>>val;
            temp.push_back(val);
        }    
        grid.push_back(temp);
        temp.clear();
    }
}
// display data
void display() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            outfile << grid[i][j] <<" ";
        }    
        outfile << endl;
    }
}
// checks if the no. is present in the row and col or not and if present returns false
bool check_row_col(int key, int row, int col) {
    for(int i=0; i<9; i++) {
        if(row!=i and key==grid[i][col]) { return false; }
        if(col!=i and key==grid[row][i]) { return false; }
    }
    return true;
}
// checks if the no. is present in the 3*3 sub matrix  or not and if present returns false
bool check_matrix(int key, int row, int col) {
    int lr,lc,ur,uc;
    if(row>=0 and row<=2) { lr=0; ur=2; }
    else if(row>=3 and row<=5) { lr=3; ur=5; }
    else { lr=6; ur=8; }
    
    if(col>=0 and col<=2) { lc=0; uc=2; }
    else if(col>=3 and col<=5) { lc=3; uc=5; }
    else { lc=6; uc=8; }
    
    for(int i=lr; i<=ur; i++) {
        for(int j=lc; j<=uc; j++) {
            if( i!=row and j!=col){
                if(key==grid[i][j]) { 
                    return false; 
                }
            } 
        }
    }
    return true;
}
// checks for the validity of the input by using check_matrix and check_row_col functions
bool check() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(grid[i][j]!=0 and !check_matrix(grid[i][j],i,j) and !check_row_col(grid[i][j],i,j) ) {
                return false;
            }
        }
    }
    return true;
}
// checks if a cell is safe or not
bool isSafe(int key,int row, int col ) {
    if(check_matrix(key, row, col) and check_row_col(key,row,col)){ return true;}
    return false;
}
// contains our main logic
void sudoku() {
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(grid[i][j]==0)
            {
                    for(int ct=1; ct<=9; ct++) {
                        if( isSafe(ct,i,j)) {
                            grid[i][j]=ct;
                            sudoku();
                            grid[i][j]=0;
                        }
                    }
                if(grid[i][j]==0)
                    {
                        return ;
                    }
            }    
        }
    }
    zero_count();
    
    if(c==0) {
        display();
        return ;
    }
}

int main() {
    infile.open("input.txt",ios::in); 
    outfile.open("output.txt",ios::out);
    input();
    
    if(!check()) {
        outfile << "Invalid Input"<<endl;
    }
    else{
        sudoku();
    }
    outfile.close();
    infile.close();
    return 0;
}
