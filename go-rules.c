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

  last_board = (stone**) calloc(DIM+2, sizeof(stone*));
  curr_board = (stone**) calloc(DIM+2, sizeof(stone*));
  next_board = (stone**) calloc(DIM+2, sizeof(stone*));
  old_group = (Group***) calloc(DIM+2, sizeof(Group**));
  new_group = (Group***) calloc(DIM+2, sizeof(Group**));

  for(i = 0; i < DIM+2; i++) {
    last_board[i] = (stone*) calloc(DIM+2, sizeof(stone));
    curr_board[i] = (stone*) calloc(DIM+2, sizeof(stone));
    next_board[i] = (stone*) calloc(DIM+2, sizeof(stone));
    old_group[i] = (Group**) calloc(DIM+2, sizeof(Group*));
    new_group[i] = (Group**) calloc(DIM+2, sizeof(Group*));
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
  if(grp->count=grp->size) {
    grp->stones = realloc(grp->stones, 2 * grp->size * sizeof(int*)
  }
  grp->stones[grp->count++] = {x,y};
  next_groups[x][y] = grp;
  return grp->count;
}

int merge_groups(Group *grp1, Group *grp2) {
  int i;
  for (i=0; i<grp1->count; i++) {
    add_to_group(grp1->stones[i][0],grp1->stones[i][1],grp2);
  }

  if unset(grp1) return grp2->count;

  return grp2->count;
}

int unset(Group *grp) {
  int i;
  for(i=0; i<grp->count; i++) {
    free(grp->stones[i]);
  }
  free(grp->stones);
  free(grp);
}

