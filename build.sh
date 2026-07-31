# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at https://mozilla.org/MPL/2.0/.

# Ensure GCC is installed.

gcc libs/filelib/filelib.c libs/hexlib/hexlib.c hexview.c -o "build/linux@x64/hexview.elf"

echo "Build complete."

