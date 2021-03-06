/*
 * create collection of records (array of struct vars)
 * initialize, fill with random vals, fill with user input
 * add a record at end
 * computations -- filters, aggregations, filters + aggregations
*/

#include<stdio.h>
#include<stddef.h>
#include<string.h>

#define MAX_SIZE 50
//const int max_size 50

struct Weather {
  unsigned int cityCode;
  //double dummy;
  char cityName[20];
  double temperature;
  double humidity;
  double pressure;
  unsigned int seqno;
};
//offsetof(struct Weather, cityName);  
typedef  struct Weather weather_t;

void displayAll(const weather_t arr[],int n); 
          //displayAll(const weather_t*,int)
void displayOne(const weather_t*);
weather_t* findCityByCode(const weather_t *,int,int);
weather_t* findCityByName(const weather_t *,int,const char*);
double findAverageTemperature(const weather_t *, int);
double findMinimumHumidity(const weather_t *, int)

int  main() {
  weather_t warr[MAX_SIZE] = {
      { 101, "Pune", 24, 72, 512, 1 },   //0
      { 102, "Mumabi", 25, 70, 512, 2 }, //1
      { .cityCode = 103, .temperature = 32, .pressure = 900 },  //2
      [5] = { 105, "Delhi", 26, 68, 920, 4 },  //5
      [8] = { .cityCode = 108, .seqno = 5 }    //8
  };
  
  //weather_t warr[max_size];
  
  //You may fill temperature, humidity, pressure with rand vals
  printf("Size of single: %d\n", sizeof(weather_t));
  printf("Size of arr: %d\n", sizeof(warr));  // 56 * MAX_SIZE : 2800
  printf("cityName offset : %d\n", offsetof(weather_t, cityName));
  //printf("dummy offset : %d\n", offsetof(weather_t, dummy));                        
  int length=5;
  displayAll(warr, length);

  return 0;
}

void displayOne(const weather_t *ptr) {
  printf("cityCode : %d\n", ptr->cityCode);
  printf("cityName : %s\n", ptr->cityName);
  printf("Temperature : %lf\n", ptr->temperature);
  printf("Humidity : %lf\n", ptr->humidity);
  printf("Pressure : %lf\n", ptr->pressure);
}
/*void readSingle(weather_t *ptr) {
  scanf("%d%s%lf%lf%lf",ptr->cityCode, ptr->cityName,
          ptr->temperature, ptr->humidity, ptr->pressure);          
}
void readAll(weather_t *parr,int n) {
  int counter = 0;
  for(int i=0;i<n;i++)
    readSingle(&parr[i]);
} 
void fillRecord(weather_t *ptr, int code, const char *name) {
   ptr->cityCode=code;
   strcpy(ptr->cityName,name);
   ptr->temperature = 10 + rand()%30;
   ptr->humidity = 50 + rand()%50;
   ptr->pressure = 260 + rand()%1000;   
}
*/   
  
//void displayAll(const weather_t* parr,int n)
void displayAll(const weather_t parr[],int n) {
  printf("Size of arr: %d\n", sizeof(parr));
  //for(int i=0;i<n;i++)
      //displayOne(&parr[i]);
  const weather_t *pcur=parr;
  for(int i=0;i<n;i++)
    displayOne(pcur++);
}

weather_t* findCityByCode(const weather_t *parr,int n, int keyCode) {
  /*for(int i=0;i<n;i++) {
    if(parr[i].cityCode==keyCode)
        return &parr[i];           //safe, though it's pointer
  }*/
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
/** TODO:- max pressure
    min temperature of a particular city
    addRecord (at end) 
*/     
  
  
  
  
  
  
  












  
  
  
