typedef struct {
  int cityCode;
  char cityName[20];
  double temperature;
  double humidity;
  double pressure;
  int seqno;
}weather_t;

weather_t getRecord(int code, const char *name) {
   weather_t temp;
   temp.cityCode=code;
   strcpy(temp.cityName,name);
   temp.temperature = 10 + rand()%30;
   temp.humidity = 50 + rand()%50;
   temp.pressure = 260 + rand()%1000;   
   return temp;  //not efficient
}
weather_t* getRecordp(int code, const char *name) {
   weather_t temp;
   temp.cityCode=code;
   strcpy(temp.cityName,name);
   temp.temperature = 10 + rand()%30;
   temp.humidity = 50 + rand()%50;
   temp.pressure = 260 + rand()%1000;   
   return &temp;    //unsafe
}
