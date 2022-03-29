#define ARDUINOJSON_USE_DOUBLE 1
#define ARDUINOJSON_USE_LONG_LONG 1

#include <Arduino.h>
#include <FreematicsPlus.h>

#include <HTTPClient.h>
#include <ArduinoJson.h>
//#include <ThingSpeak.h>
#include <ESPmDNS.h>
#include <pgmspace.h>
#include "index.h" //Web page header file
#include "global.h"
#include "page_gauges.h"
#include "page_vin.h"
#include "page_error.h"
#include "page_solution.h"
#include "page_parts.h"
#include "page_openai.h"
#include "page_list.h"
#include "page_pids.h"
#include "page_top.h"

const char *input_parameter1 = "input_string";



void Top_parts(String part , int limite=1)

{

  HTTPClient http5;
  part.replace(" ","%20");
  String serverPath = serverName21 + idCar + "&part=" + part+"&lim="+limite;
  http5.useHTTP10(true);

  http5.begin(serverPath.c_str());
  Serial.println(serverPath);
  // Send HTTP GET request
  int httpResponseCode = http5.GET();
  
  if (httpResponseCode > 0)
  {

    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, http5.getStream());
     Serial.println();
    Serial.print("Memory: ");
    Serial.println(doc.capacity());
    Serial.print("Doc: ");
    Serial.println(doc.memoryUsage());
    Serial.println();
    if (error)
    {

      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    if (limite == 1){
    JsonObject root_0 = doc[0];
    const char* root_0_OENbr = root_0["OENbr"]; // "17801-68020"
    const char* root_0_REF_EURO = root_0["REF_EURO"]; // "FAI5240"
    const char* root_0_libelleproduit = root_0["libelleproduit"]; // "Filtre - air"
    const char* root_0_prixeuroht = root_0["prixeuroht"];
    const char* REF_EURO = root_0["REF_EURO"];
    String REF_EURO2 = String(REF_EURO);
    String familia = (String(REF_EURO).substring(0, 3));
    familia.toLowerCase();
    REF_EURO2.toLowerCase();
      //mensajeW  = "<table>"
      mensajeW += "<div class='w3-card-4'><header class='w3-container w3-light-grey'><h3>" + String(root_0_OENbr) + "</h3></header>";
      mensajeW += "<div class='w3-container'><p>" + String(root_0_REF_EURO) + "</p><hr>";
      mensajeW += "<img src='http://blog.euro4x4parts.com/photos/"+ familia + "/" + String(REF_EURO2) + "z.jpg' class='w3-left w3-circle w3-margin-right' style='width:200px' ><p>" + String(root_0_libelleproduit) + "</p></div>";
      mensajeW += "<button class='w3-button w3-block w3-dark-grey'>+ Buy " + String(root_0_prixeuroht) + "€"+"</button></div>";
      //mensajeW += "</table>";
    }else{
   for (JsonObject item : doc.as<JsonArray>()) {


    const char* root_0_OENbr = item["OENbr"]; // "17801-68020"
    const char* root_0_REF_EURO = item["REF_EURO"]; // "FAI5240"
    const char* root_0_libelleproduit = item["libelleproduit"]; // "Filtre - air"
    const char* root_0_prixeuroht = item["prixeuroht"];
    const char* REF_EURO = item["REF_EURO"];
    
    String REF_EURO2 = String(REF_EURO);
    String familia = (String(REF_EURO).substring(0, 3));
    familia.toLowerCase();
    REF_EURO2.toLowerCase();
      //mensajeW  = "<table>"
      mensajeW += "<div class='w3-card-4'><header class='w3-container w3-light-grey'><h3>" + String(root_0_OENbr) + "</h3></header>";
      mensajeW += "<div class='w3-container'><p>" + String(root_0_REF_EURO) + "</p><hr>";
      mensajeW += "<img src='http://blog.euro4x4parts.com/photos/"+ familia + "/" + String(REF_EURO2) + "z.jpg' class='w3-left w3-circle w3-margin-right' style='width:200px' ><p>" + String(root_0_libelleproduit) + "</p></div>";
      mensajeW += "<button class='w3-button w3-block w3-dark-grey'>+ Buy " + String(root_0_prixeuroht) + "€"+"</button></div>";
      //mensajeW += "</table>";
    
   }
  }
 }
    
  
  http5.end();
  //delay(500);
}

void Top_parts_oem(String part)

{

  HTTPClient http5;
  part.replace(" ","%20");
  String serverPath = serverName23 + idCar + "&part=" + part;
  http5.useHTTP10(true);

  http5.begin(serverPath.c_str());
  Serial.println(serverPath);
  // Send HTTP GET request
  int httpResponseCode = http5.GET();
  
  if (httpResponseCode > 0)
  {

    DynamicJsonDocument doc(3072);
    DeserializationError error = deserializeJson(doc, http5.getStream());
     Serial.println();
    Serial.print("Memory: ");
    Serial.println(doc.capacity());
    Serial.print("Doc: ");
    Serial.println(doc.memoryUsage());
    Serial.println();
    if (error)
    {

      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      return;
    }
    mensajeW  += "<table><tr><td style='padding:5px;'> OTHERS REFERENCES </td></tr>";
   for (JsonObject item : doc.as<JsonArray>()) {

  const char* T_MAKE = item["MAKE"]; // "TOYOTA", "TOYOTA", "TOYOTA", "TOYOTA", "TOYOTA", "TOYOTA", ...
  const char* T_OEM = item["OEM"]; // "1780178011", "177005B080", "1780160020", "1780168030", "1780160050", ...


      mensajeW += "<tr><td style='paddingn:15px;'>"+String(T_MAKE)+"</td><td style='padding:15px;'>"+String(T_OEM)+"</td></tr>";
     
      
  }
  mensajeW += "</table>";
  }  
  
  http5.end();
  //delay(500);
}

void Buscar_suppliers(String code)

{

  HTTPClient http5;
  code.replace(" ","%20");
  String serverPath = serverName24 + idCar + "&code=" + code;
  http5.useHTTP10(true);

  http5.begin(serverPath.c_str());
  Serial.println(serverPath);
  // Send HTTP GET request
  int httpResponseCode = http5.GET();
  
  if (httpResponseCode > 0)
  {

    DynamicJsonDocument doc(7072);
    DeserializationError error = deserializeJson(doc, http5.getStream());
     Serial.println();
    Serial.print("Memory: ");
    Serial.println(doc.capacity());
    Serial.print("Doc: ");
    Serial.println(doc.memoryUsage());
    Serial.println();
    if (error)
    {

      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      return;
    }
    mensajeW  += "<table><tr><td style='padding:5px;'> OTHERS REFERENCES </td></tr>";
   for (JsonObject item : doc.as<JsonArray>()) {

  const char* T_MAKE = item["name"]; // "TOYOTA", "TOYOTA", "TOYOTA", "TOYOTA", "TOYOTA", "TOYOTA", ...
  const char* T_OEM = item["number"]; // "1780178011", "177005B080", "1780160020", "1780168030", "1780160050", ...


      mensajeW += "<tr><td style='paddingn:15px;'>"+String(T_MAKE)+"</td><td style='padding:15px;'>"+String(T_OEM)+"</td></tr>";
     
      
  }
  mensajeW += "</table>";
  }  
  
  http5.end();
  //delay(500);
}


void Buscar_solucion(String codigo_error)
{

  HTTPClient http5;
  http5.useHTTP10(true);
  String serverPath = serverName9 + codigo_error + "'";
  http5.begin(serverPath.c_str());

  int httpResponseCode = http5.GET();

  if (httpResponseCode > 0)
  {

    DynamicJsonDocument doc2(12288);
    DeserializationError error = deserializeJson(doc2, http5.getStream());

    if (error)
    {

      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    for (JsonObject elem : doc2.as<JsonArray>())
    {
      const char *parts = elem["parts"];
      Articulo_a_buscar = String(parts);
      //getParts2();
      Top_parts(Articulo_a_buscar,3);
      Buscar_suppliers(codigo_error);
    }
  }
  http5.end();
}

void Mirar_error(String codigo_error)
{

  HTTPClient http4;
  http4.useHTTP10(true);
  String serverPath = serverName8 + codigo_error + "'";
  Serial.println(serverPath);
  http4.begin(serverPath.c_str());

  // Send HTTP GET request
  int httpResponseCode = http4.GET();

  if (httpResponseCode > 0)
  {

    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, http4.getStream());

    if (error)
    {

      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    for (JsonObject elem : doc.as<JsonArray>())
    {

      /*const char *ERROR_DEF = elem["ERROR"];
      const char *TIPO = elem["TIPO"];*/
       const char *ERROR_DEF = elem["error"];
      const char *TIPO = "";
      Error = Error + "</td><td style='background: white ;color: red; padding: 15px;'>" + String(TIPO) + "</td><td style='background: white ;color: red; padding: 15px;'>" + String(ERROR_DEF) + "</td></tr>";
    }
  }
  http4.end();
}

void Buscar_error()
{
  
  Error = ("<table> <tr><td>");
  if (dtcCount == 0)
  {

    Error += ("<img src='http://172.20.10.10/buttons/ok.jpg'  width='50' height='50'></td><td style='background: #03C04A ;color: white; padding: 15px;'>SYSTEM OK, NO CODES");
    Articulo_a_buscar = "";
    mensajeW = "";
    //Limpieza();
  }
  else
  {
    Error += ("WARNING " + String(dtcCount) + " CODES </td></tr></table>");
    String Error_l = String(codes[0], HEX);
    Error += ("<table>");
    if (Error_l.length() == 3)
    {

      Error += (" <tr><td style='width:50px;'><img src='http://172.20.10.10/buttons/alert.jpg'  width='50' height='50'> </td><td style='background: white ;color: red; padding: 15px;'> P0" + String(codes[0], HEX));

      Mirar_error(("P0" + String(codes[0], HEX)));
      
    }

    if (Error_l.length() == 4)
    {
      Error += (" <tr><td style='width:50px;'><img src='http://172.20.10.10/buttons/alert.jpg'  width='50' height='50'> </td><td style='background: white ;color: red; padding: 15px;'> P" + String(codes[0], HEX));

      Mirar_error(("P" + String(codes[0], HEX)));
    }
    for (int index_er = 1; index_er < dtcCount; index_er++)
    {
      String Error_l = String(codes[index_er], HEX);
      if (Error_l.length() == 3)
      {
        Error += (" <tr><td style='width:50px;'><img src='http://172.20.10.10/buttons/alert.jpg'  width='50' height='50'> </td><td style='background: white ;color: red; padding: 15px;'> P0" + String(codes[index_er], HEX));

        //Error = Error + ("P0" + String(codes[index_er], HEX));
        Mirar_error(("P0" + String(codes[index_er], HEX)));
      }
      if (Error_l.length() == 4)
      {

        Error += (" <tr><td style='width:50px;'><img src='http://172.20.10.10/buttons/alert.jpg'  width='50' height='50'> </td><td style='background: white ;color: red; padding: 15px;'> P" + String(codes[index_er], HEX));

        // Error = Error + ("P" + String(codes[index_er], HEX));
        Mirar_error(("P" + String(codes[index_er], HEX)));
      }
    }
  }
  Error += "</table>";
}



/*
void Mirar_error3(String codigo_error)

{

  HTTPClient http5;
  
  String serverPath = serverName22 + idCar + "&code=" + codigo_error;
  http5.useHTTP10(true);

  http5.begin(serverPath.c_str());
  Serial.println(serverPath);
  // Send HTTP GET request
  int httpResponseCode = http5.GET();
  
  if (httpResponseCode > 0)
  {

    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, http5.getStream());
    Serial.println();
    Serial.print("Memory: ");
    Serial.println(doc.capacity());
    Serial.print("Doc: ");
    Serial.println(doc.memoryUsage());
    Serial.println();
    if (error)
    {

      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
    
    JsonObject root_0 = doc[0];
    const char* root_0_OENbr = root_0["OENbr"]; // "17801-68020"
    const char* root_0_REF_EURO = root_0["REF_EURO"]; // "FAI5240"
    const char* root_0_libelleproduit = root_0["libelleproduit"]; // "Filtre - air"
    const char* root_0_prixeuroht = root_0["prixeuroht"];
    const char *REF_EURO = root_0["REF_EURO"];
    String REF_EURO2 = String(REF_EURO);
    String familia = (String(REF_EURO).substring(0, 3));
    familia.toLowerCase();
    REF_EURO2.toLowerCase();
      //mensajeW  = "<table>"
      mensajeW += "<div class='w3-card-4'><header class='w3-container w3-light-grey'><h3>" +codigo_error+" - " + String(root_0_REF_EURO) + "</h3></header>";
      mensajeW += "<div class='w3-container'><p>" + String(root_0_OENbr) + "</p><hr>";
      mensajeW += "<img src='http://blog.euro4x4parts.com/photos/"+ familia + "/" + String(REF_EURO2) + "z.jpg' class='w3-left w3-circle w3-margin-right' style='width:200px' ><p>" + String(root_0_libelleproduit) + "</p></div>";
      mensajeW += "<button class='w3-button w3-block w3-dark-grey'>+ Buy " + String(root_0_prixeuroht) + "€"+"</button></div>";
      //mensajeW += "</table>";
   
    }
  
    
  
  http5.end();
 
}*/


void Buscar_error3()
{

  if (dtcCount == 0)
  {

    Error = ("NO HAY ERRORES DE CODIGOS DTC:");
    Articulo_a_buscar = "";
    //Limpieza();
  }
  else
  {

    String Error_l = String(codes[0], HEX);

    if (Error_l.length() == 3)
    {

      Error = ("HAY " + String(dtcCount) + " CODIGOS DTC DE ERRORES :<BR>   P0" + String(codes[0], HEX));
      Buscar_solucion("P0" + String(codes[0], HEX));
      
    }

    if (Error_l.length() == 4)
    {

      Error = ("HAY " + String(dtcCount) + " CODIGOS DTC DE ERRORES :<BR>   P" + String(codes[0], HEX));
      Buscar_solucion("P" + String(codes[0], HEX));
    }
    for (int index_er = 1; index_er < dtcCount; index_er++)
    {
      String Error_l = String(codes[index_er], HEX);
      if (Error_l.length() == 3)
      {
        Error = Error + ("P0" + String(codes[index_er], HEX));
        Buscar_solucion("P0" + String(codes[index_er], HEX));
      }
      if (Error_l.length() == 4)
      {
        Error = Error + ("P" + String(codes[index_er], HEX));
        Buscar_solucion("P" + String(codes[index_er], HEX));
      }
    }
  }
}





void getList()
{

  HTTPClient http;
  http.useHTTP10(true);
  String serverPath = serverName15+make_code;

  Serial.println(serverPath);

  http.begin(serverPath.c_str());

  Serial.println(" - SOLICITANDO LISTADO DE ERRORES via SERVER");

  int httpResponseCode = http.GET();
  Serial.print("httpResponseCode:  ");
  Serial.println(httpResponseCode);

  if (httpResponseCode > 0)
  {
    
    //DynamicJsonDocument doc(49152);
    DynamicJsonDocument doc(90000);
    DeserializationError error = deserializeJson(doc, http.getStream());

    Serial.println();
    Serial.print("Memory: ");
    Serial.println(doc.capacity());
    Serial.print("Doc: ");
    Serial.println(doc.memoryUsage());
    Serial.println();

    if (error)
    {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      
      http.end();
      return;
    }
    else
    {
      Serial.println(" GENERANDO LISTADO DE ERRORES via SERVER");
     
    }
    //List_errors = "<table><tr><td>Lista de Errores: </td></tr>";
    List_errors = "<table><tr><td>Lista de Errores: </td><td><img src='http://192.168.50.11/2022/images_carbrands/"+make_code+".png' width='50' height='50'></td></tr>";
    for (JsonObject item : doc.as<JsonArray>())
    {

      const char *TIPO = item["TIPO"];     // "GENERAL", "GENERAL", "GENERAL", "GENERAL", "GENERAL", "GENERAL", ...
      const char *CODIGO = item["CODIGO"]; // "P0010", "P0011", "P0012", "P0013", "P0014", "P0015", "P0020", ...
      const char *ERROR = item["ERROR"];   // "Circuito del actuador de posicion A del arbol de levas Banco 1 ", ...

      List_errors += "<tr><td>" + String(TIPO) + "</td><td>" + String(CODIGO) + " </td><td> - </td><td>" + String(ERROR) + " </td></tr>";
    }

    List_errors += "</table>";
  } 
  http.end();
}


void BCats()

{

  HTTPClient http5;

  String serverPath = serverName12 + idCar + "&group=" + Cat;
  http5.useHTTP10(true);

  http5.begin(serverPath.c_str());
  Serial.println(serverPath);
  // Send HTTP GET request
  int httpResponseCode = http5.GET();

  if (httpResponseCode > 0)
  {

    DynamicJsonDocument doc2(2048);

    DeserializationError error = deserializeJson(doc2, http5.getStream());

    Serial.println();
    Serial.print("Memory: ");
    Serial.println(doc2.capacity());
    Serial.print("Doc: ");
    Serial.println(doc2.memoryUsage());
    Serial.println();

    if (error)
    {

      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
    String Group = Cat;
    Group.replace("%20", " ");
    Cats = "<table><tr><td>Group: " + Group + "</td></tr><tr><td>Categories</td></tr>";
    for (JsonObject elem : doc2.as<JsonArray>())
    {

      const char *gro = elem["categories"];

      Cats += "<tr><td><a href='/pageRef?gr=" + String(gro) + "'>" + String(gro) + "</a></td></tr>";
    }
    Cats += "</table>";
  }
  http5.end();
}

void BRefs()

{

  HTTPClient http5;

  String serverPath = serverName13 + idCar + "&group=" + Cat + "&ref=" + Ref;
  http5.useHTTP10(true);

  http5.begin(serverPath.c_str());
  Serial.println(serverPath);
  // Send HTTP GET request
  int httpResponseCode = http5.GET();

  if (httpResponseCode > 0)
  {

    DynamicJsonDocument doc2(2048);
    DeserializationError error = deserializeJson(doc2, http5.getStream());

    if (error)
    {

      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
    String Group = Cat;
    String Sref = Ref;
    Group.replace("%20", " ");
    Sref.replace("%20", " ");
    Refs = "<table><tr><td>Group: " + Group + " Cat:" + Sref + "</td></tr><tr><td>References</td></tr>";
    for (JsonObject elem : doc2.as<JsonArray>())
    {

      const char *gro = elem["name"];

      Refs += "<tr><td><a href='/pageCrossRef?gr=" + String(gro) + "'>" + String(gro) + "</a></td></tr>";
    }
    Refs += "</table>";
  }
  http5.end();
}


void BGroups()

{

  HTTPClient http5;
  String serverPath = serverName11 + idCar;
  http5.useHTTP10(true);
  http5.begin(serverPath.c_str());
  Serial.println(serverPath);
  // Send HTTP GET request
  int httpResponseCode = http5.GET();

  if (httpResponseCode > 0)
  {

    DynamicJsonDocument doc2(4096);

    DeserializationError error = deserializeJson(doc2, http5.getStream());

    Serial.println();
    Serial.print("Memory: ");
    Serial.println(doc2.capacity());
    Serial.print("Doc: ");
    Serial.println(doc2.memoryUsage());
    Serial.println();

    if (error)
    {

      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
    Groups = "<table><tr><td>Groups</td></tr><tr>";
    int col = 0;
    for (JsonObject elem : doc2.as<JsonArray>())
    {
      col++;
      const char *gro = elem["group"];
      if (col <= 3)
      {

        Groups += "<td><a href='/pageCat?gr=" + String(gro) + "'>" + String(gro) + "</a></td>";
      }
      else
      {
        Groups += "</tr><tr><td><a href='/pageCat?gr=" + String(gro) + "'>" + String(gro) + "</a></td>";

        col = 1;
      }
    }
    Groups += "</tr></table>";
  }
  http5.end();
}

String hexToAscii(String hex)
{
  uint16_t len = hex.length();
  String ascii = "";

  for (uint16_t i = 0; i < len; i += 2)
    ascii += (char)strtol(hex.substring(i, i + 2).c_str(), NULL, 16);

  return ascii;
}

void DecoderVin2(String vin)
{

  HTTPClient http2;

  String serverPath = serverName2 + vin + "&lang=en";
  Log_text +="Stage 2 - Decoder VIN  <br>";
  Serial.println(serverPath);
  http2.useHTTP10(true);

  http2.begin(serverPath.c_str());

  // Send HTTP GET request
  int httpResponseCode = http2.GET();

  if (httpResponseCode > 0)
  {
    Serial.println("Fase 2 - VINDECODER : VIA PARTSAPI.RU ");
    //Serial.println(httpResponseCode);
    //String payload = http2.getString();

    DynamicJsonDocument doc(1536);
    /////////////////////////
    DeserializationError error = deserializeJson(doc, http2.getStream());
    ////////////////////////////////

    //ReadBufferingStream bufferedFile(payload, 64);
    //DeserializationError error = deserializeJson(doc, bufferedFile);

    if (error)
    {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    JsonObject result_0 = doc["result"]["0"];
    int result_0_carId = result_0["carId"];
    const char *result_0_manuName = result_0["manuName"];
    const char *result_0_modelName = result_0["modelName"];
    long result_0_yearOfConstrFrom = result_0["yearOfConstrFrom"];
    long result_0_yearOfConstrTo = result_0["yearOfConstrTo"];
    const char *result_0_typeName = result_0["typeName"];
    const char *result_0_fuelType = result_0["fuelType"];
    idCar = String(result_0_carId);
    Make = result_0_manuName;
    Model = result_0_modelName;
    Year = result_0_yearOfConstrFrom;
    String Year2 = String(result_0_yearOfConstrTo);
    Year2 = Year2.substring(0, 4);
    Year = Year.substring(0, 4);
    Year = Year + " - " + Year2;
    Version = result_0_typeName;
    Fuel = result_0_fuelType;
  }

  // Free resources
  http2.end();

  Serial.print("Marca: ");
  Serial.println(Make);
  Serial.print("Modelo: ");
  Serial.println(Model);
  Serial.print("Year: ");
  Serial.println(Year);
  Serial.print("Version: ");
  Serial.println(Version);
  Serial.print("Combustible: ");
  Serial.println(Fuel);
  Serial.println();

  Log_text +="Stage 2 - All OK <br>";
}

void leer_vin()
{

  obd.getVIN(VIN, 192);
  delay(1000);
  Serial.println(VIN);
 

  VIN2 = String(VIN);

  //Serial.println(VIN_S);
  if (VIN2.length() > 20)
  {
    VIN2.replace("49 02 05", "");
    VIN2.replace("49 02 04", "");
    VIN2.replace("49 02 03", "");
    VIN2.replace("49 02 02", "");
    VIN2.replace("49 02 01", "");
    VIN2.replace("00 00 00", "");
    VIN2.replace(">", "");
    VIN2.replace(" ", "");

    VIN2.replace("\n", "");
    VIN2.replace("\r", "");
    //VIN2.replace("\0","");
    Serial.println(VIN2.length());
    String VIN_S, VIN_S2;
    VIN_S = hexToAscii(VIN2);
    Serial.println(VIN_S);
    VIN_S.toCharArray(VIN, 18);
  }
 // DecoderVin2(VIN);
}

///////////////////////////////////////////////////

void showData(byte pid, int value)
{
  switch (pid)
  {
  case PID_RPM:
    RPM = value;
    break;
  case PID_SPEED:
    SPEED = value;
    break;
  case PID_CONTROL_MODULE_VOLTAGE:
    VOLTAGE = value;
    break;
  case PID_COOLANT_TEMP:
    TEMPAGUA = value;
    break;
  case PID_ENGINE_OIL_TEMP:
    TEMPOIL = value;
    break;
  case PID_FUEL_LEVEL:
    FUELLEVEL = value;
    break;
  }
}

void showData2(byte pid, int value)
{
  switch (pid)
  {
  case PID_ODOMETER:
    ODOMETER = value;
    break;
  case PID_ENGINE_REF_TORQUE:
    ENGINE_REF_TORQUE = value;
    break;
  case PID_ENGINE_TORQUE_PERCENTAGE:
    ENGINE_TORQUE_PERCENTAGE = value;
    break;
  case PID_ENGINE_TORQUE_DEMANDED:
    ENGINE_TORQUE_DEMANDED = value;
    break;
  case PID_ENGINE_FUEL_RATE:
    ENGINE_FUEL_RATE = value;
    break;
  case PID_FUEL_INJECTION_TIMING:
    FUEL_INJECTION_TIMING = value;
    break;
  case PID_FUEL_RAIL_PRESSURE:
    FUEL_RAIL_PRESSURE = value;
    break;
  case PID_HYBRID_BATTERY_PERCENTAGE:
    HYBRID_BATTERY_PERCENTAGE = value;
    break;
  case PID_ETHANOL_FUEL:
    ETHANOL_FUEL = value;
    break;
  case PID_ENGINE_LOAD:
    ENGINE_LOAD = value;
    break;
  case PID_SHORT_TERM_FUEL_TRIM_1:
    SHORT_TERM_FUEL_TRIM_1 = value;
    break;
  case PID_LONG_TERM_FUEL_TRIM_1:
    LONG_TERM_FUEL_TRIM_1 = value;
    break;
  case PID_SHORT_TERM_FUEL_TRIM_2:
    SHORT_TERM_FUEL_TRIM_2 = value;
    break;
  case PID_LONG_TERM_FUEL_TRIM_2:
    LONG_TERM_FUEL_TRIM_2 = value;
    break;
  case PID_FUEL_PRESSURE:
    FUEL_RAIL_PRESSURE = value;
    break;
  case PID_INTAKE_MAP:
    INTAKE_MAP = value;
    break;
  case PID_TIMING_ADVANCE:
    TIMING_ADVANCE = value;
    break;
  case PID_INTAKE_TEMP:
    INTAKE_TEMP = value;
    break;
  case PID_MAF_FLOW:
    MAF_FLOW = value;
    break;
  case PID_THROTTLE:
    THROTTLE = value;
    break;
  case PID_AUX_INPUT:
    AU_INPUT = value;
    break;
  case PID_RUNTIME:
    RUNTIME = value;
    break;
  case PID_DISTANCE_WITH_MIL:
    DISTANCE_WITH_MIL = value;
    break;
  case PID_COMMANDED_EGR:
    COMMANDED_EGR = value;
    break;
  case PID_EGR_ERROR:
    EGR_ERROR = value;
    break;
  case PID_COMMANDED_EVAPORATIVE_PURGE:
    COMMANDED_EVAPORATIVE_PURGE = value;
    break;
  case PID_WARMS_UPS:
    WARMS_UPS = value;
    break;
  case PID_DISTANCE:
    DISTANCE = value;
    break;
  case PID_EVAP_SYS_VAPOR_PRESSURE:
    EVAP_SYS_VAPOR_PRESSURE = value;
    break;
  case PID_BAROMETRIC:
    BAROMETRIC = value;
    break;
  case PID_CATALYST_TEMP_B1S1:
    CATALYST_TEMP_BS_C = value;
    break;
  case PID_CATALYST_TEMP_B2S1:
    CATALYST_TEMP_BS_D = value;
    break;
  case PID_CATALYST_TEMP_B1S2:
    CATALYST_TEMP_BS_E = value;
    break;
  case PID_CATALYST_TEMP_B2S2:
    CATALYST_TEMP_BS_F = value;
    break;
  case PID_ABSOLUTE_ENGINE_LOAD:
    ABSOLUTE_ENGINE_LOAD = value;
    break;
  case PID_AIR_FUEL_EQUIV_RATIO:
    AIR_FUEL_EQUIV_RATIO = value;
    break;
  case PID_RELATIVE_THROTTLE_POS:
    RELATIVE_THROTTLE_POS = value;
    break;
  case PID_AMBIENT_TEMP:
    AMBIENT_TEMP = value;
    break;
  case PID_ABSOLUTE_THROTTLE_POS_B:
    ABSOLUTE_THROTTLE_POS_B = value;
    break;
  case PID_ABSOLUTE_THROTTLE_POS_C:
    ABSOLUTE_THROTTLE_POS_C = value;
    break;
  case PID_ACC_PEDAL_POS_D:
    ACC_PEDAL_POS_D = value;
    break;
  case PID_ACC_PEDAL_POS_E:
    ACC_PEDAL_POS_E = value;
    break;
  case PID_ACC_PEDAL_POS_F:
    ACC_PEDAL_POS_F = value;
    break;
  case PID_COMMANDED_THROTTLE_ACTUATOR:
    COMMANDED_THROTTLE_ACTUATOR = value;
    break;
  case PID_TIME_WITH_MIL:
    TIME_WITH_MIL = value;
    break;
  case PID_TIME_SINCE_CODES_CLEARED:
    TIME_SINCE_CODES_CLEARED = value;
    break;
  }
}

void leer_pids()
{

  static byte pids[] = {PID_RPM, PID_SPEED, PID_CONTROL_MODULE_VOLTAGE, PID_FUEL_LEVEL, PID_COOLANT_TEMP, PID_ENGINE_OIL_TEMP};
  static byte index = 0;
  byte pid = pids[index];

  int value;

  if (obd.readPID(pid, value))
  {

    showData(pid, value);
  }
  index = (index + 1) % sizeof(pids);
   //Serial.println("LEYENDO PIDS STANDARS");
}

void leer_pids2()
{

  static byte pids[] = {PID_ODOMETER, PID_ENGINE_REF_TORQUE, PID_ENGINE_TORQUE_PERCENTAGE, PID_ENGINE_TORQUE_DEMANDED, PID_ENGINE_FUEL_RATE, PID_FUEL_INJECTION_TIMING, PID_HYBRID_BATTERY_PERCENTAGE, PID_FUEL_RAIL_PRESSURE, PID_ETHANOL_FUEL, PID_ENGINE_LOAD, PID_SHORT_TERM_FUEL_TRIM_1, PID_LONG_TERM_FUEL_TRIM_1, PID_SHORT_TERM_FUEL_TRIM_2, PID_LONG_TERM_FUEL_TRIM_2, PID_FUEL_PRESSURE, PID_INTAKE_MAP, PID_TIMING_ADVANCE, PID_INTAKE_TEMP, PID_MAF_FLOW, PID_THROTTLE, PID_AUX_INPUT, PID_RUNTIME, PID_DISTANCE_WITH_MIL, PID_COMMANDED_EGR, PID_EGR_ERROR, PID_COMMANDED_EVAPORATIVE_PURGE, PID_WARMS_UPS, PID_DISTANCE, PID_EVAP_SYS_VAPOR_PRESSURE, PID_BAROMETRIC, PID_CATALYST_TEMP_B1S1, PID_CATALYST_TEMP_B2S1, PID_CATALYST_TEMP_B1S2, PID_CATALYST_TEMP_B2S2, PID_ABSOLUTE_ENGINE_LOAD, PID_AIR_FUEL_EQUIV_RATIO, PID_RELATIVE_THROTTLE_POS, PID_AMBIENT_TEMP, PID_ABSOLUTE_THROTTLE_POS_B, PID_ABSOLUTE_THROTTLE_POS_C, PID_ACC_PEDAL_POS_D, PID_ACC_PEDAL_POS_E, PID_ACC_PEDAL_POS_F, PID_COMMANDED_THROTTLE_ACTUATOR, PID_TIME_WITH_MIL, PID_TIME_SINCE_CODES_CLEARED};
  static byte index = 0;
  byte pid = pids[index];

  int value;

  if (obd.readPID(pid, value))
  {

    showData2(pid, value);
  }
  index = (index + 1) % sizeof(pids);
  //Serial.println("LEYENDO PIDS COMPLETOS");
}

void Nuevo_VIN()
{

  if (strcmp(VIN, VIN_INI) == 0)
  {
  }

  else
  {
    Serial.println();
    Serial.print("Leido un nuevo VIN : ");
    Log_text +="Stage 2 - New VIN: ";
    Log_text +=String(VIN) +"<br>";
    Serial.println(VIN);

    Serial.println("Inicializamos nuevos datos : ");
    
    DecoderVin2(VIN);
    strcpy(VIN_INI, VIN);
  }
}




void handlePageCat(AsyncWebServerRequest *request)
{

  pids_status = false;
  Serial.println("Pag Catalogo - Catergories");
  Cat = request->arg("gr");
  Cat.replace(" ", "%20");
  Serial.println(Cat);

  request->send(200, "text/html", PAGE_Parts2);
}

void handlePageRef(AsyncWebServerRequest *request)
{

  pids_status = false;
  Serial.println("Pag Catalogo - Referencias");
  Ref = request->arg("gr");
  Ref.replace(" ", "%20");
  Serial.println(Ref);

  request->send(200, "text/html", PAGE_Parts3);
}
void handlePageCrossRef(AsyncWebServerRequest *request)
{

  pids_status = false;
  Serial.println("Pag Catalogo - Cross Referencias");
  CrossRef = request->arg("gr");
  CrossRef.replace(" ", "%20");
  Serial.println(CrossRef);

  request->send(200, "text/html", PAGE_Parts4);
}
void handlePageList(AsyncWebServerRequest *request)
{

  pids_status = false;
  Serial.println("Pag Listado  - Errores STANDARD");
  make_code = request->arg("make_code");
  make_code.replace(" ", "%20");
  request->send(200, "text/html", PAGE_List);
}


void handleList(AsyncWebServerRequest *request)
{
  pids_status = false;

  getList();
  //Serial.println(List_errors);
  request->send(200, "text/html", List_errors);
}

void handleCats(AsyncWebServerRequest *request)
{
  pids_status = false;

  BCats();
  request->send(200, "text/html", Cats);
}
void handleRefs(AsyncWebServerRequest *request)
{
  pids_status = false;

  BRefs();
  request->send(200, "text/html", Refs);
}

void handleCrossRefs(AsyncWebServerRequest *request)
{
  pids_status = false;

  //BCrossRefs();
  mensajeW="";
  Top_parts(CrossRef);
  Top_parts_oem(CrossRef);
  request->send(200, "text/html", mensajeW);
}

void handleNotFound(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Pag NotFound 404");
  request->send(404, "text/plain", "Not found");
}

void handlePageGauges(AsyncWebServerRequest *request)
{
  pids_status = true;
  Serial.println("Pag Gauges");
  request->send(200, "text/html", PAGE_Gauges); //Send web page
}

void handlePagePids(AsyncWebServerRequest *request)
{
  pids_status = true;
  Serial.println("Pag Pids");
  request->send(200, "text/html", PAGE_Pids); //Send web page
}


void handlePageTop(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Pag Top");
  request->send(200, "text/html", PAGE_Top); //Send web page
}

void handlePageVin(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Pag Manual VIN");
  request->send(200, "text/html", PAGE_Vin); //Send web page
}

void handlePageAVin(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Pag Automatic VIN");
  VIN_MANU = "";
  Make = "";
  Model = "";
  Version = "";
  Year = "";
  Fuel = "";
 

  request->send(200, "text/html", "Request sent to your OBD2 on input VIN with value: Automatic <br><a href=\"/\">Return to Home Page</a>");
                             
}

void handlePageDtc(AsyncWebServerRequest *request)
{

  pids_status = false;
  Serial.println("Pag DTCS");
  Solucion_Euro = "";
  request->send(200, "text/html", PAGE_Error_1); //Send web page
}
void handleGroups(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Pag Catalogo - Groups");
  BGroups();
  //Error_codes="";
  request->send(200, "text/html", Groups);
}
void handlePageSolution(AsyncWebServerRequest *request)
{

  pids_status = false;
  Serial.println("Pag DTCS");

  dtcCount = obd.readDTC(codes, 6);
  if (dtcCount == 0)
  {
    mensajeW = "";
  }
  else
  {
   // while (!Conect_Json)
   // {
      
      Serial.println("Buscando el recambio: ");
      Buscar_error3();
      delay(100); //
   // }
  }
  //Serial.println(Solucion_Euro);

  //String response = (Make + " " + Model + " " + Year + " " + Fuel + " Err: " + ("P0" + String(codes[0], HEX)) + " Sol: " + Solucion_Euro + "'");
  //String Pagina_solution = PAGE_Error_S + response + PAGE_Error_S2;
  request->send(200, "text/html", PAGE_Error_S);
}
void handlePageParts(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Pag Catalogue");
  mensajeW = "";
  CrossRefs = "";
  // BGroups();
  request->send(200, "text/html", PAGE_Parts); //Send web page
}

void handlePageParts2(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Pag ALL Catalogue");

  request->send(200, "text/html", PAGE_All_catalogue); //Send web page
}

void handleRoot(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Pag Info/Home");

  request->send(200, "text/html", MAIN_page); //Send web page
}
/*void handleLeerVin(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Pag Leer Vin");
  leer_vin();

  request->send(200, "text/html", MAIN_page); //Send web page
}*/
void handleReset(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Reset  5 segundos");

  connected = false;
  obd.reset();

  request->send(200, "text/html", Page_Reset); //Send web page

  delay(1000);

  sys.resetLink();
  //ESP.restart();
}

void handleOpenAI(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Actualizando OpenAI");
  /*OpenAI();*/

  request->send(200, "text/html", Texto_OpenAI); //Send ADC value only to client ajax request
}
void handlePageOpenAI(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("PAG OpenAI");
  //OpenAI();

  request->send(200, "text/html", PAGE_Open_AI); //Send ADC value only to client ajax request
}

void handleClearDtc(AsyncWebServerRequest *request)
{
  pids_status = false;
  obd.clearDTC();
  delay(100);
  Serial.println("Errores limpiados");
  //request->send(200, "text/html", PAGE_Error_1);

    request->send(200, "text/html", "Cleared DTCs to your OBD2 <br><a href=\"/\">Return to Home Page</a>");

}

void handleError(AsyncWebServerRequest *request)
{
  pids_status = false;
  Serial.println("Actualizando Errores DTCS");
  Buscar_error();
  request->send(200, "text/html", Error); //Send Status_texte value only to client ajax request
}

void handleMake(AsyncWebServerRequest *request)
{
  pids_status = false;
  
  VIN2 = String(VIN);
  String make2 = Make;
  make2.replace(" ", "");
  //Serial.println(VIN2.length() );
  if (connected)
  {
    Serial.println("Actualizando Info del vehicle");
    InfoValue = ("<table><tr style='color:#0063b1; padding: 15px; background:white ;'><td style='padding: 15px;'> <img src='http://172.20.10.10/buttons/images_carbrands/" + make2 + ".png' class='w3-left w3-circle w3-margin-right' style='width:40px'></td><td style='padding: 15px;'><h4>VIN: " + String(VIN) + "<br>" + "BRAND: " + Make + " - " + " MODEL: " + Model + " <br> " + " VERSION: " + Version + "<br>" + "YEAR: " + Year + " - " + " FUEL: " + Fuel + "</h4></td></tr></table>");

    request->send(200, "text/html", InfoValue); //Send ADC value only to client ajax request
  }
}

void handleProtocolo(AsyncWebServerRequest *request)
{

  pids_status = false;
  Serial.println("Actualizando Protocolo del vehicle");
  if (connected)
  {
    if ((connected) and (dtcCount == 0))
    {
      InfoValue = ("<table><td style='background: #03C04A ;color: white; padding: 15px;'>Connected to ECU Protocol: " + S_Obd_protocol + " </td><td style='background: #03C04A ;color: white; padding: 15px;'>   Nº codes: " + dtcCount + "</td></table>");
    }

    if ((connected) and (dtcCount > 0))
    {
      InfoValue = ("<table><td style='background: #03C04A ;color: white; padding: 15px;'>Connected to ECU Protocol: " + S_Obd_protocol + " </td><td style='background: red ;color: white; padding: 15px;'>   Nº codes: " + dtcCount + "</td></table>");
    }
  }
  else
  {
    InfoValue = ("<h4 style='background: orange ;color: white; padding: 15px;'>Auto-scanner Protocol: " + S_Obd_protocol);
  }

  request->send(200, "text/html", InfoValue); //Send ADC value only to client ajax request
}

void handlePIDS(AsyncWebServerRequest *request)
{
  pids_status = true;
  Serial.println("Actualizando PIDS TAB- INFO del vehicle ADVANCED");
  
  if (connected)
  {
    String InfoValue;
    InfoValue = ("<h5><table style='width:100%;'><tr><td><table><tr><td>RPM: </td><td>" + String(RPM) + "rpm</td></tr><tr><td>SPEED: </td><td>" + String(SPEED) + "km/h</td></tr><tr><td>VOLTAGE: </td><td>" + String(VOLTAGE) + "v</td></tr><tr><td>FUEL: </td><td>" + String(FUELLEVEL) + "%</td></tr><tr><td>TEMP H2O: </td><td>" + String(TEMPAGUA) + "cº</td></tr><tr><td>TEMP OIL: </td><td>" + String(TEMPOIL) + "cº</td></tr><tr><td>ODOMETRE: </td><td>" + String(ODOMETER) + "m</td></tr><tr><td>TORQUE: </td><td>" + String(ENGINE_REF_TORQUE) + "n/m</td></tr><tr><td>TORQUE: </td><td>" + String(ENGINE_TORQUE_PERCENTAGE) + "%</td></tr><tr><td>TORQUE DEMANDA: </td><td>" + String(ENGINE_TORQUE_DEMANDED) + "n/m</td></tr><tr><td>FUEL RATE: </td><td>" + String(ENGINE_FUEL_RATE) + "%</td></tr><tr><td>FUEL INJECTION TIMING: </td><td>" + String(FUEL_INJECTION_TIMING) + "s</td></tr><tr><td>FUEL RAIL PRESSUERE: </td><td>" + String(FUEL_RAIL_PRESSURE) + "kPa</td></tr><tr><td>HYBRID BATTERY: </td><td>" + String(HYBRID_BATTERY_PERCENTAGE) + "%</td></tr><tr><td>ETHANOL FUEL: </td><td>" + String(ETHANOL_FUEL) + "%</td></tr></table></td><td></td><td></td><td></td><td><table><tr><td>ENGINE_LOAD: </td><td>" + String(ENGINE_LOAD) + "%</td></tr><tr><td>FUEL_PRESSURE: </td><td>" + String(FUEL_PRESSURE) + "Kpa</td></tr><tr><td>WARMS_UPS: </td><td>" + String(WARMS_UPS) + "</td></tr><tr><td>EGR_ERROR: </td><td>" + String(EGR_ERROR) + "</td></tr><tr><td>COMMANDED_EGR: </td><td>" + String(COMMANDED_EGR) + "</td></tr><tr><td>BAROMETRIC: </td><td>" + String(BAROMETRIC) + "</td></tr><tr><td>INTAKE_MAP: </td><td>" + String(INTAKE_MAP) + "</td></tr><tr><td>THROTTLE: </td><td>" + String(THROTTLE) + "%</td></tr><tr><td>RELATIVE_THROTTLE_POS: </td><td>" + String(RELATIVE_THROTTLE_POS) + "%</td></tr><tr><td>ABSOLUTE_THROTTLE_POS_B: </td><td>" + String(ABSOLUTE_THROTTLE_POS_B) + "</td></tr><tr><td>ABSOLUTE_THROTTLE_POS_C: </td><td>" + String(ABSOLUTE_THROTTLE_POS_C) + "</td></tr><tr><td>COMMANDED_THROTTLE_ACTUATOR: </td><td>" + String(COMMANDED_THROTTLE_ACTUATOR) + "s</td></tr><tr><td>MAF_FLOW: </td><td>" + String(MAF_FLOW) + "</td></tr><tr><td>RUNTIME: </td><td>" + String(RUNTIME) + "s</td></tr><tr><td>DISTANCE: </td><td>" + String(DISTANCE) + "m</td></tr></table></td><td></td><td></td><td></td><td><table><tr><td>TIMING_ADVANCE: </td><td>" + String(TIMING_ADVANCE) + "s</td></tr><tr><td>TIME_WITH_MIL: </td><td>" + String(TIME_WITH_MIL) + "s</td></tr><tr><td>TIME_SINCE_CODES_CLEARED: </td><td>" + String(TIME_SINCE_CODES_CLEARED) + "</td></tr><tr><td>AMBIENT_TEMP: </td><td>" + String(AMBIENT_TEMP) + "</td></tr><tr><td>DISTANCE_WITH_MIL: </td><td>" + String(DISTANCE_WITH_MIL) + "</td></tr><tr><td>ABSOLUTE_ENGINE_LOAD: </td><td>" + String(ABSOLUTE_ENGINE_LOAD) + "</td></tr><tr><td>AIR_FUEL_EQUIV_RATIO: </td><td>" + String(AIR_FUEL_EQUIV_RATIO) + "</td></tr><tr><td>AUX_INPUT: </td><td>" + String(AU_INPUT) + "</td></tr><tr><td>COMMANDED_EVAPORATIVE_PURGE: </td><td>" + String(COMMANDED_EVAPORATIVE_PURGE) + "</td></tr><tr><td>EVAP_SYS_VAPOR_PRESSURE: </td><td>" + String(EVAP_SYS_VAPOR_PRESSURE) + "</td></tr><tr><td>INTAKE_TEMP: </td><td>" + String(INTAKE_TEMP) + "</td></tr><tr><td>CATALYST_TEMP_BS_C: </td><td>" + String(CATALYST_TEMP_BS_C) + "s</td></tr><tr><td>CATALYST_TEMP_BS_D: </td><td>" + String(CATALYST_TEMP_BS_D) + "</td></tr><tr><td>CATALYST_TEMP_BS_E: </td><td>" + String(CATALYST_TEMP_BS_E) + "s</td></tr><tr><td>CATALYST_TEMP_BS_F: </td><td>" + String(CATALYST_TEMP_BS_F) + "m</td></tr></table></td></tr></table></h5>");

    request->send(200, "text/html", InfoValue); //Send ADC value only to client ajax request
  }
}

void handlePIDS2(AsyncWebServerRequest *request)
{

  pids_status = true;
  
  Serial.println("Actualizando PIDS TAB- INFO del vehicle STANDARS");
  if (connected)
  {
    String InfoValue;
    InfoValue = ("<table><tr><td><div style='font-size:150%; background:white; color:#0063b1; span:15;'>RPM    </td><td style='min-width: 150px; span:10px;'></td><td><div style='font-size:150%; background:white; color:#0063b1; span:15;'>   SPEED </div></td><td style='min-width: 150px; span:10px;'></td></tr><tr><td><div style='font-size:300%; background:#0063b1; color:white; span:15;text-align: right;'>" + String(RPM) + "</td><td style='font-size:100%; background:#0063b1; color:white; span:15;'>rpm</td><td><div style='font-size:300%; background:#0063b1; color:white; span:15;text-align: right;'>" + String(SPEED) + "</td><td style='font-size:100%; background:#0063b1; color:white; span:15;'>km/h</div></td></tr><tr><td><div style='font-size:150%; background:white; color:#0063b1; span:15;'>VOLTAGE  </td><td></td><td><div style='font-size:150%; background:white; color:#0063b1; span:15;'>   FUEL </div></td></tr><tr><td><div style='font-size:300%; background:#0063b1; color:white; span:15;text-align: right;'>" + String(VOLTAGE) + "</td><td style='font-size:100%; background:#0063b1; color:white; span:15;'>V</td><td><div style='font-size:300%; background:#0063b1; color:white; span:15;text-align: right;'>" + String(FUELLEVEL) + "</td><td style='font-size:100%; background:#0063b1; color:white; span:15;'>%</div></td></tr><tr><td><div style='font-size:150%; background:white; color:#0063b1; span:15;'>TEMP H2O </td><td></td><td><div style='font-size:150%; background: white; color:#0063b1; span:15;'> TEMP OIL </div></td></tr><tr><td><div style='font-size:300%; background:#0063b1; color:white; span:15;text-align: right;'>" + String(TEMPAGUA) + "</td><td style='font-size:100%; background:#0063b1; color:white; span:15;'>cº   </td><td> <div style='font-size:300%; background:#0063b1; color:white; span:15;text-align: right;'>" + String(TEMPOIL) + "</td><td style='font-size:100%; background:#0063b1; color:white; span:15;'>cº</div></td></tr></table>");

    request->send(200, "text/html", InfoValue); //Send ADC value only to client ajax request
  }
}


void handleLog(AsyncWebServerRequest *request)
{
  Serial.println("Actualizando Log OBD");
  pids_status = false;
  request->send(200, "text/html", Log_text); //Send ADC value only to client ajax request
  
}



void handleidCar(AsyncWebServerRequest *request)
{
  Serial.println("Actualizando Catalogo OEM");
  pids_status = false;
  mensajeW = "";
  if (dtcCount != 0)
  {
    Buscar_error3();
    request->send(200, "text/html", "<table><tr><td>Recommended solutions: </td></tr><tr><td></td></tr><tr><td>-Check the electrical wiring and connectors, related to the code</td></tr><tr><td>-Verify there is no corrosion, or water in the sensor / related spare part</td></tr><tr><td>-Replace the following spare part:</td></tr><tr><td>.</td></tr><tr><td>.</td></tr><tr><td>" + mensajeW + "</td></tr></table>");
  }
}

void handleRPM(AsyncWebServerRequest *request)
{
  pids_status = true;
  valor_gauge = RPM;
  //Serial.print("Actualizando RPM - Gauges: ");
  //Serial.println(RPM);
  String adcValue = String(valor_gauge);

  request->send(200, "text/plain", adcValue); //Send ADC value only to client ajax request
}

void handleSPEED(AsyncWebServerRequest *request)
{
  pids_status = true;
  valor_gauge = SPEED;
  //Serial.print("Actualizando SPEED - Gauges: ");
  //Serial.println(SPEED);
  String adcValue = String(valor_gauge);

  request->send(200, "text/plain", adcValue); //Send ADC value only to client ajax request
}

void handleTop(AsyncWebServerRequest *request)
{

  pids_status = false;
  Serial.println("Actualizando TOP del vehicle");
  
 if ((connected) and (Make != "") )
 {
  
mensajeW="<table>";
Top_parts("Air Filter");
Top_parts("Oil Filter");
Top_parts("Fuel Filter");
Top_parts("Clutch disc");
Top_parts("Thermostat, coolant");
Top_parts("Master cylinder, clutch system");
mensajeW+="</table>";
    request->send(200, "text/html", mensajeW); //Send ADC value only to client ajax request
  }
}


void Buscar_Protocolo()
{
  pids_status = false;
  //PROTO_AUTO
  Serial.println("PROTO_AUTO Conectando");
  Log_text +="Stage 1 - Protocol AUTO Connect --->  ";
  S_Obd_protocol = "PROTO_AUTO Connecting ";
  if (obd.init(PROTO_AUTO))
  {
    S_Obd_protocol = "PROTO_AUTO OK !!";
    Serial.println("PROTO_AUTO OK");
    Log_text +=" Protocol AUTO OK <br>";
    Serial.println();
    connected = true;

    Serial.print("Fase 1 - Leemos VIN: ");
    Log_text +="Stage 1 - Read VIN: ";
    leer_vin();

    Serial.println(VIN);
    Log_text +=String(VIN)+"<br>";
    Log_text +="Stage 1 - All Ok <br>";
  }
  else
  {

    //delay(50);
    Serial.println("PROTO_KWP2000_5KBPS Conectando");
    S_Obd_protocol = "PROTO_KWP2000_5KBPS Connecting ";
    if (obd.init(PROTO_KWP2000_5KBPS))
    {
      S_Obd_protocol = "PROTO_KWP2000_5KBPS OK !!";
      Serial.println("PROTO_KWP2000_5KBPS OK");
      Serial.println();
      connected = true;

      Serial.print("Fase 1 - Leemos VIN: ");
      leer_vin();

      Serial.println(VIN);
    }
    else
    {
     // delay(50);
      Serial.println("PROTO_CAN_11B_500K Conectando");
      S_Obd_protocol = "PROTO_CAN_11B_500K Connecting ";
      if (obd.init(PROTO_CAN_11B_500K))
      {
        S_Obd_protocol = "PROTO_CAN_11B_500K OK !!";
        Serial.println("PROTO_CAN_11B_500K OK");
        Serial.println();
        connected = true;

        Serial.print("Fase 1 - Leemos VIN: ");
        leer_vin();

        Serial.println(VIN);
      }
      else
      {
       // delay(50);
        Serial.println("PROTO_CAN_29B_500K Conectando");
        S_Obd_protocol = "PROTO_CAN_29B_500K Connecting ";
        if (obd.init(PROTO_CAN_29B_500K))
        {
          S_Obd_protocol = "PROTO_CAN_29B_500K OK !!";
          Serial.println("PROTO_CAN_29B_500K OK");
          Serial.println();
          connected = true;

          Serial.print("Fase 1 - Leemos VIN: ");
          leer_vin();

          Serial.println(VIN);
        }
        else
        {
         // delay(50);
          Serial.println("PROTO_CAN_29B_250K Conectando");
          S_Obd_protocol = "PROTO_CAN_29B_250K Connecting ";
          if (obd.init(PROTO_CAN_29B_250K))
          {
            S_Obd_protocol = "PROTO_CAN_29B_250K OK !!";
            Serial.println("PROTO_CAN_29B_250K OK");
            Serial.println();
            connected = true;

            Serial.print("Fase 1 - Leemos VIN: ");
            leer_vin();

            Serial.println(VIN);
          }
          else
          {
          //  delay(50);
            Serial.println("PROTO_CAN_11B_250K Conectando");
            S_Obd_protocol = "PROTO_CAN_11B_250K Connecting ";
            if (obd.init(PROTO_CAN_11B_250K))
            {
              S_Obd_protocol = "PROTO_CAN_11B_250K OK !!";
              Serial.println("PROTO_CAN_11B_250K OK");
              Serial.println();
              connected = true;

              Serial.print("Fase 1 - Leemos VIN: ");
              leer_vin();

              Serial.println(VIN);
            }
            else
            {
            //  delay(50);
              Serial.println("PROTO_ISO_9141_2 Conectando");
              S_Obd_protocol = "PROTO_ISO_9141_2 Connecting ";
              if (obd.init(PROTO_ISO_9141_2))
              {
                S_Obd_protocol = "PROTO_ISO_9141_2 OK !!";
                Serial.println("PROTO_ISO_9141_2 OK");
                Serial.println();
                connected = true;

                Serial.print("Fase 1 - Leemos VIN: ");
                leer_vin();

                Serial.println(VIN);
              }
              else
              {
               // delay(50);
                Serial.println("PROTO_KWP2000_FAST Conectando");
                S_Obd_protocol = "PROTO_KWP2000_FAST Connecting ";
                if (obd.init(PROTO_KWP2000_FAST))
                {
                  S_Obd_protocol = "PROTO_KWP2000_FAST OK !!";
                  Serial.println("PROTO_KWP2000_FAST OK");
                  Serial.println();
                  connected = true;

                  Serial.print("Fase 1 - Leemos VIN: ");
                  leer_vin();
                  Serial.println(VIN);
                }
                else
                {
                  
                  S_Obd_protocol = "ReConnecting  !!";
                  Serial.println("RE - Conectamos ");
                  
                }
              }
            }
          }
        }
      }
    }
  }
}

void setup()
{

  delay(100);
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  WiFi.begin(ssid, password);
  Serial.println("Fase 0 - Buscando Wifi ");
  Log_text +="Stage 0 - Search Wifi <br>";
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Conectado to WiFi network con IP Address: ");
  Serial.println(WiFi.localIP());
  
  Log_text +="Stage 0 - Connect to WiFi network <br>";
  
  Serial.println();
  ////////////////////////////////////
  //  ThingSpeak.begin(cliente);
  ////////////////////////////////////

  Serial.println("Inicializando mDNS , Http server");
  Serial.println();
  Log_text +="Stage 0 - Init mDNS , Http server: ";
  // DNS name  navegador http://obd2.local

  if (!MDNS.begin("obd2"))
  {
    Serial.println("Error inicializacion mDNS");
    Log_text +="Error init mDNS <br>";
    return;
  }
  else
  {
    Serial.println("mDNS  OK: obd2.local - OK");
    Log_text +="DNS  OK: obd2.local - OK <br>";
  }

  server.on("/", handleRoot); //This is display page
  
  server.on("/pageGauges", handlePageGauges);
  server.on("/pagePids", handlePagePids);
  server.on("/pageTop", handlePageTop);
  server.on("/pageVin", handlePageVin);
  server.on("/pageAVin", handlePageAVin);
  server.on("/pageDtcs", handlePageDtc);
  server.on("/pageSolution", handlePageSolution);
  server.on("/pageParts", handlePageParts);
  server.on("/pageParts2", handlePageParts2);
  //server.on("/pageOpenAI", handlePageOpenAI);
  server.on("/pageCat", handlePageCat);
  server.on("/pageRef", handlePageRef);
  server.on("/pageCrossRef", handlePageCrossRef);
  server.on("/pageList",handlePageList);
  

  server.on("/readList",handleList);
  server.on("/readLog",handleLog);
  server.on("/readRPM", handleRPM); //To get update of RPM Value only
  server.on("/readSPEED", handleSPEED);
  server.on("/readProtocolo", handleProtocolo);
  server.on("/readMake", handleMake);
  server.on("/readPIDS", handlePIDS);
  server.on("/readPIDS2", handlePIDS2);
  server.on("/readTop", handleTop);
  server.on("/readError", handleError);

  server.on("/idCar", handleidCar);
  server.on("/ClearDTC", handleClearDtc);
  //server.on("/LeerVin", handleLeerVin);
  server.on("/Reset", handleReset);
  //server.on("/OpenAI", handleOpenAI);

  server.on("/Groups", handleGroups);
  server.on("/Cats", handleCats);
  server.on("/Refs", handleRefs);
  server.on("/CrossRefs", handleCrossRefs);

  server.on("/get", HTTP_GET, [](AsyncWebServerRequest *request)
            {
              String input_message;
              String input_parameter;

              if (request->hasParam(input_parameter1))
              {
                input_message = request->getParam(input_parameter1)->value();
                input_parameter = input_parameter1;
                VIN_MANU = input_message;
                //VIN_MANU.toCharArray(VIN, 18);
                //DecoderVin2(VIN);
                //request->send(200, "text/html", MAIN_page);
                request->send(200, "text/html", "Request sent to your OBD2 on input VIN with value: " + input_message +
                                "<br><a href=\"/\">Return to Home Page</a>");
              }
            });

  // Handle requests for pages that do not exist
  server.onNotFound(handleNotFound);

  server.begin(); //Start server
  delay(100);     //
  Serial.println("HTTP server started - OK ");
  Log_text +="Stage 0 - HTTP server started - OK   <br>";
  Serial.println();

  Serial.println("Inicializando OBDII");
  Log_text +="Stage 0 - Inicializando OBDII  <br>";
  Serial.println();

  // inicializamos sys y obd
  while (!sys.begin())
    ;
  obd.begin(sys.link);

  digitalWrite(PIN_LED, HIGH);
  Log_text +="Stage 0 - All Ok  <br>";
}

void loop()
{

  // put your main code here, to run repeatedly:
 dtcCount = obd.readDTC(codes, 6);

 
   if (!connected)
    {

      Serial.println("Conexion    OBDII ---> ");
      Log_text +="Stage 1 - Connect to   OBDII --->   <br>";
      Buscar_Protocolo();

      digitalWrite(PIN_LED, LOW);
      return;
    }

  if (VIN_MANU != "")
  {
    VIN_MANU.toCharArray(VIN, 18);
  }else{
   leer_vin();
   
  }
 
  Nuevo_VIN();
 
  
  if (pids_status){
  leer_pids();
  leer_pids2();
  }

  // if (obd.errors >= 2) {Serial.println("OBD Desconectado");connected = false;obd.reset();}

   // Miramos si hay un nuevo vin ??

  //if (timing<90){timing++; }else{

  //Serial.println();
  //grabar_datos_mysql();
  //Grabar_ThingSpeak();
  // timing=0;}//  Es el timming para Thing Speak Serial.println(timing);

  /////////////////////////
  //if (obd.errors >= 2) {Serial.println("OBD Desconectado");connected = false;obd.reset();}//  si hay errores de concexion OBD II ... Re-conectar.
  ////////////////////////
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_LED, LOW);
  //delay(500);
}
