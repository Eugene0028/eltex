#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int SIZE_STR;


struct PhoneBook{
	char Number[SIZE];
	char FirstName[SIZE];
	char SecondName[SIZE];
};


void print_menu()
{
	printf("Phone note\n");
	printf("1. Add note\n");
	printf("2. Delete note\n");
	printf("3. View list\n");
	printf("4. Search note\n");
	printf("5. Exit\n");
}



void Add(struct PhoneBook *reg)
{
	
	printf("\nEnter FirstName: ");
	scanf("%s", reg -> FirstName);
	printf("\nEnter SecondName: ");
	scanf("%s", reg -> SecondName);
	printf("\nEnter Number: ");
	scanf("%s", reg -> Number);
}

void Delete(struct PhoneBook *reg)
{
	
	reg -> FirstName[0]= '\0';
	reg -> SecondName[0] = '\0';
	reg -> Number[0] = '\0';
}
void assimilate(char a[], char b[]) {
	int i;
	for(i = 0; i < SIZE; i++) {
		a[i] = b[i];
	}
}
void swap_str(struct PhoneBook  *a, struct PhoneBook *b) {
	struct PhoneBook *tmp = (struct PhoneBook*) calloc(SIZE_STR, sizeof(struct PhoneBook));
	
	assimilate(tmp->Number, a->Number);
	assimilate(a->Number,b->Number);
	assimilate(b->Number, tmp->Number);

	assimilate(tmp->FirstName, a->FirstName);
	assimilate(a->FirstName, b->FirstName);
	assimilate(b->FirstName, tmp->FirstName);
	
	assimilate(tmp->SecondName, a->SecondName);
	assimilate(a->SecondName, b->SecondName);
	assimilate(b->SecondName, tmp->SecondName);
	free(tmp);
}

void sort(struct PhoneBook user1[]) {
	int k = 0, i, j;
       	for(i = 0; i < SIZE_STR; i++) {
       		for(j = i + 1; j < SIZE_STR; j++) {
			k = 0;
			do {
				if((user1[i].FirstName[k] > user1[j].FirstName[k] || user1[i].FirstName[0] == '\0')
						  && user1[j].FirstName[0] != '\0') {
					swap_str(&user1[i], &user1[j]);
				} else if(user1[i].FirstName[k] == user1[j].FirstName[k] ) {
					k++;
					continue;
				}
				break;
			} while(user1[i].FirstName[k] == user1[i].FirstName[k]
					&& k < SIZE
				       	&& user1[j].FirstName[0] != '\0');
		}
     }	
}




void View (struct PhoneBook element) {
	printf("FirstName: %s \n", element.FirstName);
	printf("SecondName: %s \n", element.SecondName);
	printf("Number: %s\n\n", element.Number);
}	





int enter(){
	char *enter = (char*) calloc (SIZE, sizeof(char)); 
	while(1){
		fgets(enter, SIZE, stdin);
		if (0x30 <= enter[0] && enter[0] <= 0x39){
			return enter[0] &= 0x0F;
		}
		else if (enter[0] != 10){
			printf("\nPlease re-enter!\n");
			continue;
		}
	}
}


void Search(struct PhoneBook arr[]){
	char *enter = (char*) calloc (SIZE, sizeof(char)); 
	int i, j, q;
	printf("Please, enter any information for matching\n");
	fgets(enter, SIZE, stdin);
	enter[strlen(enter)-1] = '\0';
	for(i = 0; i < SIZE_STR; i++){
		if ( !strcmp(enter, arr[i].FirstName) || !strcmp(enter, arr[i].SecondName) || !strcmp(enter, arr[i].Number)){
			View(arr[i]);
		}
	}
}

void Menu(){
	int c = 0, num, i;
	struct PhoneBook *arr = 0;
	print_menu();
	while(1)
	{
		switch(enter())
		{
			
			case 1:
				SIZE_STR++;
				arr = (struct PhoneBook*) realloc(arr, SIZE_STR * sizeof(struct PhoneBook));
				Add(&arr[c]);
				c++;
				sort(arr);
				printf("\n");
				print_menu();
				break;	
			case 2:
				printf("\nWhich note you want to delete?: ");
				Delete(&arr[enter()-1]);
				sort(arr);
				SIZE_STR--;
				arr = (struct PhoneBook*) realloc(arr, SIZE_STR * sizeof(struct PhoneBook));
				printf("\n");
				print_menu();
				break;
			case 3:
				for (i = 0; i < SIZE_STR; i++)
				{
					printf("%d. ", i+1);
					View(arr[i]);
				}
				printf("\n");
				print_menu();
				break;
			case 4:
				Search(arr);
				print_menu();
				break;
			case 5:
				free(arr);
				exit(EXIT_SUCCESS);
		}
		
	}
	
}




int main(){
	Menu();
	return 0;

}




