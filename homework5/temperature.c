#include <stdio.h>
#include <stdlib.h>

int main(){
  float start_tem = 0.0, tem_fluc = 0.0, curr_tem = 0.0, sum_tem = 0.0, ave_tem = 0.0, high_tem = 0.0, low_tem = 0.0;
  int ran_num = 0, hot_streak = 0, cold_streak = 0, hotter = 0, colder = 0;
  printf("Please enter a start temperature:");
  scanf("%f", &start_tem);
  if(start_tem < 0)
    return 0;
  curr_tem = start_tem;
  sum_tem = start_tem;
  high_tem = start_tem;
  low_tem = start_tem;
  srandom(time(0));
  int i;
  for(i = 0; i < 365; ++i){
    sleep(1);
    ran_num = random()%(81);
    tem_fluc = (ran_num - 40) / 10.0;
    if(tem_fluc < 0){
      if(hotter >= 3)
	hot_streak++;
      hotter = 0;
      colder++;
    }else if (tem_fluc > 0){
      if(colder >= 3)
	cold_streak++;
      colder = 0;
      hotter++;
    }else{
      if(colder >= 3)
	cold_streak++;
      if(hotter >= 3)
	hot_streak++;
      colder = 0;
      hotter = 0;
    }
    curr_tem += tem_fluc;
    if(curr_tem >= 100){
      printf("The temperature reaches 100! Simulation will stop!");
      break;
    }
    if(curr_tem < low_tem)
      low_tem = curr_tem;
    if(curr_tem > high_tem)
      high_tem = curr_tem;
    sum_tem += curr_tem;
    ave_tem = sum_tem / (i + 2);
    printf("The current temperature is: %.1f\n", curr_tem);
    if(curr_tem > start_tem)
      printf("Higher than the init temperature by %.1f degrees\n", curr_tem - start_tem);
    else if(curr_tem < start_tem)
      printf("Lower than the init temperature by %.1f degrees\n", start_tem - curr_tem);
    else
      printf("Equal to the init temperature\n");
    printf("The highest temperature is: %.1f\nThe lowest temperature is: %.1f\nThe average temperature is: %.1f\n\n", high_tem, low_tem, ave_tem);
  }
  printf("We have experienced %d hot streaks and %d cold streaks.\n", hot_streak, cold_streak);
  return 1;
}
