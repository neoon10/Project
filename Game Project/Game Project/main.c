#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

#define HALL_LINES 25
#define MAG_LINES 3

const char* hall[] = {
    "+=================================================================================================================+",
    "|                                             +--------------------------+        +---------+     +-------+       |",
    "|                                             |                          |        |   < >   |     |  __   |       |",
    "|                                             |                          |        |   < >   |     | |  |  |       |",
    "|       +---------------------+               |                          |        +---------+     +-------+       |",
    "|       |  )               /  |               |                          |                +-------+               |",
    "|       |--               /   |               |                          |                |       |               |",
    "|       |________________/    |               |                          |                |   _   |               |",
    "|       |               /     |               |                          |                |  ( )  |               |",
    "|       +---------------------+               |                          |                | |   | |               |",
    "|                                             |                          |                +-------+               |",
    "|                                             |                          |                                        |",
    "|                                             |                    [ ]   |                                        |",
    "|                                             |                          |                                        |",
    "|                                             |                          |                                        |",
    "|     +--------------------+                  |                          |                                        |",
    "|     | []    []      []   |                  |                          |                                        |",
    "|     | []    []      []   |                  |                          |                                        |",
    "|     | []    []      []   |                  |                          |                                        |",
    "|     |--------------------|                  |                          |                                        |",
    "|     |    []      []      |                  |                          |                                        |",
    "|     |    []      []      |                  |                          |                                        |",
    "|     |    []      []      |                  |                          |                                        |",
    "|     +--------------------+                  +--------------------------+                                        |",
    "+=================================================================================================================+"
};

const char* mag[] = {
    " _ ",
    "( )",
    " | "
};

void draw_screen(int mag_x, int mag_y) {
    system("cls");
   
    for (int y = 0; y < HALL_LINES; y++) {
        char line[200];              // 한 줄 버퍼 
        strcpy(line, hall[y]);       // 기본 복도 한 줄 복사

        // 이 줄이 돋보기의 세로 범위 안인지 확인
        if (y >= mag_y && y < mag_y + MAG_LINES) {
            int ly = y - mag_y;      // 돋보기 내부 y 인덱스

            int mag_len = (int)strlen(mag[ly]);
            int line_len = (int)strlen(line);

            for (int x = 0; x < mag_len; x++) {
                if (mag[ly][x] == ' ') continue; // 공백은 안 덮어씀

                int gx = mag_x + x; // 전체 줄 기준 x 좌표

                if (gx >= 0 && gx < line_len) {
                    line[gx] = mag[ly][x];
                }
            }
        }

        printf("%s\n", line);
    }
}

int main(void) {
    int mag_x = 55;  // 시작 x 위치
    int mag_y = 10;   // 시작 y 위치

    while (1) {
        draw_screen(mag_x, mag_y);
        Sleep(80);

        if (_kbhit()) {
            char c = _getch();
            if (c == 'q' || c == 'Q') break;

            if (c == 'w' || c == 'W') mag_y--;
            if (c == 's' || c == 'S') mag_y++;
            if (c == 'a' || c == 'A') mag_x--;
            if (c == 'd' || c == 'D') mag_x++;
        }
    }

    return 0;
}
