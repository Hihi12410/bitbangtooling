REM Ensure Clang is installed.
@ECHO off
clang libs/filelib/filelib.c libs/hexlib/hexlib.c hexview.c -o hexview.exe -v
cls
echo Build finished.