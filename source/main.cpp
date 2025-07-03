#include <tic_tac_toe.h>
#include <iostream>

int main()
{
    int field[3][3];

    reset_field(field);

    int coordinate_x = 0;
    int coordinate_y = 0;

    int current_player = 1;

    while(true)
    {
        std::cout << "player " << current_player << " Enter 2 numbers separated by a space: ";
        std::cin >> coordinate_x >> coordinate_y;

        field[coordinate_x][coordinate_y] = current_player;

        print_field(field);

        switch_player(current_player);
    }

    return 0;
}


