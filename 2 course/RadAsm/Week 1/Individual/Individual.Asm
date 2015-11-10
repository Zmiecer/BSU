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
    buffer              db  300 dup (' ')
    szOut               db  20  dup (?)
    szEnd               db  13, 10, 13, 10, "Press ENTER to continue...", 13, 10, 0
    szFirst             db  "Type in your number: ", 10, 0
    szWhatout           db  "Number of even digits: ", 10, 0
    x                   dd  0
    NumOfEven           dd  0
    len                 dd  0
    ten                 dd  10
    two                 dd  2

.code

MainProc	proc
            Invoke  StdOut, addr szFirst
            Invoke  StdIn,  addr buffer, LengthOf buffer
            mov len, eax
            Invoke  atol,   addr buffer
            mov x, eax
            
         lap:
            mov eax, x
            cmp eax, 0
            jz endd
            
            cdq
            div ten
            
            mov x, eax
            mov eax, edx
            
            ;можно также: cdq; div two; cmp edx, 0
            
            and eax, 1
            
            jz plus
            loop lap
            
         plus:
            inc NumOfEven
            loop lap
            
         endd:
            
            Invoke  dwtoa,  NumOfEven, addr szOut
            Invoke  StdOut, addr szWhatout 
            Invoke  StdOut, addr szOut
            Invoke  StdOut, addr szEnd 
            invoke  StdIn,  addr buffer, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
