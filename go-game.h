typedef enum stone {
  EMPTY = 0,
  BLACK = 1,
  WHITE = 2,
  EDGES = 3
} stone;

typedef enum direction {
  EAST = 0,
  NORTH = 1,
  WEST = 2,
  SOUTH = 3
} direction;

typedef enum result {
  FAIR = 0,
  KO = 17,
  CAPTURED = 16,
  COLLISION = 18,
  OOB = 19
} result;

typedef struct Group {
  int count;
  int size;
  int **point;
} Group;

stone **last_board;
stone **curr_board;
stone **next_board;

Group ***old_group;
Group ***new_group;

result place(stone color, int x, int y);
result put(stone color, int x, int y);
result is_capt(int x, int y);

int capture(Group *grp);
int add_to_group(int x, int y, Group *grp);
int merge_groups(Group *grp1, Group *grp2);
int unset(Group *grp);


int init_board(int dim);
int kill_board(void);
int updt_board(void);
int copy_board(stone **from, stone **to);

#include "go-game.c"
