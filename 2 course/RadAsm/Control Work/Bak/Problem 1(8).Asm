.586
.model flat,stdcall
option casemap:none

 include Problem 1.inc

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
           CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,\
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
	
	.IF uMsg==WM_DESTROY
    	invoke PostQuitMessage,NULL
    	
	.ELSEIF uMsg==WM_CREATE
	    mov   ebx,hWnd
	    mov   cc.lStructSize,SIZEOF CHOOSECOLOR 
	    mov   ebx,hWnd
	    mov   cc.hwndOwner, ebx
	    mov   cc.lpCustColors, OFFSET acrCustClr

	   	mov   ofn.lStructSize, SIZEOF OPENFILENAME
	    mov   ofn.lpstrFile, OFFSET szFile
	    mov   ofn.nMaxFile, SIZEOF szFile
	    
	    mov   chf.lStructSize, SIZEOF CHOOSEFONT
	    mov   chf.lpLogFont, OFFSET lf
	    mov   chf.Flags, CF_SCREENFONTS or CF_INITTOLOGFONTSTRUCT;
	    mov   chf.nFontType, SIMULATED_FONTTYPE;
	    
	   .elseif uMsg==WM_COMMAND
	    mov eax,wParam
	    and eax,0FFFFh
	    
	    .if eax==IDM_EXIT
			invoke SendMessage,hWnd,WM_CLOSE,0,0
		    
		.elseif eax==IDM_COLOR
		    invoke ChooseColor, OFFSET cc
		    invoke SetTextColor, hDC, cc.rgbResult
            invoke  CreateSolidBrush, cc.rgbResult
            mov     hBrush, eax
            mov cc.Flags, CC_RGBINIT or CC_FULLOPEN
            invoke SetTextColor, hDC, cc.rgbResult
            invoke  InvalidateRect, hWnd, NULL, TRUE

        .elseif eax==IDM_MOVE
            mov ebx, hWnd
            mov hWndTmp, ebx
            invoke DialogBoxParam,hInstance,IDD_DLG1,NULL,addr DlgProc,NULL
            
        .elseif eax==IDM_CHFILE
            invoke GetOpenFileName, OFFSET ofn
            invoke lstrlen, addr szFile
            
            
            invoke  InvalidateRect, hWnd, NULL, TRUE
            invoke lstrlen, addr szFile
            mov ecx, eax
            mov tmpString[ecx-1], 0
            mov al, 10
    	    mov nWords, 0
loop1:
    	        .if szFile[ecx-1] == '\'
    	            mov tmpString[ecx-2], al
    	            inc nWords
    	        .elseif ecx == 2
    	            mov bl, szFile[ecx-2] 
    	            mov tmpString[ecx-2], bl
    	            inc nWords
    	            mov ecx, 1
    	        .else
    	            mov bl, szFile[ecx-1] 
    	            mov tmpString[ecx-2], bl    
    	        .endif
    	    loop loop1
    	    invoke lstrlen, addr tmpString
        	    xor ebx, ebx
        	    xor ecx, ecx
        	    xor edx, edx
            
			invoke  InvalidateRect, hWnd, NULL, TRUE  
            ;invoke  dwtoa, count, addr szCount
            ;invoke  StdOut, addr szCount
            ;invoke  StdOut, addr szDot
            ;invoke  StdOut, addr wordd
            
         n_end_end:
            
            invoke  InvalidateRect, hWnd, NULL, TRUE
            ret      
  
		.endif
		
    .ELSEIF uMsg==WM_PAINT
	    invoke  BeginPaint, hWnd, addr ps
	    mov     hDC, eax
	    invoke SetBkMode, hDC, TRANSPARENT
	    invoke GetClientRect,hWnd, OFFSET crect 
	    mov eax,crect.right
	    cdq
	    div dva
	    mov x, eax
	    mov eax,crect.bottom
	    cdq
	    div dva
	    mov y, eax
	    invoke lstrlen, ofn.lpstrFile
	    mov szFileLen, eax
	    invoke SelectObject,hDC,hFont
	    invoke SetTextColor, hDC, cc.rgbResult
	    invoke SetTextAlign,hDC,TA_CENTER
	    invoke TextOut,hDC,x,y,ofn.lpstrFile,szFileLen
	    
	    invoke TextOut,hDC,0,0,tmpString,szFileLen
	    invoke DrawText, hDC, addr tmpString, -1, addr crect, DT_LEFT
	 
	    invoke  EndPaint, hWnd, addr ps
	    
	.elseif eax==WM_CLOSE
		invoke DestroyWindow,hWnd

	    
	.else
		invoke DefWindowProc,hWnd,uMsg,wParam,lParam		
		ret
	.endif
	
	xor eax,eax
	ret
WndProc endp

DlgProc proc hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM

mov		eax,uMsg
	
	.if eax==WM_CLOSE
        invoke EndDialog,hWin,0
        
    .elseif eax==WM_INITDIALOG
        invoke GetDlgItem, hWin,IDC_INSERT
        mov ebx, eax
        invoke SendMessage, ebx,BM_SETCHECK,1,0
        mov off, 15
        invoke GetDC, NULL
        mov hDCScreen, eax
        
        invoke GetDeviceCaps,hDCScreen,HORZRES
        mov horres, eax
        invoke GetDeviceCaps,hDCScreen,VERTRES
        mov vertres, eax
        invoke ReleaseDC, NULL, hDCScreen
        
    .elseif eax==WM_COMMAND
	    mov     eax, wParam
	    mov     bx, ax	; LOWORD(wParam) - control identifier
	    shr     eax, 16	; HIWORD(wParam) -  notification code 
            
        .if (bx==IDC_INSERT)
            invoke GetDlgItemText,hWin,IDC_EDT1,addr szBuffer, 300
            invoke atol,addr symbol
            invoke EndDialog,hWin, 0
            mov eax, 0
         .endif
        
	.else
	    mov		eax,FALSE
		ret
		
	.endif
	
	mov		eax,TRUE
	ret

DlgProc endp




end start
