// Given the position of a Bishop (A, B) on an 8 * 8 chessboard.

// Your task is to count the total number of squares that can be visited by the Bishop in one move.

// The position of the Bishop is denoted using row and column number of the chessboard.




int Solution::solve(int A, int B) {
    
    int count = 0;
    
    //top left, stop the loop once the bishop hits the edge of the board, it can either hit left side(j) or top(i)
    for(int i = A - 1, j = B - 1; j >= 1 && i >= 1; i--, j--) {
        count++;
    }
    
    //top right, it can either hit right side(j) or top(i)
    for(int i = A - 1, j = B + 1; j <= 8 && i >= 1; i--, j++) {
        count++;
    }
    
    //bottem left, it can either hit left side(j) or bottom(i)
    for(int i = A + 1, j = B - 1; j >= 1 && i <= 8; i++, j--) {
        count++;
    }
    
    //bottom right, it can either hit right side(j) or bottom(i)
    for(int i = A + 1, j = B + 1; j <= 8 && i <= 8; i++, j++) {
        count++;
    }
    
    return count;
}
