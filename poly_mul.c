#include<stdio.h>

struct values
{
    char variable_name;
    int power_value;
};

struct expression
{
    int coef;
    int no_variables;
    struct values v[100];
};

struct polynomial
{
    int no_terms;
    struct expression e[100];
};
struct polynomial p[100];

int a=0,b=0,zz=0;

void main()
{
    int count=1,k=0,l=0,sum=0,c=1,z=0,temp=1,m=0,t=1,cc=0;
    char str1[100],str2[100];
    int str1_len,str2_len;
    for(int i=0;i<2;i++)
    {
        printf("Enter the Polynomial %d : ",i+1);
        gets(str1);
        str1_len=strlen(str1);
        for(int i=0;i<str1_len;i++)
        {
            if((str1[i]=='+' || str1[i]=='-' ) && (str1[i-1]!='^'))
            {
                count++;
            }
        }
        p[k].no_terms=count;
        for(int i=0;i<=str1_len;i++)
        {
            if(i==0 && str1[i]=='-')
            {
                i++;
            }
            if((str1[i]=='+' || str1[i]=='-' || i==str1_len) && (str1[i-1]!='^'))
            {
                for(int j=z;j<i;j++)
                {
                    if(str1[z]=='-')
                    {
                        temp=-1;
                        j++;
                    }
                    while(str1[j]>=48 && str1[j]<=58)
                    {
                        sum=(sum*c)+(str1[j]-'0');
                        if(c==1)
                        {
                            c=10;
                        }
                        j++;
                    }
                    p[k].e[l].coef=sum*temp;
                    temp=1;
                    sum=0;
                    c=1;
                    while(j<i)
                    {
                        if(str1[j]>=97 && str1[j]<=122)
                        {
                            p[k].e[l].v[m].variable_name=str1[j];
                            cc++;
                            j++;
                            if(str1[j]==94)
                            {
                                j++;
                                if(str1[j]=='-')
                                {
                                    t=-1;
                                    j++;
                                }
                                while(str1[j]>=48 && str1[j]<=58)
                                {
                                    sum=(sum*c)+(str1[j]-'0');
                                    if(c==1)
                                    {
                                        c=10;
                                    }
                                    j++;
                                }
                                p[k].e[l].v[m].power_value=sum*t;
                                sum=0;
                                c=1;
                                t=1;
                                m++;

                            }
                            else
                            {
                                p[k].e[l].v[m].power_value=t;
                                m++;
                            }
                        }
                        else{
                            j++;
                        }
                    }
                    p[k].e[l].no_variables=cc;
                    cc=0;
                }
                z=i;
                if(str1[z]=='-')
                {
                    temp=-1;
                }
                z++;
                l++;
                m=0;
            }
        }
        k++;
        l=0;
        count=1;
        z=0;
    }
    p[2].no_terms=((p[0].no_terms)*(p[1].no_terms));
    for(int i=0;i<p[0].no_terms;i++)
    {
        for(int j=0;j<p[1].no_terms;j++)
        {
            if(p[0].e[i].no_variables==0)
            {
                p[2].e[a].coef=((p[0].e[i].coef)*(p[1].e[j].coef));
                int n=p[1].e[j].no_variables;
                int nn=0;
                while(nn<n)
                {
                    p[2].e[a].v[b].variable_name=p[1].e[j].v[nn].variable_name;
                    p[2].e[a].v[b].power_value=p[1].e[j].v[nn].power_value;
                    b++;
                    nn++;
                }
            }
            for(int k=0;k<p[0].e[i].no_variables;k++)
            {
                if(p[1].e[j].no_variables==0)
                {
                    p[2].e[a].coef=((p[0].e[i].coef)*(p[1].e[j].coef));
                    int n=p[0].e[i].no_variables;
                    int nn=0;
                    while(nn<n)
                    {
                        p[2].e[a].v[b].variable_name=p[0].e[i].v[nn].variable_name;
                        p[2].e[a].v[b].power_value=p[0].e[i].v[nn].power_value;
                        b++;
                        nn++;
                    }
                    break;
                }
                for(int l=0;l<p[1].e[j].no_variables;l++)
                {
                    if(b==0)
                    {
                        p[2].e[a].coef=((p[0].e[i].coef)*(p[1].e[j].coef));
                        if(p[0].e[i].v[k].variable_name==p[1].e[j].v[l].variable_name)
                        {
                            p[2].e[a].v[b].variable_name=p[0].e[i].v[k].variable_name;

                            p[2].e[a].v[b].power_value=(p[0].e[i].v[k].power_value+p[1].e[j].v[l].power_value);
                            b++;
                        }
                        else
                        {
                            p[2].e[a].v[b].variable_name=p[0].e[i].v[k].variable_name;
                            p[2].e[a].v[b].power_value=p[0].e[i].v[k].power_value;
                            b++;
                            p[2].e[a].v[b].variable_name=p[1].e[j].v[l].variable_name;
                            p[2].e[a].v[b].power_value=p[1].e[j].v[l].power_value;
                            b++;
                        }
                    }
                    else
                    {
                        if(k>l)
                        {
                            int flag=0;
                            while(zz<b)
                            {
                                if(p[2].e[a].v[zz].variable_name==p[0].e[i].v[k].variable_name)
                                {
                                    p[2].e[a].v[zz].power_value=(p[2].e[a].v[zz].power_value+p[0].e[i].v[k].power_value);
                                    flag=1;
                                    break;
                                }
                                zz++;
                            }
                            if(flag==0)
                            {
                                p[2].e[a].v[b].variable_name=p[0].e[i].v[k].variable_name;
                                p[2].e[a].v[b].power_value=p[0].e[i].v[k].power_value;
                                b++;
                            }
                        zz=0;
                        }
                        else if(k<l)
                        {
                            int flag=0;
                            while(zz<b)
                            {
                                if(p[2].e[a].v[zz].variable_name==p[1].e[j].v[l].variable_name)
                                {
                                    p[2].e[a].v[zz].power_value=(p[2].e[a].v[zz].power_value+p[0].e[i].v[k].power_value);
                                    flag=1;
                                    break;
                                }
                                zz++;
                            }
                            if(flag==0)
                            {
                                p[2].e[a].v[b].variable_name=p[1].e[j].v[l].variable_name;
                                p[2].e[a].v[b].power_value=p[1].e[j].v[l].power_value;
                                b++;
                            }
                            zz=0;
                        }
                    }
                }
            }
            p[2].e[a].no_variables=b;
            a++;
            b=0;
        }
    }


    int flag=0,a=0,b=0;
    count=0;
    for(int i=0;i<p[2].no_terms-1;i++)
    {
        for(int j=i+1;j<p[2].no_terms;j++)
        {
            if((p[2].e[j].coef)==0 || (p[2].e[i].coef)==0)
            {
                break;
            }
            if((p[2].e[i].no_variables==p[2].e[j].no_variables))
            {
                for(int k=0;k<p[2].e[i].no_variables;k++)
                {
                    for(int l=0;l<p[2].e[j].no_variables;l++)
                    {
                        if(p[2].e[i].v[k].variable_name==p[2].e[j].v[l].variable_name)
                        {
                            flag=1;
                            count++;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        flag=2;
                        break;
                    }
                    flag=0;
                }
                if(count==p[2].e[i].no_variables)
                {
                    p[2].e[i].coef=(p[2].e[i].coef+p[2].e[j].coef);
                    p[2].e[j].coef=0;
                    int n=p[2].e[i].no_variables;
                    int kk=0;
                    while(kk<n)
                    {
                        p[2].e[i].v[kk].power_value=(p[2].e[i].v[kk].power_value+p[2].e[j].v[kk].power_value);
                        kk++;
                    }
                }
                count=0;

            }
        }
    }
    printf("\n RESULT : ");
  for(int i=0;i<p[2].no_terms;i++)
    {
        if((p[2].e[i].coef)!=0)
        {

            printf("%d",p[2].e[i].coef);
            for(int j=0;j<p[2].e[i].no_variables;j++)
            {

                printf("%c^%d",p[2].e[i].v[j].variable_name,p[2].e[i].v[j].power_value);
            }
            if(p[2].e[i+1].coef>=0)
            {
                printf("+");
            }
        }
    }
    printf("\b \n\n");
}




