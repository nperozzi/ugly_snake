#ifndef SNAKE_H
#define SNAKE_H

typedef struct
{
    int seg_x;
    int seg_y;
} snake_seg_t;

typedef struct
{
    snake_seg_t seg_array[900];
    int snake_size;
    int direction_y;        //-1 = left, 1 = right, 0 = no movement in that axis.
    int direction_x;        //-1 = up, 1 = down, 0 = no movement in that axis
} snake_t;

void get_user_input(snake_t *snake);
void move_snake(snake_t *snake, int offset_x, int offset_y);
void test_snake_collision(snake_t *snake);

#endif      //SNAKE_H
