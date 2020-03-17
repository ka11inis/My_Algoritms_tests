#include <stdio.h>

#define ROW 16
#define COL 64
enum board{ dead, alive, wall };
int arr[ ROW ][ COL ];
int nextArr[ ROW ][ COL ];

void initTable();
void printTable();
int setCell(const int row, const int col);

int main(int argc, char **argv){
    srand(time(NULL));
    initTable();
    printTable();

    arr[7][7] = alive;
    arr[8][8] = alive;
    arr[9][6] = alive;
    arr[9][7] = alive;
    arr[9][8] = alive;
    arr[4][5] = alive;
    arr[5][3] = alive;
    arr[5][4] = alive;
    arr[5][5] = alive;
    arr[3][6] = alive;
    arr[4][6] = alive;
    arr[5][6] = alive;
    arr[6][6] = alive;
    arr[7][6] = alive;

    for (int i=0; i<30000; i++){
        system("clear");
        printTable();
        system("sleep 0.3");
    }
}

void initTable(){
    for (int i=0; i < ROW; i++ ){
        for (int j=0; j < COL; j++){
            if( i == 0 || j == 0 || j == COL-1 || i == ROW-1) arr[i][j] = wall;
            else arr[i][j] = dead;
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

void printTable(){
    for (int i=0; i < ROW; i++){
        for (int j=0; j<COL; j++){
            nextArr[i][j] = setCell(i,j);
            switch ( arr[i][j] ){
                case dead:
                    printf(" ");
                    break;
                case alive:
                    printf("*");
                    break;
                case wall:
                   printf("+");
                   break;
                default:
                    printf("");
            }
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<ROW; i++) for(int j=0; j<COL; j++){
        arr[i][j] = nextArr[i][j]; 
    }
}

int setCell(const int row, const int col){
    int neighboursAlive = 0;

    if (arr[row][col] == wall) return wall;

    for (int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            if (row+i == row && col == col+j) neighboursAlive += 0;
            else if (arr[row + i][col + j] == wall) neighboursAlive += 0;
            else if ( arr[row + i][col + j] == alive ) neighboursAlive += 1 ;
        }
    }
    if(neighboursAlive == 2 && arr[row][col] ) return  alive;
    if(neighboursAlive == 3  ) return  alive;
    if(neighboursAlive < 2 ) return dead;
    if(neighboursAlive > 3 ) return dead;
}
