#!/usr/bin/python
import urllib2
import re
source=urllib2.urlopen("http://www.iiit.ac.in/faculty/faculty.php/")
sread=source.read()
#f=re.findall("http://www\.iiit\..*/faculty/.*\.php",sread)
g=re.findall("http://www\.iiit\..*/faculty/.*\.php",sread)
fc=[]
fc.append(g[0])
k=len(g)
for i in range(0,k):
	if fc[-1]!=g[i] :
		fc.append(g[i])
#print fc
pp= len(fc)
for i in range(0,pp):
	src=urllib2.urlopen("fc[i]")
	rsrc=src[i].read()
	
