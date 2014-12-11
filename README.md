ANSI C Reference Card [<sup>*</sup>]
====================================

들어가기에 앞서
---------------

본 문서는 다음의 문서를 기반하여 만든 것을 명시합니다.

[원본 링크](http://www.digilife.be/quickreferences/qrc/c%20reference%20card%20%28ansi%29%202.2.pdf)

프로그램 구성 요소/함수
-----------------------

* main 함수

  ```c
  header
  
  int main() {
    declarations // main변수에서 local variable들의 선언
    statements
    return 0;
  }
  ```

* 함수의 구성

  ```c
  type function_name( argc1, ... ) { // 함수의 정의
    declarations // 해당 함수 내에서 사용할 local variable들의 선언
    statements
    
    return value; // type이 void일 경우 
  }
  ```

* 변수/배열 선언
  * 변수 선언
  ```
  type identifier; 
  ```
  * 배열 선언
  ```
  type identifier[size]; // size에는 배열의 크기를 나타내는 상수가 적혀야 함
  ```
  
C언어 전처리기(preprocessor)
----------------------------

* library 파일을 소스코드에 포함시키기

  ```c
  #include <header_name>
  ```
  
  * header_name의 예
    * stdio.h - standard input/output
    * stdlib.h - standard library
    * math.h - math library
    * string.h - string(문자열) library

* scanf/printf 사용시 `C4996` 오류를 해결 하는 방법

  ```c
  #pragma warning(disable:4996)
  ```
  
* `#define` 전처리기를 이용한 상수 정의
  * 문법
    
    ```c
    #define CONST_NAME const_value
    ```
    
  * 예
    
    ```c
    #define MAX_SIZE 50
    ```

자료형
------

* 정수형 변수
  * `char` - 1 byte (저장 범위: 절댓값 127이하)
  * `int` - 4 byte (저장 범위 : 절댓값 20억 이하)
* 실수형 변수
  * `double` - 8 byte
* 포인터형 변수
  * 선언법 - `type *identifier`

초기화
------

* 변수 초기화 - `type identifier = value;`
* 배열 초기화 - `type identifier[size] = {value1,...};`
  * size는 생략 가능
* 문자열 초기화 - `char identifer[] = "string";`
  * `char *identifier = "string"`도 가능하지만, 이 경우는 수정이 불가능함

상수의 예시
-----------

* 정수형 - `65536`
  * 8진수와 16진수 표현법 - `0475`, `0xFF` 
* 실수형 - `3.0`, `3.14f`, `1e-4`
* 문자 상수 - `'a'`, `'0'`, `'+'`, `' '`
* newline, tab, backspace, null character - `'\n'`, `'\t'`, `'\b'`, `'\0'`
* 문자열 상수 - `"abc...def"`
  * 뒤에 자동으로 `'\0'`가 추가됨

포인터와 배열, 구조체
---------------------

* 포인터 선언 - `type *identifier;`
* NULL 포인터 - `NULL`
* 포인터가 가리키는 변수의 간접 참조 - `*identifier`
* 변수의 주소 - `&identifier`
* 배열
  * 1차원 배열의 원소 접근법 - `identifier[index]`
  * 2차원 배열의 원소 접근법 - `identifier[index1][index2]`
* 구조체
  * 정의 방법
    
    ```c
      typedef struct {
        declarations
      } strcut_name;
    ```

  * 선언 방법
  
    ```
      struct_name idenitifer;
      struct_name identifier[size];
    ```
    
  * 멤버 사용법
  
    * `identifier.member_name`
    * `identifier[index].member_name` - 구조체 배열일 경우
    * `identifier.member_name[index]` - member가 배열일 경우

연산자
------

* 증감 연산자 - `++`, `--`
* 사칙 연산자 - `+`, `-`, `*`, `/`, `%`
  * `%`의 경우 정수형 변수, 상수에만 사용 가능
* 대입 연산자 - `=`
  * 다음과 같이 사칙연산자와 조합될 수 있음
  * `+=`, `-=`, `*=`
    * `a += b`는 `a = a+b`와 동일 
* 논리식 연산자
  * `&&` - and, 이항 연산자
  * `||` - or, 이항 연산자
  * `!` - not, 단항 연산자
* 관계 연산자
  * `==`, `!=`, `>`, `>=`, `<`, `<=`
  * **주의** - 순서를 바꿔 쓰면 문법상 맞지 않음
* `sizeof` - 변수, 자료형의 크기를 알아내는 연산자
  * 예 - `sizeof(int)`, `sizeof(3.5)`   
* `(type) expr` - 형변환 연산자
  * 예 - `(int)3.14` 

