#include<ncurses.h>
#include<stdlib.h>

int main(){
    // make the string versions of ints for str input to be stored in
    char rowstr[5];
    char colintstr[5];
    char heigthstr[5];
    char lengthstr[5];
    // get the input
    printf("row ot start at> ");
    fgets(rowstr, 5, stdin);
    printf("column to start at>");
    fgets(colintstr, 5, stdin);
    printf("heigth>");
    fgets(heigthstr, 5, stdin);
    printf("length>");
    fgets(lengthstr, 5, stdin);
    // turn the strings to ints and calculate some of them
    int row = atoi(rowstr);
    int colint = atoi(colintstr) * 2;
    int heigth = atoi(heigthstr) - 1;
    int length = atoi(lengthstr) * 2 - 1;
    // start the screen for ncurses
    initscr();
    // backup the colint
    int colintback = colint;
    // set the column to end to colint + 11 which will make the square 6 # long
    int coltoend=colint+=length;
    // reset colint to the backup
    colint = colintback;

    int rowrestart=row;
    
    // remove the cursor
    curs_set(0);
    
    // column is the colint; while the column is smaller/equals coltoend loop this; increment column by 2
    for(int col=colint;col<=coltoend;col+=2){
        // write a character in columns everytime col from above increases the column changes
        for(int j=0;j<=heigth;j++){
            mvaddch(row++,col,'#');
            refresh();
            napms(10);
        }
        row=rowrestart;
    }
    // done!
    addstr("\ndone...");
    // show teh cursor and wait for input to end the program
    curs_set(1);
    getch();
    endwin();
}
