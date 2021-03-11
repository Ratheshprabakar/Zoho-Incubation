#include<stdio.h>
#include<stdlib.h>
void printbox();
int print_fun();
int matrix[4][4];
void check_fun();
void check_fun()
{
    int k=1,count=0,flg=1;;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(matrix[i][j]==k)
            {
                count++;
                k++;
                if(count==15)
                {
                printf("\nCongratulation.....!!!!");
                exit(0);
                }
            }
            else if()
            {
                flg=0;
                break;
            }
        }
    }
}
void printbox()
{
	for(int row=0;row<20;row++)
	{
		printf("-");
	}
	printf("-\n");
}

int print_fun()
{
    system("cls");
    printbox();
    for(int i=0;i<4;i++)
    {
        printf("|");
        for(int j=0;j<4;j++)
        {
            if(matrix[i][j]==0)
            {
                printf("    |");
            }
            else if(matrix[i][j]<10)
            {
                printf(" 0");
                printf("%d |",matrix[i][j]);
            }
            else
            {
                printf(" %d |",matrix[i][j]);
            }

        }
        printf("\n");
        printbox();
    }
    return 0;
}

void main()
{
    int check_arr[100],count=0,k,array_len=0,l=0,flag=0;
    while(count<16)
    {
        k=rand()%16;
        while(l<=array_len)
        {
            if(check_arr[l]==k)
            {
                flag=1;
                break;
            }
            l++;
        }
        if(flag==0)
        {
            check_arr[array_len]=k;
            array_len++;
            count++;
        }
        flag=0;
        l=0;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            matrix[i][j]=check_arr[array_len-1];
            array_len-=1;
        }
    }

    printbox();
    for(int i=0;i<4;i++)
    {
        printf("|");
        for(int j=0;j<4;j++)
        {
            if(matrix[i][j]==0)
            {
                printf("    |");
            }
            else if(matrix[i][j]<10)
            {
                printf(" 0");
                printf("%d |",matrix[i][j]);
            }
            else
            {
                printf(" %d |",matrix[i][j]);
            }

        }
        printf("\n");
        printbox();
    }
    int choice,temp;
    while(1)
    {
        print_fun();
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(matrix[i][j]==0)
                {
                    printf("Enter the element : ");
                    scanf("%d",&choice);
                    if(j-1>=0 && matrix[i][j-1]==choice)
                    {
                        temp=matrix[i][j];
                        matrix[i][j]=matrix[i][j-1];
                        matrix[i][j-1]=temp;
                        print_fun();
                        check_fun();
                        i=0;j=-1;
                    }
                    else if(j+1<=3 && matrix[i][j+1]==choice)
                    {
                        temp=matrix[i][j];
                        matrix[i][j]=matrix[i][j+1];
                        matrix[i][j+1]=temp;
                        print_fun();
                        check_fun();
                        i=0;j=-1;
                    }
                    else if(i-1>=0 && matrix[i-1][j]==choice)
                    {
                        temp=matrix[i][j];
                        matrix[i][j]=matrix[i-1][j];
                        matrix[i-1][j]=temp;
                        print_fun();
                        check_fun();
                        i=0;j=-1;
                    }
                    else if(i+1<=3 && matrix[i+1][j]==choice)
                    {
                        temp=matrix[i][j];
                        matrix[i][j]=matrix[i+1][j];
                        matrix[i+1][j]=temp;
                        print_fun();
                        check_fun();
                        i=0;j=-1;
                    }
                    else
                    {
                        printf("\nIncorrect choice...please try again\n");
                        i=0;j=0;
                    }
                }

            }
        }
        break;
    }
}


