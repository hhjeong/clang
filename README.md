Code blocks 사용 팁
===================

유용한 단축키
-------------

* `F8` - 디버그 모드로 진입 및 실행, 다음의 `break point`까지 실행
* `F9` - 컴파일 후 전체 실행 (`break point` 무시됨)
* `F5` - `break point` 활성/비활성
* `F7` - 한 단계씩 실행
* `shift+F8` - 디버그 종료

프로젝트 만들기
---------------
1. `File > New > Project` 선택
2. `Console application` 선택 후 `Go` 클릭
3. 다음에 전환된 창에서 `next`선택
4. `C`선택 후 `next`클릭, 만약 `sort`를 사용하고 싶을 경우 `C++` 선택
5. `Project title`에는 적당한 이름을 적고, 만약 `Resulting filename`이 제대로 안보이면 `...`버튼을 눌러 설정
6. `Finish`선택

ANSI C Reference Card
=====================

약어
----

* `statements` - 0개이상의 연속된 문장(`statement`)의 사용
* `declarations` - 0개 이상의 연속된 변수 선언
* `type` - 자료형
* `identifier` - 변수나 함수 따위의 이름
* 함수 사용 관련
  * `c` - `char`형의 문자 상수, 변수
  * `s` - `char []` 혹은 `char *` 형의 문자열 상수, 변수
  * `x` - `int`혹은 `double`형의 변수

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

포인터와 배열
-------------

* 포인터 선언 - `type *identifier;`
* NULL 포인터 - `NULL`
* 포인터가 가리키는 변수의 간접 참조 - `*identifier`
* 변수의 주소 - `&identifier`
* 배열
  * 1차원 배열의 원소 접근법 - `identifier[index]`
  * 2차원 배열의 원소 접근법 - `identifier[index1][index2]`

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

흐름 제어
---------

* 문장의 끝 - `;`
* 블록 - `{ ... }`
* 반복문 탈출 명령 - `break;`
* 뒤의 문장들을 무시하고 반복문 수행 - `continue;`
* 값 반환 - `return expr;`

### 흐름 제어를 위한 문법

* `if`문

  ```c
  if( expr1 )
  {
    statements1
  }
  else if( expr2 )
  {
    statements2
  }
  else 
  {
    statements3
  }
  ```

* `while` 문

  ```
    while(expr)
    {
      statements
    }
  ```
  
* `for` 문

  ```
    for( expr1 ; expr2 ; expr3 ) 
    {
      statements
    }
  ```
  
  * expr2의 조건이 참이 되어야 아래 statements가 실행
  * expr1에는 일반적으로 반복문을 위한 변수의 초기화에 대한 수식
  * expr3에는 일반적으로 반복문을 위한 변수의 증감에 대한 수식
  * expr1, expr2, expr3 모두 생략 가능
  
* `swtich` 문
  
  ```c
  switch(expr) 
  {
    case const1:
      statements1;
      break;
    case const2:
      statements2;
      break;
    default:
      statements;
  }
  ```
  
기본 라이브러리
---------------

* `<ctype.h>`
  * 영문자인가? - `isalpha(c)`
  * 숫자인가? - `isdigit(c)`
  * 대소문자인가? - `islower(c)`, `isupper(c)`
  * 공백문자인가? - `isspace(c)`
  * 알파벳, 영문자인가? - `isalnum(c)`
  * 공백, 영문자, 숫자를 제외한 문자인가? - `ispunct(c)`
  * 대소문자로 변환하기 - `tolower(c)`, `toupper(c)`
* `<string.h>`

  `s`는 문자열 `cs`, `ct`는 문자열 상수
  
  *  문자열의 길이 - `strlen(s)`
  *  `ct`를 `s`에 복사 - `strcpy(s,ct)`
  *  `ct`를 `s`뒤에 붙이기 - `strcat(s,ct)`
  *  `cs`와 `ct`비교 - `strcmp(cs,ct)`
    *  같을 경우 - `0` 
    *  `cs`가 `ct`보다 사전순으로 앞서 있을 경우 - `<0`
    *  이외의 경우 - `>0`

* `<stdio.h>` - 입출력을 위한 헤더
  * 표준 입출력
    * 표준 입력, 출력, 오류 stream - `stdin`, `stdout`, `stderr` 
    * 파일의 끝 - `EOF`
    * 한글자 읽기 - `getchar()`
    * 한글자 출력 - `putchar(ch)`
    * 형식에 따른 출력 - `printf("format", arg1, ... )`
    * 문자열 `s`에 출력 - `sprintf(s, "format", arg1, ...)`
    * 형식에 따른 입력 - `scanf("format", &identifier)`
    * 문자열 `s`에서 값 읽기 - `sscanf(s, "format", &identifier)`
    * 문자열 출력하고 `'\n'`도 출력하기 - `puts(s)`
  * 파일 입출력
    * 파일 포인터 선언하기 - `FILE *fp;`
    * 파일 열기 - `fp = fopen("filename", "mode");`
      * `mode` - `r` (읽기), `w` (쓰기), `a` (이어쓰기)
    * 한글자 읽기 - `getc(fp)`
    * 한글자 출력 - `putc(ch,fp)`
    * 형식에 따른 출력 - `fprintf(fp, "format", arg1, ...)`
    * 형식에 따른 입력 - `fscanf(fp, "format", arg1, ...)`
    * 파일 닫기 - `fclose(fp)`
    * `EOF` 확인 - `feof(fp)`
    * 한줄에서 `size`미만의 문자열 읽기 - `fgets(s,size,fp)`
    * 문자열 출력 - `fputs(s,fp)`
  * 형식 지정자 : `"%-+ 0w.pc"`
    * `-` - 왼쪽 정렬
    * `+` - 부호 출력
    * ` `(공백) - 부호가 없을 경우 공백 출력
    * `0` - 빈 공간에 0을 출력
    * `w` - 출력시의 공간의 너비
    * `p` - 정밀도
    * `c` - 출력 변수, 상수의 자료형 지정
      * `d` - 정수형
      * `f` - 실수형
      * `lf` - `scanf`/`fscanf`에서 사용되는 `double`자료형을 위한 지정자
      * `c` - 문자
      * `s` - 문자열
      
* `<stdlib.h>`
  * 절댓값 - `abs(n)`
  * 문자열 `s`를 `double`로 - `atof(s)`
  * 문자열 `s`를 `int`로 - `atoi(s)`
  * 시스템 명령 사용 - `system(s)`
  * 프로그램 종료 - `exit(status)`
* `<math.h>`
    * 삼각함수 - `sin(x)`, `cos(x)`, `tan(x)`
      * 역함수 - `asin(x)`, `acos(x)`, `atan(x)`, `atan2(y,x)`
    * 지수 관련 함수 - `exp(x)`, `log(x)`, `log10(x)`
    * 제곱 함수 - `pow(x,y)`
    * 제곱근 함수 - `sqrt(x)`
    * 자리 올림, 내림 함수 - `ceil(x)`, `floor(x)`, `fabs(x)`

주의사항
--------

* 가급적 `main`함수는 `return 0;`을 적길 바랍니다.
* 변수를 직접 참조하여 `scanf`를 사용할 경우, 반드시 주소 연산인 `&` 연산자를 붙이길 바랍니다.
  * 단, 문자열에 대해서는 `&`를 붙일 필요가 없습니다.
* `fopen`를 이용해 파일을 열었으면, 프로그램 종료 전 `fclose`를 사용하길 바랍니다.
* `scanf`, `printf` 사용시 형식 지정자와 자료형을 일치시키세요.
  * 만약 `double`을 `int`로 출력하고 싶을 경우와 같이 형 변환이 필요할 경우 형변환 연산을 사용하면 됩니다.
  
참고자료
--------

1. [원본 링크](http://www.digilife.be/quickreferences/qrc/c%20reference%20card%20%28ansi%29%202.2.pdf)
