#include<stdio.h>
#include<string.h>
struct person
{
    char person_name[100];
    char person_gender[10];
    struct parent
    {
        char father_name[100];
        char father_gender[100];
        char mother_name[100];
        char mother_gender[100];
    }parent;
    struct sibiling
    {
    char sibiling_name[100];
    char gender[10];
    char person_perent_details[100];
    int n;
    }s[10];
}p[100];

int z=0,zz=0;
char m[]="male";
char f[]="female";
char xx[]="xyz";
void main()
{
    int k=1,kk=1;
    while(kk)
    {
        printf("Enter the person %d details : \n",z+1);
        printf("Person Name  : ");
        scanf("%s",p[z].person_name);

        printf("Gender       : ");
        scanf("%s",p[z].person_gender);

        printf("Father Name  : ");
        scanf("%s",p[z].parent.father_name);
        strcpy(p[z].parent.father_gender,"male");

        printf("Mother Name  : ");
        scanf("%s",p[z].parent.mother_name);
        strcpy(p[z].parent.mother_gender,"female");

        printf("\nEnter the sibling details for 1->Father or 2->Mother or 0->No Sibling :  ");
        scanf("%d",&k);
        while(k)
        {

            if(k==1)
            {
                printf("Sibling Name : ");
                scanf("%s",p[z].s[zz].sibiling_name);
                printf("Gender       : ");
                scanf("%s",p[z].s[zz].gender);
                strcpy(p[z].s[zz].person_perent_details,p[z].parent.father_name);
                zz++;
                strcpy(p[z].s[zz].sibiling_name,xx);


            }
            else if(k==2)
            {
                printf("Sibling Name : ");
                scanf("%s",p[z].s[zz].sibiling_name);
                printf("Gender       : ");
                scanf("%s",p[z].s[zz].gender);
                strcpy(p[z].s[zz].person_perent_details,p[z].parent.mother_name);
                zz++;
                strcpy(p[z].s[zz].sibiling_name,xx);

            }
            else
            {
                break;
            }
            printf("\nEnter the sibling details for 1->Father or 2->Mother or 0->No Sibling :  ");
            scanf("%d",&k);

        }
        zz=0;
    printf("\nDo you want do continue another person details press 1 else 0 : ");
    scanf("%d",&kk);
    z++;
    }
    char p_name[100],p_gender[100],p_f_name[100],p_m_name[100];
    printf("Enter the person name : ");
    scanf("%s",p_name);
    printf("person Gender         : ");
    scanf("%s",p_gender);
    int y=0,i=0,yy=0,ii=0,w=0;
    while(y<z)
    {
        if(!(strcmp(p_name,p[y].person_name)))
        {
            strcpy(p_f_name,p[y].parent.father_name);
            strcpy(p_m_name,p[y].parent.mother_name);
            while(yy<z)
            {
                while((strcmp(p[yy].s[ii].sibiling_name,xx)))
                {

                    if(!(strcmp(p[yy].s[ii].person_perent_details,p_f_name)))//
                    {
                        if(!(strcmp(p[yy].s[ii].gender,f)))
                        {
                                while(w<z)
                                {
                                    if(!(strcmp(p[yy].s[ii].sibiling_name,p[w].parent.mother_name)))
                                    {
                                        if((strcmp(p[w].person_gender,p_gender)))
                                        {
                                            printf("%s\n",p[w].person_name);

                                        }

                                    }
                                    w++;
                                }
                        }
                    }
                    else if(!(strcmp(p[yy].s[ii].person_perent_details,p_m_name)))//find person parent name
                    {
                        if(!(strcmp(p[yy].s[ii].gender,m)))//find sibling if opposite gender of the sibling
                        {
                                while(w<z)
                                {
                                    if(!(strcmp(p[yy].s[ii].sibiling_name,p[w].parent.father_name)))
                                    {
                                        if(strcmp(p[w].person_gender,p_gender))
                                        {
                                            printf("%s\n",p[w].person_name);
                                        }

                                    }
                                    w++;
                                }
                        }
                    }

                ii++;
                }
            yy++;
            ii=0;

            }


        }
          y++;
        }
}
