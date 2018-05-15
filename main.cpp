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
    auto tempBoard = gameBoard;

    while(heuristics != 0)
    {

        int tempHeuristics;
        hillClimbing::GameBoard res;

        col = rand()%gameBoard.size();
        row = rand()%gameBoard.size();


        res = hillClimbing::moveQueen(tempBoard, col, row);
        tempHeuristics = hillClimbing::countHeuristics(res);

        if(tempHeuristics < heuristics)
        {
            heuristics = tempHeuristics;
            tempBoard = res;
        }

    }

    hillClimbing::printBoard(tempBoard);
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
        for(auto it : board)
        {
            for(auto inner = 0; inner < board.size(); ++inner)
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
        for(auto it : board)
        {
            for(auto inner : board)
            {
                if((it != inner) && (board[it] == board[inner]))
                {
                    ++retValue;
                }
            }

            for(auto i = it+1; i < board.size(); ++i)
            {
                int comp = 1;

                if((board[it] == (board[i] + comp) || (board[it] == (board[i] - comp))))
                {
                    ++retValue;
                }
                ++comp;
            }

            for(auto i = it - 1; i > 0; --i)
            {
                int comp = 1;

                if ((board[it] == (board[i] + comp) || (board[it] == (board[i] - comp)))) {
                    ++retValue;
                }
                ++comp;
            }
        }
        return retValue;
    }

    GameBoard moveQueen(GameBoard board, int col, int row)
    {
        board[col] = row;
        return board;
    }
}