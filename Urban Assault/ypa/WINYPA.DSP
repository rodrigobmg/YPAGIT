# Microsoft Developer Studio Project File - Name="WINYPA" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=WINYPA - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WINYPA.MAK".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WINYPA.MAK" CFG="WINYPA - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WINYPA - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WINYPA - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""$/Urban Assault/YPA", YCBAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WINYPA - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /Zp1 /w /W0 /GX /O2 /I "..\include" /I "..\amiga" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "__NETWORK__" /D "__DBCS__" /D "_WIN32" /D "__WIN32" /D "MSDOS" /D "__WINDOWS__" /D "_LittleEndian_" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ddraw.lib dinput.lib dplayx.lib quartz.lib strmbase.lib wsock32.lib imm32.lib /nologo /subsystem:windows /machine:I386 /out:"Release/ua_msvc.exe"
# Begin Special Build Tool
TargetPath=.\Release\ua_msvc.exe
SOURCE=$(InputPath)
PostBuild_Cmds=copy $(TargetPath) \\mlyons3\ua
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WINYPA - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /Zp1 /w /W0 /Gm /GX /Zi /Od /I "..\include" /I "..\amiga" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "__NETWORK__" /D "__DBCS__" /D "_WIN32" /D "__WIN32" /D "MSDOS" /D "__WINDOWS__" /D "_LittleEndian_" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ddraw.lib dinput.lib dplayx.lib quartz.lib strmbase.lib wsock32.lib imm32.lib /nologo /subsystem:windows /map /debug /machine:I386 /out:"Debug\ua_msvcd.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=.\Debug\ua_msvcd.exe
SOURCE=$(InputPath)
PostBuild_Cmds=copy $(TargetPath) \public 	copy  $(TargetPath) \\mlyons3\ua
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "WINYPA - Win32 Release"
# Name "WINYPA - Win32 Debug"
# Begin Source File

SOURCE=..\Libs\Win\MSS32.LIB
# End Source File
# Begin Source File

SOURCE=.\WINMAIN.C
# End Source File
# Begin Source File

SOURCE=.\YPA.C
# End Source File
# Begin Source File

SOURCE=.\res\ypa.rc

!IF  "$(CFG)" == "WINYPA - Win32 Release"

!ELSEIF  "$(CFG)" == "WINYPA - Win32 Debug"

!ENDIF 

# End Source File
# End Target
# End Project
