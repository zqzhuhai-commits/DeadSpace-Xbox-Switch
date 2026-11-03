基于原始 NRO 的中文显示增补，版本号与 ds1-nx 上游 v1.0.0 一致。作者：Xiao Fan。

用户已确认本次 NRO 正常。只替换菜单绘制与宽度计算两段函数，其余字节保持原样，包括原版音视频代码。

下载并解压 `DeadSpace-Switch-Chinese-v1.0.0.zip`，使用 Python 3 运行：

```sh
python apply_patch.py original-ds1-nx.nro ds1-nx.nro
```

生成文件与设备测试通过的 NRO 完全一致。将它替换到 `SD:/switch/ds1-nx/ds1-nx.nro`，保留现有汉化 VIV，无需重装 NSP。补丁包需要受支持的原始 NRO；不包含完整游戏数据或 VIV。

原始 NRO SHA-256：`34216488c7d71c3430d2a2211ffb76e35ac9052728b1efc349ebcc5317a1674b`

中文 NRO SHA-256：`3025da82e8756f109f91dbf83ecc3576ad77bd3074bea97ea8b8e889152e921d`
