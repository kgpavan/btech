#!/usr/bin/python
from mod_python import Session
import cgi
def login(req):
		l="""\
		<html>
		<body>
		<center><h1>LOGIN PAGE</h1>
		<form action="./fill" method="post">
		USER<input type="text" name="log" value="" size="30"/>
		<br>
		PASSWORD<input type="password" name="pass" value="" size="30"/>
		<input type="submit" value="submit"/>
		</center>
		</body>
		</html>
		"""
		return l
def fill(req,log):
		k="""\
		<html>
		<h1>Shopping Cart</h1>
		<h2>ITEM      &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp   QUANTITY</h2>
		loggd in as %s
		<form action="./upd" method="post">
		<input type="text" name="item1" value="item1" size="30"/>
		<input type="text"
		name="var1" value="0" 
		size="30"/>
		<br>
		<input type="text" name="item2" value="item2" size="30"/>
		<input type="text"
		name="var2" value="0"
		size="30"/>
		<br>
		<input type="text" name="item3" value="item3" size="30"/>
		<input type="text"
		name="var3" value="0"
		size="30"/>
		<br>
		<input type="text" name="item4" value="item4" size="30"/>
		<input type="text"
		name="var4" value="0"
		size="30"/>
		<br>
		<input type="text" name="item5"  value="item5" size="30"/>
		<input type="text"
		name="var5" value="0"
		size="30"/>
		<br>
		<input type="submit" name="but" value="Add to Cart"/>
		<input type="submit" name="but" value="buy"/>
		<input type="hidden" name="log" value="%s">
		<br>
		</form>
		<table border="3">
		<tr>
		<td>item 1</td>
		<td>100</td>
		</tr>
		<tr>
		<td>item 2</td>
		<td>100</td>
		</tr>
		<tr>
		<td>
		item 3</td>
		<td> 100</td>
		</tr>
		<tr>
		<td>
		item 4
		</td>
		<td>
		100</td>
		</tr>
		<tr>
		<td>
		item 5</td>
		<td> 100</td>
		</tr>
		</table>
		</html>
		"""%(log,log)
		return k	
def pr(req,item1,var1,item2,var2,item3,var3,item4,var4,item5,var5):
	req.content_type='text/html'
	rat1=int(var1)*100
	rat2=int(var2)*100
	rat3=int(var3)*100
	rat4=int(var4)*100
	rat5=int(var5)*100
	req.write("""<html>
			<body>
			<p>Cost of %s is %s <p>
			<p>Cost of %s is %s <p>
			<p>Cost of %s is %s <p>
			<p>Cost of %s is %s <p>
			<p>Cost of %s is %s <p>
			</body>
			</html>""" %(item1,rat1,item2,rat2,item3,rat3,item4,rat4,item5,rat5))
		
def upd(req,item1,var1,item2,var2,item3,var3,item4,var4,item5,var5,but,log):
		global ses
		ses=Session.Session(req,timeout=300)
		try:
			if ses.has_key(item1):
				ses[item1]=ses[item1]+int(var1)
			else:
				ses[item1]=int(var1)
			if ses.has_key(item2):
				ses[item2]=ses[item2]+int(var1)
			else:
				ses[item2]=int(var2)
			if ses.has_key(item3):
				ses[item3]=ses[item3]+int(var3)
			else:
				ses[item3]=int(var3)
			if ses.has_key(item4):
				ses[item4]=ses[item4]+int(var4)
			else:
				ses[item4]=int(var4)
			if ses.has_key(item5):
				ses[item5]=ses[item5]+int(var5)
			else:
				ses[item5]=int(var5)
			ses.save()
		except:
			req.write("""<html>Enter Values
					<form action="./fill" method="post"/>
					<input type="submit" value="Back"/>
					</form>
					</html>""")
		if but=='Add to Cart':
			req.write("""
					<html>
					<form action="./fill" method="post"/>
					<h1>To Update Names Of The Items Or The Number Of Items Press UPDATE</h1>
					
					<input type="hidden" name="log" value= "%s">
					<input type="submit" value="update"/>
					</form>
					</html>
				"""%(log))
		if but=="buy":
			for i in ses.keys():
				req.write("""
					<html>
					<center>
						
					%s ---------- %d
						
					</center>
					</html>
					"""%(i,int(ses[i])*100))					
			ses.delete()	
