
#include <Arduino.h>
#include <FreematicsPlus.h>
#include <ArduinoJson.h>
#include <WebServer.h>
#include "AsyncTCP.h"
#include "ESPAsyncWebServer.h"




//*********************************************
//const char* serverName  = "http://192.168.50.11/";
//const char* serverName3  = "http://192.168.50.11/post-esp-data.php";
const char* serverName6  = "http://172.20.10.10/php/mysql_json.php?REF='";
const char* serverName7  = "http://172.20.10.10/php/mysql_json2.php?REF='";
const char* serverName8  = "http://172.20.10.10/php/mysql_json3.php?CODIGO='";
const char* serverName9  = "http://172.20.10.10/php/mysql_json4.php?CODIGO='";
const char* serverName10 = "http://172.20.10.10/php/mysql_json5.php?carid=";
const char* serverName11 = "http://172.20.10.10/php/mysql_json6.php?carid=";
const char* serverName12 = "http://172.20.10.10/php/mysql_json7.php?carid=";
const char* serverName13 = "http://172.20.10.10/php/mysql_json8.php?carid=";
const char* serverName14 = "http://172.20.10.10/php/mysql_json9.php?carid=";
//////////////////////////////////////////
const char* serverName15 = "http://172.20.10.10/php/mysql_json10.php?make_code=";

const char* serverName21 = "http://172.20.10.10/php/mysql_jsonPART.php?carid=";
const char* serverName22 = "http://172.20.10.10/php/mysql_jsonESP.php?carid=";
const char* serverName23 = "http://172.20.10.10/php/mysql_jsonPART_OEM.php?carid=";
const char* serverName24 = "http://172.20.10.10/mysql_jsonESP_SUPLIERS.php?carid=";

//const char* serverName17 = "http://172.20.10.10/hextostr.php?hex=";


String apiKeyValue = "tPmAT5Ab3j7F9";  //keyvalue mysql. 

const char* ssid = "iPhone de Francesc ";  // wifi movil 
const char* password = "gp5zoiqszdy9j";

//const char* ssid = "Acerko_X1_Oficina";   // wifi oficina
//const char* password = "02923451";


//const char* ssid = "MiFibra-8C6D";   // wifi oficina
//const char* password = "XHykCi7Z";



unsigned long channelID = 1348494;                //ID de vuestro canal.
const char* WriteAPIKey = "DRP4L796A9MHFCKA";     //Write API Key de vuestro canal.

//*********************************************************************


FreematicsESP32 sys;
//WiFiServer server(80); // conexion http via web
AsyncWebServer server(80);
COBD obd;
//WiFiClient cliente; // conexion ThingSpeak 

bool ref_euro_OK = false;

//String serverName = "https://vpic.nhtsa.dot.gov/api/vehicles/decodevin/";
//String serverName2 = "https://vindecodervehicle.com/api/v1/?id=cescofors&key=v9ix1pn5g0aj4cpv2iat8v20px1&vin=";
//String serverName4 = "https://vindecodervehicle.com/api/v1/?id=cescofors&key=v9ix1pn5g0aj4cpv2iat8v20px1&carid=";
String serverName2="https://partsapi.ru/api?method=VINdecode&key=8329B70D719F9878BDEC1CF864582042&vin=";

//String serverName4 = "http://192.168.50.11/mysql_json6.php?carid=";

bool connected = false;
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
int timing=0;
String Log_text="";
String make_code= "";


int Obd_protocol=3;
String S_Obd_protocol;
int RPM, SPEED, VOLTAGE,TEMPAGUA,TEMPOIL,FUELLEVEL;
int ODOMETER,ENGINE_REF_TORQUE,ENGINE_TORQUE_PERCENTAGE,ENGINE_TORQUE_DEMANDED,ENGINE_FUEL_RATE, FUEL_INJECTION_TIMING,FUEL_RAIL_PRESSURE;
int HYBRID_BATTERY_PERCENTAGE,ETHANOL_FUEL;
int ENGINE_LOAD;
int SHORT_TERM_FUEL_TRIM_1;
int LONG_TERM_FUEL_TRIM_1; 
int SHORT_TERM_FUEL_TRIM_2;
int LONG_TERM_FUEL_TRIM_2; 
int FUEL_PRESSURE; 
int INTAKE_MAP;
int TIMING_ADVANCE; 
int INTAKE_TEMP; 
int MAF_FLOW; 
int THROTTLE;
int AU_INPUT; 
int RUNTIME; 
int DISTANCE_WITH_MIL; 
int COMMANDED_EGR; 
int EGR_ERROR; 
int COMMANDED_EVAPORATIVE_PURGE; 
int WARMS_UPS;
int DISTANCE; 
int EVAP_SYS_VAPOR_PRESSURE; 
int BAROMETRIC; 
int CATALYST_TEMP_BS_C;
int CATALYST_TEMP_BS_D;
int CATALYST_TEMP_BS_E;
int CATALYST_TEMP_BS_F;
int ABSOLUTE_ENGINE_LOAD; 
int AIR_FUEL_EQUIV_RATIO;
int RELATIVE_THROTTLE_POS; 
int AMBIENT_TEMP; 
int ABSOLUTE_THROTTLE_POS_B; 
int ABSOLUTE_THROTTLE_POS_C; 
int ACC_PEDAL_POS_D; 
int ACC_PEDAL_POS_E; 
int ACC_PEDAL_POS_F; 
int COMMANDED_THROTTLE_ACTUATOR; 
int TIME_WITH_MIL;
int TIME_SINCE_CODES_CLEARED; 

char VIN[128];
char VIN_INI[128]="";
String VIN_MANU="";

String Make, Model, Year, Version,  Doors, Fuel;
String idCar, Groups, Cat, Cats, Ref, Refs, CrossRef, CrossRefs;
String List_errors;
String List_errorsF;
int valor_gauge=0;
byte dtcCount ;
uint16_t codes[6];

String InfoValue="";
String mensajeW="";
String mensajeCross="";
String Error="";
String Solucion_Euro="";
String Texto_OpenAI="";
//bool Conect_Json=false;
bool pids_status=false;

String VIN2;
String Articulo_a_buscar="";
String Error_codes="";

struct SpiRamAllocator {
  void* allocate(size_t size) {
    return heap_caps_malloc(size, MALLOC_CAP_SPIRAM);
  }

  void deallocate(void* pointer) {
    heap_caps_free(pointer);
  }

  void* reallocate(void* ptr, size_t new_size) {
    return heap_caps_realloc(ptr, new_size, MALLOC_CAP_SPIRAM);
  }
};

using SpiRamJsonDocument = BasicJsonDocument<SpiRamAllocator>;

