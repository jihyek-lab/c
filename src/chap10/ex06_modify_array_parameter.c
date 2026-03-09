#include <stdio.h>

#define SIZE 7

/*
핵심 포인트
1) 배열을 함수에 넘기면 원본 데이터가 수정될 수 있다.
2) 함수 파라미터 int a[]는 int *a와 동일하게 동작한다.
3) 원본 보호가 필요하면 복사본을 사용한다.
*/
void modify_array(int a[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        ++a[i];
    }
}

void print_array(const int a[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int list[SIZE] = {1, 2, 3, 4, 5, 6, 7};

    print_array(list, SIZE);
    modify_array(list, SIZE);
    print_array(list, SIZE);

    return 0;
}
