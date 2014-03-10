int DIM;

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
  KO = 16,
  CAPTURED = 17,
  COLLISION = 18,
  OOB = 19
} result;

typedef struct Group {
  int count;
  int **point;
} Group;

stone **last_board;
stone **curr_board;
stone **next_board;

Group ***old_group;
Group ***new_group;
