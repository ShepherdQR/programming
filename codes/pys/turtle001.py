'''
@Author: Shepherd Qirong
@Date: 2020-03-29 16:55:39
@Github: https://github.com/ShepherdQR
@LastEditors: Shepherd Qirong
@LastEditTime: 2020-03-29 17:10:45
@Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
'''
## https://docs.python.org/3/library/turtle.html

from turtle import *
color('red', 'yellow')
begin_fill()
while True:
    forward(200)
    left(170)
    if abs(pos()) < 1:
        break
end_fill()
done()