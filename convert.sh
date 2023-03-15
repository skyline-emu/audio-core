#!/bin/bash

grep -rl '// SPDX-License-Identifier: GPL-2.0-or-later' --exclude-dir={.git,skyline-conversion} | xargs sed -i 's/\/\/ SPDX-License-Identifier: GPL-2.0-or-later/\/\/ SPDX-License-Identifier: MPL-2.0/g' 
grep -rl 'Kernel' --exclude-dir={.git,skyline-conversion} | xargs sed -i 's/Kernel/KernelShim/g' 


for i in `find . -name "*.cpp" -o -name "*.h" -type f`; do
    sed -i -E 's/"core\/([^"]+)"/<core\/\1>/g' $i
    sed -i -E 's/"audio_core\/([^"]+)"/<audio_core\/\1>/g' $i
    sed -i -E 's/"common\/([^"]+)"/<audio_core\/common\/\1>/g' $i
done

for i in `grep -rl 'std::ranges' --exclude-dir={.git,skyline-conversion}`; do
    sed -i -E 's/std::ranges/ranges/g' $i
    gawk -i inplace '!found && /include/ { print "#include <range/v3/algorithm.hpp>"; found=1 } 1' $i
done


