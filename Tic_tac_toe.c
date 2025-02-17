#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

void initBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void disBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void c_choice() {
    int a, b;
    do {
        a = rand() % 3;
        b = rand() % 3;
    } while(board[a][b] != ' ');
    board[a][b] = 'O';
}

int check_free_space() {
    int a = 9;  
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != ' ') {
                a--;  
            }
        }
    }
    return a;
}

char checkans() {
  
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }


    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    return ' ';  
}

int main() {
    int x, y;
    srand(time(0));  

    initBoard();  
    char winner = ' ';

    do {
        disBoard();

        do {
            printf("Enter the row and column to place X: ");
            scanf("%d %d", &x, &y);
            x--; y--;  
            if(board[x][y] == ' ') {
                board[x][y] = 'X';
                break;
            } else {
                printf("This place is already occupied. Try again.\n");
            }
        } while(board[x][y] != ' ');

        winner = checkans();
        if(winner != ' ') {
            break;
        }  
        if(check_free_space() > 0) {
            c_choice();
            winner = checkans();
        }

    } while(check_free_space() > 0 && winner == ' ');

    disBoard();  

    if(winner == 'X') {
        printf("Congratulations! You have Won \n");
    } else if(winner == 'O') {
        printf("Computer wins \n");
    } else {
        printf("DRAW !\n");
    }

    return 0;
}
