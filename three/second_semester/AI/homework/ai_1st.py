#!/usr/bin/python
# -*- coding: UTF-8 -*-
import math
import random



x=[]
y=[]
theta = [1,1,1,1,1]
delta = 10
stepsize = 0.001

eps = 0.0000001
batch = 5
error = 0
times = 7

cnt = 0
max_times = 10000
for i in range(times):
	x.append([10*random.random()])
	for j in range(4):
		x[i].append(10*random.random())
	y.append(10*random.random())
print x

print '请输入迭代模式(其中，1为梯度下降，2为批量下降，3为随机梯度下降，4为小批量下降):'
judge = input()

sum = 0

old_theta = [0,0,0,0,0]         #origin thetas
for i in range(5):
	old_theta[i] = theta[i]
print old_theta,theta           #test
while (cnt<max_times and delta > eps):
	# sum = []
	delta = 0
    if judge == 1:
        for i in range(times):
            sum = 0
            
            for j in range(5):
                sum+=old_theta[j]*x[i][j]
            sum-=y[i]
            for j in range(5):
                theta[j] -= (sum*stepsize*x[i][j]*2)/times      #
    elif judge ==2:
        sum = 0
        rand = (int)(times*random.random())
        for j in range(5):
            sum+=old_theta[j]*x[rand][j]
        sum-=y[rand]
            for j in range(5):
                theta[j] -= (sum*stepsize*x[rand][j]*2)

    

	for i in range(5):
		delta += math.fabs(old_theta[i]-theta[i])
	print old_theta,theta,delta
	for i in range(5):
		old_theta[i] = theta[i]
	cnt+=1
	# for i in range
	
for i in range (times):
	result = 0
	for j in range(5):
		result += theta[j]*x[i][j]
	print result,y[i]
print theta







