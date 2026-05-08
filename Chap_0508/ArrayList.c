#include "ArrayList.h"

int main(void) {
    
    // 1. 리스트를 빈 상태로 초기화
    init_list();

    // 2. 리스트에 순서대로 데이터 삽입
    insert(0, 1);
    insert(1, 2);
    insert(2, 3);
    insert(3, 4);
    insert(4, 5);
    insert(5, 6);
    insert(6, 7);
    insert(7, 8);
    insert(8, 9);
    insert(size, 10); // 현재 size 위치, 즉 맨 끝에 10 삽입
    insert(10, 11);   // 10번 인덱스에 11 삽입
    print_list("ArrayList: ");

    // 3. 리스트 데이터 삭제 테스트
    // [오류 수정] 헤더에 정의된 함수 이름은 delete_entry() 입니다. (delete() 사용 불가)
    delete_entry(2);         // 위치 2의 데이터(기존의 3) 삭제
    delete_entry(size - 1);  // 맨 마지막 요소 삭제
    delete_entry(0);         // 맨 앞의 요소(기존의 1) 삭제
    print_list("ArrayList: ");

    return 0;
}
