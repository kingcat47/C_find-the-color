#include <stdio.h>
#include <stdlib.h>

char grid(x,y){
    int color = grid[x][y];
    switch (color){
        case 0: return "빨강";break;
        case 1: return "파랑";break;
        default: return "노랑";break;
    }
}

int main() {
    int n, m;  // 배열의 크기를 위한 변수
    int color_count[3];  // 각 색상의 채울 개수를 저장하는 배열
    int x, y;  // 알고 싶은 좌표의 변수
    int color_index = 0;  // 현재 색상을 가리키는 인덱스 (0: 빨강, 1: 파랑, 2: 노랑)
    int fill_count = 0;  // 현재 색상으로 몇 개의 셀을 채웠는지 추적하는 변수

    // 배열 크기 입력
    printf("배열의 크기를 입력하세요 (n m): ");
    scanf("%d %d", &n, &m);

    // n x m 크기의 2차원 배열 선언
    int** grid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grid[i] = (int*)malloc(m * sizeof(int));  // 각 칸에 숫자 저장 (0: 빨강, 1: 파랑, 2: 노랑)
    }

    // 빨강, 파랑, 노랑에 대응되는 숫자 입력
    printf("빨강, 파랑, 노랑에 대응되는 숫자를 입력하세요 (r b y): ");
    scanf("%d %d %d", &color_count[0], &color_count[1], &color_count[2]);

    // 배열을 순서대로 채우기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = color_index;  // 색상 인덱스 저장 (0: 빨강, 1: 파랑, 2: 노랑)

            // 채운 셀의 개수를 증가시킴
            fill_count++;

            // 현재 색상으로 지정된 개수만큼 채웠으면 다음 색상으로 바꿈
            if (fill_count == color_count[color_index]) {
                color_index = (color_index + 1) % 3;  // 다음 색상으로 전환 (0 -> 1 -> 2 -> 0)
                fill_count = 0;  // 채운 개수 초기화
            }
        }
    }

    // 배열 출력 (디버깅용)
    printf("\n배열 출력:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", grid[i][j]);  // 숫자 출력 (0: 빨강, 1: 파랑, 2: 노랑)
        }
        printf("\n");
    }

    // 알고 싶은 좌표 입력
    printf("알고 싶은 좌표를 입력하세요 (x y): ");
    scanf("%d %d", &x, &y);

    // 좌표 값 출력
    if (x >= 0 && x < n && y >= 0 && y < m) {
        printf("좌표 (%d, %d)에 있는 값: %s\n", x, y, grid(int x,y));
    } else {
        printf("잘못된 좌표입니다.\n");
    }

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        free(grid[i]);  // 각 행의 메모리 해제
    }
    free(grid);  // 전체 배열 메모리 해제

    return 0;
}
