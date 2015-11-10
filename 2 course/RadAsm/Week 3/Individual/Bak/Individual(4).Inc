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

IDR_MENU						equ 10000
IDM_FILE_EXIT					equ 10001
IDM_COLOR1						equ 10002
IDM_COLOR2					    equ 10003
IDM_COLOR3						equ 10004


.data
   ClassName        db "MainWinClass",0
   AppName          db "Concentric circles",0
   FirstBrush       dd  000ffh
   SecondBrush      dd  0fff0h
   ThirdBrush       dd  0f000h
   
   firsttop         dd  0
   firstleft        dd  0
   firstbot         dd  0
   firstright       dd  0
   
   secondtop        dd  0
   secondleft       dd  0
   secondbot        dd  0
   secondright      dd  0
   
   thirdtop         dd  0
   thirdleft        dd  0
   thirdbot         dd  0
   thirdright       dd  0
   
   fifty            dd  50
      
.data?
   hInstance        HINSTANCE   ?
   CommandLine      LPSTR   ?
   ps   	        PAINTSTRUCT <>
   hDC  	        HDC ?
   hFirstBrush        dd  ?
   hSecondBrush     dd  ?
   hThirdBrush      dd  ?
   crect            RECT    <>
   hMenu            HMENU   ?
   cc           CHOOSECOLOR <>
   ofn          OPENFILENAME <> 
   acrCustClr   COLORREF    16 dup(?)
   hor              dd  ?
   ver              dd  ?