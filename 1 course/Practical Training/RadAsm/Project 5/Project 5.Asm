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
    buffer              db  99                                                  dup (' ')
    szOut               db  16                                                  DUP (?)
    szHelloWorld        db  "Hello, world!", 13, 10,
                            "Press ENTER to continue...", 13, 10, 0
    szFirst             db  "Type in first number: ", 10, 0
    szSecond            db  "Type in second number: ", 10, 0
    szNOD               db  "NOD: ", 10, 0

.code

MainProc	proc
            Invoke  StdOut, addr szFirst
            Invoke  StdIn,  addr buffer,LengthOf buffer
            Invoke  atol,   addr buffer
            mov ebx, eax
            
            Invoke  StdOut, addr szSecond
            Invoke  StdIn,  addr buffer,LengthOf buffer
            Invoke  atol,   addr buffer
            
      lap:   
            cmp   eax, 0
            jle   endd
            
            cmp   ebx, 0
            jle   endd
            
            cmp ebx, eax
            jle subb
            
            mov edx, eax
            mov eax, ebx
            mov ebx, edx
      subb:   
            sub eax, ebx
            jmp lap
      endd:   
            add eax, ebx
            
            
            Invoke  dwtoa,  eax, addr szOut
            Invoke  StdOut, addr szNOD 
            Invoke  StdOut, addr szOut 
            invoke  StdIn,  addr buffer, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
