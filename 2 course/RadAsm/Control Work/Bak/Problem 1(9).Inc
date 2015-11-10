include windows.inc
include masm32.inc
include gdi32.inc
include kernel32.inc
include user32.inc
include Comctl32.inc
include shell32.inc
include shlwapi.inc
include comdlg32.inc

   
includelib masm32.lib
includelib gdi32.lib
includelib kernel32.lib
includelib user32.lib
includelib Comctl32.lib
includelib shell32.lib
includelib shlwapi.lib
includelib comdlg32.lib



WinMain proto :DWORD,:DWORD,:DWORD,:DWORD
DlgProc proto :DWORD,:DWORD,:DWORD,:DWORD

IDR_MENU						equ 10000
IDM_EXIT						equ 10001
IDM_COLOR						equ 10002
IDM_MOVE						equ 10004
IDM_CHFILE						equ 10003


IDD_DLG1						equ 1000
IDC_EDT1						equ 1001
IDC_INSERT                      equ 1002




.data
   ClassName db "MainWinClass",0
   AppName  db "Main Window",0

   btn          db "BUTTON",0
   btnok        db "OK",0    
   szFilter     db "All Files\0*.*\0",0
   
   szBuffer        db  300 dup(' ')
   
   
   buf                 db  300 dup(' ')
    len                 dd  0
    wordd               db  100  dup(' '), 13, 10, 0
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
    symbol              db  " ", 0

    initialString db 250 dup(0)
   xorString db 250 dup(0)
   tmpString db 250 dup(0)
   unxorString db 250 dup(0)
   chXor db 10 dup(0)
   tempbuff db 100 dup(0)
   box dd 50 dup(0)
   nWords dd 0
   mrect RECT <0, 0, 0, 0>
   tempRect RECT <0, 0, 0, 0>
   temp dd 0
   xN dd 0
   yN dd 0
   x1 dd 0
   y1 dd 0
   x2 dd 0
   y2 dd 0
   max dd 0
   color dd 150


.data?
   hInstance HINSTANCE ?
   CommandLine LPSTR ?
   acrCustClr   COLORREF    16 dup(?)
   szFile       db          100 dup(?)
   szFileLen    dd          ?
   hFont        dd          ?
   hMenu        HMENU       ?
   hBrush       dd          ?
   hPen         dd          ?
   hDC  	    HDC         ?
   hDCScreen    HDC         ?
   szFileName   db          100 dup(?)
   ps   	    PAINTSTRUCT <>
   lf           LOGFONT     <>
   cc           CHOOSECOLOR <>
   crect        RECT        <>
   ofn          OPENFILENAME <> 
   chf          CHOOSEFONT   <>
    
   hWndTmp HWND ? 
   x dd ?
   y dd ?
   myheight dd ?
   mywidth dd ? 
   horres dd ?
   vertres dd ?
   off dd ? 
   
.const
   dva          dd 2
   off1         dd 10
   off2         dd 20
   off3         dd 30