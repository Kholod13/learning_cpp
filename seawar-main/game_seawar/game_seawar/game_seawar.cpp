#include <iostream>
#include "linksOnFuncs.h"

using namespace std;

int main()
{   
    const int SIZE = 10;

    char shootingRange1[SIZE][SIZE]{};
    char shootingRange2[SIZE][SIZE]{};

    int valueVarGame = 0;
    for (; valueVarGame < 1 || valueVarGame > 2;) {

        cout << "\n\nGame modes:\n|1 - You VS Bot|\n|2 - Bot VS Bot|\n\n";
        cout << "Input variant >> ";
        cin >> valueVarGame;

        switch (valueVarGame) {
        case 1: {
            //Palyer vs bot
            int valueArrangement = 0;

            char fieldPlayer[SIZE][SIZE]{};
            char fieldBot[SIZE][SIZE]{};
            emptyFillField(fieldPlayer, SIZE);
            emptyFillField(fieldBot, SIZE);

            for (; valueArrangement < 1 || valueArrangement > 2;) {

                cout << "\nArrangement variants:\n|1 - Manual|\n|2 - Auto|\n\n";
                cout << "Input variant >> ";
                cin >> valueArrangement;

                switch (valueArrangement) {
                case 1: {

                    arrangementManual(fieldPlayer, SIZE);
                    arrangementAuto(fieldBot, SIZE);

                    int computerGameModes = 0;

                    for (; computerGameModes < 1 || computerGameModes > 2;) {

                        cout << "\nComputer shot game modes:\n|1 - Random|\n|2 - Stratagy|\n\n";
                        cout << "Input variant >> ";
                        cin >> computerGameModes;

                        switch (computerGameModes) {
                            case 1: {

                                gamePBRandomShot(SIZE, shootingRange1, shootingRange2, fieldPlayer, fieldBot);

                                return false;
                            }
                            case 2: {



                                return false;
                            }
                        }

                    }

                    return false;
                }
                case 2: {
                    // auto

                    arrangementAuto(fieldPlayer, SIZE);
                    arrangementAuto(fieldBot, SIZE);

                    int computerGameModes = 0;

                    for (; computerGameModes < 1 || computerGameModes > 2;) {

                        cout << "\nComputer shot game modes:\n|1 - Random|\n|2 - Stratagy|\n\n";
                        cout << "Input variant >> ";
                        cin >> computerGameModes;

                        switch (computerGameModes) {
                        case 1: {

                            gamePBRandomShot(SIZE, shootingRange1, shootingRange2, fieldPlayer, fieldBot);

                            return false;
                        }
                        case 2: {

                            

                            return false;
                        }
                        }

                    }
                    
                    return false;
                }
                };
            };

            return false;
        }
        case 2: {
            //bot vs bot
            int valueArrangement = 0;

            char fieldPlayer[SIZE][SIZE]{};
            char fieldBot[SIZE][SIZE]{};
            emptyFillField(fieldPlayer, SIZE);
            emptyFillField(fieldBot, SIZE);

            for (; valueArrangement < 1 || valueArrangement > 2;) {

                cout << "\nArrangement variants:\n|1 - Manual|\n|2 - Auto|\n\n";
                cout << "Input variant >> ";
                cin >> valueArrangement;

                switch (valueArrangement) {
                case 1: {

                    cout << "\n|Fill field for player 1|\n";
                    arrangementManual(fieldPlayer, SIZE);
                    cout << "\n|Fill field for player 2|\n";
                    arrangementManual(fieldBot, SIZE);

                    int computerGameModes = 0;

                    for (; computerGameModes < 1 || computerGameModes > 2;) {

                        cout << "\nComputer shot game modes:\n|1 - Random|\n|2 - Stratagy|\n\n";
                        cout << "Input variant >> ";
                        cin >> computerGameModes;

                        switch (computerGameModes) {
                        case 1: {

                            gameBBRandomShot(SIZE, shootingRange1, shootingRange2, fieldPlayer, fieldBot);

                            return false;
                        }
                        case 2: {



                            return false;
                        }
                        }

                    }

                    return false;
                }
                case 2: {
                    // auto

                    arrangementAuto(fieldPlayer, SIZE);
                    arrangementAuto(fieldBot, SIZE);

                    int computerGameModes = 0;

                    for (; computerGameModes < 1 || computerGameModes > 2;) {

                        cout << "\nComputer shot game modes:\n|1 - Random|\n|2 - Stratagy|\n\n";
                        cout << "Input variant >> ";
                        cin >> computerGameModes;

                        switch (computerGameModes) {
                        case 1: {

                            gameBBRandomShot(SIZE, shootingRange1, shootingRange2, fieldPlayer, fieldBot);

                            return false;
                        }
                        case 2: {



                            return false;
                        }
                        }

                    }

                    return false;
                }
                };
            };

            return false;
        }
        }
    }

}
