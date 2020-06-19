#include "weather.h"

#include<stdio.h>  
#include<stddef.h>
#include<string.h>

extern int length;

static int sum(int x,int y) { return x + y; }
static void filter() { }

void addRecord(weather_t *parr, int cityCode, const char* cityName) {
  int lastIndex = length;
  fillRecord(&parr[lastIndex], cityCode, cityName);
  ++length;
}

void displayOne(const weather_t *ptr) {
  printf("cityCode : %d\n", ptr->cityCode);
  printf("cityName : %s\n", ptr->cityName);
  printf("Temperature : %lf\n", ptr->temperature);
  printf("Humidity : %lf\n", ptr->humidity);
  printf("Pressure : %lf\n", ptr->pressure);
}

void fillRecord(weather_t *ptr, int code, const char *name) {
   ptr->cityCode=code;
   strcpy(ptr->cityName,name);
   ptr->temperature = 10 + rand()%30;
   ptr->humidity = 50 + rand()%50;
   ptr->pressure = 260 + rand()%1000;   
}

 
void displayAll(const weather_t parr[],int n) {
  printf("Size of arr: %d\n", sizeof(parr));
  const weather_t *pcur=parr;
  for(int i=0;i<n;i++)
    displayOne(pcur++);
}

weather_t* findCityByCode(const weather_t *parr,int n, int keyCode) {
  const weather_t *ptr = parr; 
  for(int i=0;i<n;i++) {
    if(ptr->cityCode==keyCode) {   //if(ptr++->cityCode==keyCode
       return ptr;                 //safe, though it's pointer
    }
    ptr++;
  }
  return NULL;
}  
weather_t* findCityByName(const weather_t *parr,int n, 
                                        const char* keyName) {
  const weather_t *ptr = parr; 
  for(int i=0;i<n;i++) {
    if(strcmp(ptr->cityName,keyName)==0) { 
       return ptr;                 
    }
    ptr++;
  }
  return NULL;
}
double findAverageTemperature(const weather_t *parr, int n) {
  double tsum = 0;
  const weather_t *ptr=parr;
  for(int i=0;i<n;i++) {
    tsum += ptr->temperature;  //tsum += ptr++ -> temperature
    ptr++;
  }
  return tsum/n;
}  
double findMinimumHumidity(const weather_t *parr, int n) {
  const weather_t *ptr=parr;
  double hmin = ptr->humidity;
  ptr++;
  for(int i=1;i<n;i++) {
    if(ptr->humidity < hmin)
        hmin = ptr->humidity;
    ptr++;
  }
  return hmin;
} 
double findMinTemperatureOfCity(const weather_t * parr, int n,int cityCode){
   //TODO
}   


