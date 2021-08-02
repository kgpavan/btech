#include<stdio.h>
   main()
	   {
		              int n,k,a,sum,b,l=0,m,i,p,c,su,x,z,g,e,h,f,o;
			                 scanf("%d",&m);
					            for(i=0;i<m;i++)
							               {
									                  scanf("%d",&n);
											             k=1;
												                g=n+1;
														           p=1;
															                     while(k<=n)
																		               {
																				                         b=k;
																							                   sum=0;
																									                     {
																												                               while(b>0)
																																                                 {
																																					                                   a=b%10;
																																									                                     sum=sum+a;
																																													                                       b=b/10;
																																																	                                 }
																															                                                 if(n==k+sum)
																																						                           {
																																										                                     f=k;
																																														                                       o=sum;
																																																		                                         l=1;
																																																							  
																																																							                           }
																																					  
																																					  
																																					  
																																					                           }
																											                       k++;
																													                 }
																	                 while(p<=g)
																				           {
																						                     c=p;
																								                       su=0;
																										                         {
																														                           while(c>0)
																																		                             {
																																						                                       x=c%10;
																																										                                         su=su+x;
																																															                                   c=c/10;
																																																			                             }
																																	                                             if(g==p+su)
																																							                               {
																																											                                        h=p;
																																																                                 e=su;
																																																				                                   z=1;

																																																								                             }



																																						                               }
																													                   p++;
																															             }
																			                   if(z==0 && l==0)
																						                             printf("No Output\n");

																					                    if(h>f)
																								                      printf("%d %d",h,e);
																							                      if(f>h)
																										                        printf("%d %d",f,o);
																									                }

						                     }


