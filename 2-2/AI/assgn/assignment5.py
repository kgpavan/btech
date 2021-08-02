#!/usr/bin/python
file=open("y","r")
input=""
t1={}
t1['Obj']=['cube', 'cuboid', 'sphere', 'cone', 'cylinder', 'pyramid']
t1['Task']=['put', 'move']
t1['Adj']=['green', 'red', 'blue', 'yellow', 'brown']

for line in file:
	if '(' in line:
		input=line
l1=len(input)
Tr={}
s=""
x=""
for i in range(l1):
	if input[i] is '(':
		s=s+"("+" "
	else:
		s=s+input[i]

s=s.split()
lable=[]
#print s ,'\n'
len1=len(s)
a=[]
for i in range(len1):
	if s[i] is ')':
		j=i-1
		s[i]='+'
		while j!=0:
			if s[j]=='(':
				s[j]=s[j+1]
				if s[j+1].split('~')[0] == 'PP':
					lable.append(s[j+1].split('~')[1])
				Tr[s[j+1]]=[]
				for k in range(j+2,i):
					if '~' in s[k]:
						s[k]=s[k].split('~')[1]
					if '/' in s[k]:
						s[k]=s[k].split('/')[0]
					if s[k] == 'the':
						s[k]='+'
					if s[k] == '.':
						s[k]='+'
						
					Tr[s[j+1]].append(s[k])
								
					s[k]='+'
				break
			j=j-1
		j=i
#print Tr
T1={}
for i in Tr.keys():
	y=i.split('~')[1]
	if i.split('~')[0] =="S":
		y="TOP"
	if not T1.has_key(y):
		T1[y]=[]
	x=Tr[i]
	u=[]
	for p in x:
		if p not in u and p !='+':
			u.append(p)
	for z in u:
		if z not in T1[y] and z !=y:
			T1[y].append(z)
final={}
final['TOP']=['start',T1['TOP']]
ref='TOP'
output=[]
z=[]
object = [] 
for i in T1.keys():
	if i in t1['Obj'] and i not in object:
		object.append(i)
	for j in T1[i]:
		if j in t1['Obj'] and i not in lable:
			output.append((i,'OBJ',j))
			if j not in object:
				object.append(j)
		elif j in t1['Task'] and i not in lable:
			output.append((i,'TAST',j))
		elif j in t1['Adj'] and i not in lable:
			output.append((i,'RADJ',j))
		elif j in lable and i not in lable:
			x=T1[j]
			for k in x:
				output.append((i,j,k))
		else:
			if i not in lable:
				output.append((i,'start',j))
Function=[]
obj={}

id_number=len(object)
s1=""
for i in range(id_number):
	s1=s1+"all "
for j in range(id_number):
	obj[object[j]]='x'+str(j)
	s1=s1+" "+obj[object[j]]
	Function.append(('SHAPE('+'x'+str(j)+','+object[j]+')'))
flag=0

for x in output:
#print x[0] ,'----',x[1],'----',x[2]
	if x[1] == 'RADJ':
		Function.append(('COLOR('+obj[x[0]]+','+x[2]+')'))
	if x[1] == 'OBJ':
		Function.append((x[0].upper()+'('+obj[x[2]]+')'))
	if x[1] in lable:
		for y in output :
			if y[0] == x[0] and y[1] == 'OBJ':
				Function.append((x[1].upper()+'('+obj[y[2]]+','+obj[x[2]]+')'))
				flag=1
				break;
				
		if flag==0:
			Function.append((x[1].upper()+'('+obj[x[0]]+','+obj[x[2]]+')'))
print '\n'
s1=s1+" "+"("
for x in range(len(Function)):
	if x == len(Function)-1:
		s1=s1+" "+Function[x]+" "+")"
	else:
		s1=s1+" "+Function[x]+" "+"^"
#print x
	
print s1		
