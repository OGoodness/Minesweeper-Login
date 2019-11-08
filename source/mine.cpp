#include <signal.h>
#include "field.hpp"
#include "buffer.hpp"
#include "setup.hpp"
#include "colour.hpp"
#include "display.hpp"



int main()
{
    system("clear");
    signal(SIGINT, catch_int);
    signal(SIGTSTP, catch_int);
    setGameMode();
    getQuickClearSettings();
    int timer = 0;
    Field field;

    while (timer < 1600)
    {
        system("clear");

        dispBanner();
        field.drawField();
        dispFlagCounter();
        
        if (gameState != RUNNING)
            dispVictoryOrDefeat();
        else
            dispControls();

        writeBuf.disp();
        writeBuf.clear();

        if (gameState == RUNNING)
            field.getMove();
        else
            break;
	sleep(0.1);
	timer++;
    }


    std::cout << endl
              << reset;

    return 0;
}
