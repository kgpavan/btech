#!/usr/bin/python
bigram={}
unigram={}
a=[]
b=[]
str=""
c=[]
length1=0
length=0
br=[]
d=[]
e=[]
f=[]
tup=()
tupple=()
state=0
state1=0
litup=()
def Probability():
	print"...........................................Probability Of A Sentence Using Unigram....................................................."
	print"\n"
	prob=1.0
	count=0
	for i in range(0,len(f)):
		if(f[i]=="."):
			count=count+1
			print "Probability Of A Sentence NO. %d Using Unigram Is:"%(count),
			print prob
		#	print"%0.6s"%(prob)   
			print "\n"
			prob=1.0
		else:
			if(unigram.has_key(f[i])):
				prob=(prob*unigram[f[i]])/length
				print unigram[f[i]],
				print length,
				print prob
			else:
				prob=prob/length
	print "\n"
	print".............................................Probability Of A Sentence Using Bigram.................................................."
	prob1=1.0
	count1=0
	for i in range(0,len(f)):
		if(i+1<len(f)):
			if(f[i+1]=="."):
				count1=count1+1
				print "Probability Of A Sentence NO. %d Using Bigram Is:"%(count1),
				print prob1   
				print "\n"
				prob1=1.0
			else:
				if(i+1<len(f)):
					litup=(f[i],f[i+1])
				if(bigram.has_key(litup)):
					if(unigram.has_key(f[i])):
						prob1=(prob1*bigram[litup])/unigram[f[i]]
					else:
						prob1=(prob1*bigram[litup])/length
				else:
					prob1=prob1/length
	print"\n"
				
				
			
			
	
	


f1=open("text","r")
m=f1.read()
f1.close()
f2=open("test","r")
q=f2.read()
f2.close()
for i in range(0,len(m)):
	if((m[i]>="a" and m[i]<="z")or(m[i]>="A" and m[i]<="Z")):
		str=str+m[i]
	else:

		if(m[i]==" " or m[i]=="\t" and str):
			if str:
				a.append(str)
			str=""
		if((m[i]==".")and(m[i+1]=="\n")and i+1<len(m)):	
				if str:
					a.append(str)
				str=""
		if(m[i]=="."):
			if str:
				a.append(str)
			if str!=".":
				a.append(".")
			b.append(a)
			a=[]
			str=""
for i in b:
	for j in i:
		c.append(j)
for i in range(0,len(q)):
        if((q[i]>="a" and q[i]<="z")or(q[i]>="A" and q[i]<="Z")):
                str=str+q[i]
        else:

                if((q[i]<"a"or q[i]>"z" or q[i]<"A"or q[i]>"Z") and str):
                        if str:
                                d.append(str)
                        str=""
                if((q[i]==".")and(q[i+1]=="\n")and i+1<len(q)):
                                if str:
                                        d.append(str)
                                str=""
                if(q[i]=="."):
                        if str:
                                d.append(str)
                        if str!=".":
                                d.append(".")
                        e.append(d)
                        d=[]
                        str=""
for i in e:
        for j in i:
                f.append(j)

length1=0
for i in f:
	if i!=".":
		length1=length1+1
length=0
for i in c:
	if i!=".":
		length=length+1
for i in range(0,len(c)):
	if unigram.has_key(c[i]):
		unigram[c[i]]=unigram[c[i]]+1
	else:
		unigram[c[i]]=1
#.............................................................For Bigram............................................................................


ar=()
for i in range(0,len(c)):
	if(i+1<len(c)):
		if(c[i+1]!="."):
			ar=(c[i],c[i+1])
			if((bigram.has_key(ar))):
				bigram[ar]=bigram[ar]+1
			else:
				bigram[ar]=1
Probability()
			
		
		
					
		
	 
	
		


	
		

