# 嵌入式Linux训练 

## 练习清单

* Shell脚本
* WolfSSL加解密
* 网络包抓取
* 驱动编写

## 练习EL01 Shell脚本

1. 文本替换，脚本传入原始文件路径参数，读取文本文件，将DATETIME替换成当前时间，保存到原始文件
```
# 原始文件内容
Today is DATETIME
```
1. 编写一个脚本，根据传入参数，解压一个文件到一个目录，或压缩一个目录到指定位置
```
目录结构
├── a1
│   └── a11
└── b2
    ├── b21
    └── b22
```
```
命令行
myzip compress src_path dst_path.zip
myzip uncompress src_path.zip dst_dir
```

## 练习EL02 使用WolfSSL加解密

* 源码编译wolfssl库
* 生成一个文件大小为128字节，全部内容是1的文件
* 计算文件MD5
* 使用AES GCM算法字符串加解密

## 练习EL03 网络包抓取

1. 编写程序，抓取有线网卡所有网络包
2. 解析ARP，ICMP，UDP，TCP等网络包基础信息

## 练习EL04 驱动编写

1. 任务内容，任务开始运行时，每隔1秒返回一句“hello, world.”
1. 提供文件写接口, 允许写入start/stop，开始及停止任务
1. 提供ioctl接口，返回任务运行时间，次数，用户程序读取显示
1. 提供poll接口，返回任务返回的字符串

