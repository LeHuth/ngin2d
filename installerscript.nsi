; Include Modern UI
!include "MUI2.nsh"

; The name of the installer
Outfile "Installer.exe"

; The default installation directory
InstallDir $PROGRAMFILES\2dgameengine

; Default section
Section

    ; Output path for the executable
    SetOutPath $INSTDIR

    ; Executable file
    File /oname=2dgameengine.exe C:\Users\leona\CLionProjects\2dgameengine\cmake-build-debug\2dgameengine.exe

    ; DLL files
    File /oname=SDL2.dll C:\Users\leona\CLionProjects\2dgameengine\cmake-build-debug\SDL2.dll
    File /oname=lua54.dll C:\Users\leona\CLionProjects\2dgameengine\cmake-build-debug\lua54.dll

    ; Create a shortcut on the desktop
    CreateShortCut "$DESKTOP\My Program.lnk" "$INSTDIR\2dgameengine.exe"

SectionEnd

; Settings for the installer's UI
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

!insertmacro MUI_LANGUAGE "English"