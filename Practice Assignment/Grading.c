#include <stdio.h>

int main() {
   int rexam, mexam;
   int rpract, mpract;
   int rastsk, mastsk;
   int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
   int i;

   // Input and calculate for exam scores
  for (i = 1; i <= 2; i++) {
        printf("Enter raw score exam %d: ", i);
        scanf("%d", &rexam);
        sum1 += rexam;
        
        printf("Enter maximum score exam %d: ", i);
        scanf("%d", &mexam);
        sum2 += mexam;   
   }

   // Input and calculate for practical activity scores
   for (i = 1; i <= 5; i++) {
       printf("Enter raw score practicals %d: ", i);
       scanf("%d", &rpract);
       sum3 += rpract;

       printf("Enter maximum score practicals %d: ", i);
       scanf("%d", &mpract);
       sum4 += mpract;
   }

   // Input and calculate for assigned task scores
   for (i = 1; i <= 10; i++) {
       printf("Enter raw score assigned task %d: ", i);
       scanf("%d", &rastsk);
       sum5 += rastsk;

       printf("Enter maximum score assigned task %d: ", i);
       scanf("%d", &mastsk);
       sum6 += mastsk;
   }

   // Calculate percentage for exams
   float prctg1 = (float)sum1 / (float)sum2 * 100;

   // Calculate percentage for practical activities
   float prctg2 = (float)sum3 / (float)sum4 * 100;

   // Calculate percentage for assigned tasks
   float prctg3 = (float)sum5 / (float)sum6 * 100;

   // Calculate final grade
   float fgrade = (prctg1 * 0.4) + (prctg2 * 0.3) + (prctg3 * 0.3);

   fgrade < 60? fgrade = 60: fgrade;

    // Display the evaluation
    if (fgrade >= 90) {
        printf("Proficient");
    } else if (fgrade >= 80) {
        printf("Advanced");
    } else if (fgrade >= 75) {
        printf("Average");
    } else {
        printf("Needs improvement");
    }

    return 0;
}