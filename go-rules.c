#include <stdio.h>
#include <assert.h>
#include "go-defs.c" 

result place(stone color, int x, int y);
result put(stone color, int x, int y);
int add_to_group(int x, int y, Group grp);
int merge_groups(Group *grp1, Group *grp2);
int init_board(int dim);

int init_board(int dim){
  DIM = dim;
  int i=0;

  last_board = calloc(DIM+2, stone*);
  curr_board = calloc(DIM+2, stone*);
  next_board = calloc(DIM+2, stone*);
  old_groups = calloc(DIM+2, Group*);
  new_groups = calloc(DIM+2, Group*);

  for(i = 0; i < DIM+2; i++) {
    last_board[i] = calloc(DIM+2, stone);
    curr_board[i] = calloc(DIM+2, stone);
    next_board[i] = calloc(DIM+2, stone);
    old_groups[i] = calloc(DIM+2, Group);
    new_groups[i] = calloc(DIM+2, Group);
  } 

}

result place(stone color, int x, int y){
  result rslt = 0;
  if(x < 1)||(y < 1)||(x > DIM)||(y > DIM) return OOB;
  //if(curr_board[x][y] = EDGES) return OOB;
  if(curr_board[x][y] != EMPTY) return COLLISION;

  rslt = put(color, x, y);

  if(rslt % 16 = 0)&&(rslt / 16 = 15;

  return FAIR;
}

result put(stone color, int x, int y) {
  return FAIR;
}

int add_to_group(int x, int y, Group *grp) {
  return grp->count;
}

int merge_groups(Group *grp1, Group *grp2) {
  
  return grp2->count;
}
