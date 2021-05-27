#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "server.h"

char sorted_array[1000][1000];//array to store data from file
int r=0,n=0;//n is the number of elements in the array 



void sort_alpha()//function to sort strings alphabeticaly
{
	int f=0,swap1=1;char temp[1000];
	while(f<n-1 && swap1)
	{
		for(int j=0;j<n-f-1;j++)
		{


			 if(strcasecmp(sorted_array[j],sorted_array[j+1])>0)//bubble sort is used as it is the most efficient sorting logic
			{
				strcpy(temp,sorted_array[j]);
				strcpy(sorted_array[j],sorted_array[j+1]);
				strcpy(sorted_array[j+1],temp);
				swap1=1;
			}
			else
				swap1=0;

		}
		f++;
	}
	for(int j=0;j<n-1;j++)
	{
		if(strcasecmp(sorted_array[j],sorted_array[j+1])==0)//condition to check if elements are same after ignoring case
			{
				if(strcmp(sorted_array[j],sorted_array[j+1])<0)//code helps store lower case strings before upper case
				{
					strcpy(temp,sorted_array[j]);
					strcpy(sorted_array[j],sorted_array[j+1]);
					strcpy(sorted_array[j+1],temp);
				}
			}
	}



}

void sort_reverse()//function to sort strings in descending order
{
	int swap2=1,i=0;char temp[1000];
	while(i<n-1 && swap2)
	{
		for(int j=0;j<n-i-1;j++)
		{

			if(strcasecmp(sorted_array[j+1],sorted_array[j])>0)//bubble sort is used as it is the most efficient sorting logic
			{
				strcpy(temp,sorted_array[j]);
				strcpy(sorted_array[j],sorted_array[j+1]);
				strcpy(sorted_array[j+1],temp);
				swap2=1;
			}
			else
				swap2=0;

		}
		i++;
	}
	for(int j=n-1;j>=0;j--)
	{
		if(strcasecmp(sorted_array[j],sorted_array[j-1])==0)
			{
				if(strcmp(sorted_array[j],sorted_array[j-1])<0)
				{
					strcpy(temp,sorted_array[j]);
					strcpy(sorted_array[j],sorted_array[j-1]);
					strcpy(sorted_array[j-1],temp);
				}
			}
	}
}

void sort_ignore_case()//function to sort strings after ignoring their case
{
	int k=0,swap3=1;char temp[1000];
	while(k<n-1 && swap3)
	{
		for(int j=0;j<n-k-1;j++)
		{
			if(strcasecmp(sorted_array[j],sorted_array[j+1])>0)//strcasecmp is used to compare strings without considering case
			{
				strcpy(temp,sorted_array[j]);
				strcpy(sorted_array[j],sorted_array[j+1]);
				strcpy(sorted_array[j+1],temp);
				swap3=1;
			}
			else
				swap3=0;

		}
		k++;
	}

}

int input_and_display_fileinfo()//function for file handeling
{
    int no_of_files;
    FILE *fp;
    char filename[100][100];

    printf("\nEnter number of files to be sorted\n");
	scanf("%d",&no_of_files);
	for(int inp=1;inp<=no_of_files;inp++)
	{
		printf("\nPlease Enter the name of  file %d \n",inp);
		scanf("%s",filename[inp-1]);
		fp = fopen(filename[inp-1], "r");//open file in read mode
		if (fp == NULL)//if file is not found it prints could not open file
		{
        		printf("Could not open file\n ");
        		return 1;
    		}
   		while (feof(fp)==0)//checks if file end is reached
		{
        		fscanf(fp,"%s",sorted_array[r]);//stores strings in a 2D array
			r++;

		}

		fclose(fp);//close file
	}
	n=r;
	return 0;

}

void  sort_switchcase()//function to print menu
{

	int choice=0;
	while(1)
	{
		printf("Enter 1 to sort alphabetically,2 to reverse sort , 3 to ignore case and sort and 4 to quit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				sort_alpha();
				for(int p=0;p<=n;p++)
					printf("%s\n",sorted_array[p]);
				break;
			}
			case 2:
			{
				sort_reverse();
				for(int q=0;q<=n;q++)
					printf("%s\n",sorted_array[q]);
				break;
			}
			case 3:
			{
				sort_ignore_case();
				for(int s=0;s<=n;s++)
					printf("%s\n",sorted_array[s]);
				break;
			}
			case 4:
				exit(0);
			break;
			default:
				printf("Invalid choice\n");
		}
	}



}







