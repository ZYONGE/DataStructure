#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "circular_deque.h"

#define MAZE_DIM 6

char map[MAZE_DIM][MAZE_DIM] = {
    {'1', '1', '1', '1', '1', '1'},
    {'0', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', '1'},
    {'1', 'x', '1', '1', '1', '1'}
};

void push_loc(int r, int c);
void print_maze();
int is_valid_loc(int r, int c);

int main (void) {
    init_deque();

    push_loc(1, 0);

    while (!is_empty()) {
        system("clear");
        print_maze();
        usleep(500000);

        Element here = get_rear();
        int c = here.c;
        int r = here.r;
        if (map[r][c] == 'x') {
            printf("목적지에 도착했습니다!\n");
            return 0;
        } else {
            map[r][c] = '.';

            if (is_valid_loc(r - 1, c)) {
                push_loc(r - 1, c);
            } else if (is_valid_loc(r, c + 1)) {
                push_loc(r, c + 1);
            } else if (is_valid_loc(r + 1, c)) {
                push_loc(r + 1, c);
            } else if (is_valid_loc(r, c - 1)) {
                push_loc(r, c - 1);
            } else {
                delete_rear();
            }
        }
    }

    printf("미로탈출 실패\n");

    return 0;
}

void print_maze(){
    Element here = get_rear();
    for(int i = 0; i < MAZE_DIM; i++){
        for(int j = 0; j < MAZE_DIM; j++){
            if(here.r == i && here.c == j){
                printf("@ ");
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}
int is_valid_loc(int r, int c) {
    if (r < 0 || r >= MAZE_DIM || c < 0 || c >= MAZE_DIM) {
        return 0;
    }
    return map[r][c] != '1' && map[r][c] != '.';
}

void push_loc(int r, int c) {
    if (!is_valid_loc(r, c)) {
        return;
    }
    Element pos = {r, c};
    add_rear(pos);
}