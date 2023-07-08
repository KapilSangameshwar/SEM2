// write a C Program to Calculate Difference Between Two Time Periods using structures
#include<stdio.h>

 

  struct time {

    int seconds;

    int minutes;

    int hours;

  };

  int main()

  {

   

    struct time t1, t2, diff;

    scanf("%d%d%d",&t1.hours,&t1.minutes,&t1.seconds);

    scanf("%d%d%d",&t2.hours,&t2.minutes,&t2.seconds);

      

   if(t2.seconds > t1.seconds)

    {

        t1.seconds += 60;

        --t1.minutes;

    }

  if(t2.minutes > t1.minutes)

    {

        t1.minutes += 60;

        --t1.hours;

    }

    diff.seconds = t1.seconds - t2.seconds;

    diff.minutes = t1.minutes - t2.minutes;

    diff.hours = t1.hours - t2.hours;

    printf("%d:%d:%d", diff.hours, diff.minutes, diff.seconds);

    return 0;

  }