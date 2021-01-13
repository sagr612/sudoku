# sudoku
9x9 sudoku solver

Program description :------
    The program accepts a 9x9 matrix as input and prints the result of sudoku.

    The empty space in the matrix are represented by 0's.

    I have used c++ language for this program.
    I have used simple backtracking approach for this program.

    Any one with  g++ complier and a text editor  can run this program.

Approach :---

      I have used a basic backtracking appraoch in this program.

      If  an empty cell is found we try  every number from 1 to 9 in that cell. And If any number does not fit this position then we move to the previous step and try with a              different number. This process continues until there is no zero (i.e. empty space) in the matrix.
