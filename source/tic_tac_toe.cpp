#include <tic_tac_toe.h>
#include <iostream>

int main()
{
    int field[3][3];

    char letter = 0; // буква, в дальнейшем используется для выбора ячейки
    int number = 0; // число, в дальнейшем используется для выбора ячейки

    int current_player = 1;
    while(true)
    {
        int input = 0;

        std::cout << "Enter your number: ";
        std::cin >> input;
        std::cout << "player " << current_player << " Enter number: " << input << std::endl;

        if(current_player == 1)
        {
            current_player = 2;
        }
        else
        {
            current_player = 1;
        }
    }

    return 0;
}


