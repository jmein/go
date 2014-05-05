#include "go-game.h"

void print_board(void) {
  int i,j;
  for(i=0;i<DIM+2;i++) {
    for(j=0;j<DIM+2;j++) {
      printf("%d",last_board[i][j]);
    } 
    printf(" ");
    for(j=0;j<DIM+2;j++) {
      printf("%d",curr_board[i][j]);
    }
    printf(" ");
    for(j=0;j<DIM+2;j++) {
      printf("%d",next_board[i][j]);
    } 
    printf("\n");
  }
  printf("\n");
}

int main(void) {
  int x,y;
  result rslt;
  char *results[20];
  results[FAIR]="FAIR";
  results[KO]="KO";
  results[COLLISION]="COLLISION";
  results[OOB]="OOB";
  if(!init_board(9)) {
    kill_board();
  }

  do {
    print_board();
    scanf("%d %d",&x,&y);
    rslt=place(WHITE,x,y);
    printf("%d\n",rslt);
    if(rslt<20) {
      printf("%s\n",results[rslt]);
    }
  } while (rslt!=COLLISION);
  kill_board();

  return 0;
}
