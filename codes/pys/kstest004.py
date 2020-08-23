'''
@Author: Shepherd Qirong
@Date: 2020-05-27 16:39:59
@Github: https://github.com/ShepherdQR
@LastEditors: Shepherd Qirong
@LastEditTime: 2020-05-27 18:07:41
@Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
'''
"""
https://docs.scipy.org/doc/scipy/reference/stats.html


"""

import numpy as np
from scipy import stats
import matplotlib.pyplot as plt



dataFile = "./Data/coa_8000_uniform.txt"


matrix1 = np.loadtxt(dataFile, usecols=range(1))

matrix = (matrix1 - np.min(matrix1)) / (np.max(matrix1) - np.min(matrix1) )
#print(matrix)
counts, bin_edges = np.histogram(matrix, bins=20)
freq = counts / np.sum(counts)
print(freq)


fig, ax = plt.subplots(1, 1)
# ax.hist(matrix, 20)
ax.plot(freq)


dataIn = freq
out1 = stats.kstest(dataIn, 'norm')# ,[3]
print(out1) # KstestResult(statistic=0.502076881817829, pvalue=0.0)

out2 = stats.kstest(dataIn, 'powernorm' ,[3])#
print(out2) # KstestResult(statistic=0.502076881817829, pvalue=0.0)
out3 = stats.kstest(dataIn, 'f' ,[10, 20])#
print(out3)

# rv=stats.norm(4.45)
# ax.plot(matrix, rv.pdf(matrix))

dfn, dfd = 10,20
x = np.linspace(stats.f.ppf(0.01, dfn, dfd),
                    stats.f.ppf(0.99, dfn, dfd), 100)
ax.plot(x, stats.f.pdf(x, dfn, dfd),
                    'r-', lw=5, alpha=0.6, label='f pdf')




out4 = stats.kstest(dataIn, 'weibull_min' ,[1.7])#
print(out4)

out5 = stats.kstest(dataIn, 'wald')#
print(out5)

out6 = stats.kstest(dataIn, 'skewnorm', [1])#set ot 0 is norm
print(out6)

out7 = stats.kstest(dataIn, 'recipinvgauss', [88])#set ot 0 is norm
print(out7)

plt.show()

"""
[0.00392958 0.02907891 0.09006602 0.1315624  0.11552971 0.12213141
 0.10641308 0.09383842 0.07717699 0.06507388 0.05297076 0.03678089
 0.02829299 0.02121974 0.01100283 0.00770198 0.00345803 0.00220057
 0.00125747 0.00031437]
KstestResult(statistic=0.5001254141068313, pvalue=3.765885177294875e-05)
KstestResult(statistic=0.8750940369890488, pvalue=1.7232606092249795e-18)
KstestResult(statistic=0.9988816290425954, pvalue=1.8739051540833788e-59)
KstestResult(statistic=0.9686934268500027, pvalue=1.6358392845825146e-30)
KstestResult(statistic=0.9849847708088775, pvalue=6.786866522956184e-37)
KstestResult(statistic=0.6949262830727543, pvalue=3.5272779171051434e-10)
KstestResult(statistic=0.7249219818344819, pvalue=3.265292711387697e-11)

"""