#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	struct University
	{
		char name[50];
		char city[20];
		char state[3];
		int rank;
		int tuition;
	};
	
	struct University university[10];
	
	struct University inputData(char n[50],char c[20],char s[3],int r,int t){
		struct University *uni = malloc(sizeof(struct University));
		strcpy(uni->name, n);
		strcpy(uni->city, c);
		strcpy(uni->state, s);
		uni->rank = r;
		uni->tuition = t;
		
		return *uni;
	};
	
    university[0] = inputData("Princeton University","Princeton","NJ",1,45320);
	
	university[1] = inputData("University of Virginia","Charlottesville","VA",24,52040);
	
	university[2] = inputData("Boston College","Chestnut Hill","MA",31,51296);
	
	university[3] = inputData("Georgia Institute of Technology","Atlanta","GA",34,32404);
	
	university[4] = inputData("Lehigh University","Bethlehem","PA",44,48320);
	
	university[5] = inputData("University of Chicago","Chicago","IL",3,52491);
	
	university[6] = inputData("Duke University","Durham","NC",8,51265);
	
	university[7] = inputData("University of Georgia","Athens","GA",56,29844);
	
	university[8] = inputData("University of Denver","Denver","CO",86,46362);
	
	university[9] = inputData("Loyola University Chicago","Chicago","IL",99,26270);
	
	void printInfo(struct University u){
		printf("\nName: %s   City: %s   State: %s   Rank: %d   Tuition: %d\n", u.name,u.city,u.state,u.rank,u.tuition);
	}
	
	// I hope it's okay that I made another function so that I wouldn't have to use printInfo 10 times to print the whole database.
	void printAll(){
		int i;
		for (i=0;i<10;i++){
			printInfo(university[i]);
		}
	}
	
	void printTopUniversity(int n){
		int i;
		for (i=0;i<10;i++){
			if (university[i].rank <= n){
				printInfo(university[i]);
			}
		}
	}
	
	void printStateofUniversity(char c[3]){
		int i;
		for (i=0;i<10;i++){
			if(strcmp(university[i].state,c) == 0){
				printInfo(university[i]);
			}
		}
	}
	
	void printMinMaxTuitionUniversity(){
		int i;
		struct University MinMax[2];
		MinMax[0] = university[0]; // MinMax[0] is where the lowest tuition is stored
		MinMax[1] = university[0]; // MinMax[1] is where the highest tuition is stored
		for (i=0;i<10;i++){
			if (university[i].tuition < MinMax[0].tuition){
				MinMax[0] = university[i];
			}
		}
		for (i=0;i<10;i++){
			if (university[i].tuition > MinMax[1].tuition){
				MinMax[1] = university[i];
			}
		}
		printInfo(MinMax[0]);
		printInfo(MinMax[1]);
	}
	
	void printSortedUniversity(){
		struct University sort[10];
		struct University temp[1];
		int i,j,k,l;
		for (k=0;k<10;k++){
			sort[k]=university[k];
		}
		for (i=0;i<10;i++){
			for (j=0;j<9;j++){
				if (sort[j].tuition > sort[j+1].tuition){
					temp[0] = sort[j];
					sort[j] = sort[j+1];
					sort[j+1] = temp[0];
				}
			}
		}
		for (l=0;l<10;l++){
			printInfo(sort[l]);
		}
	}
	
	printAll(); //this is printInfo, but just loops 10 times instead of putting printInfo(university[0-9]); 10 times
	printf("--------------------------");
	printTopUniversity(50);
	printf("--------------------------");
    printStateofUniversity("GA");
	printf("--------------------------");
	printMinMaxTuitionUniversity();
	printf("--------------------------");
	printSortedUniversity();

    return 0;
}