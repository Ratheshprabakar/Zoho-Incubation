#include<stdio.h>
char ins[10];
char input_instruction[20];
int main()
{
	int i=0;
	while(1)
	{
		printf("\nEnter the Command:\t");
		gets(input_instruction);
		int first_space=input_split(&input_instruction,i);
		process(&ins,first_space+1);
	}	   
}
int input_split(char *input_instruction, int i)
{
	int k=0;
	for(i;i<=strlen(input_instruction);i++)
    {
        if(input_instruction[i]==' '||input_instruction[i]=='\0')
        {
            break;
        }
        else
        {
        	ins[k++]=input_instruction[i];
        }
    }
    ins[k]='\0';
    return i;
}
int process(char *ins,int k)
{
	int value=0;
	static int value_array[27];
	char instruction_type[5][10]={"SET","PRINT","ADD","SUB","MUL"};

	//SET
	if(!strcmp(ins,instruction_type[0])) 
	{
		int second_space=input_split(&input_instruction,k);
		char input_var=ins[0];
		if(input_var>='A' && input_var<='Z')
		{
			if(strlen(input_instruction)>7)
			{
				int init=second_space+1,c=10;
				while(init<strlen(input_instruction))
				{
					//printf("%c",input_instruction[init]);
					value=(value*c)+(input_instruction[init]-'0');
					init++;
				}
			}
			else
			{
			
				value=input_instruction[second_space+1]-'0';
			}
		value_array[(input_var-'0')%65]=value;
		printf("%d",value_array[(input_var-'0')%65]);	
		}
		else
		{
			printf("INVALID INSTRUCTION FORMAT");
		}
				
	}
	//PRINT
	else if(!strcmp(ins,instruction_type[1]))
	{
		int second_space=input_split(&input_instruction,k);
		char input_var=ins[0];
		if(input_var>='A' && input_var<='Z')
		{
			if(value_array[(input_var-'0')%65]!=0)
				printf("%d",value_array[(input_var-'0')%65]);
			else
				printf("Variable %c not yet setted",input_var);	
		}
		else
		{
			printf("INVALID INSTRUCTION FORMAT");
		}
		
	}
	//ADD
	else if(!strcmp(ins,instruction_type[2]))
	{
		int second_space=input_split(&input_instruction,k);
		char first_var=ins[0];
		char second_var=input_instruction[second_space+1];
		if((first_var>='A' && first_var<='Z') && (second_var>='A' && second_var<='Z'))
		{
			if(value_array[(first_var-'0')%65]!=0 && value_array[(second_var-'0')%65]!=0)
			{
				value_array[(first_var-'0')%65]=value_array[(first_var-'0')%65]+value_array[(second_var-'0')%65];
				printf("%d",value_array[(first_var-'0')%65]);
			}
			else
			{
				printf("Cannot do this operation");
			}
			
		}
		else if ((first_var>='A' && first_var<='Z') && (second_var>='0' && second_var<='9'))
		{
			if(strlen(input_instruction)>7)
			{
				int init=second_space+1,c=10;
				while(init<strlen(input_instruction))
				{
					//printf("%c",input_instruction[init]);
					value=(value*c)+(input_instruction[init]-'0');
					init++;
				}
			}
			else
			{
				value=input_instruction[second_space+1]-'0';
			}
			if(value_array[(first_var-'0')%65]!=0)
			{
				value_array[(first_var-'0')%65]=value_array[(first_var-'0')%65]+value;
				printf("%d",value_array[(first_var-'0')%65]);

			}
			else
			{
				printf("Cannot do this operation");
			}

		}
		else
		{
			printf("INVALID INSTRUCTION");	
		}
	}
	//SUB
	else if(!strcmp(ins,instruction_type[3])){
		int second_space=input_split(&input_instruction,k);
		char first_var=ins[0];
		char second_var=input_instruction[second_space+1];
		if((first_var>='A' && first_var<='Z') && (second_var>='A' && second_var<='Z'))
		{
			if(value_array[(first_var-'0')%65]!=0 && value_array[(second_var-'0')%65]!=0)
			{
				value_array[(first_var-'0')%65]=value_array[(first_var-'0')%65]-value_array[(second_var-'0')%65];
				printf("%d",value_array[(first_var-'0')%65]);

			}
			else
			{
				printf("Cannot do this operation");
			}
		}
		else if ((first_var>='A' && first_var<='Z') && (second_var>='0' && second_var<='9'))
		{
			if(strlen(input_instruction)>7)
			{
				int init=second_space+1,c=10;
				while(init<strlen(input_instruction))
				{
					//printf("%c",input_instruction[init]);
					value=(value*c)+(input_instruction[init]-'0');
					init++;
				}
			}
			else
			{
				value=input_instruction[second_space+1]-'0';
			}
			if(value_array[(first_var-'0')%65]!=0)
			{
				value_array[(first_var-'0')%65]=value_array[(first_var-'0')%65]-value;
				printf("%d",value_array[(first_var-'0')%65]);
			}
			else
			{
				printf("Cannot do this operation");
			}

		}
		else
		{
			printf("INVALID INSTRUCTION");	
		
		}
	}
	//MUL
	else if(!strcmp(ins,instruction_type[4])){
		int second_space=input_split(&input_instruction,k);
		char first_var=ins[0];
		char second_var=input_instruction[second_space+1];
		if((first_var>='A' && first_var<='Z') && (second_var>='A' && second_var<='Z'))
		{
			if(value_array[(first_var-'0')%65]!=0 && value_array[(second_var-'0')%65]!=0)
			{
				value_array[(first_var-'0')%65]=value_array[(first_var-'0')%65]*value_array[(second_var-'0')%65];
				printf("%d",value_array[(first_var-'0')%65]);
			}
			else
			{
				printf("Cannot do this operation");
			}
			
		}
		else if ((first_var>='A' && first_var<='Z') && (second_var>='0' && second_var<='9'))
		{
			if(strlen(input_instruction)>7)
			{
				int init=second_space+1,c=10;
				while(init<strlen(input_instruction))
				{
					//printf("%c",input_instruction[init]);
					value=(value*c)+(input_instruction[init]-'0');
					init++;
				}
			}
			else
			{
				value=input_instruction[second_space+1]-'0';
			}
			if(value_array[(first_var-'0')%65]!=0)
			{
				value_array[(first_var-'0')%65]=value_array[(first_var-'0')%65]*value;
				printf("%d",value_array[(first_var-'0')%65]);
			}
			else
			{
				printf("Cannot do this operation");
			}
		}
		else
		{
			printf("INVALID INSTRUCTION");	
		}
	}
	else
	{
		printf("INVALID INSTRUCTION");	
	}
}
