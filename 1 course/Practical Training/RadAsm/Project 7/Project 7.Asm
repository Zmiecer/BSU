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
    szExit              db  10, "Press ENTER to continue...", 13, 10, 0
    szStrings           db  "Enter the number of strings: ", 0
    szColumns           db  "Enter the number of columns: ", 0
    buf                 db  300 dup(' ')
    n                   dd  0
    m                   dd  0
    x                   dd  0
    sum                 dd  0
    sumstr              dd  0
    flag0               dd  0
    szFormat            db  "%d", 0
    
.code

MainProc	proc

            invoke  StdOut, addr szStrings
            Invoke  StdIn,  addr buf,LengthOf buf
            Invoke  atol,   addr buf
            mov n, eax
            
            invoke  StdOut, addr szColumns
            Invoke  StdIn,  addr buf,LengthOf buf
            Invoke  atol,   addr buf
            mov m, eax
            
            mov esi, 0
            mov ebx, 0
    lap:
            cmp esi, m
            je colend
            inc esi
            
            cmp ebx, n
            je endd
           
            pushad
            Invoke  StdIn,  addr buf,LengthOf buf
            Invoke  atol,   addr buf
            mov x, eax
            popad
            mov eax, x
            add sumstr, eax
            
            cmp eax, 0
            je  nul
            jmp lap
            
     nul:
            mov flag0, 1
            jmp lap
            
     colend:
     
            cmp flag0, 1
            jne notsumm
     summ:
            mov edx, sumstr
            add sum, edx
     notsumm:
            xor esi, esi
            mov flag0, 0
            mov sumstr, 0
            inc ebx
            jmp lap
     endd:
            invoke  wsprintf, addr buf, addr szFormat, sum
			invoke  StdOut, addr buf
            
            
            invoke  StdOut, addr szExit
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
