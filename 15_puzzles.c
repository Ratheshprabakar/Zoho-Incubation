#include<stdio.h>
#include<stdlib.h>
void create_board(int *board_matrix_copy);
void printbox();
void puzzle_arrangement(int *board_matrix_copy);
int check_fun(int *board_matrix_copy);

//function to create matrix
void create_board(int *board_matrix_copy)
{
	int row,col,i,check_array_copy[100],check_arr_len=0;
	while(1)
	{
		int init=0;
		int random_num=rand()%16;
		while(init<check_arr_len)
		{
			if(check_array_copy[init]==random_num)
			{
				if(random_num==15)
				{
					random_num=-1;
				}
				random_num++;
				init=-1;
			}
			init++;
		}
		check_array_copy[check_arr_len]=random_num;
		check_arr_len+=1;
		if(check_arr_len==16)
		{
			break;
		}	
	}
	for(row=0;row<4;row++)
	{
		for(col=0;col<4;col++)
		{
			check_arr_len-=1;
			*((board_matrix_copy+row*4)+col)=check_array_copy[check_arr_len];	
		}
	}
}

void printbox()
{
	int row;
	for(row=0;row<20;row++)
	{
		printf("-");
	}
	printf("-\n");
}

//Function to print matrix
int print_fun(int *board_matrix_copy)
{
	int row,col;
    system("cls");
    printbox();
    for(row=0;row<4;row++)
    {
        printf("|");
        for(col=0;col<4;col++)
        {
            if(*((board_matrix_copy+row*4)+col)==0)
            {
                printf("    |");
            }
            else if(*((board_matrix_copy+row*4)+col)<10)
            {
                printf(" 0");
                printf("%d |",*((board_matrix_copy+row*4)+col));
            }
            else
            {
                printf(" %d |",*((board_matrix_copy+row*4)+col));
            }

        }
        printf("\n");
        printbox();
    }
    return 0;
}

//Function to move the tiles
void puzzle_arrangement(int *board_matrix_copy)
{
	int choice,temp,row,col;
    while(1)
    {
        print_fun(board_matrix_copy);
		for(row=0;row<4;row++)
        {
            for(col=0;col<4;col++)
            {
                if(*((board_matrix_copy+row*4)+col)==0)
                {
                	 if(row==3 && col==3)
                    {
                       	check_fun(board_matrix_copy);
					}
                    printf("Enter the element : ");
                    scanf("%d",&choice);
                    if(col-1>=0 && *((board_matrix_copy+row*4)+(col-1))==choice)
                    {
                        temp=*((board_matrix_copy+row*4)+col);
                        *((board_matrix_copy+row*4)+col)=*((board_matrix_copy+row*4)+col-1);
                        *((board_matrix_copy+row*4)+col-1)=temp;
                        print_fun(&(*board_matrix_copy));
                        row=0;col=-1;
                    }
                    else if(col+1<=3 && *((board_matrix_copy+row*4)+col+1)==choice)
                    {
                        temp=*((board_matrix_copy+row*4)+col);
                        *((board_matrix_copy+row*4)+col)=*((board_matrix_copy+row*4)+col+1);
                        *((board_matrix_copy+row*4)+col+1)=temp;
                        print_fun(&(*board_matrix_copy));
                        row=0;col=-1;
                    }
                    else if(row-1>=0 && *((board_matrix_copy+(row-1)*4)+col)==choice)
                    {
                        temp=*((board_matrix_copy+row*4)+col);
                        *((board_matrix_copy+row*4)+col)=*((board_matrix_copy+(row-1)*4)+col);
                        *((board_matrix_copy+(row-1)*4)+col)=temp;
                        print_fun(&(*board_matrix_copy));
                        row=0;col=-1;
                    }
                    else if(row+1<=3 && *((board_matrix_copy+(row+1)*4)+col)==choice)
                    {
                        temp=*((board_matrix_copy+row*4)+col);
                        *((board_matrix_copy+row*4)+col)=*((board_matrix_copy+(row+1)*4)+col);
                        *((board_matrix_copy+(row+1)*4)+col)=temp;
                        print_fun(&(*board_matrix_copy));
                        row=0;col=-1;
                    }
                    else
                    {
                        printf("\nUnable to move : \n");
                        row=0;col=0;
                    }
                }
			
            }
        }
    }
}

// Puzzle Validation
int check_fun(int *board_matrix_copy)
{
    int value=1,count=0,row,col;
    for(row=0;row<4;row++)
    {
        for(col=0;col<4;col++)
        {
            if(*((board_matrix_copy+row*4)+col)==value)
            {
                count++;
                value++;
                if(count==15)
                {
                printf("\nCongratulation.....!!!!");
                exit(0);
                }
            }
            else
            {
                return;
            }
        }
    }
}

void main()
{
	int row,col;
	int board_matrix[4][4];
	create_board(&board_matrix);
	print_fun(&board_matrix);
	puzzle_arrangement(&board_matrix);
