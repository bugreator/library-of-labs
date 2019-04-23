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
times = 10

cnt = 0
max_times = 10000
for i in range(times):
	x.append([10*random.random()])
	for j in range(4):
		x[i].append(10*random.random())
	y.append(10*random.random())
print x

# (0.1,1,3,4,2)	(0.3,2,6,3.96,3) y = [2.5,5,...]
# for i in range(times):
# 	x.append([0.1+i*0.2])
# 	x[i].append(1.0*i+1.0)
# 	x[i].append(3.0*i+3.0)
# 	x[i].append(4.0-0.04*i)
# 	x[i].append(2.0+i*1.0)
# 	y.append(0.5*i+0.5)


sum = 0
#random x,y
# print y,len(y),len(x),len(x[4])

old_theta = [0,0,0,0,0]
for i in range(5):
	old_theta[i] = theta[i]
print old_theta,theta
while (cnt<max_times and delta > eps):
	# sum = []
	delta = 0
	for i in range(batch):
		sum = 0
		
		for j in range(5):
			sum+=old_theta[j]*x[i][j]
		sum-=y[i]
		for j in range(5):
			theta[j] -= (sum*stepsize*x[i][j]*2)/batch


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
