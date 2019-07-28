#include<stdio.h>
struct student{
	char fname[20]; 
	char lname[20];
	int id;

};
void writeStruct(){
	struct student s1;
	FILE *outfile;
	outfile = fopen ("person.txt","w");
	int x;
	if(outfile == NULL){
		printf("Error\n");
	}
	else
	{
		while(1){
			printf("Enter name:");
			scanf("%s",s1.fname);
			printf("Enter lastname:");
			scanf("%s",s1.lname);
			printf("Enter id:");
			scanf("%d",&s1.id);
			printf("Enter -1 to end: ");
			scanf("%d",&x);
			fwrite(&s1, sizeof(struct student),1,outfile);
			
			if(x==-1)
				break;
		}
		fclose(outfile); 
		
	}
}
void readStruct(){
	FILE *infile;
	struct student s2;
	infile = fopen("person.txt","r");
	if(infile == NULL){
		printf("Error\n");
	}
	else
	{
		while(fread(&s2,sizeof(struct student),1,infile)){
			printf("id= %d name= %s %s\n",s2.id,s2.fname,s2.lname);
		}
		fclose(infile);
	}
	
}

int main(){
	int n;
	do{
		printf("1. Register all students\n2. Display all students\n3. Exit\n");
		scanf("%d",&n);
		if(n==1){
			writeStruct();
		}
		if(n==2){
			readStruct();
		}
		if(n==3){
			break;
		}
	}while(1);

	return 0;

}
