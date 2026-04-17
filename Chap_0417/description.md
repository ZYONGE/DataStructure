# 자료구조 - 동적 메모리와 스택 구현 (04/17)

## 1. 포인터와 배열

- 배열은 선언 후 크기를 변경할 수 없지만, 포인터는 선언 후에도 다른 주소를 가리킬 수 있다.
- 포인터와 구조체를 통해 **동적 메모리 할당**이 가능하다.
- 모든 메모리에는 **고유한 주소**가 있다. 데이터 값은 중복될 수 있지만 주소는 중복될 수 없다.

### 논리적 주소 (가상 주소)

- MMU(Memory Management Unit)를 통해 물리적 주소가 아닌 **논리적(가상) 주소**를 사용한다.
- 프로그램은 실제 물리 주소에 직접 접근하지 않는다.
- 동적 메모리 할당은 **heap** 영역에서 이루어진다.

### 포인터 기본 문법

```c
int a = 10;
int* p = &a;   // a의 주소를 p에 저장
*p = 20;       // p가 가리키는 주소에 20 저장 (역참조)
```

| 연산자 | 의미 |
|--------|------|
| `&a`   | 변수 a의 주소를 가져옴 |
| `*p`   | 포인터 p가 가리키는 주소의 값을 가져옴 (역참조) |

### 이중 포인터

- 포인터의 주소를 저장하는 포인터.

```c
int** pp = &p;  // p(포인터)의 주소를 pp에 저장
```

---

## 2. 동적 메모리 할당

### malloc()

```c
#include <stdlib.h>

int* p = (int*)malloc(sizeof(int) * 10);  // int 10개 크기의 메모리 할당
free(p);   // 메모리 해제
p = NULL;  // 댕글링 포인터 방지
```

- 반드시 **캐스팅 연산자**로 원하는 자료형으로 변환해야 한다.
- 포인터로 선언하더라도 배열처럼 인덱스(`p[i]`)로 접근 가능하다.

### realloc()

```c
int* p = (int*)malloc(sizeof(int) * 10);
p = (int*)realloc(p, sizeof(int) * 20);  // 기존 메모리를 20칸으로 재할당
free(p);
p = NULL;
```

- 첫 번째 인자: 기존 할당된 메모리 주소
- 두 번째 인자: 변경할 새로운 크기
- 기존 데이터를 유지하면서 크기를 변경한다. 실패 시 `NULL` 반환.

---

## 3. 자체 참조 구조체

구조체 안에 **자기 자신 타입의 포인터**를 멤버로 갖는 구조체. 연결 리스트의 노드로 활용된다.

```c
typedef struct Node {
    int data;           // 데이터 필드
    struct Node* next;  // 링크 필드 (다음 노드 주소)
} Node;
```

---

## 4. 연결 구조 (Linked Structure)

- 데이터를 메모리의 **연속된 공간이 아닌** 여기저기에 분산하여 저장하고 포인터로 연결한다.
- **꼬리 노드**는 항상 `NULL`을 가리킨다.

| 종류 | 설명 |
|------|------|
| 단순 연결 노드 | 다음 노드만 가리키는 링크 1개 |
| 이중 연결 노드 | 이전/다음 노드를 모두 가리키는 링크 2개 (헤드의 이전은 NULL) |
| 원형 연결 | 꼬리 노드가 헤드 노드를 가리키는 구조 |

---

## 5. 스택 구현 비교

### 5-1. 동적 배열 스택 (`dynarraystack.h`)

배열 기반 스택에서 `realloc()`으로 용량을 자동 확장하는 방식.

```c
int MAX_SIZE = 100;
Element* data = NULL;
int top;

void init_stack() {
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
    top = -1;
}

void push(Element e) {
    if (is_full()) {
        MAX_SIZE *= 2;  // 가득 차면 크기 2배 확장
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE);
    }
    data[++top] = e;
}

Element pop() {
    if (is_empty()) error("Stack underflow");
    return data[top--];
}
```

- `top == -1` : 스택 비어있음
- `top == MAX_SIZE - 1` : 스택 가득 참 → `realloc()`으로 2배 확장
- 사용 후 반드시 `free(data)` 호출

### 5-2. 연결 스택 (`linkedstack.h`)

노드를 동적 할당하여 포인터로 연결하는 방식.

```c
typedef struct Node {
    Element data;
    struct Node *link;
} Node;

Node *top = NULL;
```

| 함수 | 설명 |
|------|------|
| `init_stack()` | `top = NULL` 로 초기화 (`-1`이 아닌 이유: `top`이 포인터이기 때문) |
| `is_empty()` | `top == NULL` 이면 true |
| `is_full()` | 항상 `0(false)` 반환 — 동적 할당이므로 가득 찰 수 없음 |
| `push(e)` | 새 노드 생성 후 `top` 앞에 삽입 |
| `pop()` | `top` 노드 데이터 반환 후 해제, `top`을 다음 노드로 이동 |
| `peek()` | `top->data` 반환 |
| `destroy_stack()` | `pop()`을 반복하여 모든 노드 해제 |
| `size()` | 노드를 순회하며 개수 반환 |
| `print_stack()` | top → tail 순서로 출력 (입력 역순) |
| `print_recur(p)` | 재귀로 tail → top 순서로 출력 (입력 순서) |

```c
void push(Element e) {
    Node *p = alloc_node(e);
    p->link = top;   // 새 노드가 기존 top을 가리킴
    top = p;         // top을 새 노드로 갱신
}

void pop() {
    if (is_empty()) error("Stack underflow");
    Node *p = top;
    top = top->link; // top을 다음 노드로 이동
    free_node(p);    // 이전 top 노드 메모리 해제
}
```

---

## 6. 두 스택 구현 비교 요약

| 항목 | 동적 배열 스택 | 연결 스택 |
|------|---------------|----------|
| 저장 방식 | 연속된 배열 | 분산된 노드 (포인터 연결) |
| 초기 `top` | `-1` | `NULL` |
| `is_full()` | 배열 꽉 차면 `true` → `realloc` | 항상 `false` |
| 오버헤드 | 배열 재할당 시 복사 비용 | 노드마다 포인터 추가 공간 |
| 메모리 해제 | `free(data)` 1회 | `pop()` 반복으로 노드별 해제 |

---

## 7. 소스코드 해설

### 7-1. 동적 배열 스택 (`dynarraystack.h` / `dynarraystack.c`)

#### 작동 원리

`Element* data`는 힙(heap)에 할당된 배열의 시작 주소를 가리키는 포인터다. `top`은 현재 스택의 맨 위 인덱스를 나타내는 정수값으로, `-1`이면 스택이 비어있음을 의미한다.

```
초기 상태:  top = -1,  data → [ _ ][ _ ][ _ ]...[ _ ]  (MAX_SIZE개)
push(10):  top = 0,   data → [10][ _ ][ _ ]...[ _ ]
push(20):  top = 1,   data → [10][20][ _ ]...[ _ ]
pop():     top = 0,   20 반환
```

`push()`에서 스택이 가득 차면 `MAX_SIZE *= 2` 후 `realloc()`으로 힙 메모리를 2배로 확장한다. 기존 데이터는 그대로 유지된다.

#### 포인터 사용 방법

| 위치 | 포인터 사용 | 설명 |
|------|------------|------|
| `Element* data` | 힙 배열을 가리키는 포인터 | `malloc`/`realloc`으로 할당된 주소 저장 |
| `data[++top] = e` | 포인터를 배열처럼 인덱스 접근 | `*(data + top) = e`와 동일 |
| `realloc(data, ...)` | 포인터를 인자로 전달 | 기존 메모리 블록의 크기를 변경 |
| `free(data)` | 포인터가 가리키는 힙 해제 | 반드시 `main`에서 직접 호출 |

#### 유의사항

- `dynarraystack.c`의 `main()`에서 `MAX_SIZE = 8`로 작게 설정한 뒤 50개를 push하므로, `realloc()`이 `8 → 16 → 32 → 64 → 128` 순으로 총 4회 자동 실행된다.
- `realloc()` 실패 시 `NULL`을 반환하고 기존 포인터는 유효하지만, 이 코드는 실패를 검사하지 않아 교육용 단순화 코드임에 주의한다.
- `realloc()`의 반환값을 **동일 포인터 변수에 바로 대입**하면 실패 시 원래 주소를 잃는다. 실제 프로덕션 코드에서는 임시 변수로 받아야 한다.

---

### 7-2. 연결 스택 (`linkedstack.h` / `linkedstack.c`)

#### 작동 원리

각 노드가 힙에 독립적으로 할당되고, `link` 포인터로 다음 노드를 연결한다. `top`은 맨 위 노드의 주소를 저장하는 포인터이며, 빈 스택은 `top == NULL`로 판별한다.

```
push(1) → push(2) → push(3) 후 상태:

top → [3|link] → [2|link] → [1|NULL]
```

`pop()`은 `top`이 가리키는 노드의 주소를 임시 저장 후, `top = top->link`로 한 칸 내려가고, 임시 저장한 주소를 `free()`한다.

```c
Node *p = top;       // 현재 top 주소 임시 저장
top = top->link;     // top을 다음 노드로 이동
free_node(p);        // 임시 저장한 이전 top 해제
```

`free()` 전에 `top->link`를 미리 읽어둬야 한다. `free()` 이후에 `p->link`를 읽으면 **해제된 메모리 접근(dangling pointer 역참조)** 이 된다.

#### `print_recur()`의 재귀 역순 출력

```c
void print_recur(Node *p) {
    if (p != NULL) {
        print_recur(p->link);  // 먼저 끝까지 재귀 진입
        printf("%3d ", p->data); // 돌아오는 길에 출력
    }
}
```

스택에 1→2→3 순서로 push하면 연결 구조는 `top(3)→2→1→NULL`이다. `print_recur(top)`을 호출하면 재귀가 `NULL`까지 내려갔다가 복귀하면서 `1, 2, 3` 순(입력 순서)으로 출력한다.

#### 포인터 사용 방법

| 위치 | 포인터 사용 | 설명 |
|------|------------|------|
| `Node *top` | 스택의 최상단 노드 주소 | `NULL`이면 빈 스택 |
| `struct Node *link` | 자체 참조 포인터 | 다음 노드의 힙 주소 저장 |
| `p->data`, `p->link` | 화살표 연산자(`->`) | `(*p).data`와 동일, 포인터 역참조 후 멤버 접근 |
| `alloc_node()` 반환값 | 새로 할당된 노드 주소 | `malloc()` 결과를 캐스팅하여 반환 |

#### 유의사항

- `linkedstack.c`의 `pop()`은 반환값이 `void`다. 값을 꺼내려면 반드시 `peek()` 후 `pop()`을 따로 호출해야 한다. `dynarraystack.h`의 `pop()`이 값을 반환하는 것과 다른 설계임에 주의한다.
- `destroy_stack()`은 `while(!is_empty()) pop()`으로 모든 노드를 하나씩 해제한다. `linkedstack.c`의 `main()`에서는 루프가 끝난 시점에 스택이 비어있으므로 별도 호출이 없어도 메모리 누수가 없지만, 중간에 프로그램을 종료할 경우에는 반드시 호출해야 한다.

---

### 7-3. 원형 연결 큐 (`cirlinkedqueue.h` / `cirlinkedqueue.c`)

#### 작동 원리

`rear` 포인터 하나만으로 **front(앞)** 와 **rear(뒤)** 를 모두 관리한다. 꼬리 노드(`rear`)의 `link`가 머리 노드(front)를 가리키는 원형 구조를 유지한다.

```
enqueue(0) ~ enqueue(6) 후 상태:

rear → [6] → [0] → [1] → [2] → [3] → [4] → [5] → (rear로 순환)
               ↑ front = rear->link
```

- **front 접근**: `rear->link` (rear의 다음이 항상 front)
- **enqueue**: 새 노드를 `rear`와 `front` 사이에 삽입하고 `rear`를 새 노드로 갱신
- **dequeue**: `rear->link`(front)를 제거하고 `rear->link`를 다음 노드로 갱신

#### `enqueue()` 상세

```c
void enqueue(Element e) {
    Node *p = alloc_node(e);
    if (is_empty()) {
        rear = p;
        rear->link = rear;   // 노드 1개: 자기 자신을 가리키는 자기 참조
    } else {
        p->link = rear->link;  // 새 노드 → 기존 front
        rear->link = p;        // rear → 새 노드 (새 노드가 rear 바로 다음)
        rear = p;              // rear 갱신 (새 노드가 새 rear)
    }
}
```

#### `dequeue()` 상세

```c
Element dequeue() {
    Node *p = rear->link;      // p = front 노드
    Element e = p->data;
    if (rear == rear->link) {  // 노드가 1개뿐인 경우
        rear = NULL;
    } else {
        rear->link = p->link;  // rear가 front의 다음 노드를 가리키게 함
    }
    free_node(p);
    return e;
}
```

노드가 1개일 때 `rear == rear->link`(자기 자신)이므로 반드시 별도로 처리해야 한다. 이를 빠뜨리면 해제된 메모리를 `rear->link`로 접근하는 버그가 발생한다.

#### `size()` 순환 종료 조건

```c
int size() {
    if (is_empty()) return 0;
    int count = 1;
    for (Node *p = rear->link; p != rear; p = p->link) {
        count++;
    }
    return count;
}
```

원형 구조이므로 `p != NULL`로는 종료할 수 없다. `rear->link`(front)에서 시작하여 `p == rear`가 될 때 루프를 종료하고, `rear` 자신은 초기 `count = 1`로 미리 세어둔다.

#### 포인터 사용 방법

| 위치 | 포인터 사용 | 설명 |
|------|------------|------|
| `Node* rear` | 마지막 노드 주소 | `NULL`이면 빈 큐 |
| `rear->link` | front 노드 접근 | 별도 front 포인터 없이 rear 하나로 관리 |
| `rear->link = rear` | 자기 자신을 가리키는 포인터 | 노드가 1개일 때의 원형 구조 |

#### 유의사항

- `print_recur()`는 `p != NULL`을 종료 조건으로 사용하는데, 원형 연결 큐에서는 `NULL`에 도달하지 않으므로 **무한 루프**가 발생한다. 원형 구조에서 재귀 순회가 필요하다면 시작 노드 주소를 별도로 전달하여 종료 조건으로 삼아야 한다.
- `cirlinkedqueue.c`의 `main()`에서 `destroy_queue()`를 호출하지 않아 프로그램 종료 시 힙 메모리가 해제되지 않는다(OS가 회수하지만 명시적 해제 습관이 중요하다).

---

## 8. 자료구조와 포인터 사용의 공통 유의사항

| 항목 | 내용 |
|------|------|
| **댕글링 포인터** | `free()` 후 반드시 포인터에 `NULL` 대입. 해제된 주소를 역참조하면 미정의 동작(UB) |
| **메모리 누수** | `malloc`/`realloc`으로 할당한 메모리는 반드시 `free()` 호출. 연결 구조는 노드를 하나씩 순회하며 해제 |
| **NULL 반환 검사** | `malloc`, `realloc` 실패 시 `NULL` 반환. 프로덕션 코드에서는 반환값 검사 필수 |
| **원형 구조 순회** | 종료 조건을 `NULL`이 아닌 **시작 노드와의 동일 여부**(`p == rear` 등)로 설정 |
| **`free()` 순서** | 포인터의 `link`를 읽기 전에 `free()` 금지. 반드시 다음 주소를 먼저 저장 후 해제 |
| **`realloc` 대입** | `p = realloc(p, ...)` 형태는 실패 시 기존 주소 손실. 임시 변수에 받아서 검사 후 대입 |

