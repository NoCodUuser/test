#include <tic_tac_toe.h>
#include <iostream>

int main()
{
    int field[3][3];

    reset_field(field);
    print_field(field);

    int coordinate_x = 0;
    int coordinate_y = 0;

    int current_player = 1;

    while(true)
    {
        std::cout << "player " << current_player << " Enter 2 numbers separated by a space: ";
        std::cin >> coordinate_x >> coordinate_y;
        std::cout << std::endl;

        if(field[coordinate_x][coordinate_y] == 0)
        {
           field[coordinate_x][coordinate_y] = current_player;
        }
        else
        {
            std::cout << "cell is occupied. choose another" << std::endl << std::endl;
            continue;
        }

        print_field(field);

        if(has_someone_won(field))
        {
            std::cout << "player " << current_player << ", you win" << std::endl;
            break;
        }

        switch_player(current_player);

        if(should_break(field))
        {
            break;
        }
    }
    return 0;
}


