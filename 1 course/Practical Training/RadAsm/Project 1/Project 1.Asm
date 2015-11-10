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
    szHelloWorld       	db  "Enter String: ", 0
    szGoodBye           db  13, 10, "Press ENTER to continue...", 13, 10, 0
    buf                	db  300 dup(' ')
    var                 dd  0
    i                   dd  0
    szTmp               db  " ", 10
    ;szFormat           	db  "Result = %d", 0

.code

MainProc	proc

            ;invoke  StdOut, addr szHelloWorld
            
            
    lap:
            invoke  StdOut, addr var
            inc var
            inc i
            cmp i, 10
            jnl ent
    gogo:
            cmp var, 127
            jl lap
            jmp endd

    ent:
            mov i, 0
            invoke  StdOut, addr szTmp
            jmp gogo

    endd:
            invoke  StdOut, addr szGoodBye
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
