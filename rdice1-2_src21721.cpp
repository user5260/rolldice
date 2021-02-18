///////////////////////////////////
/* Roll Dice 1.2                 */
/* Driver 21721                  */
/* created 2-17-2021             */
/* contact: brianc2788@gmail.com */
///////////////////////////////////
// -make sure to sanitize input (did i use that term right?)
// -switching input var to char and manually
//  convert to int of correct value.
//
// summary: works almost perfectly,
// user can't cause errors through
// input, though entering strings
// is still probably somewhat
// 'undefined behavior'. however,
// program always returns 0 at exit.
#include <iostream>
#include <time.h>

// user inputs char, but main only passes
// to this function when char is '0' - '9'.
void vRoll (int nDice);

int main(int argc, char** arg){ // trying char** instead of char x[].
    // title
    printf("=====================\n"\
           "||  Roll Dice 1.2  ||\n"\
           "=====================\n");
    // srand() seeds rand() to local time (seconds since jan 1970).
    srand(time(NULL));
    bool bRunning = 1;
    char chInput = ' ';
    // program loop not necessary; leaning purposes.
    while(bRunning){
        // print instructions and prompt user for input.
        printf("-Enter number of dice (up to 9) or q/Q to quit-\n"\
               "ENTER: ");
        scanf("%c", &chInput);
        // got input, time to do stuff.
        // if 'q' or 'Q', exit program.
        if (chInput == 'q' || chInput == 'Q'){ // ascii values: q-113, Q-???
            bRunning = 0;
        }
        // if char value is greater than 48:
        // (because ascii: 048-058 is '0'-'9' ?)
        else if((int)chInput > 48 & (int)chInput < 59){
            vRoll(((int)chInput - 48));
        }
        // if user enters anything other than 049-058, 113, or 'Q':
        else{
            printf("Invalid input, try again.\n");
        }
        // loop returns to beginning to check bRunning.
        // stays 1 unless user inputs chars '1' - '9'.

        // need getchar to flush the input buffer (?).
        // '\n' seems to get stuck and entered in after each loop.
        getchar();
    }

    return 0;
}

void vRoll (int nDice){
    for (int x = 0; x < nDice; x++){
        // rand number 0-5 and add 1 for 1-6.
        printf("Rolled a | %d |\n", ((rand() % 6) + 1));
    }
}
