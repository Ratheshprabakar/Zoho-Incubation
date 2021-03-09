#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printmatrix(int flag,int n,char matrix[][n]);
void printbox(int n);
void printdef(int n,char matrix[][n]);
int updateflag(int* count,int flag,int n,char dupmat[][n],char matrix[][n],int row,int col)
{

	if(matrix[row][col]=='@'&& dupmat[row][col]==48)
	{
		dupmat[row][col]='#';
		*count=*count-1;
		printf("%d\n",count);
	}
	else if(dupmat[row][col]==48 && matrix[row][col]!='@')
	{
		dupmat[row][col]='#';
		*count=*count+1;
	
	}
	else if(dupmat[row][col]=='#' && matrix[row][col]!='@')
	{
		dupmat[row][col]=48;
		*count=*count-1;
	}
	else if(dupmat[row][col]=='#' && matrix[row][col]=='@')
	{
		dupmat[row][col]=48;
		*count=*count+1;
	}
	else
	{
		printf("enter the correct location:-)\n");
	}
	
	printmatrix(flag,n,dupmat);
        printf("Remaining Flags");
        printbox(n-5);
		printf("--> < %d >",flag);
        printf("\n");
        printbox(n);
        printf( "\n");
	if(*count==0)
	{
		printf("\a");
		printbox(n);
		printf("\n   !!!!CONGRAGULATIONS YOU HAVE WON!!!!\n");
		printbox(n);
		printf("\a");
		printf("\n");
	    printdef(n,matrix);
		exit(0);
	}
	return 1;
}
void printdef(int n,char matrix[][n])
{
	int row,col;
	printbox(n);
	printf("\n");
		for(row=0;row<n;row++)
    {
        printf("|");
        for(col=0;col<n;col++)
        {
        	if(matrix[row][col]==48)
        	{
        		printf("    |");
			}
			else
			{
            	printf(" %2c |",matrix[row][col]);
            }
        }
        printf("\n");
        printbox(n);
        
        printf("\n");
    }
}
void printbox(int n)
{
	int row,range=n*5;
	for(row=0;row<range;row++)
	{
		printf("-");
	}
	printf("-");
}
void printmatrix(int flag,int n,char matrix[][n])
{
    system("cls");
    printf("\t\t\t\t\tMINE SWEEPER GAME - PLEASE ENTER THE POSITION\n");
    int row,col,i;
    printbox(n);
    printf("\n");
	for(row=0;row<n;row++)
    {
        printf("|");
        for(col=0;col<n;col++)
        {
        	if(matrix[row][col]==48)
        	{
        		printf(" %d%d |",row,col);
        	}
			else
			{
            	printf(" %2c |",matrix[row][col]);
            }
        }
        printf("\n");
        printbox(n);
        printf("\n");
        
    }
    
    
}
void bomb(int n,char matrix[][n],int rran,int cran)
{
    int i,j,r=rran-1,c=cran-1,r1=rran+1,c1=cran+1;
    for(i=r;i<=r1;i++)
    {
        for(j=c;j<=c1;j++)
        {
        	if(i>=0&&i<=n-1&&j<=n-1&&j>=0)
        	{
            	if(matrix[i][j]!='@')
            	{
                	matrix[i][j]+=1;
            	}
        	}
        }
    }
}
int check(int flag,int n,char matrix[][n],char dupmat[][n],int pos,int pos1)
{
	int row,col;
	if(matrix[pos][pos1]==48)
	{
		int i=pos-1,j=pos1-1,x=pos+1,y=pos1+1;
		for(row=i;row<=x;row++)
		{
			for(col=j;col<=y;col++)
			{
				if(row>=0&&row<=n-1&&col<=n-1&&col>=0)
				{
					if(dupmat[row][col]=='#')
					{
						continue;
					}
					else if(row==pos&&col==pos1)
					{
						
						matrix[row][col]=' ';
						dupmat[row][col]=' ';
						continue;
					}
					else
					{
						if(matrix[row][col]==48)
						{
							dupmat[row][col]='-';
							return check(flag,n,matrix,dupmat,row,col);
						}
						else
						{
							dupmat[row][col]=matrix[row][col];
						}
					}
				}
			}
		}
	}
	else if(matrix[pos][pos1]=='@'&&dupmat[pos][pos1]!='#')
	{
		for(row=0;row<n;row++)
		{
			for(col=0;col<n;col++)
			{
				if(dupmat[row][col]=='#'&&matrix[row][col]!='@')
				{
					dupmat[row][col]=88;
				}
				else if(matrix[row][col]=='@')
				{
					dupmat[row][col]=matrix[row][col];
				}
			}
		}	
		
			printmatrix(flag,n,dupmat);
			printbox(n);
			printf("\n   !!!!!YOU LOSE TRY AGAIN!!!!!\n");
			printbox(n);
			printf("\a");
			exit(0);

	}
	else if(matrix[pos][pos1]!='@'&&matrix[pos][pos1]!=48)
	{
		if(dupmat[pos][pos1]!='#')
		{
			dupmat[pos][pos1]=matrix[pos][pos1];
		}
	}
	printmatrix(flag,n,dupmat);
	return 1;
}
void main()
{
	int n,m;
	    printf("Levels\n");
	    printf("1.EASY\n2.MEDIUM\n3.HARD\n\n");
	    printf("Enter the level: ");
	scanf("%d",&m);
	if(m==1)
	{
		n=7;
	}
	else if(m==2)
	{
		n=8;
	}
	else
	{
		n=9;
	}
	char matrix[n][n],dupmat[n][n],choice;
    int row,col,count=-1,i,flag=1,flg=0,con,pos,pos1,x;
    int rran=0,cran=0,s[10],t[10];
    srand(time(0));
    for(row=0;row<n;row++)
    {
        for(col=0;col<n;col++)
        {
            matrix[row][col]=48;
        }
    }
    for(row=0;row<n;row++)
    {
        count++;
        s[row]=rran;
        t[row]=cran;
        rran = rand() % n;
        cran = rand() % n;
        for(i=0;i<=row;i++)
        {
            if(s[i]==rran&&t[i]==cran)
            {
                flag=0;    
            }
        }
            
            if(flag==1)
            {
            	matrix[rran][cran]= '@';
            	flg+=1;
                bomb(n,matrix,rran,cran);
            }
    }
    printmatrix(flag,n,matrix);  
    for(row=0;row<n;row++)
    {
    	for(col=0;col<n;col++)
    	{
    		dupmat[row][col]=48;
		}
	}
	printmatrix(flag,n,dupmat);
	int cont=flg;
	printf("INITIAL NO OF FLAG ");
	printbox(n-6);
	printf("---> < %d >\n",flg);
	printbox(n);
	do
	{
		printf("\nf->FLAG\nr->REVEAL\ne->EXIT\n");
		printf("enter the option:\n");
		choice=getch();
		switch(choice)
		{
			case 'r':
				{
					printf("\nPlease enter the position to reveal : \t");
					scanf("%d",&x);
					pos=x%10;
					pos1=x/10;
					con=check(flag,n,matrix,dupmat,pos1,pos);
					break;
				}
			case 'f':
				{
					printf("\nPlease enter the position to set the flag:\t");
					scanf("%d",&x);
					pos=x%10;
					pos1=x/10;
					if(dupmat[pos1][pos]=='#')
					{
						flg=flg+1;
					}
					else
					{
						flg-=1;
					}
					if(pos<n&&pos1<n)
					{
						con=updateflag(&cont,flg,n,dupmat,matrix,pos1,pos);
					}
					else
					{
						continue;
					}
					break;
				}
			case 'e':
				{
					exit(0);
				}
		}
	}while(con==1);
}
