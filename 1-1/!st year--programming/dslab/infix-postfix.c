infix:  3+4*2-1  ==   10
postfix:  3 4 2 * + 1 -

		3 8 + 1 -
		11 1 -
		10


priority:    * /= 2
`		+ - =1
		( = 3 when outside the stack
		    0 when inside the stack

we can push operator wid higher priority over that of lower
when this not happen then pop till it hapen


infix:  3+(2*(8-4)-1)+5  == 15
postfix: 3 2 8 4 - * 1 - + 5 +

		
		3 2 4 * 1 - + 5 +
		3 8 1 - + 5 +
		3 7 + 5 +
		10 5 +
		15


in case of ) pop till ( comes





if(operator)
{
n2=pop(stack);
n1=pop(stack);
ans=n1 op. n2;
push(ans,stack);
}

final_ans=pop(stack);
