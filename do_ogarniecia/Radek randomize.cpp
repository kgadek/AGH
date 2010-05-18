#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float oldrand[56];
int jrand;

void advance_random(void){
     int j1;
     float new_random;
     for(j1=1; j1<=24; j1++){
               new_random = oldrand[j1] - oldrand[j1+31];
               if(new_random < 0.0){ new_random += 1.0; }
               oldrand[j1] = new_random;
               }
     for(j1=25; j1<=55; j1++){
               new_random = oldrand[j1] - oldrand[j1-24];
               if(new_random < 0.0){ new_random += 1.0; }
               oldrand[j1] = new_random;
               }
     }              

void warmup_random(float random_seed){
     int j1, ii;
     float new_random, prev_random;
     oldrand[55] = random_seed;
     new_random = 1.0e-9;
     prev_random = random_seed;
     for(j1=1; j1<=54; j1++){
               ii = (21*j1) % 54;
               oldrand[ii] = new_random;
               new_random = prev_random - new_random;
               if(new_random < 0.0){ new_random += 1.0; }
               prev_random = oldrand[ii];
               }
     advance_random();
     advance_random();
     advance_random();
     jrand=0;
     }

float losowa(void){
      jrand++;
      if(jrand>55) {
                   jrand=1;
                   advance_random();
                   }
      return oldrand[jrand];
      }

void warm(void){
     int warmi = 0;
     int i;
     int czas=time(0);
     for(i=0; i<6; i++){
             warmi *=10;
             warmi = warmi + (czas % 10);
             czas /= 10;
             }
     float warmf = warmi;
     warmf = warmf / 1000000;
     warmup_random(warmf);
     }
     
     
     

int main()
{
float a;
warm();
a=losowa();
printf("%f", a);
getchar();
}   