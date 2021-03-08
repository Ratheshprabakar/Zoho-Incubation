#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct customer
{
  int cid;
  char cname[50];
  char phonenum[11];
  char time[6];
  char date[10];
 struct purchase
 {
  int purchased;
  int quantity;
 }p[20];
  
  int total;
}b[100];
struct Date {
    int d, m, y;
}dt1,dt2;

void purchase();
void checklist();
void display();
void returning();
int countLeapYears(struct Date);
int static c=0;
char product[20][50]={"Biscuit","5Star","mongdhal","redchilli","Butter","Rice","Ghee","Gingili-Oil","Sunflower-Oil","Peper",
                     "Colgate-Paste","Brush","Stayfree","Shampoo","Rin-Powder","Lux-Soap","talc-Powder","Facewash","Lion-Dates","Sunrise"};
int cost[20]={25,10,50,30,75,80,50,100,120,20,30,25,35,50,20,40,60,25,90,40};
const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30, 
       31, 31, 30, 31, 30, 31 };
int main()
{
 
  int i,option,j;
  for(i=0;i<100;i++)
  {
    for(j=0;j<20;j++)
      b[i].p[j].purchased=0;
  }
  printf("\n!!!WELCOME TO STORE FOR YOUR NEED!!!3>\n");
  
  while(1)
  {
      printf("\n1.purchase\n2.checklist\n3.display\n4.returning\n5.exit\n");
      printf("Enter your option\n");
      scanf("%d",&option);
      switch(option)
       {
         case 1:purchase();break;
         case 2:checklist();break;
         case 3:display();break;
         case 4:returning();break;
         case 5:exit(1);
         default:printf("INVALID OPTION\n");
       }
  }
 
}
void purchase()
{
  int i,j=0;
  printf("\nITEMS IN THE STORE ARE...\n");
  printf(" ITEM_NO           PRODUCTS            COST/KG in Rs\n");
  for(i=0;i<20;i++)
  {
     printf("%3d     %20s\t  %10d\n",i+1,product[i],cost[i]);
  }
  printf("Enter the item number and quantity to purchase...\n");
  printf("press 0 to stop purchasing ortherwise press 21..\n");
  scanf("%d",&i);
  b[c].total=0;
  while(i)
  {
     
       printf("enter the item number = ");
       scanf("%d",&b[c].p[j].purchased);
       printf("\nenter the quantity  = ");
       scanf("%d",&b[c].p[j].quantity);
       b[c].total+=(cost[(b[c].p[j].purchased)-1])*(b[c].p[j].quantity);
  
       j++;
       printf("\npress 0 to stop purchasing ortherwise press 21..\n");
       scanf("%d",&i); 
  }
  printf("Enter Customer id,Name,mobilenumber,time,date[yy/m/d]\n");
  scanf("%d%s%s%s%s",&b[c].cid,b[c].cname,b[c].phonenum,b[c].time,b[c].date);
  if((strlen(b[c].phonenum)>10 || strlen(b[c].phonenum)<10))
    printf("Inavlid mobile number");
  else
   {
      printf("\nS_no\titem_id\tquantity\tcost\tproduct\n"); 
      for(j=0;b[i].p[j].purchased!=0;j++)
       
      printf("%d\t%d\t%d\t\t%d\t%s\n",j+1,b[c].p[j].purchased,b[c].p[j].quantity,cost[(b[c].p[j].purchased)-1],product[(b[c].p[j].purchased)-1]);
      printf("\n                                           Total=%d\n",b[c].total);
   
      printf("Bill Generating....\n");
  
      printf("\nCustomer_id\tDate\t\ttime\tMobileNumber\tName\n");
  
      
      printf("%d\t\t%s\t%s\t%s\t%s\n",b[c].cid,b[c].date,b[c].time,b[c].phonenum,b[c].cname);
    
      printf("\nS_no\titem_id\tquantity\tcost\tproduct\n");  
      for(j=0;b[c].p[j].purchased!=0;j++)
	{

    printf("%d\t%d\t%d\t\t%d\t%s\n",j+1,b[c].p[j].purchased,b[c].p[j].quantity,cost[(b[c].p[j].purchased)-1],product[(b[c].p[j].purchased)-1]);
	}
     printf("\n                                                Total=%d\n",b[c].total);
     printf("%s Successfully paid\n  **** Thank You **** Visit Again****  \n",b[c].cname);
     printf("\n-------------------------------------------------------\n");
     c++;
    }
}
void checklist()
{
  int id,i,j=0;
  char date1[10],time1[6];
  printf("Enter the Customer Id,Date and time\n");
  scanf("%d%s%s",&id,date1,time1);
  for(i=0;i<c;i++)
  {
      if((id==b[i].cid) && (strcmp(date1,b[i].date)==0)&&(strcmp(time1,b[i].time)==0))
      {
      
	 printf("\nCustomer_id\t\tDate\ttime\tMobileNumber\tName\n");
        
	 printf("%d\t\t%s\t%s\t%s\t%s\n",b[i].cid,b[i].date,b[i].time,b[i].phonenum,b[i].cname);
         printf("\nS_no\titem_id\tquantity\tcost\tproduct\n");
        for(j=0;b[i].p[j].purchased!=0;j++)
        {  if(b[i].p[j].purchased!=-1)
            printf("%d\t%d\t%d\t\t%d\t%s\n",j+1,b[c].p[j].purchased,b[c].p[j].quantity,cost[(b[c].p[j].purchased)-1],product[(b[c].p[j].purchased)-1]);
      
        }
        printf("\n----------------------------------------------------------\n");
        printf("\n                                            Total=%d\n",b[i].total);
      }
  }
}
void display()
{
     int i,j;
    
     printf("\nCustomer_id\tDate\t\ttime\tMobileNumber\tName\n");
     for(i=0;i<c;i++)
      { 
      
        printf("%d\t\t%s\t%s\t%s\t%s\n",b[i].cid,b[i].date,b[i].time,b[i].phonenum,b[i].cname);
        printf("\nS_no\titem_id\tquantity\tcost\tproduct\n");
        for(j=0;b[i].p[j].purchased!=0;j++)
        {if(b[i].p[j].purchased!=-1)
             printf("%d\t%d\t%d\t\t%d\t%s\n",j+1,b[c].p[j].purchased,b[c].p[j].quantity,cost[(b[c].p[j].purchased)-1],product[(b[c].p[j].purchased)-1]);
        }
        printf("\n                                              Total=%d\n",b[i].total);
        printf("\n--------------------------------------------------------\n");
       }
}

void returning()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char purchased_date[20];
  int i,r=1000,temp,num=0,item_id,quantity,c_id,option,j,k,temp1;
   long int n1 ,n2;
  struct Date dt1,dt2;
  
  printf("enter purchased date formate: yy/m/d\n");
  scanf("%s",purchased_date);
  printf("now: %d/%02d/%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday); 
  for(i=0;i<4;i++)
  {
        num+=(purchased_date[i]-48)*r;
        r/=10;
  }
  
  dt1.y=num;
  num=0;
  
  num+=(purchased_date[5]-48)*10;

  num+=(purchased_date[6]-48)*1;
  dt1.m=num;
 
  num=0;
  num+=(purchased_date[8]-48)*10;

  num+=(purchased_date[9]-48)*1;
 
  dt1.d=num;
 
  dt2.y=tm.tm_year + 1900;
  dt2.m=tm.tm_mon + 1;
  dt2.d=tm.tm_mday;
 n1 = dt1.y * 365 + dt1.d;
 
    // Add days for months in given date
    for ( i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];
 
    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);
 
    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'
 
    n2 = dt2.y * 365 + dt2.d;
    for ( i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
 
    // return difference between two counts
    temp1= (n2 - n1);
    printf("%d\n",temp1);
  if(temp1<=10)
  {
     printf("enter the cutomer id item id and quantity that you brought\n");
     scanf("%d%d%d",&c_id,&item_id,&quantity);
     for(i=0;i<c;i++)
     {
      
         if((c_id==b[i].cid)&& strcmp(b[i].date,purchased_date)==0)
         {
            temp=i;
           
            for(j=0;b[temp].p[j].purchased!=0;j++)
            { 
                  if((item_id==b[temp].p[j].purchased)&&(b[temp].p[j].quantity==quantity))
                  {
                     
                
                                  b[temp].total-=(cost[item_id-1])*(quantity);
                             
                             
                              b[temp].p[j].purchased=-1;
                                    b[temp].p[j].quantity=-1;
                      
                  }
            }
            
        
         }
     printf("rr\n");
     }
         printf("\nCustomer_id\t\t\tName\t\tmobile_number\t\ttime\t\tdate\n");
         printf("%2d\t\t\t%10s\t\t%10s\t\t%10s\t\t%10s\n",b[temp].cid,b[temp].cname,b[temp].phonenum,b[temp].time,b[temp].date);
        for(j=0;b[temp].p[j].purchased!=0;j++)
        {   if(b[temp].p[j].purchased!=-1)
                printf("%2d\t\t%d\t\t\t%10s\t\t%10d  \t\t%10d\n",j+1,b[temp].p[j].purchased,product[(b[temp].p[j].purchased)-1],cost[(b[temp].p[j].purchased)-1],b[temp].p[j].quantity);
      
        }
        printf("\n-------------------------------------------------------------------\n");
        printf("\n                                                          Total=%d\n",b[temp].total);
            
  }
  else
  {
  printf("sorry you can't return your products\n");
  }
}
int countLeapYears( struct Date d)
{
    int years = d.y;
 
    // Check if the current year needs to be
    //  considered for the count of leap years
    // or not
    if (d.m <= 2)
        years--;
 
    // An year is a leap year if it 
    // is a multiple of 4,
    // multiple of 400 and not a 
     // multiple of 100.
    return years / 4 
           - years / 100
           + years / 400;
}

