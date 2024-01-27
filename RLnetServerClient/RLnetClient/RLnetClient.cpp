#include <RLnetClient.h>
#include <WiFi.h>

void RLnetClient::Connect(const char* ssid, const char* pass, const char* urlP){
    WiFi.begin(ssid, pass);
    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);
    }
    Serial.print("Rede conectada");
    Serial.println(WiFi.SSID());
    url = urlP;
      
}
void RLnetClient::stateWiFi(){
    if(WiFi.status() != WL_CONNECTED){
        return;
    }
}
void RLnetClient::get(String router, String query, fn f){

    stateWiFi();
    WiFiClient client;
    HTTPClient http;

    http.begin(client, url+router+query);

    int get = http.GET();
    
    if (get > 0){
        String res = http.getString();
        f(res);
    }
    else{
        Serial.print("Falha no servidor");
        f("Erro ao requisitar o servidor");
    }
    http.end();
}
void RLnetClient::post(String router, String data, fn f){
    stateWiFi();
    WiFiClient client;
    HTTPClient http;

    http.begin(client, url+router);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
   
    int post = http.POST(data.length()==0?"vazio=true":data);
    
    if (post > 0){
        String res = http.getString();
        f(res);
    }
    else{
        Serial.print("Falha no servidor");
        f("Erro ao requisitar o servidor");
    }
    http.end();
}