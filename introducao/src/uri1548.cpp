#include <bits/stdc++.h>

using namespace std;

int main() {
   int number_of_test_cases;
   scanf("%d", &number_of_test_cases);

   for (int test_case = 0; test_case < number_of_test_cases; test_case++) {
      int number_of_students;
      scanf("%d", &number_of_students);
      
      vector<int> grades(number_of_students);
      for (int i = 0; i < number_of_students; i++) {
         scanf("%d", &grades[i]);
      }

      vector<int> sorted_grades = grades;
      sort(sorted_grades.begin(), sorted_grades.end());
      reverse(sorted_grades.begin(), sorted_grades.end());

      int answer = 0;
      for (int i = 0; i < number_of_students; i++) {
         if (sorted_grades[i] == grades[i]) {
            answer++;
         }
      }

      printf("%d\n", answer);
   }
}
