REM     This Source Code Form is subject to the terms of the Mozilla Public
REM     License, v. 2.0. If a copy of the MPL was not distributed with this
REM     file, You can obtain one at https://mozilla.org/MPL/2.0/.


REM Ensure Clang is installed.
@ECHO off
clang libs/filelib/filelib.c libs/hexlib/hexlib.c hexview.c -o "build/winnt@x64/hexview.exe"

echo Build finished.
