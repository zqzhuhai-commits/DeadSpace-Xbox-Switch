from pathlib import Path
import argparse, os, subprocess
p=argparse.ArgumentParser();p.add_argument('--sdk',type=Path,required=True);p.add_argument('--build',type=Path,required=True);p.add_argument('--devkitpro',type=Path,required=True);a=p.parse_args()
root=Path(__file__).resolve().parents[1];sdk=a.sdk.resolve();dk=a.devkitpro.resolve()
compiler=dk/'devkitA64/bin'/('aarch64-none-elf-g++.exe' if os.name=='nt' else 'aarch64-none-elf-g++')
flags='-ffunction-sections -fdata-sections -march=armv8-a+crc+crypto -mtune=cortex-a57 -mtp=soft -ftls-model=local-exec -fPIE -D__SWITCH__ -DNX -D_GNU_SOURCE -DSPDLOG_NO_TZ_OFFSET -Wno-psabi -Oz -DNDEBUG -std=gnu++23'.split()
inc=[root/'native',sdk/'include',a.build.resolve()/'rexglue-sdk/include',sdk/'thirdparty/simde',sdk/'thirdparty/simde/simde',sdk/'thirdparty/fmt/include',sdk/'thirdparty/spdlog/include',sdk/'thirdparty/tomlplusplus/include',dk/'devkitA64/include',dk/'libnx/include',dk/'portlibs/switch/include']
subprocess.run([str(compiler),*flags,*['-I'+str(v) for v in inc],'-c',str(root/'native/text.cpp'),'-o',str(root/'native/text.o')],check=True)
