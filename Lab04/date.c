//Date handler
//lab04_2

#include <stdio.h>

int main() {

	printf("Give me the date in format dd/mm/yyyy. I will translate it in a more expressive language.\n");
	int day, month, year;
	printf("Day: \n");
	scanf("%d", &day);
	printf("Month: \n");
	scanf("%d", &month);
	printf("Year: \n");
	scanf("%d", &year);

	if(month < 1 || month >12 || day < 1 || day > 31){
		printf("ERROR");
	} else {
		switch(day){
		default:
			printf("%dth ", day);
			break;
		case 1:
			printf("%dst ", day);
			break;
		case 2:
			printf("%dnd ", day);
			break;
		case 3:
			printf("%drd ", day);
	}
		switch(month){
			case 1:
				printf("January ");
				break;
			case 2:
				printf("February ");
				break;
			case 3:
				printf("March ");
				break;
			case 4:
				printf("April ");
				break;
			case 5:
				printf("May ");
				break;
			case 6:
				printf("June ");
				break;
			case 7:
				printf("July ");
				break;
			case 8:
				printf("August ");
				break;
			case 9:
				printf("September ");
				break;
			case 10:
				printf("October ");
				break;
			case 11:
				printf("November ");
				break;
			case 12:
				printf("December");
				break;
		}
		printf("%d", year);
	}

	return 0;
}
