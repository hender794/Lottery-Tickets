/*
* Auth: Jake Henderson
* Date: 12-16-24 (Due: 12-20-24)
* Course: CSCI-4350
* Desc: Project 3
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int check_matches(int generated[], int input[], int matches[], int cnt);
int generate(int generated[], int cnt);
int find(int generated[], int num, int cnt);
void sort(int generated[], int cnt);
int check_bonus(int generated[], int input[], int cnt);
void drawing(int generated[], int input[], int drawing_num, int bonus);

int main(void) {
	int generated[6];  
	int input[7];
    int drawing_num;
    int i;
    int bonus;

    srand(time(NULL));

	printf("Please give 7 numbers from 1-45: ");
	for (i = 0; i < 7; i++) {
	    scanf("%d", &input[i]);
	    }
	
	bonus = input[6];

	printf("How many drawings would you like to have between 1-100?: ");
	scanf("%d", &drawing_num);

    drawing(generated, input, drawing_num, bonus);

    return 0;
}

void sort (int generated[], int cnt) {
    int temp;
    int i;
    int j;

    for ( i = 0; i < cnt - 1; i++) {
        for ( j = i + 1; j < cnt; j++) {
            if (generated[i] > generated[j]) {
                temp = generated[i];
                generated[i] = generated[j];
                generated[j] = temp;
            }
        }
    }
}

int check_matches(int generated[], int input[], int matches[], int cnt) {
    int match_count = 0;
    int i;
    int j;

    for ( i = 0; i < cnt; i++) {
        for ( j = 0; j < 7; j++) {
            if (generated[i] == input[j]) {
            	matches[match_count] = generated[i];
                match_count++;
            }
        }
    }
    return match_count;
}

int check_bonus(int generated[], int input[], int cnt) {
	int i;

    for (i = 0; i < cnt; i++) {
        if (generated[i] == input[6]) {  
            return 1;
        }
    }
    return 0;
}

void drawing (int generated[], int input[], int drawing_num, int bonus){
	int wins = 0;
	int drawing_count;
	int match_count;
	int matches[6];
	int i;
	int bonus_match;
	int cnt = 6;

	for (drawing_count = 1; drawing_count <= drawing_num; drawing_count++) {
		printf("Drawing %d: ", drawing_count );

		generate(generated, cnt);
    	sort(generated, cnt);

	    printf("Generated numbers: [");
	    printf("%d", generated[0]);
	    for ( i = 1; i < 6; i++) {
	        printf(", %d", generated[i]);
	    }
	    printf("]: ");

	    match_count = check_matches(generated, input, matches, 6);
	    bonus_match = check_bonus(generated, input, 6);

		if (match_count == 6) {
			printf("Matched numbers: [");
			printf("%d", matches[0]);
            for ( i = 1; i < match_count; i++) {
                printf(", %d", matches[i]);
            }
			printf("]. All matches! 1st prize!!! :)\n");
			wins++;
		}
		else if (match_count == 5 && bonus_match == 1) {
			printf("Matched numbers: [");
			printf("%d", matches[0]);
            for ( i = 1; i < match_count; i++) {
                printf(", %d", matches[i]);
            }
			printf("] and bonus [%d]. 2nd prize!! :)\n", bonus);
			wins++;
		}
		else if (match_count == 5 && bonus_match == 0) {
			printf("Matched numbers: [");
			printf("%d", matches[0]);
            for ( i = 1; i < match_count; i++) {
                printf(", %d", matches[i]);
            }
			printf("]. 3rd prize! :)\n");
			wins++;
		}
		else if (match_count == 4){
			printf("Matched numbers: [");
			printf("%d", matches[0]);
            for ( i = 1; i < match_count; i++) {
                printf(", %d", matches[i]);
            }
			printf("]. 4th prize! :)\n");
			wins++;
		}
		else if (match_count == 3){
			printf("Matched numbers: [");
			printf("%d", matches[0]);
            for ( i = 1; i < match_count; i++) {
                printf(", %d", matches[i]);
            }
			printf("]. 5th prize! :)\n");
			wins++;
		}  
		else if (match_count == 2 || match_count == 1){
			printf("Matched numbers: [");
			printf("%d", matches[0]);
            for ( i = 1; i < match_count; i++) {
                printf(", %d", matches[i]);
            }
			printf("]. Lose :(\n");
		} 
		else {
			printf("No matching numbers. Lose :(\n");
		}
	}
	printf("\nYou win: %d\n", wins);
}

int generate(int generated[], int cnt) {
    int i = 0;
    int num = 0;

    while (i < cnt) {
        num = rand() % 45 + 1;
        
        if (find(generated, num, i) == -1) {
            generated[i] = num;
            i++;
        }
    }
    return 0;
}

int find(int generated[], int num, int cnt) {
	int i;
	int value = -1;

	for (i = 0; i < cnt; i++) {
        if (generated[i] == num){
        	value = i;
        	return value;
        }
    }
    return value;
}





