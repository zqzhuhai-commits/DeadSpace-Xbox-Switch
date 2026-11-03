# 死亡空间 Xbox / Switch 中文显示补丁

作者：**Xiao Fan**。版本：**v1.0.0**，与 [ds1-nx 上游](https://github.com/VasilkovND/ds1-nx/tree/v1.0.0) 保持一致。

这是基于音频正常的原始 NRO 制作的中文显示增补。已由作者在设备上确认可运行。只替换菜单文字绘制与宽度计算函数，增加 UTF-8 解码及完整字库页查找；其余字节，包括音视频代码，保持不变。

## 安装

本补丁需要已经汉化的 VIV（含中文文本和字库），不单独提供游戏数据。已安装本次通过测试的 NRO 的玩家无需重复安装。

1. 从 [Releases](https://github.com/zqzhuhai-commits/DeadSpace-Xbox-Switch/releases) 下载补丁包并解压；电脑需安装 Python 3。
2. 准备未修改的 `ds1-nx.nro`，运行：
   ```sh
   python apply_patch.py original-ds1-nx.nro ds1-nx.nro
   ```
3. 备份设备上的 NRO，把生成文件复制至 `SD:/switch/ds1-nx/ds1-nx.nro`。
4. 保留现有汉化 VIV，完全退出并重新启动游戏，无需重装 NSP。

工具会校验输入、输出 SHA-256，拒绝不匹配的原版或覆盖已有文件。输出与本次设备测试通过的 NRO 完全一致。

## 对应文件

| 文件 | SHA-256 |
| --- | --- |
| 原始 NRO | `34216488c7d71c3430d2a2211ffb76e35ac9052728b1efc349ebcc5317a1674b` |
| 中文 NRO | `3025da82e8756f109f91dbf83ecc3576ad77bd3074bea97ea8b8e889152e921d` |

文件长度均为 **51,140,805 字节**。只修改 `[0x6A08C0, 0x6A28C0)` 与 `[0x21A8470, 0x21A90D0)` 两段。

## 源码与验证

- `apply_patch.py`：对原版 NRO 应用已验证的差异补丁。
- `native/`：本次替换的两个函数、UTF-8 解码器及编译头文件。
- `tools/`：独立编译与二进制装配脚本；见 [构建说明](BUILD.md)。
- `tests/test_patch.py`：输入输出校验、拒绝错误输入和覆盖输出的检查。
- [上游源码](https://github.com/VasilkovND/ds1-nx/tree/19c9b38b905cd4e0a875147783ebc3d36ca01e8a) 保留原作者署名与许可证。

本次不包含字体大小、翻译措辞或 VIV 内容的新改动。早期重编译版本及音频诊断版本未纳入发布。
