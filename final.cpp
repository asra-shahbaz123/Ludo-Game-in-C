#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void setConsoleTextAttribute(HANDLE h, int color) {
    SetConsoleTextAttribute(h, color);
}
void MENU(char arr[], char left[], char up[], char down[], char right[]);
void SELECTION(char arr[], char left[], char up[], char down[], char right[]);
void BOARD(char arr[], char left[], char up[], char down[], char right[]);
void TWOPLAyers(char arr[], char left[], char up[], char down[], char right[]);
void FOURPLAyers(char arr[], char left[], char up[], char down[], char right[]);
void p1turn(char arr[], char left[]);
void p2turn(char arr[], char up[]);
void p3turn(char arr[], char down[]);
void p4turn(char arr[], char right[]);
void MENU(char arr[], char left[], char up[], char down[], char right[]);
struct Player {
    char name[50];
    char token;
    int score;
};

    int counter = 0;
int option; // to select the menu
int c1 = 0;
int c2 = 0;

int c3 = 0;
int c4 = 0;
int i = 1;  // subscript for player1
int j = 14; // subscript for player2
int k = 40; // subscript for player3
int l = 27; // subscript for player4
char t1, t2, t3, t4;
char p1[100];
char p2[100];
char p3[100];
char p4[100];
int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0; // count marks for eachplayer
int dice = 0;
int members;
char g11, g12, g13, g14;
char r11, r12, r13, r14; // each tokens
char b11, b12, b13, b14;
char y11, y12, y13, y14;

int main ()
{
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    Sleep(2000);  // Pause for 2 seconds
    setConsoleTextAttribute(h, 9);  // Set text color to blue
    printf("\n\n\n\t\aL");
    Sleep(300);  // Pause for 300 milliseconds
    setConsoleTextAttribute(h, 12);  // Set text color to red
    Sleep(300);
    printf("\aU");
    setConsoleTextAttribute(h, 10);  // Set text color to green
    Sleep(300);
    printf("\aD");
    setConsoleTextAttribute(h, 14);  // Set text color to yellow
    Sleep(300);
    printf("\aO");
    Sleep(300);
    setConsoleTextAttribute(h, 9);  // Set text color to blue
    Sleep(300);
    printf("\t\aG");
    setConsoleTextAttribute(h, 12);  // Set text color to red
    Sleep(300);
    printf("\aA");
    setConsoleTextAttribute(h, 10);  // Set text color to green
    Sleep(300);
    printf("\aM");
    setConsoleTextAttribute(h, 14);  // Set text color to yellow
    Sleep(300);
    printf("\aE\n");
    setConsoleTextAttribute(h, 7);  // Reset text color to default
    Sleep(2000);  // Pause for 2 seconds

    printf("\n\tLOADING\n\t\t");
    setConsoleTextAttribute(h, 6);  // Set text color to red
    for (int s = 1; s <= 40; s++) {
        Sleep(28);  // Pause for 28 milliseconds
        printf(".");
    }
    printf("\n\t\t");
   char arr[60];
    char left[25];
    char up[10];
    char down[10];
    char right[25];
    left[6] = ' ';
    up[6] = ' ';
    down[6] = ' ';
    right[6] = ' ';
    arr[11] = ' ';
    arr[12] = ' ';
    arr[13] = ' ';
    arr[10] = ' ';
    up[1] = '/';
    arr[14] = '/';
    arr[9] = '/';
    up[2] = '/';
    arr[15] = ' ';
    arr[8] = ' ';
    up[3] = '/';
    arr[16] = ' ';
    arr[7] = ' ';
    up[4] = '/';
    arr[17] = ' ';
    arr[6] = ' ';
    up[5] = '/';
    arr[18] = ' ';
    arr[0] = ' ';
    arr[1] = '/';
    arr[2] = ' ';
    arr[3] = ' ';
    arr[4] = ' ';
    arr[5] = ' ';
    arr[19] = ' ';
    arr[20] = ' ';
    arr[21] = ' ';
    arr[22] = '/';
    arr[23] = ' ';
    arr[24] = ' ';
    arr[51] = ' ';
    left[1] = '/';
    left[2] = '/';
    left[3] = '/';
    left[4] = '/';
    left[5] = '/';
    right[5] = '/';
    right[4] = '/';
    right[3] = '/';
    right[2] = '/';
    right[1] = '/';
    arr[25] = ' ';
    arr[50] = ' ';
    arr[49] = ' ';
    arr[48] = '/';
    arr[47] = ' ';
    arr[46] = ' ';
    arr[45] = ' ';
    arr[31] = ' ';
    arr[30] = ' ';
    arr[29] = ' ';
    arr[28] = ' ';
    arr[27] = '/';
    arr[26] = ' ';
    arr[44] = ' ';
    down[5] = '/';
    arr[32] = ' ';
    arr[43] = ' ';
    down[4] = '/';
    arr[33] = ' ';
    arr[42] = ' ';
    down[3] = '/';
    arr[34] = ' ';
    arr[41] = ' ';
    down[2] = ' ';
    arr[35] = '/';
    arr[40] = '/';
    down[1] = '/';
    arr[36] = ' ';
    arr[39] = ' ';
    arr[38] = ' ';
    arr[37] = ' ';

    MENU(arr, left, up, down, right);
    return 0;
}


void MENU(char arr[], char left[], char up[], char down[], char right[])
{

 printf("\n\n\t1. PLAY GAME");
    printf("\n\t2. HOW TO PLAY");
    printf("\n\t3. HIGH SCORES");
    printf("\n\t4. EXIT");

   int option;

    printf("\n\n\tSELECT THE MENU : ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            SELECTION(arr, left, up, down, right);
            break;
        case 2:
            printf("\n\tHOW TO PLAY GAME\n");
            printf("\n\tOn each player's turn, the player rolls the die to determine a move.\n");
            printf("The goal of the game is to move all four of the player's pieces clockwise once \naround the board,");
            printf("up the home column, and into the home triangle.\n");
            printf("To begin, a player must roll a six to move a piece out of the base and \nonto the start position.");
            break;
        case 3:
            printf("\n\tHIGH SCORES : PROCESSING...");
            break;
        case 4:
            break;
        default:
            printf("\n\tWRONG INPUT!....");
            break;
    }

}
void SELECTION(char arr[], char left[], char up[], char down[], char right[])
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setConsoleTextAttribute(h, 9);  // Set text color to blue
    system("CLS");
    printf ("Let's start the game:");
     int members;
    printf("\n\tHOW MANY PLAYERS WANT TO PLAY:- \n");
    printf("\n\t2. TWO PLAYERS");
    printf("\n\t4. FOUR PLAYERS\n");
    printf("\n\tSELECT your choice:- ");
    scanf("%d", &members);

    if (members == 2) {
        printf("\n\tWELCOME TO PLAY GAME: \n");
        printf("\n\tENTER FIRST PLAYER NAME: ");
        scanf("%s", p1);
        printf("\n\tENTER SECOND PLAYER NAME: ");
        scanf("%s", p2);
        fflush (stdin);

     char t1, t2, t3, t4;

    printf("\n\tPress 'g' for GREEN");
    printf("\n\tPress 'r' for RED");
    printf("\n\tPress 'b' for BLUE");
    printf("\n\tPress 'y' for YELLOW");


        printf("\n\n\t%s!", p1);
        printf("\n\tSELECT YOUR FAVOURITE TOKEN: ");
        t1 = getche();

        printf("\n\n\t%s!", p2);
        printf("\n\tSELECT YOUR FAVOURITE TOKEN: ");
        t2 = getche();

    t3 = ' ';
    t4 = ' ';


    g11 = t1, g12 = t1, g13 = t1, g14 = t1;
    r11 = t2, r12 = t2, r13 = t2, r14 = t2;
    b11 = t3, b12 = t3, b13 = t3, b14 = t3;
    y11 = t4, y12 = t4, y13 = t4, y14 = t4;

    printf("\n");
    system("CLS");
    BOARD(arr, left, up, down, right);

        TWOPLAyers(arr, left, up, down, right);
    }
    if (members == 4) {
               HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setConsoleTextAttribute(h, 15);  // Set text color to blue
        printf("\n\tWELCOME TO PLAY GAME: \n");

        printf("\n\tENTER FIRST PLAYER NAME: ");
        scanf("%s", p1);
        printf("\n\tENTER SECOND PLAYER NAME: ");
        scanf("%s", p2);
        printf("\n\tENTER THIRD PLAYER NAME: ");
        scanf("%s", p3);
        printf("\n\tENTER FOURTH PLAYER NAME: ");
        scanf("%s", p4);
        system("CLS");
        Sleep(1000);
        setConsoleTextAttribute(h, 6);

        printf("\n\tPress 'g' for GREEN");
        printf("\n\tPress 'r' for RED");
        printf("\n\tPress 'b' for BLUE");
        printf("\n\tPress 'y' for YELLOW");

        printf("\n\n\t%s!", p1);
        printf("\n\tSELECT YOUR FAVOURITE TOKEN: ");
        t1 = getche();

        printf("\n\n\t%s!", p2);
        printf("\n\tSELECT YOUR FAVOURITE TOKEN: ");
        t2 = getche();

        printf("\n\n\t%s!", p3);
        printf("\n\tSELECT YOUR FAVOURITE TOKEN: ");
        t3 = getche();

        printf("\n\n\t%s!", p4);
        printf("\n\tSELECT YOUR FAVOURITE TOKEN: ");
        t4 = getche();

    g11 = t1, g12 = t1, g13 = t1, g14 = t1;
    r11 = t2, r12 = t2, r13 = t2, r14 = t2;
    b11 = t3, b12 = t3, b13 = t3, b14 = t3;
    y11 = t4, y12 = t4, y13 = t4, y14 = t4;

        printf("\n");
        system("CLS");
        printf("\n");
    }
    BOARD(arr, left, up, down, right);
        FOURPLAyers(arr, left, up, down, right);
}
void BOARD(char arr[], char left[], char up[], char down[], char right[])
{
       HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setConsoleTextAttribute(h, 15);  // Set text color to blue
    system("CLS");

printf("\n\n");
printf("\t\t\t\t\t");
printf("  ---  "
       "  ---  "
       "  ---  \n");
printf("\t\t\t\t\t");

printf(" | %c | ", arr[11]);
printf(" | %c | ", arr[12]);
printf(" | %c | ", arr[13]);
printf("\n");
printf("\t\t\t\t\t");
printf("  ---  "
       "  ---  "
       "  ---  \n");
printf("\t\t\t\t\t");

printf(" | %c | ", arr[10]);
printf(" | %c | ", up[1]);
printf(" | %c | ", arr[14]);
printf("\n");
printf("\t\t\t\t\t");
printf("  ---  "
       "  ---  "
       "  ---  \n");
printf("\t\t%c\t%c\t\t", g11, g12);
printf(" | %c | ", arr[9]);
printf(" | %c | ", up[2]);
printf(" | %c | ", arr[15]);
printf("\t\t%c\t%c\t\t", r11, r12);
printf("\n");
printf("\t\t\t\t\t");
printf("  ---  "
       "  ---  "
       "  ---  \n");
printf("\t\t%c\t%c\t\t", g13, g14);
printf(" | %c | ", arr[8]);
printf(" | %c | ", up[3]);
printf(" | %c | ", arr[16]);
printf("\t\t%c\t%c\t\t", r13, r14);
printf("\n");
printf("\t\t\t\t\t");
printf("  ---  "
       "  ---  "
       "  ---  \n");
printf("\t\t\t\t\t");
printf(" | %c | ", arr[7]);
printf(" | %c | ", up[4]);
printf(" | %c | ", arr[17]);
printf("\n");
printf("\t\t\t\t\t");
printf("  ---  "
       "  ---  "
       "  ---  \n");
printf("\t\t\t\t\t");
printf(" | %c | ", arr[6]);
printf(" | %c | ", up[5]);
printf(" | %c | ", arr[18]);
printf("\n");
printf("\t\t\t\t\t");
printf("  ---  "
       "  ---  "
       "  ---  \n");
printf("\n");
printf("  ---  "
       "  ---  "
       "  ---  "
       "  ---  "
       "  ---  "
       "  ---  ");
printf("   |        |   ");
printf("  ---  "
       "  ---  "
       "  ---  "
       "  ---  "
       "  ---  "
       "  ---  \n");
printf(" | %c | ", arr[0]);
printf(" | %c | ", arr[1]);
printf(" | %c | ", arr[2]);
printf(" | %c | ", arr[3]);
printf(" | %c | ", arr[4]);
printf(" | %c | ", arr[5]);
printf("   |        |   ");
printf(" | %c | ", arr[19]);
printf(" | %c | ", arr[20]);
printf(" | %c | ", arr[21]);
printf(" | %c | ", arr[22]);
printf(" | %c | ", arr[23]);
printf(" | %c | ", arr[24]);
printf("\n");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("   | %c    %c |   ", left[6], up[6]);
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("  ---  \n");
printf(" | %c | ", arr[51]);

printf(" | %c | ", left[1]);
printf(" | %c | ", left[2]);
printf(" | %c | ", left[3]);
printf(" | %c | ", left[4]);
printf(" | %c | ", left[5]);
printf("   |--------|   ");
printf(" | %c | ", right[5]);
printf(" | %c | ", right[4]);
printf(" | %c | ", right[3]);
printf(" | %c | ", right[2]);
printf(" | %c | ", right[1]);

printf(" | %c | ", arr[25]);
printf("\n");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");
printf("  ---  ");

    printf ("   | %c    %c |  ",down[6],right[6]);
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  \n");

   printf (" | %c |  ",arr[50]);
     printf("| %c | ", arr[49]);
    printf(" | %c | ", arr[48]);
    printf(" | %c | ", arr[47]);
    printf(" | %c | ", arr[46]);
    printf(" | %c | ", arr[45]);
    printf("   |        |   ");



    printf(" | %c | ", arr[31]);
    printf(" | %c | ", arr[30]);
    printf(" | %c | ", arr[29]);
    printf(" | %c | ", arr[28]);
    printf(" | %c | ", arr[27]);
    printf(" | %c | ", arr[26]);
    printf("\n");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("   |        |   ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  \n");
    printf("\n");
    printf("\t\t\t\t\t");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  \n");
    printf("\t\t\t\t\t");


   printf(" | %c | ", arr[44]);
    printf(" | %c | ", up[5]);
    printf(" | %c | ", arr[32]);
    printf("\n");
    printf("\t\t\t\t\t");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  \n");
    printf("\t\t\t\t\t");


    printf(" | %c | ", arr[43]);
    printf(" | %c | ", up[4]);
    printf(" | %c | ", arr[33]);
    printf("\n");
    printf("\t\t\t\t\t");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  \n");
    printf("\t\t%c\t%c\t\t", b11, b12);

 printf(" | %c | ", arr[42]);
    printf(" | %c | ", down[3]);
    printf(" | %c | ", arr[34]);
    printf("\t\t%c\t%c\t\t", y11, y12);
    printf("\n");
    printf("\t\t\t\t\t");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  \n");
    printf("\t\t%c\t%c\t\t", b13, b14);

    printf(" | %c | ", arr[41]);
    printf(" | %c | ", up[2]);
    printf(" | %c | ", arr[35]);
    printf("\t\t%c\t%c\t\t", y13, y14);
    printf("\n");
    printf("\t\t\t\t\t");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  \n");
    printf("\t\t\t\t\t");


     printf(" | %c | ", arr[40]);
    printf(" | %c | ", up[1]);
    printf(" | %c | ", arr[36]);
    printf("\n");
    printf("\t\t\t\t\t");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  \n");
    printf("\t\t\t\t\t");


      printf(" | %c | ", arr[39]);
    printf(" | %c | ", arr[38]);
    printf(" | %c | ", arr[37]);
    printf("\n");
    printf("\t\t\t\t\t");
    printf("  ---  ");
    printf("  ---  ");
    printf("  ---  \n");
    printf("\t\t\t\t\t");
    printf("\n");

}
void TWOPLAyers(char arr[], char left[], char up[], char down[], char right[])
{
char swap;
    int p1counter = 0;
    int p2counter = 0;
    char again = '0';
    while (1) {
        printf("\n\t%s : %c : %d\n", p1, t1, sum1);
        printf("\n\t%s : %c : %d\n", p2, t2, sum2);


        p1turn(arr, left);
        p2turn(arr, up);

        if (left[6] == t1) {
                c1=0;
            p1counter++;
            if (p1counter == 4) {
                printf("\n\t%s! YOU WON........", p1);
                break;
            } else {
                printf("\n\tYOUR %d tokens is/are in destination.", p1counter);
            }
        } else if (up[6] == t2) {
            p2counter++;
            if (p2counter == 4) {
                printf("\n\t%s! YOU WON........", p2);
                break;
            } else {
                printf("\n\tYOUR %d tokens is/are in destination.", p2counter);
            }
        }

        system("CLS");
        BOARD(arr, left, up, down, right);

        printf("\n\tDO YOU WANT TO:\n");
        printf("\t%c : continue\n", 'c');
        printf("\t%c : exit\n", 'e');

        scanf(" %c", &again);
        if (again == 'e') {
            printf("\n\n%s : %d : %d", p1, t1, sum1);
            printf("\n\n%s : %d : %d", p2, t2, sum2);
            if (sum1 > sum2) {
                printf("\n\n HIGHEST SCORE : %d by %s", sum1, p1);
            } else if (sum1 < sum2) {
                printf("\n\n HIGHEST SCORE : %d by %s", sum2, p2);
            } else if (sum1 == sum2) {
                printf("\n BOTH PLAYERS HAVE SAME SCORE : %d", sum1);
            }
            printf("\nEXITING! YOUR GAME DATA WILL BE LOSS\n\n");
            break;
        } else if (again == 'c') {
            continue;
        } else {
            printf("\nINVALID INPUT!");
        }
    }
}

void FOURPLAyers(char arr[], char left[], char up[], char down[], char right[])
{
       HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setConsoleTextAttribute(h, 2);  // Set text color to blue
    //char p1[] = "Player1";
    //char p2[] = "Player2";
    //char p3[] = "Player3";
    //char p4[] = "Player4";
   // int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    //int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    int p1counter = 0;
    int p2counter = 0;
    int p3counter = 0;
    int p4counter = 0;
    char again = '0';

    while (1) {
        printf("\n\t%s : %c : %d", p1, t1,sum1);
        printf("\n\t%s : %c : %d", p2, t2,sum2);
        printf("\n\t%s : %c : %d", p3, t3,sum3);
        printf("\n\t%s : %c : %d", p4, t4,sum4);
        printf("\n");

        for (int t = 0; t <= 3; t++) {
            for (int u = 0; u < 20; u++) {
                printf("-");
            }
        }
        printf("\n");

        p1turn(arr, left);
        p2turn(arr, up);
        p3turn(arr, down);
        p4turn(arr, right);

        if (left[6] == t1) {
            p1counter++;
            if (p1counter == 4) {
                printf("\n\t%s! YOU WON........", p1);
                break;
            } else {
                printf("\n\tYOUR %d tokens is/are in destination.", p1counter);
            }
        } else if (up[6] == t2) {
            p2counter++;
            if (p2counter == 4) {
                printf("\n\t%s! YOU WON........", p2);
                break;
            } else {
                printf("\n\tYOUR %d tokens is/are in destination.", p2counter);
            }
        } else if (down[6] == t3) {
            p3counter++;
            if (p3counter == 4) {
                printf("\n\t%s! YOU WON........", p3);
                break;
            } else {
                printf("\n\tYOUR %d tokens is/are in destination.", p3counter);
            }
        } else if (right[6] == t4) {
            p4counter++;
            if (p4counter == 4) {
                printf("\n\t%s! YOU WON........", p4);

                break;
            } else {
                printf("\n\tYOUR %d tokens is/are in destination.", p4counter);
            }
        }

        BOARD(arr, left, up, down, right);

        printf("\n\tDO YOU WANT TO:\n");
        printf("\t c : continue\n");
        printf("\t e : exit\n");

        scanf(" %c", &again);
        if (again == 'e') {
            printf("\n\n%s : %c : %d", p1, t1, sum1);

            printf("\n\n%s : %c : %d", p2, t2, sum2);

            printf("\n\n%s : %c : %d", p3, t3, sum3);

            printf("\n\n%s : %c : %d", p4, t4, sum4);

            if (sum1 > sum2 && sum1 > sum3 && sum1 > sum4) {
                printf("\n\n HIGHEST SCORE : %d by %s", sum1, p1);
            } else if (sum2 > sum1 && sum2 > sum3 && sum2 > sum4) {
                printf("\n\n HIGHEST SCORE : %d by %s", sum2, p2);

            } else if (sum3 > sum1 && sum3 > sum2 && sum3 > sum4) {
                printf("\n\n HIGHEST SCORE : %d by %s", sum3, p3);

            } else if (sum4 > sum1 && sum4 > sum2 && sum4 > sum3) {
                printf("\n\n HIGHEST SCORE : %d by %s", sum4, p4);

            } else if (sum1 == sum2 && sum1 == sum3 && sum1 == sum4) {
                printf("\n ALL PLAYERS HAVE SAME SCORE : %d", sum1);

            } else if (sum1 == sum2 && sum1 > sum3 && sum1 > sum4) {
                printf("\nPLAYERS 1 & 2 HAVE SAME SCORE : %d", sum1);
            } else if (sum1 == sum3 && sum1 > sum4 && sum1 > sum2) {
                printf("\nPLAYERS 1 & 3 HAVE SAME SCORE : %d", sum1);
            } else if (sum1 == sum4 && sum1 > sum3 && sum1 > sum2) {
                printf("\nPLAYERS 1 & 4 HAVE SAME SCORE : %d", sum1);
            } else if (sum2 == sum3 && sum2 > sum1 && sum2 > sum4) {
                printf("\nPLAYERS 2 & 3 HAVE SAME SCORE : %d", sum2);

            } else if (sum2 == sum4 && sum2 > sum3 && sum2 > sum1) {
                printf("\nPLAYERS 2 & 4 HAVE SAME SCORE : %d", sum2);

            } else if (sum3 == sum4 && sum3 > sum1 && sum3 > sum2) {
                printf("\nPLAYERS 3 & 4 HAVE SAME SCORE : %d", sum3);
            }
            printf("\n EXITING! YOUR GAME DATA WILL BE LOST\n\n");
            break;
        } else if (again == 'c') {
            continue;
        } else {
            printf("\nINVALID INPUT!");
        }
    }

}
void p1turn(char arr[], char left[])
{
       HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setConsoleTextAttribute(h, 5);  // Set text color to blue
    char swap1 = '0';
    int max = 6, min = 1;
   printf ("\n\t  %s!  Its your turn: ",p1);
    printf ("\n\tENTER ANY KEY TO ROLL THE DICE = ");
    getche();
    printf ("\n");
    int dice = 0;
    srand(time(0));
    dice = (rand() % (max - min + 1) + min);
    if (dice == 1) {
    printf(" -----\n");
    printf("|     |\n");
    printf("|  0  |\n");
    printf("|     |\n");
    printf(" -----\n");
    sum1 = sum1 + dice;
  }
  if (dice == 2) {
    printf(" -----\n");
    printf("|   0 |\n");
    printf("|     |\n");
    printf("|O    |\n");
    printf(" -----\n");
    sum1 = 2 + sum1;
  }
  if (dice == 3) {
    printf(" -----\n");
    printf("|    0|\n");
    printf("|  0  |\n");
    printf("|0    |\n");
    printf(" -----\n");
    sum1 = dice + sum1;
  }
  if (dice == 4) {
    printf(" -----\n");
    printf("|0   0|\n");
    printf("|     |\n");
    printf("|O   0|\n");
    printf(" -----\n");
    sum1+=dice;
  }
  else if (dice == 5) {
  printf(" -----\n");
  printf("|O    O|\n");
  printf("|   0  |\n");
  printf("|O    O|\n");
  printf(" -----\n");
  sum1 = sum1 + dice;
}
else if (dice == 6) {
  printf(" -----\n");
  printf("|O    O|\n");
  printf("|O    O|\n");
  printf("|O    O|\n");
  printf(" -----\n");
  printf ("\n");
  printf ("\n\tCongratulations ! you got 6 the dice will be rolled again");
 g11 = ' ';
        dice = 0;
        dice = ((rand() % 6) + 1);
        printf ("\n\tthis time you get = %d",dice);
        sum1 = sum1 + 6 + dice;
        c1++;
        if (c1 > 1)
        {
            i = i + 6;
        }
}
if (c1 == 0)
    {
        sum1 = 0;
          printf ("\n\t");
          printf ("To begin, You must roll a six to move a piece out of the base and onto the start position.");
        arr[i] = '/';
    }
 else if (c1 != 0)
    {
        if (i > 51)
        {
            i = i - 51;
            swap1 = left[i];
            char temp = '0';
            temp = left[i];
            i = i + dice;    // i = 1+5 = 6
            left[i] = t1;    // arr[i] = g
            i = i - dice;    // i = 6-5 = 1
            left[i] = swap1; // arr[i] = '/'
            left[i] = '/';
            if (i == 6)
            {
               printf ("\n\tCONGRATULATIONS!");
            }
            else if (i > 6)
            {
               printf ("\n\tsorry! NEXT TIME.....");
            }
            else if (i < 6)
            {
                i = i + dice;
            }
        }
        else
        {
            char req;
            req = arr[i];
            arr[i] = t1;

            swap1 = arr[i]; // swap1 = '/'
            char temp = '0';
            temp = arr[i];
            i = i + dice;   // i = 1+5 = 6
            arr[i] = t1;    // arr[i] = r
            i = i - dice;   // i = 6-5 = 1
            arr[i] = swap1; // arr[i] = '/'
            if (temp == arr[i])
            {
                if (i == 1 || i == 9 || i == 14 || i == 22 || i == 27 || i == 35 || i == 40 || i == 48)
                {
                    arr[i] = '/';
                }
                else
                {
                    arr[i] = ' ';
                }
            }
            i = i + dice; // i = 1+5 = 6
        }
    }

     printf ("\n\t %s's score:%d\n ",p1,sum1);
}
void p2turn(char arr[], char up[])
{
       HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setConsoleTextAttribute(h, 8);  // Set text color to blue
    char swap2 = '0';
    int max = 6, min = 1;
    printf ("\n\t %s! Its your turn:",p2);
    printf ("\n\tENTER ANY KEY TO ROLL THE DICE = ");
    getche();
    printf ("\n");
    int dice = 0;
    srand(time(0));
    dice = (rand() % (max - min + 1) + min);
    if (dice == 1)
    {
        printf ("-----\n");
        printf ("|     |\n");
        printf ("|  0  |\n");
        printf ("|     |\n");
        printf (" -----\n");
        sum2 = sum2 + dice;
    }
    else if (dice == 2)
    {
        printf (" -----\n");
        printf ("|    0|\n");
        printf ("|     |\n");
        printf ("|0    |\n");
        printf (" -----\n");
        sum2 = dice + sum2;
    }
    else if (dice == 3)
    {
         printf ("-----\n");
        printf ("|     0|\n");
        printf ("|   0  |\n");
        printf ("|0     |\n");
        printf (" -----\n");
        sum2 = dice + sum2;
    }
    else if (dice == 4)
    {
         printf ("-----\n");
        printf ("|0    0|\n");
        printf ("|      |\n");
        printf ("|0    0|\n");
        printf (" -----\n");
        sum2 = sum2 + dice;
    }
    else if (dice == 5)
    {
         printf ("-----\n");
        printf ("|0    0|\n");
        printf ("|  0   |\n");
        printf ("|0    0|\n");
        printf (" -----\n");
        sum2 = sum2 + dice;
    }
    else if (dice == 6)
    {
        printf ("-----\n");
        printf ("|0    0|\n");
        printf ("|0    0|\n");
        printf ("|0    0|\n");
        printf (" -----\n");
        printf ("\n");
        printf ("\n\tCongratulations ! you got 6 the dice will be rolled again\n");
        r11 = ' ';
        dice = 0;
        dice = ((rand() % 6) + 1);
        printf("\n\tthis time you get %d",dice);
        sum2 = sum2 + dice + 6;
        c2++;
        if (c2 > 1)
        {
            j = j + 6;
        }
    }
    if (c2 == 0)
    {
        sum2 = 0;
        printf ("\n\t");
             printf ("To begin, You must roll a six to move a piece out of the baseand onto the start position.") ;
    }
    else if (c2 != 0)
    {
        if (j > 51)
        {
            j = j - 51;
            swap2 = arr[j]; // swap1 = '/'
            char temp = '0';
            temp = arr[j];
            j = j + dice;   // i = 1+5 = 6
            arr[j] = t2;    // arr[i] = b
            j = j - dice;   // i = 6-5 = 1
            arr[j] = swap2; // arr[i] = '/'
            arr[j] = '/';
            if (j > 12)
            {
                j = j - 12;
                swap2 = up[j]; // swap1 = '/'
                char temp = '0';
                temp = up[j];
                j = j + dice;  // i = 1+5 = 6
                up[j] = t2;    // arr[i] = b
                j = j - dice;  // i = 6-5 = 1
                up[j] = swap2; // arr[i] = '/'
                up[j] = '/';
                j = j + dice;
            }
            if (j == 6)
            {
                printf ("\n\tCONGRATULATIONS!");
            }
            else if (j > 6)
            {
                printf ("\n\tNO WORK!");
                j = j - dice;
                arr[j] = arr[j];
            }
            else if (j < 6)
            {
                j = j + dice;
                j = j + dice;  // i = 1+5 = 6
                up[j] = t2;    // arr[i] = b
                j = j - dice;  // i = 6-5 = 1
                up[j] = swap2; // arr[i] = '/'
                up[j] = '/';
            }
        }
        else
        {
            char req;
            req = arr[j];
            arr[j] = t2;
            swap2 = arr[j]; // swap2 = '/'
            char temp = '0';
            temp = arr[j];
            j = j + dice; // i = 1+5 = 6
            arr[j] = t2;  // arr[i] = b

            j = j - dice;   // i = 6-5 = 1
            arr[j] = swap2; // arr[i] = '/'
            if (temp == arr[j])
            {
                if (j == 1 || j == 9 || j == 14 || j == 22 || j == 27 || j == 35 || j == 40 || j == 48)
                {
                    arr[j] = '/';
                }
                else
                {
                    arr[j] = ' ';
                }
            }
            j = j + dice; // i = 1+5 = 6
        }
    }

   printf ("\n\t %s's score: %d\n",p2,sum2);


}
void p3turn(char arr[], char down[])
{
       HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setConsoleTextAttribute(h, 9);  // Set text color to blue
    char swap3 = '0';
    int max = 6, min = 1;

    printf ("\n\t %s! Its your turn:",p3);
    printf ("\n\tENTER ANY KEY TO ROLL THE DICE = ");
    getche();
    printf ("\n");
    int dice = 0;
    srand(time(0));
    dice = (rand() % (max - min + 1) + min);
    if (dice == 1)
    {
        printf ("-----\n");
        printf ("|     |\n");
        printf ("|  0  |\n");
        printf ("|     |\n");
        printf (" -----\n");
        sum3 = sum3 + dice;
    }
     else if (dice == 2)
    {
        printf (" -----\n");
        printf ("|    0|\n");
        printf ("|     |\n");
        printf ("|0    |\n");
        printf (" -----\n");
        sum3 = dice + sum3;
    }
    else if (dice == 3)
    {
         printf ("-----\n");
        printf ("|     0|\n");
        printf ("|   0  |\n");
        printf ("|0     |\n");
        printf (" -----\n");
        sum3 = dice + sum3;
    }
    else if (dice == 4)
    {
         printf ("-----\n");
        printf ("|0    0|\n");
        printf ("|      |\n");
        printf ("|0    0|\n");
        printf (" -----\n");
        sum3 = sum3 + dice;
    }
    else if (dice == 5)
    {
         printf ("-----\n");
        printf ("|0    0|\n");
        printf ("|  0   |\n");
        printf ("|0    0|\n");
        printf (" -----\n");
        sum3 = sum3 + dice;
    }
    else if (dice == 6)
    {
         printf ("-----\n");
        printf ("|0    0|\n");
        printf ("|0    0|\n");
        printf ("|0    0|\n");
        printf (" -----\n");
         printf ("\n");
        printf ("\n\tCongratulations ! you got 6 the dice will be rolled again\n");
        b11 = ' ';
        dice = 0;
        dice = ((rand() % 6) + 1);
        printf ("\n\tthis time you get %d",dice);
        sum3 = sum3 + dice + 6;
        c3++;
        if (c3 > 1)
        {
            k = k + 6;
        }
    }
    if (c3 == 0)
    {
        sum3 = 0;
       printf ("\n\t To begin, You must roll a six to move a piece out of the base and onto the start position.");
    }
    else if (c3 != 0)
    {
        if (k > 51)
        {
            b11 = ' ';
            k = k - 51;
            swap3 = arr[k]; // swap1 = '/'
            char temp = '0';
            temp = arr[k];
            k = k + dice;   // i = 1+5 = 6
            arr[k] = t3;    // arr[i] = y
            k = k - dice;   // i = 6-5 = 1
            arr[k] = swap3; // arr[i] = '/'
            arr[k] = '/';
            if (k > 12)
            {
                y11 = ' ';
                l = l - 40;
                swap3 = down[k]; // swap1 = '/'
                char temp = '0';
                temp = down[k];
                k = k + dice;    // i = 1+5 = 6
                down[k] = t3;    // arr[i] = y
                k = k - dice;    // i = 6-5 = 1
                down[k] = swap3; // arr[i] = '/'
                down[k] = '/';
            }

            if (k == 6)
            {
                printf ("\n\tCONGRATULATIONS!");
            }
            else if (k > 6)
            {
                printf ("\n\tsorry! NEXT TIME.....");
            }
            else if (k < 6)
            {
                k = k + dice;
            }
        }
        else
        {
            char req;
            req = arr[k];
            arr[k] = t3;
            swap3 = arr[k]; // swap2 = '/'
            char temp = '0';
            temp = arr[k];
            k = k + dice; // i = 1+5 = 6
            arr[k] = t3;  // arr[i] = y

            k = k - dice;   // i = 6-5 = 1
            arr[k] = swap3; // arr[i] = '/'
            if (temp == arr[k])
            {
                if (k == 1 || k == 9 || k == 14 || k == 22 || k == 27 || k == 35 || k == 40 || k == 48)
                {
                    arr[k] = '/';
                }
                else
                {
                    arr[k] = ' ';
                }
            }
            k = k + dice; // i = 1+5 = 6
        }
    }

    printf ("\n\t %s's score: %d\n",p3,sum3);
}
void p4turn(char arr[], char right[])
{
       HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    setConsoleTextAttribute(h, 4);  // Set text color to blue
    char swap4 = '0';
    printf ("\n\t %s! Its your turn:",p4);
    printf ("\n\tENTER ANY KEY TO ROLL THE DICE = ");
    getche();
    printf ("\n");
    int dice = 0;
    srand(time(0));
    dice = ((rand() % 6)+1);
    if (dice == 1)
    {
        printf ("-----\n");
        printf ("|     |\n");
        printf ("|  0  |\n");
        printf ("|     |\n");
        printf (" -----\n");
        sum4 = sum4 + dice;
    }
    else if (dice == 2)
    {
         printf ("-----\n");
        printf ("|    0|\n");
        printf ("|     |\n");
        printf ("|0    |\n");
        printf (" -----\n");
        sum4 = dice + sum4;
    }
    else if (dice == 3)
    {
         printf ("-----\n");
        printf ("|    0|\n");
        printf ("|  0  |\n");
        printf ("|0    |\n");
        printf (" -----\n");
        sum4 = dice + sum4;
    }
    else if (dice == 4)
    {
         printf ("-----\n");
        printf ("|0  0|\n");
        printf ("|    |\n");
        printf ("|0  0|\n");
        printf (" -----\n");
        sum4 = sum4 + dice;
    }
    else if (dice == 5)
    {
         printf ("-----\n");
        printf ("|0   0|\n");
        printf ("|  0  |\n");
        printf ("|0   0|\n");
        printf (" -----\n");
        sum4 = sum4 + dice;
    }
    else if (dice == 6)
    {
         printf ("-----\n");
        printf ("|0   0|\n");
        printf ("|0   0|\n");
        printf ("|0   0|\n");
        printf (" -----\n");
        printf ("\n");
        printf ("\n\tCongratulations ! you got 6 the dice will be rolled again\n");
        y11 = ' ';
        dice = 0;
        dice = ((rand() % 6) + 1);
        printf ("\n\tthis time you get %d",dice);
        sum4 = sum4 + dice + 6;
        c4++;
        if (c4 > 1)
        {
            l = l + 6;
        }
    }
    if (c4 == 0)
    {
        sum4 = 0;
        printf ("\n\t");
        printf("To begin, You must roll a six to move a piece out of the base and onto the start position.");
    }
    else if (c4 != 0)
    {
        if (l > 51)
        {
            l = l - 51;
            swap4 = arr[l]; // swap1 = '/'
            char temp = '0';
            temp = arr[l];
            l = l + dice;   // i = 1+5 = 6
            arr[l] = t4;    // arr[i] = y
            l = l - dice;   // i = 6-5 = 1
            arr[l] = swap4; // arr[i] = '/'
            arr[l] = '/';
            if (l > 12)
            {
                y11 = ' ';
                l = l - 27;
                swap4 = right[l]; // swap1 = '/'
                char temp = '0';
                temp = right[l];
                l = l + dice;     // i = 1+5 = 6
                right[l] = t4;    // arr[i] = y
                l = l - dice;     // i = 6-5 = 1
                right[l] = swap4; // arr[i] = '/'
                right[l] = '/';
            }

            if (l == 6)
            {
                printf ("\n\tCONGRATULATIONS!");
            }
            else if (l > 6)
            {
                printf ("\n\tsorry! NEXT TIME.....");
            }
            else if (l < 6)
            {
                l = l + dice;
            }
            if (l == 6)
            {
                printf ("\n\tCONGRATULATIONS!");
            }
            else if (l > 6)
            {
                printf ("\n\tsorry! NEXT TIME.....");
            }
            else if (l < 6)
            {
                l = l + dice;
            }
        }
        else
        {
            char req;
            req = arr[l];
            arr[l] = t4;

            swap4 = arr[l]; // swap2 = '/'
            char temp = '0';
            temp = arr[l];
            l = l + dice; // i = 1+5 = 6
            arr[l] = t4;  // arr[i] = y

            l = l - dice;   // i = 6-5 = 1
            arr[l] = swap4; // arr[i] = '/'
            if (temp == arr[l])
            {
                if (l == 1 || l == 9 || l == 14 || l == 22 || l == 27 || l == 35 || l == 40 || l == 48)
                {
                    arr[l] = '/';
                }
                else
                {
                    arr[l] = ' ';
                }
            }
            l = l + dice; // i = 1+5 = 6
        }
    }

    printf ("\n\t%s's SCORE: \n",p4,sum4);
}
