#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 10
#define HEIGHT 20

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[WIDTH * HEIGHT]; // Snake body points
    int length;                 // Snake length
    char direction;             // Snake direction (w: up, s: down, a: left, d: right)
} Snake;

typedef struct {
    Snake snake;
    Point fruit;
    int grid[HEIGHT][WIDTH];
    int score;
    int gameOver;
} Game;

void spawnFruit(Game *game) {
    game->fruit.x = rand() % WIDTH;
    game->fruit.y = rand() % HEIGHT;
}

void initializeGame(Game *game) {
    game->snake.length = 1;
    game->snake.body[0].x = WIDTH / 2;
    game->snake.body[0].y = HEIGHT / 2;
    game->snake.direction = 'w'; // Initial direction is up
    game->score = 0;
    game->gameOver = 0;
    spawnFruit(game);
}

void moveSnake(Game *game) {
    // Move each part of the snake to the position of the previous part
    for (int i = game->snake.length - 1; i > 0; i--) {
        game->snake.body[i] = game->snake.body[i - 1];
    }

    // Move the head in the direction of the snake
    if (game->snake.direction == 'w') game->snake.body[0].y--;
    if (game->snake.direction == 's') game->snake.body[0].y++;
    if (game->snake.direction == 'a') game->snake.body[0].x--;
    if (game->snake.direction == 'd') game->snake.body[0].x++;
}

int checkCollision(Game *game) {
    Point head = game->snake.body[0];

    // Check if snake hits the wall
    if (head.x < 0 || head.x >= WIDTH || head.y < 0 || head.y >= HEIGHT) {
        return 1;
    }

    // Check if snake hits itself
    for (int i = 1; i < game->snake.length; i++) {
        if (head.x == game->snake.body[i].x && head.y == game->snake.body[i].y) {
            return 1;
        }
    }

    return 0;
}

void checkFruit(Game *game) {
    Point head = game->snake.body[0];
    if (head.x == game->fruit.x && head.y == game->fruit.y) {
        game->score++;
        game->snake.length++;
        spawnFruit(game); // Spawn a new fruit
    }
}

void draw(Game *game) {
    system("CLS");

    // Top border
    printf("+");
    for (int i = 0; i < WIDTH; i++) {
        printf("--");
    }
    printf("+\n");

    // Draw grid with snake and fruit
    for (int i = 0; i < HEIGHT; i++) {
        printf("|"); // Left border
        for (int j = 0; j < WIDTH; j++) {
            int isSnakePart = 0;

            // Check if it's the snake head or body
            for (int k = 0; k < game->snake.length; k++) {
                if (game->snake.body[k].x == j && game->snake.body[k].y == i) {
                    isSnakePart = 1;
                    if (k == 0) {
                        printf("<>"); // Snake head
                    } else {
                        printf("{}"); // Snake body
                    }
                    break;
                }
            }

            // Draw fruit if it's at the current position
            if (!isSnakePart) {
                if (game->fruit.x == j && game->fruit.y == i) {
                    printf(" 0"); // Fruit
                } else {
                    printf("  "); // Empty space
                }
            }
        }
        printf("|\n"); // Right border
    }

    // Bottom border
    printf("+");
    for (int i = 0; i < WIDTH; i++) {
        printf("--");
    }
    printf("+\n");

    printf("Score: %d\n", game->score);

    if (game->gameOver) {
        printf("Game Over! Final Score: %d\n", game->score);
    }
}

void handleInput(Game *game) {
    if (_kbhit()) {
        char key = _getch();
        if ((key == 'w' && game->snake.direction != 's') ||
            (key == 's' && game->snake.direction != 'w') ||
            (key == 'a' && game->snake.direction != 'd') ||
            (key == 'd' && game->snake.direction != 'a')) {
            game->snake.direction = key;
        }
    }
}

int main() {
    srand(time(0));
    Game game;
    initializeGame(&game);

    while (!game.gameOver) {
        handleInput(&game);
        moveSnake(&game);
        if (checkCollision(&game)) {
            game.gameOver = 1;
        }
        checkFruit(&game);
        draw(&game);
        Sleep(700); // Control game speed
    }

    return 0;
}
