#!/usr/bin/python
# -*- coding: UTF-8 -*-
# 文件名：server.py

import socket               # 导入 socket 模块

s = socket.socket()         # 创建 socket 对象
host = "127.0.0.1"          # 获取本地主机名
port = 12344                 # 设置端口
s.bind((host, port))        # 绑定端口

s.listen(5)                 # 等待客户端连接
c, addr = s.accept()        # 建立客户端连接。
print '连接地址：', addr
while True:
    buff = c.recv(1024)
    print "recv massage:",buff
    if  buff == 'exit':
        c.send('server close')
        break
    else:
        c.send('successful!')

c.close()                # 关闭连接
