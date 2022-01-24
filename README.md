# Classial Tetris
= Classic + Special Tetris

[Code](https://github.com/bbx8216/Tetris/blob/main/Code_ClassialTetris.c) | [Presentation](https://github.com/bbx8216/Tetris/blob/main/Presentation_ClassialTetris.pptx) 

2021-1 Basic C Programming   
기존 테트리스 코드는 특정 키(스페이스바)를 눌렸을 때 블록이 회전되고 이 회전시킨 블록을 차례차례 쌓고 제거되게 하는 형식이다.



변형 Point
---
1. "하늘에서 음식이 떨어진다면"을 가정했을 때 자유낙하하는 음식은 보통회전을 하며 떨어지게 됩니다.   
**'떨어질 때는 회전'** 에서 아이디어를 얻어 테트리스의 블럭이 특정 키를 눌렸을 때 회전하는 것이 아닌, 계속 회전을 하며 떨어지다가 특정 키를 눌렸을 때 회전이 멈추게하는 테트리스를 고안하게 되었습니다.

2. "적란운 속 우박의 형성과정"을 생각해보면 얼음 결정이 적란운의 하부쪽에 이르렀을 땐 결정에 붙은 다른 입자들로 인해 부피가 커지게 됩니다.   
**'하강할수록 부피는 증가'** 에서 아이디어를 얻어 테트리스의 몇몇 블록들은 블록이 하강할때마다 (시간이 증가될때마다) 크기가 커지고, 처음으로 돌아가고를 반복하게 하였고 특정 키를 눌렸을 때 크기가 고정되는 테트리스를 고안하게 되었습니다.

3. '꾸미기'가 유행이었기에, 우리도 **"테트리스의 블록의 디자인을 플레이어가 선택할 수 있도록 하자"** 라 생각했고 블록의 디자인 4개를 선정해 게임 시작 창에서 선택할 수 있도록 하였습니다.



Original Code
---
(원본으로 사용한 코드입니다.)
https://hoil2.tistory.com/19
