.486
.model flat, stdcall                    
option casemap :none

include windows.inc     ; always first

include masm32.inc      ; StdOut, StdIn
include kernel32.inc      ; ExitProcess

includelib masm32.lib
includelib kernel32.lib

.data
    szHello             db  "Enter String", 13, 10, 0
    szPressEnter        db  "Press Enter to exit...", 13, 10, 0
    buf                 db  300 dup(' ')
    len                 dd  0
    wordd               db  20  dup(' '), 13, 10, 0
    worddtmp            db  20  dup(' '), 13, 10, 0
    tmpecx              dd  0
    tmpeax              dd  0
    first               dd  0
    last                dd  0
    tmpedi              dd  0
    tmpesi              dd  0
    count               dd  0
    szCount             db  300 dup(' ')
    szDot               db  ". ", 0
    k                   dd  0

.code

MainProc	proc
            invoke  StdOut, addr szHello
            invoke  StdIn, addr buf, 300
            mov len, eax
            lea edi, buf          
            mov first, edi
            mov ecx, len
            
            lea edi, buf          
            mov first, edi
            mov ecx, len
         n_beg:
            
            mov al, ' '
            repne scasb
            jz space
            
            cmp ecx, 0
            jz n_end
            
         space:
            mov tmpecx, ecx
            mov tmpeax, eax
            mov tmpedi, edi
            mov tmpesi, esi


            mov last, edi
            mov eax, last
            sub eax, first
            cmp eax, 1
            je gogo
            
            mov ecx, eax
            lea edi, wordd
            mov esi, first
            rep movsb 
            
            inc count
            
			
            invoke  dwtoa, count, addr szCount
            invoke  StdOut, addr szCount
            invoke  StdOut, addr szDot
            invoke  StdOut, addr wordd
            
            
         gogo:
            mov eax, last
            mov first, eax
            
            mov ecx, 20
            lea edi, wordd 
            lea esi, worddtmp
            rep movsb 
            
            mov edi, tmpedi
            mov esi, tmpesi
            mov eax, tmpeax
            mov ecx, tmpecx
            
            jmp n_beg
            
         n_end:
            
            mov last, edi
            mov eax, last
            sub eax, first
            cmp eax, 2
            je n_end_end
            
            mov ecx, eax
            lea edi, wordd
            mov esi, first
            rep movsb 
            
            inc count
            
			
            invoke  dwtoa, count, addr szCount
            invoke  StdOut, addr szCount
            invoke  StdOut, addr szDot
            invoke  StdOut, addr wordd
            
         n_end_end:
            
            invoke  StdOut, addr szPressEnter
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc