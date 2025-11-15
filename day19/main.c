#include <stdio.h>

int main() {

    int attendance[5][5];
    int marks[5][5];
    char names[5][20];
    int i, j, choice;

    for(i=0;i<5;i++){
        printf("enter name of student %d: ", i+1);
        scanf("%s", names[i]);
    }

    printf("\nenter attendance matrix (1 present, 0 absent):\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d", &attendance[i][j]);
        }
    }

    printf("\nenter marks matrix:\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d", &marks[i][j]);
        }
    }

    while(1){
        printf("\n========= menu =========\n");
        printf("1. display attendance matrix\n");
        printf("2. display marks matrix\n");
        printf("3. attendance report\n");
        printf("4. performance report\n");
        printf("5. grade report\n");
        printf("6. exit\n");
        printf("========================\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            printf("\nattendance matrix:\n");
            for(i=0;i<5;i++){
                for(j=0;j<5;j++){
                    printf("%d ", attendance[i][j]);
                }
                printf("\n");
            }
        }

        else if(choice == 2){
            printf("\nmarks matrix:\n");
            for(i=0;i<5;i++){
                for(j=0;j<5;j++){
                    printf("%d ", marks[i][j]);
                }
                printf("\n");
            }
        }

        else if(choice == 3){
            int total[5], abs[5];
            int highest, lowest, hi_index = 0, lo_index = 0;

            for(i=0;i<5;i++){
                total[i] = 0;
                abs[i] = 0;
                for(j=0;j<5;j++){
                    if(attendance[i][j] == 1)
                        total[i]++;
                    else
                        abs[i]++;
                }
            }

            highest = total[0];
            lowest = total[0];

            for(i=1;i<5;i++){
                if(total[i] > highest){
                    highest = total[i];
                    hi_index = i;
                }
                if(total[i] < lowest){
                    lowest = total[i];
                    lo_index = i;
                }
            }

            printf("\nattendance report:\n");
            for(i=0;i<5;i++){
                printf("%s -> present: %d, absent: %d\n", names[i], total[i], abs[i]);
            }

            printf("\nhighest attendance: %s (%d)\n", names[hi_index], highest);
            printf("lowest attendance: %s (%d)\n", names[lo_index], lowest);
        }

        else if(choice == 4){
            int total[5];
            int highest, lowest, hi_index = 0, lo_index = 0;

            for(i=0;i<5;i++){
                total[i] = 0;
                for(j=0;j<5;j++){
                    total[i] += marks[i][j];
                }
            }

            highest = total[0];
            lowest = total[0];

            for(i=1;i<5;i++){
                if(total[i] > highest){
                    highest = total[i];
                    hi_index = i;
                }
                if(total[i] < lowest){
                    lowest = total[i];
                    lo_index = i;
                }
            }

            printf("\nperformance report:\n");
            for(i=0;i<5;i++){
                printf("%s -> total marks: %d, average: %.2f\n", names[i], total[i], total[i]/5.0);
            }

            printf("\nclass topper: %s (%d)\n", names[hi_index], highest);
            printf("lowest performer: %s (%d)\n", names[lo_index], lowest);
        }

        else if(choice == 5){
            int total;
            float avg;
            char grade;

            printf("\ngrade report:\n");
            for(i=0;i<5;i++){
                total = 0;
                for(j=0;j<5;j++){
                    total += marks[i][j];
                }
                avg = total / 5.0;

                if(avg >= 90) grade = 'A'+1; // A+
                else if(avg >= 80) grade = 'A';
                else if(avg >= 70) grade = 'B';
                else if(avg >= 60) grade = 'C';
                else if(avg >= 50) grade = 'D';
                else grade = 'F';

                if(grade == 'B'){ }

                printf("%s -> average: %.2f, grade: %c\n", names[i], avg, grade);
            }
        }

        else if(choice == 6){
            break;
        }

        else{
            printf("invalid choice\n");
        }
    }

    return 0;
}
