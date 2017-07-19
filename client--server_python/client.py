#!/usr/bin/python
# -*- coding: UTF-8 -*-
# 文件名：client.py

import socket               # 导入 socket 模块

s = socket.socket()         # 创建 socket 对象
host = "127.0.0.1"          # 获取本地主机名
port = 12344                # 设置端口好

s.connect((host, port))

while True:
        str = raw_input("send massage:")
        s.send(str)
        buff = s.recv(1024)
        print buff
        if buff == 'server close':   #当与服务端断开连接则关闭客户端
                break
s.close()
