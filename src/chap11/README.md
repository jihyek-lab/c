# chap11 포인터 응용 실습

`ex01 ~ ex06` 흐름을 바탕으로, 바로 실습할 수 있는 구현문제와 응용문제를 정리했습니다.
배열/포인터/출력 매개변수/배열 조작이 자연스럽게 이어지도록 구성했습니다.

## 실습 순서
1. `practice01_swap_and_sum.c`
2. `practice02_reverse_array.c`
3. `practice03_find_min_max.c`
4. `practice04_sum_and_average.c`
5. `practice05_sensor_data.c`
6. `practice06_rotate_right.c`
7. `practice07_sort_and_rank.c`
8. `practice08_unique_values.c`
9. `practice09_mode_value.c`
10. `practice10_second_largest.c`
11. `practice11_longest_run.c`
12. `practice12_rotate_right_k.c`
13. `practice13_max_subarray_sum.c`
14. `practice14_rank_without_sort.c`
15. `practice15_symmetric_array.c`
16. `practice16_row_col_sum.c`

## 컴파일 예시
```bash
cc src/chap11/practice01_swap_and_sum.c -o /tmp/p01 && /tmp/p01
cc src/chap11/practice03_find_min_max.c -o /tmp/p03 && /tmp/p03
cc src/chap11/practice06_rotate_right.c -o /tmp/p06 && /tmp/p06
cc src/chap11/practice07_sort_and_rank.c -o /tmp/p07 && /tmp/p07
cc src/chap11/practice14_rank_without_sort.c -o /tmp/p14 && /tmp/p14
```

## 학습 포인트
- 주소 전달로 원본 데이터 바꾸기
- 배열을 함수에 전달해 직접 수정하기
- 출력 매개변수(out parameter) 사용하기
- `const` 배열 매개변수의 의미 이해하기
- 포인터를 이용해 여러 결과를 돌려주기
- 정렬을 이용해 데이터를 순위 형태로 재구성하기
- 배열 순회와 조건 비교를 이용한 알고리즘 문제 풀기
- 2차원 배열의 행/열 단위 계산하기
