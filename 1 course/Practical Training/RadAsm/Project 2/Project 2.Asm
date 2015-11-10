;ѕеревод из 10-тичной с/с в двоичную
.686
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
    szHelloWorld        db  "Type a number: ", 13, 10, 0
    szFormatted         db  "Formatted number: ", 13, 10, 0
    buf                 db  300                                                             dup(' ')
    szGoodBye           db  13, 10, "Press ENTER to continue...", 13, 10, 0
    var                 dd  3
    szFormat            db  "%d", 0
    n                   dd  0
    a                   dd  0
    d                   dd  0
    s                   dd  0
    i                   dd  1
    ten                 dd  10

.code

MainProc	proc
            invoke  StdOut, addr szHelloWorld
            
            invoke  StdIn, addr buf, 300
            invoke  atol, addr buf
            mov var, eax
            mov eax, var
            mov a, eax
            
            invoke  StdOut, addr szFormatted
      laap:
            mov eax, a
            mov edx, d
            mov ebx, 2
            cdq
            div ebx
            mov a, eax
            mov d, edx
            
            cmp edx, 0
            jne odin
            
            mov eax, i
            mul ten
            mov i, eax
            jmp lap
            
      odin:
            
            mov eax, 1
            mul i
            add s, eax
            mov eax, i
            mul ten
            mov i, eax
            jmp lap
           
      lap:
            mov eax, a
            cmp eax, 0
            jne laap 
           
            
            
            invoke  wsprintf, addr buf, addr szFormat, s
            invoke  StdOut, addr buf
            
            
            
           
            
            invoke  StdOut, addr szGoodBye
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
