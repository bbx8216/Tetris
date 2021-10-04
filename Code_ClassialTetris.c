#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h> 
#include<stdbool.h> //bool 자료형을 쓰기위해 c 에서 추가해줘야하는 라이브러리

clock_t startDropT, endT, startGroundT;
int x = 8, y = 0;
RECT blockSize;
int blockForm;
int blockRotation = 0;
int key;
int score = 0;
int box;

//블록 정의
int block[10][4][4][6] = {
   { // T모양 블럭
      {
         {0,0,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {0,1,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {1,1,0,0,0,0},
         {0,0,0,0,0,0}
      }
   },
   { // T모양 블럭
      {
         {0,1,0,0,0,0},
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,0,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0}
      }
   },
   { // T모양 블럭
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {1,0,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {1,1,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {1,1,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {1,1,1,1,0,0},
         {0,0,0,0,0,0}
      }
   },
   { // T모양 블럭
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {1,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {1,1,0,0,0,0},
         {1,1,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {1,1,1,0,0,0},
         {1,1,1,0,0,0},
         {1,1,1,0,0,0}
      },
      {
         {1,1,1,1,0,0},
         {1,1,1,1,0,0},
         {1,1,1,1,0,0},
         {1,1,1,1,0,0}
      }
   },
   {    // 번개 블럭
      {
         {0,0,0,0,0,0},
         {0,1,1,0,0,0},
         {1,1,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {1,0,0,0,0,0},
         {1,1,0,0,0,0},
         {0,1,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,1,1,0,0,0},
         {1,1,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {1,0,0,0,0,0},
         {1,1,0,0,0,0},
         {0,1,0,0,0,0}
      }
   },
   {   // 번개 블럭 반대
      {
         {0,0,0,0,0,0},
         {1,1,0,0,0,0},
         {0,1,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,1,0,0,0,0},
         {1,1,0,0,0,0},
         {1,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {1,1,0,0,0,0},
         {0,1,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,1,0,0,0,0},
         {1,1,0,0,0,0},
         {1,0,0,0,0,0}
      }
   },
   {   // 1자형 블럭
      {
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {1,1,1,1,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,0,0,0,0,0},
         {1,1,1,1,0,0},
         {0,0,0,0,0,0}
      }
   },
   {   // L자형 블럭
      {
         {0,0,0,0,0,0},
         {1,0,0,0,0,0},
         {1,1,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {1,1,0,0,0,0},
         {1,0,0,0,0,0},
         {1,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {1,1,1,0,0,0},
         {0,0,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,1,0,0,0,0},
         {0,1,0,0,0,0},
         {1,1,0,0,0,0},
         {0,0,0,0,0,0}
      }
   },
   {   // L자형 블럭 반대
      {
         {0,0,0,0,0,0},
         {0,0,1,0,0,0},
         {1,1,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {1,0,0,0,0,0},
         {1,0,0,0,0,0},
         {1,1,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {1,1,1,0,0,0},
         {1,0,0,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {1,1,0,0,0,0},
         {0,1,0,0,0,0},
         {0,1,0,0,0,0}
      }
   },
   {   // 네모 블럭
      {
         {0,0,0,0,0,0},
         {0,1,1,0,0,0},
         {0,1,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,1,1,0,0,0},
         {0,1,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,1,1,0,0,0},
         {0,1,1,0,0,0},
         {0,0,0,0,0,0}
      },
      {
         {0,0,0,0,0,0},
         {0,1,1,0,0,0},
         {0,1,1,0,0,0},
         {0,0,0,0,0,0}
      }
   }
};

space[21][14] = {  // 세로 20+1(아래벽)칸, 가로 12+2(양쪽 벽)칸  
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


void Init();
void gotoxy(int x, int y);
void CreateRandomForm();
bool CheckCrash(int x, int y);
void RotateAndDropBlock();
void BlockToGround();
void RemoveLine();
void DrawMap();
void DrawBlock();
void InputKey();
void title0();
void title1();
void check_game_over();


int main() {
    Init();
    title0();
    title1();
    startDropT = clock();
    CreateRandomForm();

    while (true) {
        DrawMap();
        DrawBlock();
        RotateAndDropBlock();
        //커서 제거함수
        BlockToGround();
        RemoveLine();
        InputKey();
        check_game_over();
    }
    return 0;
}

void Init() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = 0;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    srand(time(NULL));
}

//커서 이동함수
void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//블록 랜덤으로 바뀌게 함.
void CreateRandomForm() {
    blockForm = rand() % 10;
}

//블록을 계속 회전하게 함

//충돌 체크하는 함수
bool CheckCrash(int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (block[blockForm][blockRotation][i][j] == 1) {
                int t = space[i + y][j + x / 2];
                if (t == 1 || t == 2) { // 벽일 때, 블럭일 때
                    return true;
                }
            }
        }
    }
    return false;
}

//블록 떨어트리는 함수인데...
int flag = 0;
void RotateAndDropBlock() {

    endT = clock();//main함수 실행되고 있었던 시간 측정
    if ((float)(endT - startDropT) >= 200) {
        if (CheckCrash(x, y + 1) == true) return;
        y++;
        if (key == 32) {
            flag = 1;
        }
        if (flag == 0) {
            blockRotation++;
            if (blockRotation >= 4)blockRotation = 0;
        }

        startDropT = clock();
        startGroundT = clock();
        system("cls");
    }
}

//블록이 땅에 닿았을 때 동작하지 않는 경우 땅으로 변하게 하는 함수
void BlockToGround() {
    if (CheckCrash(x, y + 1) == true) {
        if ((float)(endT - startGroundT) > 1500) {
            // 현재 블록 저장
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (block[blockForm][blockRotation][i][j] == 1) {
                        space[i + y][j + x / 2] = 2;
                    }
                }
            }
            x = 8;
            y = 0;
            flag = 0;
            CreateRandomForm();//그러고 다시 블록 생성
        }
    }
}

//라인 제거, 이 함수랑 동일한데 범위가 다르게 만들어서 하면 되지 않을까?
void RemoveLine() {
    for (int i = 20; i >= 0; i--) { // 벽라인 제외한 값
        int cnt = 0;
        for (int j = 1; j < 11; j++) { // 
            if (space[i][j] == 2) {
                cnt++;
            }
        }
        if (cnt >= 10) { // 벽돌이 다 차있다면
            score += 12;
            for (int j = 0; i - j >= 0; j++) {
                for (int x = 1; x < 11; x++) {
                    if (i - j - 1 >= 0)
                        space[i - j][x] = space[i - j - 1][x];
                    else      // 천장이면 0저장
                        space[i - j][x] = 0;
                }
            }
        }
    }
}

//맵 그리기
void DrawMap() {
    gotoxy(0, 0);
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 14; j++) {
            if (space[i][j] == 1) {
                gotoxy(j * 2, i);
                printf("□");
            }
            else if (space[i][j] == 2) {
                gotoxy(j * 2, i);
                printf("%s", box);
            }
        }
    }
}

//블록 그리는 함수
void DrawBlock() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (block[blockForm][blockRotation][i][j] == 1) {
                gotoxy(x + j * 2, y + i);
                printf("%s", box);
            }
        }
    }
}

//_kbhit는 입력 감지, _getch는 입력 받기
void InputKey() {
    if (_kbhit()) {
        key = _getch();
        switch (key) {

        case 75: // left
            if (CheckCrash(x - 2, y) == false) {
                x -= 2;
                startGroundT = clock();
            }
            break;
        case 77: // right
            if (CheckCrash(x + 2, y) == false) {
                x += 2;
                startGroundT = clock();
            }
            break;
        case 80: // down
            if (CheckCrash(x, y + 1) == false)
                y++;
            break;
        }
        system("cls");
    }
}

void title0() {
    int x = 5; //타이틀화면이 표시되는 x좌표 
    int y = 4; //타이틀화면이 표시되는 y좌표 
    int cnt; //타이틀 프레임을 세는 변수  



    gotoxy(x + 5, y + 0); printf("▤▤▤▤▤      ▥▥▥▥      ▨▨▨▨▨       ▧▧▧▧       ▧▧▧       ▥▥▥▥ "); Sleep(100);
    gotoxy(x + 5, y + 1); printf("    ▤          ▥                ▨           ▧     ▧        ▧        ▥        "); Sleep(100);
    gotoxy(x + 5, y + 2); printf("    ▤          ▥▥▥▥          ▨           ▨▨▨▧         ▧          ▥▥▥  "); Sleep(100);
    gotoxy(x + 5, y + 3); printf("    ▤          ▥                ▧           ▧    ▧         ▧               ▥ "); Sleep(100);
    gotoxy(x + 5, y + 4); printf("    ▤          ▥▥▥▥          ▨           ▧     ▧      ▧▧▧      ▥▥▥▥  "); Sleep(100);
    gotoxy(x + 5, y + 10); printf("◁  ▷ : Left / Right");
    gotoxy(x + 5, y + 11); printf("  ▽   : Soft Drop");
    gotoxy(x + 35, y + 10); printf("[  Space Bar  ] : Block State Fix ");
    gotoxy(x + 30, y + 15); printf("Please Enter Key to Start..");



    for (cnt = 0;; cnt++) { //cnt를 1씩 증가시키면서 계속 반복  효과 
        if (_kbhit())
        {
            while (1)
            {
                if (_kbhit()) // 특정키가 눌리면... 
                {
                    if (_getch())  // 눌린키가 z 이면 스탑. 
                        break;
                }
                // 문한반복에서 하려는 작업 
            }
            break;
        }
    }
}

void title1() {
    int x = 5; //타이틀화면이 표시되는 x좌표 
    int y = 4; //타이틀화면이 표시되는 y좌표 


    gotoxy(x + 5, y + 0); printf("▤▤▤▤         ▥▥▥▥         ▨▨▨▨         ▧▧▧▧                                         "); Sleep(100);
    gotoxy(x + 5, y + 1); printf("▤▤▤▤         ▥▥▥▥         ▨▨▨▨         ▧▧▧▧                                         "); Sleep(100);
    gotoxy(x + 5, y + 2); printf("▤▤▤▤         ▥▥▥▥         ▨▨▨▨         ▧▧▧▧                                         "); Sleep(100);
    gotoxy(x + 5, y + 3); printf("▤▤▤▤         ▥▥▥▥         ▨▨▨▨         ▧▧▧▧                                         "); Sleep(100);
    gotoxy(x + 5, y + 7); printf("<  △  >        <   ◁  >         <   ▷  >        <  ▽  >                                          "); Sleep(100);
    gotoxy(x + 5, y + 4); printf("                                                                                                     "); Sleep(100);
    gotoxy(x + 5, y + 8); printf("                                                                                                     "); Sleep(100);
    gotoxy(x + 5, y + 10); printf("                                                                                                     "); Sleep(100);
    gotoxy(x + 5, y + 11); printf("                                                                                                     "); Sleep(100);
    gotoxy(x + 30, y + 15); printf("Please Enter Key to Start..");


    while (1) {
        if (_kbhit()) {        //키보드 입력 확인 (true / false)
            int c = _getch();      // 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
            if (c == 224) {    // -32로 입력되면
                c = _getch();  // 새로 입력값을 판별하여 상하좌우 출력
                switch (c) {
                case 72:
                    box = "▤";
                    break;
                case 75:
                    box = "▥";
                    break;
                case 77:
                    box = "▨";
                    break;
                case 80:
                    box = "▧";
                    break;
                }
                break;
            }
        }
    }
}

void check_game_over(void) {
    int i;

    int x = 5;
    int y = 5;

    for (i = 1; i < 13; i++) {
        if (space[1][i] > 0) { //천장(위에서 세번째 줄)에 inactive가 생성되면 게임 오버 
            gotoxy(x, y + 0); printf("★★★★★★★★★★★★★★★★★"); //게임오버 메세지 
            gotoxy(x, y + 1); printf("★                              ★");
            gotoxy(x, y + 2); printf("★                              ★");
            gotoxy(x, y + 3); printf("★                              ★");
            gotoxy(x, y + 4); printf("★  +-----------------------+   ★");
            gotoxy(x, y + 5); printf("★  |   G A M E  O V E R..  |   ★");
            gotoxy(x, y + 6); printf("★  +-----------------------+   ★");
            gotoxy(x, y + 7); printf("★                              ★");
            gotoxy(x, y + 8); printf("★                              ★");
            gotoxy(x, y + 9); printf("★                              ★");
            gotoxy(x, y + 10); printf("★★★★★★★★★★★★★★★★★");


            Sleep(1000);
            while (1)
            {
                if (_kbhit()) // 특정키가 눌리면... 
                {
                    if (_getch())
                        break;
                }
                system("cls");
                break;
            }
            return 0;

        }
    }
}