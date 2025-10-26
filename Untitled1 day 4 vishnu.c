#include <stdio.h>
int main() {
     int m1,m2,m3,m4,m5;
     float at,pt;
    printf("Enter marks in 5 subjects : ");
    scanf("%d %d %d %d %d",&m1,&m2,&m3,&m4,&m5);
    printf("\n");
    printf("Enter attendence percentage :" );
    scanf("%f",&at);
    pt=(m1+m2+m3+m4+m5)/5;
    if(at>=75){
        if(pt>90){
            printf("Total Percentage : %f \n",pt);
            printf("Attendence : %f \n",at);
            printf("Final grade : A+ \n");
            printf("Remarks : Excellent\n");
        }
        else if(pt>=80 && pt<=89){
            printf("Total Percentage : %f \n",pt);
            printf("Attendence : %f \n",at);
            printf("Final grade : A\n");
            printf("Remarks : verygood\n");
        }
        else if(pt>=70 && pt<=79){
            printf("Total Percentage : %f \n",pt);
            printf("Attendence : %f \n",at);
            printf("Final grade : B\n");
            printf("Remarks : Good\n");
        }
        else if(pt>=60 && pt<=69){
            printf("Total Percentage : %f\n",pt);
            printf("Attendence : %f\n",at);
            printf("Final grade : C\n");
            printf("Remarks : Average\n");
        }
        else if(pt>=50 && pt<=59){
            printf("Total Percentage : %f \n",pt);
            printf("Attendence : %f \n",at);
            printf("Final grade : D\n");
            printf("Remarks : Pass\n");
        }
        else{
            if(at>=90 && pt>=45 && pt<50){
                pt=(m1+m2+m3+m4+m5+5)/5;
                if(pt>=50 && pt<=59){
                    printf("Total Percentage : %f \n",pt);
                    printf("Attendence : %f \n",at);
                    printf("Final grade : D\n");
                    printf("Remarks : Pass\n");
                }
                else{
                printf("Total Percentage : %f \n",pt);
                printf("Attendence : %f \n",at);
                printf("Final grade : F\n");
                printf("Remarks : Fail");
            }

            }
            else{
                printf("Total Percentage : %f \n",pt);
                printf("Attendence : %f \n",at);
                printf("Final grade : F\n");
                printf("Remarks : Fail\n");
            }
        }

    }
    else{
        printf("Total Percentage : %f\n",pt);
        printf("Attendence : %f\n",at);
        printf("Final grade : F\n");
        printf("Remarks : Fail\n");
    }
}
