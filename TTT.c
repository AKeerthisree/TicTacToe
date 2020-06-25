#include<stdio.h>
void prntMat(int m[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{		
			printf("%d  ",m[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------------------------\n");
}
void check2(int m[3][3])
{
	int i,j,cnt=0,cnt1=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(m[i][j]==-1)
				cnt++;
			else if(m[i][j]==1)
				cnt1++;	
		}	
		if((cnt==2)&&(cnt1==1))
			for(j=0;j<3;j++)
				if(m[i][j]==-1)
				{	m[i][j]=1;
					return;
				}
		else if(cnt==3)
		{	m[i][0]=1;
			return;
		}
	}
	cnt=0;
	cnt1=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(m[j][i]==-1)
				cnt++;
			else if(m[j][i]==1)
				cnt1++;	
		}	
		if((cnt==2)&&(cnt1==1))
			for(j=0;j<3;j++)
				if(m[j][i]==-1)
				{	m[j][i]=1;
					return;
				}
		else if(cnt==3)
		{	m[0][i]=1;
			return;
		}
	}
	cnt=0;
	cnt1=0;
	for(i=0;i<3;i++)
	{
		if(m[i][i]==-1)
			cnt++;
		else if(m[i][i]==1)
			cnt1++;
	}
	if((cnt==2)&&(cnt1==1))
	{	for(j=0;j<3;j++)
			if(m[j][j]==-1)
			{	m[j][j]=1;
				return;
			}
	}
	else if(cnt==3)
	{	m[0][0]=1;
		return;
	}
	cnt=0;
	cnt1=0;
	for(i=0;i<3;i++)
	{
		if(m[i][2-i]==-1)
			cnt++;
		else if(m[i][2-i]==1)
			cnt1++;
	}
	if((cnt==2)&&(cnt1==1))
	{	for(j=0;j<3;j++)
			if(m[j][2-j]==-1)
			{	m[j][2-j]=1;
				return;
			}
	}
	else if(cnt==3)
	{	m[0][2]=1;
		return;
	}
}
int check(int m[3][3],int r,int c)
{
	int cn=0,i,j;
	for(i=0;i<3;i++)
		if(m[r][i]==0)
			cn++;
	if(cn==2)
	{
		for(i=0;i<3;i++)
		{
			if(m[r][i]==-1)
			{
				m[r][i]=1;
				return 0;
			}
		}
	}
	if(cn==3)
		return 1;
	cn=0;
	for(i=0;i<3;i++)
		if(m[i][c]==0)
			cn++;
	if(cn==2)
	{
		for(i=0;i<3;i++)
		{
			if(m[i][c]==-1)
			{
				m[i][c]=1;
				return 0;
			}
		}
	}
	if(cn==3)
		return 1;
	cn=0;
	if(r==c)
	{
		for(i=0;i<3;i++)
		{
			if(m[i][i]==0)
				cn++;
		}
		if(cn==2)
		{
			for(i=0;i<3;i++)
			{
				if(m[i][i]==-1)
				{	m[i][i]=1;
					return 0;
				}
			}
		}
		if(cn==3)
			return 1;
	}
	cn=0;
	if(r==(2-c))
	{
		for(i=0;i<3;i++)
		{
			if(m[i][2-i]==0)
				cn++;
		}
		if(cn==2)
		{
			for(i=0;i<3;i++)
			{
				if(m[i][2-i]==-1)
				{	m[i][2-i]=1;
					return 0;
				}
			}
		}
		if(cn==3)
			return 1;
	}
	return 2;
	
}
int check1(int m[3][3])
{
	int i,j,cn=0;
	for(i=0;i<3;i++)
	{	cn=0;
		for(j=0;j<3;j++)
		{	if(m[i][j]==1)
				cn++;
		}
		if(cn==2)
		{
			for(j=0;j<3;j++)
				if(m[i][j]==-1)
				{	m[i][j]=1;
					return 1;
				}
		}
		if(cn==3)
			return 1;
	}
	cn=0;
	for(i=0;i<3;i++)
	{	cn=0;
		for(j=0;j<3;j++)
		{	if(m[j][i]==1)
				cn++;
		}
		if(cn==2)
		{
			for(j=0;j<3;j++)
				if(m[j][i]==-1)
				{	m[j][i]=1;
					return 1;
				}
		}
		if(cn==3)
			return 1;
	}
	cn=0;
	for(i=0;i<3;i++)
		if(m[i][i]==1)
			cn++;
	if(cn==2)
	{	
		for(j=0;j<3;j++)
			if(m[j][j]==-1)
			{	m[j][j]=1;
				return 1;
			}
	}
	if(cn==3)
		return 1;
		cn=0;
	for(i=0;i<3;i++)
		if(m[i][2-i]==1)
			cn++;
	if(cn==2)
	{	
		for(j=0;j<3;j++)
			if(m[j][2-j]==-1)
			{	m[j][2-j]=1;
				return 1;
			}
	}
	if(cn==3)
		return 1;
	return 0;
}
int checkUser(int m[3][3],int r,int c)
{	int i,j,cn=0;
	for(i=0;i<3;i++)
		if(m[r][i]==0)
			cn++;
	if(cn==3)
		return 1;
		cn=0;
	for(i=0;i<3;i++)
		if(m[i][c]==0)
			cn++;
	if(cn==3)
		return 1;
		cn=0;
	for(i=0;i<3;i++)
		if(m[i][i]==0)
			cn++;
	if(cn==3)
		return 1;
	cn=0;
	for(i=0;i<3;i++)
		if(m[i][2-i]==0)
			cn++;
	if(cn==3)
		return 1;
	return 0;
}
int main()
{
	int m[3][3],r,c,i,j,res,cn=0;
	//intialization
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m[i][j]=-1;
	prntMat(m);
	i=0;
	while(cn<=9)
	{
		printf("Its ur turn:\n");
		do
		{
			
			printf("Enter row and col : ");
			scanf("%d %d",&r,&c);
			if(m[r][c]!=-1)
					printf("Enter a valid position.");
		}while(m[r][c]!=-1);
		if(m[r][c]==-1)
		{	m[r][c]=0;
		}
		
		
		prntMat(m);
		res=checkUser(m,r,c);
		if(res==1)
		{	printf("U WON");
			break;
		}
		printf("Its my turn:\n");
		if(cn==0)
		
		{
			m[(r%2)][(c+1)%2]=1;
			prntMat(m);
		}
		else
		{res=check1(m);
		if(res==1)
		{	prntMat(m);
			printf("I WON");
			break;
		}
		res=check(m,r,c);
		if(res==0)
			prntMat(m);	
		if(res==1)
		{	prntMat(m);
			printf("U WON");
			break;
		}
		//prntMat(m);
		if(res==2)
		{
			check2(m);
				prntMat(m);
		}
		}
		cn+=2;
	}		
	if(cn>=9)
		printf("GAME OVER\nNO BODY WON");
}
