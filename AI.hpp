
// File for all the AI decision functions

bool checkPriority12(int winner, int x, int y, int mainBoard[], int SIZE) { // returns true if priority is 1 or 2, false if not

    // copy main board over, so we can change it without changing the main board
    int board[SIZE][SIZE][SIZE];
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            for (int k=0; k<SIZE; k++) {
                board[i][j][k] = mainBoard[i+SIZE*(j+SIZE*k)];
            }
        }
    }

    // set z and place move on the board
    int z = 0;
    for (int i = SIZE-1; i>0; i--) {
        if (board[x][y][i] == 0) {z = i; break;}
    }
    board[x][y][z] = winner;

    int in_a_row = 0;
    // check win in x direction
    for (int i = 0; i < SIZE; i++) {
        if (board[i][y][z] == winner)
            ++in_a_row;
    }
    if (in_a_row == SIZE) return true;
    // check win in y direction
    in_a_row = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[x][i][z] == winner)
            ++in_a_row;
    }
    if (in_a_row == SIZE) return true;
    in_a_row = 0;
    // check win in z direction
    for (int i = 0; i < SIZE; i++) {
        if (board[x][y][i] == winner)
            ++in_a_row;
    }
    if (in_a_row == SIZE) return true;
    in_a_row = 0;
    // check win in xy diagonals if spot is on that diagonal
    if (x == y) { // if on first diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][i][z] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
        in_a_row = 0;
    }
    if (x + y == SIZE-1) { // if on the second diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][SIZE-1-i][z] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
        in_a_row = 0;
    }
    // check win in xz diagonals if spot is on that diagonal
    if (x == z) { // if on first diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][y][i] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
        in_a_row = 0;
    }
    if (x + z == SIZE-1) { // if on the second diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][y][SIZE-1-i] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
        in_a_row = 0;
    }
    // check win in yz diagonals if spot is on that diagonal
    if (y == z) { // if on first diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[x][i][i] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
        in_a_row = 0;
    }
    if (y + z == SIZE-1) { // if on the second diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[x][SIZE-1-i][i] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
        in_a_row = 0;
    }
    // check win in the 4 xyz diagonals, if on those diagonals
    if (x == y && x == z) { // if on the (0,0,0) to (2,2,2) diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][i][i] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
        in_a_row = 0;
    }
    if (x + y == SIZE-1 && y == z) { // if on the (2,0,0) to (0,2,2) diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[SIZE-1-i][i][i] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
        in_a_row = 0;
    }
    if (x + y == SIZE-1 && x == z) { // if on the (0,2,0) to (2,0,2) diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][SIZE-1-i][i] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
        in_a_row = 0;
    }
    if (x + z == SIZE-1 && x == y) { // if on the (0,0,2) to (2,2,0) diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][i][SIZE-1-i] == winner)
                ++in_a_row;
        }
        if (in_a_row == SIZE) return true;
    }
    return false;
}

int checkPriority34(int x, int y, int mainBoard[], int SIZE) { // returns number of set-ups for future wins a play makes, 0-2

    // copy main board over, so we can change it without changing the main board
    int board[SIZE][SIZE][SIZE];
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            for (int k=0; k<SIZE; k++) {
                board[i][j][k] = mainBoard[i+SIZE*(j+SIZE*k)];
            }
        }
    }

    // set z and place move on the board
    int z = 0;
    for (int i = SIZE-1; i>0; i--) {
        if (board[x][y][i] == 0) {z = i; break;}
    }
    board[x][y][z] = 2;

    int in_a_row = 0;
    int emptySpot = 0;
    int set_ups = 0;
    // check set-up in x direction
    for (int i = 0; i < SIZE; i++) {
        if (board[i][y][z] == 2)
            ++in_a_row;
        else if (board[i][y][z] == 0)
            ++emptySpot;
    }
    if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
    // check set-up in y direction
    in_a_row = emptySpot = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[x][i][z] == 2)
            ++in_a_row;
        else if (board[x][i][z] == 0)
            ++emptySpot;
    }
    if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
    in_a_row = emptySpot = 0;
    // check set-up in z direction
    for (int i = 0; i < SIZE; i++) {
        if (board[x][y][i] == 2)
            ++in_a_row;
        else if (board[x][y][i] == 0)
            ++emptySpot;
    }
    if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
    in_a_row = emptySpot = 0;
    // check set-up in xy diagonals if spot is on that diagonal
    if (x == y) { // if on first diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][i][z] == 2)
                ++in_a_row;
            else if (board[i][i][z] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
        in_a_row = emptySpot = 0;
    }
    if (x + y == SIZE-1) { // if on the second diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][SIZE-1-i][z] == 2)
                ++in_a_row;
            else if (board[i][SIZE-1-i][z] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
        in_a_row = emptySpot = 0;
    }
    // check set-up in xz diagonals if spot is on that diagonal
    if (x == z) { // if on first diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][y][i] == 2)
                ++in_a_row;
            else if (board[i][y][i] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
        in_a_row = emptySpot = 0;
    }
    if (x + z == SIZE-1) { // if on the second diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][y][SIZE-1-i] == 2)
                ++in_a_row;
            else if (board[i][y][SIZE-1-i] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
        in_a_row = emptySpot = 0;
    }
    // check set-up in yz diagonals if spot is on that diagonal
    if (y == z) { // if on first diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[x][i][i] == 2)
                ++in_a_row;
            else if (board[x][i][i] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
        in_a_row = emptySpot = 0;
    }
    if (y + z == SIZE-1) { // if on the second diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[x][SIZE-1-i][i] == 2)
                ++in_a_row;
            else if (board[x][SIZE-1-i][i] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
        in_a_row = emptySpot = 0;
    }
    // check set-up in the 4 xyz diagonals, if on those diagonals
    if (x == y && x == z) { // if on the (0,0,0) to (2,2,2) diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][i][i] == 2)
                ++in_a_row;
            else if (board[i][i][i] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
        in_a_row = emptySpot = 0;
    }
    if (x + y == SIZE-1 && y == z) { // if on the (2,0,0) to (0,2,2) diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[SIZE-1-i][i][i] == 2)
                ++in_a_row;
            else if (board[SIZE-1-i][i][i] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE && emptySpot == 1) ++set_ups;
        in_a_row = emptySpot = 0;
    }
    if (x + y == SIZE-1 && x == z) { // if on the (0,2,0) to (2,0,2) diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][SIZE-1-i][i] == 2)
                ++in_a_row;
            else if (board[i][SIZE-1-i][i] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
        in_a_row = emptySpot = 0;
    }
    if (x + z == SIZE-1 && x == y) { // if on the (0,0,2) to (2,2,0) diagonal
        for (int i = 0; i < SIZE; i++) {
            if (board[i][i][SIZE-1-i] == 2)
                ++in_a_row;
            else if (board[i][i][SIZE-1-i] == 0)
                ++emptySpot;
        }
        if (in_a_row == SIZE-1 && emptySpot == 1) ++set_ups;
    }
    return set_ups;
}

int getPriority(int x, int y, int mainBoard[], int SIZE) {
    if (mainBoard[x+SIZE*y] != 0) return 6; // can't play in this spot
    if (checkPriority12(2, x, y, mainBoard, SIZE)) return 1;
    if (checkPriority12(1, x, y, mainBoard, SIZE)) return 2;
    int n = checkPriority34(x, y, mainBoard, SIZE);
    if (n > 1) return 3;
    if (n == 1) return 4;
    return 5;
}
