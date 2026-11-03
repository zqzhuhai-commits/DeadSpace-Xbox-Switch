# 构建说明

本发布采用对原始 NRO 的定点替换，避免更换它的音视频模块。

## 直接复现设备通过版本

`python apply_patch.py original.nro output.nro`。脚本从 `patches/nro-zh.json` 读取两段机器码，验证完整输入与输出 SHA-256。无需 Switch 密钥或游戏归档。

## 编译替换函数

`native/text.cpp` 与 `native/ds1_utf8.h` 是设备通过版本的替换函数源码。头文件使用 [rexglue-sdk-nx](https://github.com/nx-mod/rexglue-sdk-nx/tree/f961303fe3c6e3a90905b379ff4bf3de9a35a757) 的 PPCContext ABI，编译工具为 devkitA64 GCC，目标 ARMv8-A Cortex-A57。

运行 `python tools/compile_native.py --sdk SDK_PATH --build BUILD_PATH --devkitpro DEVKITPRO_PATH`。SDK_PATH 指已应用 ds1-nx v1.0.0 SDK patches 的 SDK 源码目录，BUILD_PATH 指依照上游说明配置完成的 Switch 构建目录（其中 `rexglue-sdk/include` 包含生成的配置头）。

编译后运行 `python tools/assemble_native.py original.nro native/text.o rebuilt.nro`。装配器解析 ELF 重定位、解析原版 guest-to-host 映射、拆分两个文字函数，校验 200 处原生分支，并拒绝两段范围之外的修改。最终 SHA-256 必须等于已发布的中文 NRO。改变编译器或 SDK 可能改变代码大小与布局，装配器会拒绝不符合范围约束的输出。

上游版本：v1.0.0，提交 `19c9b38b905cd4e0a875147783ebc3d36ca01e8a`。本仓库只提供增补部分；完整引擎源码及其他许可证见上游仓库。
