#!/usr/bin/python
# -*- coding: UTF-8 -*-
class vector:
	def __init__(self,x1=0,x2=0,x3=0,x4=0,x5=0):
		self.x1 = x1
		self.x2 = x2
		self.x3 = x3
		self.x4 = x4
		self.x5 = x5

	def __add__(self,obj):
		return vector(self.x1+obj.x1,self.x2+obj.x2,self.x3+obj.x3,self.x4+obj.x4,self.x5+obj.x5)

	def __mul__(self,obj):
		return vector(self.x1-obj.x1,self.x2-obj.x2,self.x3-obj.x3,self.x4-obj.x4,self.x5-obj.x5)

	def __repr__(self):
		return 'vector(%r, %r, %r, %r, %r)' % (self.x1, self.x2, self.x3, self.x4, self.x5)



v1 = vector(1,2,1,2,3)
print v1
v2 = vector(2,3,4,3,2)
print v2
print v1 + v2
print v1 * v2

# for i in range(1000):
# 	 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
