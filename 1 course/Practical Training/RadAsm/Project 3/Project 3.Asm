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
    szTypeIn            db  "Type your string: ", 13, 10, 0
    endl                db  " ", 10, 0
    szNumbered          db  "Kolichestvo slov tolko s ciframi: ", 0
    szPressEnter        db  "Press Enter to exit...", 13, 10, 0
    buf                 db  300 dup(' ')
    buf1                db  300 dup(' ')
    szFormat            db  "%d", 0
    len                 dd  0
    k                   dd  1
    search              db  '1'
    spaceflag           dd  0
    count               dd  0
    tmpecx              dd  0
    smbadr              dd  0
    spaceedi            dd  0
    tmpedi              dd  0

.code

MainProc	proc
            invoke StdOut, addr szTypeIn
            invoke  StdIn, addr buf, 100
            sub eax, 2
            
            call nulls
            call kount
            
            invoke StdOut, addr endl
            invoke StdOut, addr szPressEnter
            invoke  StdIn, addr buf1, 300
            invoke  ExitProcess, 0
MainProc    endp

nulls proc
    cld
            mov len, eax
            mov al, search
        start: 
            mov ecx, len
            lea edi, buf
        m_beg:   
            or al, 0  
            repne scasb   
            jz m_replace 
            jecxz m_end
            jmp m_beg 
            
            m_replace:   
            mov byte ptr[edi-1], '0'   
            jmp m_beg 
            
        m_end:
            mov byte ptr[edi], ' '
            inc al
            inc k
            mov edx, k
            cmp edx, 10
            jne start
    
    ret

nulls endp


kount proc
        cld
		xor eax, eax
		mov al, '0'
		mov ecx, len
		lea edi, buf
		mov spaceedi, edi
		mov tmpedi, edi
	n_beg :
		mov edi, tmpedi
		or al, 0
		repne scasb
		jz n_precount
		jecxz n_end
		mov tmpedi, edi
		jmp n_beg

	n_precount :
	    cmp byte ptr[edi-2], ' '
	    je spacee
	    jmp pacee
	spacee:
	    dec edi
	    mov spaceedi, edi
	    inc edi
	pacee:
		cmp byte ptr[edi], ' '
		je incount
		mov tmpedi, edi
		jmp n_beg

	incount :
		mov tmpecx, ecx
		mov tmpedi, edi
		or al, 0
		mov ecx, len
		mov edi, spaceedi
		;inc edi
		repe scasb

		mov ecx, tmpecx
		cmp edi, tmpedi
		jl n_beg

		mov spaceedi, edi
		mov edi, tmpedi
		inc count
		jmp n_beg

	n_end :
            
            invoke StdOut, addr szNumbered
            invoke  wsprintf, addr buf, addr szFormat, count
            invoke  StdOut, addr buf
ret
kount endp

end MainProc