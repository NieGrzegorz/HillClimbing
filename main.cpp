#include <iostream>
#include <vector>
#include <time.h>

namespace hillClimbing
{
    typedef  std::vector<int> GameBoard;
    int countHeuristics(GameBoard board);
    GameBoard resetChessBoard(int boardSize = 8);
    void printBoard(GameBoard board);
    GameBoard moveQueen(GameBoard board, int col, int row);
}

int main()
{
    int col, row;
    srand(time(NULL));

    auto gameBoard = hillClimbing::resetChessBoard(8);
    int heuristics = hillClimbing::countHeuristics(gameBoard);
    int resetCounter = 0;
    while(heuristics != 0)
    {

        int tempHeuristics;
        hillClimbing::GameBoard tempBoard;

        col = rand()%gameBoard.size();
        row = rand()%gameBoard.size();


        tempBoard = hillClimbing::moveQueen(gameBoard, col, row);
        tempHeuristics = hillClimbing::countHeuristics(tempBoard);

        if(tempHeuristics < heuristics)
        {
            heuristics = tempHeuristics;
            gameBoard = tempBoard;
            resetCounter = 0;
        }

        if(resetCounter > 50)
        {
            gameBoard = hillClimbing::resetChessBoard(8);
            heuristics = hillClimbing::countHeuristics(gameBoard);
        }
        ++resetCounter;
    }

    hillClimbing::printBoard(gameBoard);
    std::cout<<"Heuristics: "<<heuristics;

    return 0;
}

namespace hillClimbing
{

    GameBoard resetChessBoard(int boardSize)
    {
        GameBoard board;
        for(int col = 0; col < boardSize; ++col)
        {
            int row = rand()%boardSize;
            board.push_back(row);
        }
        return board;
    }

    void printBoard(GameBoard board)
    {
        for(int it = 0; it < board.size(); ++it)
        {
            for(int inner = 0; inner < board.size(); ++inner)
            {
                if(board[it] == inner)
                {
                    std::cout<<"Q";
                }
                else
                {
                    std::cout<<"*";
                }
            }
            std::cout<<"\n";
        }
    }

    int countHeuristics(GameBoard board)
    {
        int retValue = 0;
        for(int it = 0; it < board.size(); ++it)
        {
            for(int inner = 0; inner < board.size(); ++inner)
            {
                if((it != inner) && (board[it] == board[inner]))
                {
                    ++retValue;
                }
            }

            int comp1 = 1;
            for(int i = it+1; i < board.size(); ++i)
            {

                if((board[i] == (board[it] + comp1)) || (board[i] == (board[it] - comp1)))
                {
                    ++retValue;
                }
                ++comp1;
            }

            int comp2 = 1;
            for(int i = it - 1; i >= 0; --i)
            {

                if ((board[i] == (board[it] + comp2)) || (board[i] == (board[it] - comp2))) {
                    ++retValue;
                }
                ++comp2;
            }
        }
        return retValue;
    }

    GameBoard moveQueen(GameBoard board, int col, int row)
    {
        board[row] = col;
        return board;
    }
}