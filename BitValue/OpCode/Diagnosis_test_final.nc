G53 ; 기계좌표계 기준으로 동작
; 추후에 G00 코드 를 G01

;G01 X32.8 F2000;
;G04 X0.5
G01 X9.6 F2000;
G04 X0.2

; 밸브 초기화 
M504 P4;
G04 X0.2;
M504 P5;
G04 X0.2;
M504 P6;
G04 X0.2;
M504 P7;
G04 X0.2;
M504 P8;
G04 X0.2;
M504 P9;
G04 X0.2;
M504 P10;
G04 X0.2;
M504 P11;
G04 X0.2;
M504 P12;
G04 X0.2;
M504 P13;
G04 X0.2;
M504 P14;
G04 X0.2;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 1과정 시액  주입 과정 ( 실린지 )   1차 
;
M503 P3;
G04 X0.5;

M503 P10; 
G04 X0.5;

M41;

G01 X13.0 F1000;
G04 X0.5
G01 Z10.0 F200;
G04 X0.5

G01 Y0.0 F1000;  ;;G00 Y0 변경함 
G04 X0.5;

G01 A48.0;
G04 X0.5;

G01 Y24.2 F200;
G04 X0.5;

M47;

M42;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; 혈액  Kit 주입하기
M504 P3;
G04 X0.5;
M503 P4;
G04 X0.5;

M46;

;G00 Z79.0;     ;; 실제적인 값
G01 Z79.0 F200;     ;; 실제적인 값
G04 X0.5;

M41;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 1과정 시액  주입 과정 ( 실린지 )   1차 
M503 P3;
G04 X0.5;
M503 P10; 
G04 X0.5;

M47l


G01 A51.5 F200;  ;;temp value
G04 X0.5;

G01 A48.0 F200;  ;;temp value
G04 X0.5;

M504 P4;
G04 X0.5;
M504 P5;
G04 X0.5;
M504 P6;
G04 X0.5;
M504 P10; 
G04 X0.5;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; 원점 이동 과정 

G01 Z78.9 F2000;
G04 X0.3;
G01 Z0.0 F2000;
G04 X0.3;
G01 X0.0 F2000;
G04 X0.3;
G01 Y0.0 F2000;
G04 X0.3;
G01 A0.0 F2000;
G04 X0.2;
M40;

M30 ; 프로그램 종료

