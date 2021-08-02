import mod_python
import shelve
from mod_python import Session
from mod_python.util import redirect
s=0;
userlist=0;
userids={};
userids['name']="name";
userids['dude']="dude";
def start(req,username,givenp,case):
	req.content_type="text/html"
	if (username=="" and case=="Login")  or (givenp=="" and case=="Login"):
		redirect(req,"http://localhost/index.html")
	global userids;
	ids=userids.keys();
	
	if case=="Create" and username=="" and  givenp=="":
		req.write("""<html>
			 <body><br><br><br><br><br><br><br>
			 <center><h3>Create New User</h3>
			 <br>
			 <form method="post" action="./start" />
			 Desired Username <input type="text" name="username"    />
			 <br><br>
			 Desired Password <input type="password" name="givenp"  />
			 <br><br>
			 <input type="submit" name="case" value="Create">
			 </form>
			 </body>
			 </html>""");

	if case=="Create" and username!=""  and givenp!="":
		if userids.has_key(username)!=1:
			userids[username]=givenp;
			case="Login";
		else:

			req.write("""<html>
					<body><br><br><br><br><br><br><br>
					<center><h3>Create New User</h3>
					<br>
					<form method="post" action="./start" />
					Desired Username <input type="text" name="username"    />
					<br><br>
					Desired Password <input type="password" name="givenp"  />
					<br><br>
					<b>User already exists!! Choose a different user name</b>
					<br><br>
					<input type="submit" name="case" value="Create">
					</form>
					</body>
					</html>""");

	if case=="Create New User":
		req.write("""<html>
			<body><br><br><br><br><br><br><br>
			<center><h3>Create New User</h3>
			<br>
			<form method="post" action="./start" />
			Desired Username <input type="text" name="username"    />
			<br><br>
			Desired Password <input type="password" name="givenp"  />
			<br><br>
			<input type="submit" name="case" value="Create">
			</form>
			</body>
			</html>""");
	if userids.has_key(username)==0 and case!= "Create New User" and username!="":
		req.write("User Doesnt exist..!! Create a New User.")
		req.write("""<html>
				<body><br><br><br><br><br><br><br>
				<center><h3>Create New User</h3>
				<br>
			<form method="post" action="./start" />
				Desired Username <input type="text" name="username"    />
				<br><br>
				Desired Password <input type="password" name="givenp"  />
				<br><br>
				<input type="submit" name="case" value="Create">
				</form>
				</body>
				</html>""")
	elif userids.has_key(username) and case!="Create" and case!="Create New User" and givenp!="":
		if givenp!=userids[username]:
			req.write("""<html>
					<body><center><h2>Password Didn't Match</h2></center>
					<br><br><br><br><br>
					<center><h3>Re-enter Password</h3>
					<form method="post" action="./start" />
					Enter Username <input type="text" name="username" value="%s"   />
					<br><br>
					Enter Password <input type="password" name="givenp" />
					<br><br>
					<input type="submit" name="case" value="Login"/>
					</form>
					</body>
					</html>"""% username);

	if case=="Login" and userids.has_key(username)==1:
		if userids[username]==givenp:
			return index(req,username);
def index(req,username):
	req.content_type='text/html';
	usersession=Session.Session(req,timeout=800);
	if usersession.is_new():
		usersession['id']=[{},username];
		usersession.save();
	else:	
		existing=usersession['id'][1];
		usersession.load();
		if username!=existing:
			req.write("tuss%s %s"% (existing,username));
			usersession.delete();
			usersession['id']=[{},username];
			usersession.save();

	req.write ("""<html><body><br><br><br><br><br>
	<center><h1>Shopping Cartindex</h1>
	<h3>Your ID - %s<h3>
	<form action="./inter" method="post" />
	<input type="hidden" name="username" value="%s"/>
	<table>
	<tr><td>Enter Item Name</td><td>Enter Quantity</td></tr>
	<tr><td><input type="text" name="item1"/></td><td><input type="text" name="n1" value="0"  /></td></tr>	
	<tr><td><input type="text" name="item2"/> </td><td><input type="text" name="n2" value="0"  /></td></tr>
	<tr><td><input type="text" name="item3"/> </td><td><input type="text" name="n3" value="0"  /></td></tr>
	<tr><td><input type="text" name="item4"/> </td><td><input type="text" name="n4" value="0"  /></td></tr>
	<tr><td><input type="text" name="item5"/></td><td><input type="text" name="n5" value="0"  /></td></tr>
	</table>
	<br><br>
	<input type="submit" name="case1"  value="Add To Cart"></form>
	</center></body></html>"""% (username,username));
	return usersession;
def inter(req,username,item1,n1,item2,n2,item3,n3,item4,n4,item5,n5):
	req.content_type='text/html';
	counts=[n1,n2,n3,n4,n5];
	x=0;
	for i in counts:
		i=int(i);
		counts[x]=i;
		x=x+1;
	usersession=Session.Session(req)
	usersession.load();
	req.write(username);
	username=usersession['id'][1];
	temp=usersession['id'][0];
	if(temp.has_key(item1)):
		temp[item1]=temp[item1]+int(n1);
	else:
		if(item1!=""):
			temp[item1]=int(n1);
	if(temp.has_key(item2)):
		temp[item2]=temp[item2]+int(n2);
	else:
		if(item2!=""):
			temp[item2]=int(n2);
	if(temp.has_key(item3)):
		temp[item3]=temp[item3]+int(n3);
	else:
		if(item3!=""):
			temp[item3]=int(n3);
	if(temp.has_key(item4)):
		temp[item4]=temp[item4]+int(n4);
	else:
		if(item4!=""):
			temp[item4]=int(n4);
	if(temp.has_key(item5)):
		temp[item5]=temp[item5]+int(n5);
	else:
		if(item5!=""):
			temp[item5]=int(n5);
	usersession['id'][0]=temp;
	usersession.save();

	p=usersession['id'][0]
	u=usersession['id'][1]
	tems=p.keys()
	if(len(tems)>0):
		req.write("""<html>
				<br><br>
				<h2>You Have Selected</h2>

				<h3><PRE>Item		Quantity</PRE><h3>
				</html>""");
		
	for i in tems:
		req.write("""<html>
			<h3><PRE>%s		%d</PRE><h3>
			</html>"""% (i,p[i]));
	req.write("""<html>
			<br>
			<form action="./func" method="post">
			<input type="hidden" name="username" value="%s"/>
			<input type="submit" name="case1"  value="Buy"/>     <input type="submit" name="case1"  value="Buy More"></form>
			<br>
			</html>
			"""% username);
	return usersession;
def func(req,username,case1):
	req.content_type='text/html';
	usersession=Session.Session(req)
	usersession.load()
	username=usersession['id'][1];
	if case1=="Buy More":

		req.content_type='text/html';
		req.write("""	<html><body><br><br><br><br><br>
				<center><h1>Shopping Cartfunc</h1>
				<h3>Your ID - %s<h3>
				<form action="./inter" method="post" />
				<input type="hidden" name="username" value="%s"/>
				<table>
				<tr><td>Enter Item Name</td><td>Enter Quantity</td></tr>
				<tr><td><input type="text" name="item1"/> </td><td><input type="text" name="n1" value="0"  /></td></tr>        
				<tr><td><input type="text" name="item2"/> </td><td><input type="text" name="n2" value="0"  /></td></tr>
				<tr><td><input type="text" name="item3"/> </td><td><input type="text" name="n3" value="0"  /></td></tr>
				<tr><td><input type="text" name="item4"/> </td><td><input type="text" name="n4" value="0"  /></td></tr>
				<tr><td><input type="text" name="item5"/> </td><td><input type="text" name="n5" value="0"  /></td></tr>
				</table>
				<br><br
			     <input type="submit" name="case1"  value="Add To Cart"></form></PRE>
				</center></body></html>	"""% (username,username));
	if case1=="Buy":
		totalcost=0;
		req.content_type='text/html';
		each=20;
		temp1=usersession['id'][0];

		keys=temp1.keys();
		for i in keys:
			totalcost=temp1[i]*20+totalcost;
		p=usersession['id'][0]
		u=usersession['id'][1]
		tems=p.keys()
		if(len(tems)>0):
			req.write("""<html>
				<br><br>
				<h2>You Have Selected</h2>

				<h3><PRE>Item		Quantity</PRE><h3>
				</html>""");
		for i in tems:
			req.write("""<html>
				<h3><PRE>%s		%d</PRE></h3>
				</html>"""% (i,p[i]));
		usersession.delete();
		req.write("""<html>
				<h3>Total Cost is<h3></html>""");
		return totalcost;

	return usersession;
#present 1
# out 0
def logout(req):
	redirect(req,"http://localhost/index.html");

