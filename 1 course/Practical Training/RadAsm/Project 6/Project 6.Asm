.486
.model flat, stdcall                    
option casemap :none

include windows.inc     ; always first

include masm32.inc
include gdi32.inc
include user32.inc
include kernel32.inc

includelib masm32.lib
includelib gdi32.lib
includelib user32.lib
includelib kernel32.lib

.data
    szHelloWorld        db  "Hello, world!", 13, 10, 0
    szFirst             db  "Type your degree", 13, 10, 0
    buf                 db  300 dup(' ')
    buffer              db  300 dup(' ')
    degree              dq  1.0
    szFormat            db  "%d", 10, 0
    result              real8  0.0
    szOut               db  300 dup(' ')
    two                 dd  2
    number              real8  0.5
    

.code

MainProc	proc
            Invoke  StdOut, addr szFirst
            Invoke  StdIn,  addr buffer, LengthOf buffer
            invoke StrToFloat, addr buffer, addr degree
            
            finit
            ; Во-первых, вычисляем z = a*log2(x)
		    fild    degree          ; Загружаем степень
		    fld     number    		; Загружаем основание
		    fyl2x				    ; Стек FPU теперь содержит : ST(0) = a*log2(x)
		    
		    fld     st(0)			; Создаем еще одну копию z
		    frndint				    ; Округляем ST(0) = trunc(z) | ST(1) = z
		    fxch    st(1)			; ST(0) = z | ST(1) = trunc(z)
		    fsub    st(0), st(1)	; ST(0) = z - trunc(z) | ST(1) = trunc(z)
		    f2xm1				    ; ST(0) = 2^(z - trunc(z)) - 1 | ST(1) = trunc(z)
		    fld1
		    faddp   st(1), st       ; ST(0) = 2 ^ (z - trunc(z)) | ST(1) = trunc(z)	
		    fscale				    ; ST(0) = (2^(z - trunc(z)))*(2^trunc(z)) = 2^(z)
		    fstp    result			; Результат
            
            invoke FloatToStr, result, addr buf
            
            invoke  StdOut, addr buf
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
