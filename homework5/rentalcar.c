#include <stdio.h>
#include <stdlib.h>

main(){
  int start_hour, start_minute, end_hour, end_minute, total_time;
  float start_odometer, end_odometer, total_odometer, cost;
  printf("Please enter the start time and odometer reading:");
  scanf("%d %d %f", &start_hour, &start_minute, &start_odometer);
  printf("Please enter the ending time and odometer reading:");
  scanf("%d %d %f", &end_hour, &end_minute, &end_odometer);
  if(end_minute >= start_minute){
    total_time = end_hour - start_hour;
  }else{
    total_time = end_hour - start_hour - 1;
  }
  total_odometer = end_odometer - start_odometer;
  cost = 0.70 * total_odometer + 11.25 * total_time;
  printf("The total cost is: %f\n", cost);
}
