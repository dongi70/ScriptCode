
; 티칭 전방 포스트 코드


; <스텝 1>
G00 X145.693 Y102.402 Z25.289  A0.000   B0.000   ; 이동

; <스텝 2>
G17 ; XY평면 
G02 X158.644  Y39.550   I-5.542   J-33.902  ; CW원호 

; <스텝 5>
G19 ; YZ평면 
G02 Y85.016   Z35.921   J24.779   K-3.435   ; CW원호 

; <스텝 8>
G18 ; ZX평면 
G02 Z20.620   X72.664   K-55.690  I-34.441  Y85.016   ; CW원호 

; <스텝 11>
G18 ; ZX평면 
G03 Z37.379   X158.472  K-34.686  I51.315   Y85.016   ; CCW원호 

; <스텝 14>
G00 X158.472  ; 원호시작점 이동명령  
G19 ; YZ평면 
G03 Y39.125   Z25.795   J-20.683  K-14.753  ; CCW원호 

; <스텝 17>
G17 ; XY평면 
G03 X151.880  Y98.322   I-20.171  J27.719   ; CCW원호 

; 티칭 후방 포스트 코드
M30
