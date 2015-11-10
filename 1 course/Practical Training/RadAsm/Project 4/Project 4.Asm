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
    szExit              db  13, 10, "Press ENTER to exit...", 13, 10, 0
    szFormat            db  "%d", 0
    buf                 db  300 dup(' ')
    chislo              dd  0
    half                dd  0
    del                 dd  2
    two                 dd  2
    tmpeax              dd  0
    szStar              db  " * ", 0
    szEqual             db  " = ", 0
    szDegree            db  "^%d", 0
    outdel              dd  0
    outdeg              dd  0
    degree              dd  0
    StarCount           dd  0

.code

MainProc	proc
            invoke  StdIn, addr buf, 300
            invoke  atol, addr buf
            mov chislo, eax
            mov half, eax
            invoke  wsprintf, addr buf, addr szFormat, chislo
            invoke  StdOut, addr buf
            invoke  StdOut, addr szEqual
			mov eax, chislo
		lap :
			mov tmpeax, eax
			cdq
			div del

			cmp edx, 0
			je pluss

			cmp degree, 0
			jne ccout
			jmp nextt
		ccout :
		    cmp StarCount, 0
		    je  pryg
		    invoke  StdOut, addr szStar
		pryg:
		    inc StarCount
			invoke  wsprintf, addr buf, addr szFormat, del
			invoke  StdOut, addr buf
			invoke  wsprintf, addr buf, addr szDegree, degree
			invoke  StdOut, addr buf
			mov degree, 0

		nextt:
			inc del
			mov edx, del
			mov eax, tmpeax
			cmp edx, half
			jng lap
			jmp endd

		pluss :
			mov tmpeax, eax
			;invoke  wsprintf, addr buf, addr szFormat, del
			;invoke  StdOut, addr buf
			;invoke  StdOut, addr szStar
			mov eax, tmpeax

			inc degree
			mov edx, del
			cmp edx, half
			jng lap
		endd :
            mov del, 1
            ;invoke  wsprintf, addr buf, addr szFormat, del
			;invoke  StdOut, addr buf        
            
            ;invoke  wsprintf, addr buf, addr szFormat, chislo
            ;invoke  StdOut, addr buf
            invoke  StdOut, addr szExit
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
