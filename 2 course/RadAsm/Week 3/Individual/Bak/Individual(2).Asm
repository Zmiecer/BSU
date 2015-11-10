;5. SDI-приложение. Нарисовать три концентрических окружности, каждая из которых закрашивается своим цветом. Вызов из меню стандартного диалога ColorDialog для каждой окружности.

.586
.model flat,stdcall
option casemap:none

   include Individual.inc


.code

start:
	invoke GetModuleHandle, NULL
	mov    hInstance,eax
	
	invoke GetCommandLine
	mov    CommandLine,eax
	
	invoke WinMain, hInstance,NULL,CommandLine, SW_SHOWDEFAULT
	invoke ExitProcess,eax

WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
	LOCAL wc:WNDCLASSEX
	LOCAL msg:MSG
	LOCAL hwnd:HWND
	
	mov   wc.cbSize,SIZEOF WNDCLASSEX
	mov   wc.style, CS_HREDRAW or CS_VREDRAW
	mov   wc.lpfnWndProc, OFFSET WndProc
	mov   wc.cbClsExtra,NULL
	mov   wc.cbWndExtra,NULL
	push  hInstance
	pop   wc.hInstance
	mov   wc.hbrBackground,COLOR_BTNFACE+1
	mov   wc.lpszMenuName,NULL
	mov   wc.lpszClassName,OFFSET ClassName
	
	invoke LoadIcon,NULL,IDI_APPLICATION
	mov   wc.hIcon,eax
	mov   wc.hIconSm,eax
	
	invoke LoadCursor,NULL,IDC_ARROW
	mov   wc.hCursor,eax
	
	invoke RegisterClassEx, addr wc
	INVOKE CreateWindowEx,NULL,ADDR ClassName,ADDR AppName,\
           WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,\
           CW_USEDEFAULT,200,CW_USEDEFAULT,NULL,NULL,\
           hInst,NULL
	mov   hwnd,eax
	
	invoke LoadMenu,hInst,IDR_MENU
	mov hMenu,eax
	invoke SetMenu,hwnd,hMenu
	
	invoke ShowWindow, hwnd,SW_SHOWNORMAL
	invoke UpdateWindow, hwnd
	
	.WHILE TRUE
		invoke GetMessage, ADDR msg,NULL,0,0
		.BREAK .IF (!eax)
		invoke TranslateMessage, ADDR msg
		invoke DispatchMessage, ADDR msg
	.ENDW
	
	mov     eax,msg.wParam
	ret
WinMain endp

WndProc proc hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
	
	.if uMsg==WM_DESTROY
	    invoke DeleteObject, hFirstBrush
	    invoke DeleteObject, hSecondBrush
	    invoke DeleteObject, hThirdBrush
		invoke PostQuitMessage,NULL
		
	.elseif uMsg==WM_COMMAND
	    mov eax,wParam
	    and eax,0FFFFh
	    
	    .if eax==IDM_FILE_EXIT
			invoke SendMessage,hWnd,WM_CLOSE,0,0
			
	    .elseif eax==IDM_COLOR1
	        invoke ChooseColor, OFFSET cc            
            invoke  CreateSolidBrush, cc.rgbResult
            mov     hFirstBrush, eax
            
            mov cc.Flags, CC_RGBINIT or CC_FULLOPEN
            
            ;mov cc.Flags, CC_FULLOPEN
            invoke  InvalidateRect, hWnd, NULL, TRUE
			
		.elseif eax==IDM_COLOR2
		    invoke ChooseColor, OFFSET cc            
            invoke  CreateSolidBrush, cc.rgbResult
            mov     hSecondBrush, eax
            
            mov cc.Flags, CC_RGBINIT or CC_FULLOPEN
            
            invoke  InvalidateRect, hWnd, NULL, TRUE
			
		.elseif eax==IDM_COLOR3
		    invoke ChooseColor, OFFSET cc            
            invoke  CreateSolidBrush, cc.rgbResult
            mov     hThirdBrush, eax
            
            mov cc.Flags, CC_RGBINIT or CC_FULLOPEN
            
            invoke  InvalidateRect, hWnd, NULL, TRUE
				
		.endif
		
	.elseif uMsg==WM_CREATE
	    mov   ebx,hWnd
	    mov   cc.lStructSize,SIZEOF CHOOSECOLOR 
	    mov   ebx,hWnd
	    mov   cc.hwndOwner, ebx
	    mov   cc.lpCustColors, OFFSET acrCustClr
	    
		invoke  CreateSolidBrush, FirstBrush
        mov     hFirstBrush, eax
        invoke  CreateSolidBrush, SecondBrush
        mov     hSecondBrush, eax
        invoke  CreateSolidBrush, ThirdBrush
        mov     hThirdBrush, eax
        
        
    .elseif uMsg==WM_PAINT
	    invoke  BeginPaint, hWnd, addr ps
	    mov     hDC, eax
	    
	    invoke GetClientRect,hWnd,OFFSET crect
	    
	    mov eax, crect.bottom
	    sub eax, crect.top
	    mov hor, eax
	    
	    mov eax, crect.right
	    sub eax, crect.left
	    
	    .if eax < hor
	        mov hor, eax    
	    .endif
	    	    
	    invoke SelectObject,hDC,hFirstBrush                                          ;First
	    invoke  Ellipse, hDC, crect.left, crect.top, hor, hor
	    
	    mov eax, crect.left
	    add eax, fifty
	    mov secondtopleft, eax
	    
	    mov eax, hor
	    sub eax, fifty
	    mov secondrightbot, eax
	    
	    invoke SelectObject,hDC,hSecondBrush                                         ;Second
	    invoke  Ellipse, hDC, secondtopleft, secondtopleft, secondrightbot, secondrightbot
	    
	    mov eax, secondtopleft
	    add eax, fifty
	    mov thirdtopleft, eax
	    
	    mov eax, secondrightbot
	    sub eax, fifty
	    mov thirdrightbot, eax
	    
	    invoke SelectObject,hDC,hThirdBrush                                          ;Third
	    invoke  Ellipse, hDC, thirdtopleft, thirdtopleft, thirdrightbot, thirdrightbot
	    
	    invoke  EndPaint, hWnd, addr ps
            
	.else
		invoke DefWindowProc,hWnd,uMsg,wParam,lParam		
		ret
		
	.endif
	
	xor eax,eax
	ret
WndProc endp


end start

