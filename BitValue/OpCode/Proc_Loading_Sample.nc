G53 ; 기계좌표계 기준으로 동작
; 사용자 동작코드

G01 A0.0; F100;
G04 X0.5
G01 Z0.0 F100;
G04 X0.5;
G01 Y0.0 F1000;
G04 X0.5;
G01 X100.0  F1000;  ;; X59
G04 X0.5;


; 밸브 초기화 
M503 P4;
G04 X0.2;
M503 P5;
G04 X0.2;
M503 P6;
G04 X0.2;
M503 P7;
G04 X0.2;
M503 P8;
G04 X0.2;
M503 P9;
G04 X0.2;
M503 P14;
G04 X0.2;

M30 ; 프로그램 종료
