#include <stdio.h>
#include <stdlib.h>

int DIM;

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

  for(i = 0; i < DIM+2; i++) {
    last_board[i][0]=EDGES;
    last_board[i][DIM+1]=EDGES;
    last_board[0][i]=EDGES;
    last_board[DIM+1][i]=EDGES; 
    curr_board[i][0]=EDGES;
    curr_board[i][DIM+1]=EDGES;
    curr_board[0][i]=EDGES;
    curr_board[DIM+1][i]=EDGES;
    next_board[i][0]=EDGES;
    next_board[i][DIM+1]=EDGES;
    next_board[0][i]=EDGES;
    next_board[DIM+1][i]=EDGES;
  }

  return DIM;

}

result place(stone color, int x, int y){
  result rslt = 0;
  if((x < 1)||(y < 1)||(x > DIM)||(y > DIM)) return OOB;
  if(curr_board[x][y] != EMPTY) return COLLISION;

  rslt = put(color, x, y);

  if((rslt % 16 == 0)&&(rslt / 16 == 15)) return CAPTURED;

  if(updt_board()) return FAIR;

  return FAIR;
}

result put(stone color, int x, int y) {
  result rslt=0;
  rslt+=is_capt(x+1,y);
  rslt+=is_capt(x,y+1);
  rslt+=is_capt(x-1,y);
  rslt+=is_capt(x,y-1);
  next_board[x][y]=color;
}

result is_capt(int x, int y) {
  Group *grp;
  grp = old_group[x][y];
  if(grp==NULL) return 0;
  for(i=0; i<grp->count; i++) {
    x=grp->points[i][0];
    y=grp->points[i][1];
    if((next_board[x-1][y]==EMPTY)||(next_board[x+1][y]==EMPTY)||(next_board[x][y-1]==EMPTY)||(next_board[x][y+1]=EMPTY)) return 0;
  }
  return 1;
}

int add_to_group(int x, int y, Group *grp) {
  if((grp->count)==(grp->size)) {
    grp->point= realloc(grp->point, 2 * grp->size * sizeof(int*));
  }
  grp->point[grp->count][0] = x;
  grp->point[grp->count][1] = y;// = {x,y};
  grp->count = grp->count+1;
  new_group[x][y] = grp;
  return grp->count;
}

int merge_groups(Group *grp1, Group *grp2) {
  int i;
  for (i=0; i<grp1->count; i++) {
    add_to_group(grp1->point[i][0],grp1->point[i][1],grp2);
  }

  if(unset(grp1)) return grp2->count;

  return grp2->count;
}

int unset(Group *grp) {
  int i;
  for(i=0; i<grp->count; i++) {
    free(grp->point[i]);
  }
  free(grp->point);
  free(grp);
  return 1;
}

int updt_board(void) {
  return copy_board(curr_board,last_board)*copy_board(next_board,curr_board);
}

int copy_board(stone **from, stone **to) {
  int i,j;
  for (i=1;i<DIM+1;i++) for (j=1;j<DIM+1;j++) to[i][j]=from[i][j];
  return 1;
}

int kill_board(void) {
  int i,j;
  for(i=0;i<DIM+2;i++) {
    for(j=0;j<DIM+2;j++) {
      if (new_group[i][j]!=NULL) unset(new_group[i][j]);
      if (old_group[i][j]!=NULL) unset(old_group[i][j]);
    }
    free(new_group[i]);
    free(old_group[i]);
    free(last_board[i]);
    free(curr_board[i]);
    free(next_board[i]);
  }
  free(old_group);
  free(new_group);
  free(last_board);
  free(curr_board);
  free(next_board);
  return 1;
}
