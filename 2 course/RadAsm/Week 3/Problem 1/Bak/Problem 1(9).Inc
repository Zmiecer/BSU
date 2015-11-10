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
IDM_FILE						equ 10001
IDM_COLOR						equ 10002
IDM_MOVE						equ 10003
IDM_CHFILE						equ 10004
IDM_FONT						equ 10005
IDM_EXIT						equ 10001

IDD_DLG1						equ 1000
IDC_RBN1						equ 1001
IDC_RBN2						equ 1002
IDC_RBN3						equ 1003
IDC_STC1						equ 1004
IDC_CANCEL						equ 1007
IDC_PLUS						equ 1005
IDC_MINUS						equ 1006


.data
   ClassName db "MainWinClass",0
   AppName  db "Main Window",0

   btn          db "BUTTON",0
   btnok        db "OK",0    
   szFilter     db "All Files\0*.*\0",0


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
   sm dd ? 
   
.const
   dva          dd 2
   sm1          dd 15
   sm2          dd 30
   sm3          dd 45