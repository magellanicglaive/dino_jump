#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 50
#define HEIGHT 10

int dinoY = HEIGHT - 2, isJumping = 0, jumpHeight = 5;
int obstacleX = WIDTH - 1, score = 0;

void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw() {
    system("cls");
    gotoxy(5, dinoY); printf("dino");
    gotoxy(obstacleX, HEIGHT - 2); printf("|");
    gotoxy(0, HEIGHT); printf("Score: %d", score);
}

void update() {
    if (isJumping) {
        dinoY--;
        if (dinoY <= HEIGHT - 2 - jumpHeight) isJumping = 0;
    } else if (dinoY < HEIGHT - 2) {
        dinoY++;
    }

    obstacleX--;
    if (obstacleX < 0) {
        obstacleX = WIDTH - 1;
        score++;
    }
    if (obstacleX == 5 && dinoY == HEIGHT - 2) {
        gotoxy(10, HEIGHT / 2);
        printf("Game Over! Score: %d\n", score);
        getch();
        exit(0);
    }
}

int main() {
    while (1) {
        if (_kbhit() && _getch() == ' ' && dinoY == HEIGHT - 2) isJumping = 1;
        update();
        draw();
        Sleep(100);
    }
    return 0;
}