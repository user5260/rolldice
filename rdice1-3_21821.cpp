///////////////////////////////////
/* Roll Dice 1.3 - Driver 21821 */
/* github.com/user5260/rolldice*/
////////////////////////////////
// version 1.3 adds exception /
// handling.                 /
/////////////////////////////
//
// NOTE: ascii numbers:
//
// (char) 48 - 58
//           =
// (int)   0 - 9
//
// PROJECT CLOSE
// afterthoughts: throw, catch, cerr, etc. was not
// panning out and i realize i had my own
// implementation of exception handling.
// finished rewriting from scratch;
// nearly identical to v1.2 but different,
// more appealing (imo) output format.

#include <iostream>
#include <time.h>

void vRoll (int ch1_9);

int main(int argc, char** argv){
    printf("=====================""\n"\
           "||  Roll Dice 1.3  ||""\n"\
           "=====================""\n");
    printf("press enter to exit.");
    srand(time(NULL));
    bool bRunning = true;
    char chInput = 113;
    while(bRunning){
        printf("-Enter number of dice to roll (1-9) or Q to quit.""\n"\
               "-ENTER: ");
        scanf("%c", &chInput);
        getchar(); // needed to flush the input stream, i think (?)
        if (chInput == 'q' || chInput == 'Q'){
            bRunning = false;
        }
        else if (chInput > 48 & chInput < 59){
            vRoll(((int)chInput - 48));
        }
        else{
            printf("invalid input. retrying...""\n");
        }
    }

    return 0;
}

void vRoll (int nDieNum){
    for (int x = 0; x < nDieNum; x++){
        printf("| %d |", ((rand() % 6) + 1));
        if (x != (nDieNum - 1))
            printf(" - ");
    }
    printf("\n");
}
