#include <iostream>
#include <stdlib.h>
#include <ctime>

void displayBoard(char board[9]) {
    int count = 1;
    for (int i = 1; i <= 11; i ++) {
        for (int k = 1; k <= 17; k++) {
            if (i%2==0) {
                if (i%4==0)
                    std::cout << "#";
                else
                    if (k%6==3) {
                        if (board[count-1] == 'X' || board[count-1] == 'O')
                            std::cout << board[count-1];
                        else
                            std::cout << count;
                        count++;
                    }
                    else if (k%6==0)
                        std::cout << "#";
                    else
                        std::cout << " ";
            }
            else {
                if (k%6==0)
                    std::cout  << "#";
                else
                    std::cout << " ";
                }
            
        } // end k
        std::cout << std::endl;
    } // end i
}

bool checkWinner(char board[9]) {
    // Horizontals
    if (board[0] == board[1] && board[1] == board[2] && board[0] != '0')
        return true;
    if (board[3] == board[4] && board[4] == board[5] && board[3] != '0')
        return true;
    if (board[6] == board[7] && board[7] == board[8] && board[6] != '0')
        return true;

    // Verticals
    if (board[0] == board[3] && board[3] == board[6] && board[0] != '0')
        return true;
    if (board[1] == board[4] && board[4] == board[7] && board[1] != '0')
        return true;
    if (board[2] == board[5] && board[5] == board[8] && board[2] != '0')
        return true;

    // Diagonals
    if (board[0] == board[4] && board[4] == board[8] && board[4] != '0')
        return true;
    if (board[2] == board[4] && board[4] == board[6] && board[4] != '0')
        return true;
    
    //else
    return false;
}

int cpuTurn(char b[9]) {
    if ( ((b[1] == 'X' && b[2] == 'X') || (b[3] == 'X' && b[6] == 'X') || (b[4] == 'X' && b[8] == 'X')) && b[0] == '0' )
        return 0;
    if ( ((b[0] == 'X' && b[2] == 'X') || (b[4] == 'X' && b[7] == 'X')) && b[1] == '0')
        return 1;
    if ( ((b[0] == 'X' && b[1] == 'X') || (b[4] == 'X' && b[6] == 'X') || (b[5] == 'X' && b[8] == 'X')) && b[2] == '0')
        return 2;
    if ( ((b[0] == 'X' && b[6] == 'X') || (b[4] == 'X' && b[5] == 'X')) && b[3] == '0')
        return 3;
    if ( ((b[1] == 'X' && b[7] == 'X') || (b[3] == 'X' && b[5] == 'X') || (b[0] == 'X' && b[8] == 'X') || (b[2] == 'X' && b[6] == 'X')) && b[4] == '0')
        return 4;
    if ( ((b[2] == 'X' && b[8] == 'X') || (b[4] == 'X' && b[3] == 'X')) && b[5] == '0')
        return 5;
    if ( ((b[0] == 'X' && b[3] == 'X') || (b[4] == 'X' && b[2] == 'X') || (b[7] == 'X' && b[8] == 'X')) && b[6] == '0')
        return 6;    
    if ( ((b[6] == 'X' && b[8] == 'X') || (b[4] == 'X' && b[1] == 'X')) && b[7] == '0')
        return 7;
    if ( ((b[5] == 'X' && b[2] == 'X') || (b[7] == 'X' && b[6] == 'X') || (b[4] == 'X' && b[0] == 'X')) && b[8] == '0')
        return 8;
    return rand()%9;
}
    /*

    012
    345
    678

    */
int main() {
    srand(time(0));

    int player = 0;
    int turns = 0;
    char board[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};

    while (true) {
        

        // Player   
        if (player % 2 == 0) {
            // Choose Number
            int num = 0;
            bool first = true;
            while (num < 1 || num > 9 || board[num-1] == 'X' || board[num-1] == 'O') {
                system("cls");
                displayBoard(board);
                if (!first)
                    std::cout << "Invalid selection" << std::endl;
                std::cout << "Choose a number: ";
                std::cin >> num;
                first = false;
            }
            board[num-1] = 'X';
        }
        // CPU turn
        else {
            /*
            // Random CPU choice
            int num = rand()%9;
            while ( board[num] == 'X' || board[num] == 'O') {
                num = rand()%9;
            }
            */

            // Smart CPU Choice
            int num = cpuTurn(board);
            while (board[num] == 'O' || board[num] == 'X') {
                num = cpuTurn(board);
            }

            board[num] = 'O';
        }
        player++;
        turns++;
        
        if (checkWinner(board)) {
            system("cls");
            displayBoard(board);
            char winner;
            if (player%2 == 0)
                winner = 'O'; 
            else
                winner = 'X';
            std::cout << winner << " wins!" << std::endl;
            break;
        }

        if (turns == 9) {
            system("cls");
            displayBoard(board);
            std::cout << "Draw!" << std::endl;
            break;
        }

    }
}



/*       11111111 
12345678901234567
     #     #     1
  1  #  2  #  3  2
12345#     #     3
#################4
     #     #     5
  4  #  5  #  6  6
     #     #     7
#################8
     #     #     9
  7  #  8  #  9  10
     #     #     11
*/

