/*
 Basic ESP8266 MQTT example

 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.

 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outair" every two seconds
 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.

 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"

*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);

// Update these with values suitable for your network.

const char* ssid = "SLT-4G-6608";
const char* password = "334HE9T30JF";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;


//=======================================================================
int var=0;
String data;
String cpydata;
String cordinates = "20.22,23.92";
String cpycordinates = "20.22,23.92";

String Argument_Name;
String Clients_Response1 ="0";
String Clients_Response2 ="0";
String Temperature="0";
String Humidity="0";
String Pressure="0";
String PM1="0";
String PM10="0";
String PM25="0";
//======================================================================

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//============================================================================
void callback(char* topic, byte* payload, unsigned int length) {
  data="";
  var=1;
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    data+=(char)payload[i];
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    //digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    //digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}
//==============================================================================

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outair", "111hello world");
      // ... and resubscribe
      client.subscribe("inair");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
//================================================================================================
void handleRootPath() {           //Handler for the rooth path
  int count=0;
  //data="{\"PM1\":\"12\",\"PM25\":\"56\",\"PM10\":\"34\",\"Temperature\":\"45\",\"Humidity\":\"67\",\"Pressure\":\"12\"}";
  for(int j=0;j<data.length();j++){
    Serial.print(data[j]);
    };
  server.send(200, "JSON", data);
 
}
//===============================================HTML & CSS=======Side1=========================================

void HandleClient(){
    String webpage;
  webpage =  "<html>";
   webpage += "<head><title>ESP8266 Input Example</title><link href=\"https://fonts.googleapis.com/css?family=Roboto:300,400,500,700\"rel=\"stylesheet\"/>";
   webpage +="<link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.5.0/css/all.css\"integrity=\"sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU\"crossorigin=\"anonymous\"/>";
    webpage += "<style>";
     webpage += "body { min-height: 100%; }body,div,form,input,select,textarea,label,";
     webpage += "p { padding: 0; margin: 0; outline: none; font-family: Roboto, Arial, sans-serif; font-size: 14px; color: #666; line-height: 22px; } h1 { position: absolute; margin: 0; font-size: 40px; color: #fff; z-index: 2; line-height: 83px; } textarea { width: calc(100% - 12px); padding: 5px; } .testbox { display: flex; justify-content: center; align-items: center; height: inherit; padding: 20px; } form { width: 100%; padding: 20px; border-radius: 6px; background: #fff; box-shadow: 0 0 8px #669999; }";
     webpage+=".banner { position: relative; height: 500px; background-image: url(\"https://news.cgtn.com/news/3d3d674d3155444f33457a6333566d54/img/65d4acadc348426faecc19da4a5fbc07/65d4acadc348426faecc19da4a5fbc07.jpg\"); background-size: cover; display: flex; justify-content: center; align-items: center; text-align: center; }";
     webpage+=".banner::after { content: \"\"; background-color: rgba(0, 0, 0, 0.2); position: absolute; width: 100%; height: 100%; } input, select, textarea { margin-bottom: 10px; border: 1px solid #ccc; border-radius: 3px; } input { width: calc(100% - 10px); padding: 5px; } input[type=\"date\"] { padding: 4px 5px; } textarea { width: calc(100% - 12px); padding: 5px; }";
     webpage+=".item:hover p, .item:hover i, .question:hover p, .question label:hover, input:hover::placeholder { color: #669999; } .item input:hover, .item select:hover, .item textarea:hover { border: 1px solid transparent; box-shadow: 0 0 3px 0 #669999; color: #669999; } .item { position: relative; margin: 10px 0; } .item span { color: red; } .week { display: flex; justfiy-content: space-between; }";
     webpage+=".colums { display: flex; justify-content: space-between; flex-direction: row; flex-wrap: wrap; } .colums div { width: 48%; } input[type=\"date\"]::-webkit-inner-spin-button { display: none; } .item i, input[type=\"date\"]::-webkit-calendar-picker-indicator { position: absolute; font-size: 20px; color: #a3c2c2; } .item i { right: 1%; top: 30px; z-index: 1; } input[type=\"radio\"], input[type=\"checkbox\"] { display: none; } label.radio { position: relative; display: inline-block; margin: 5px 20px 15px 0; cursor: pointer; } .question span { margin-left: 30px; } .question-answer label { display: block; } label.radio:before { content: \"\"; position: absolute; left: 0; width: 17px; height: 17px; border-radius: 50%; border: 2px solid #ccc; } input[type=\"radio\"]:checked + label:before, label.radio:hover:before { border: 2px solid #669999; }";  
     webpage+="label.radio:after { content: \"\"; position: absolute; top: 6px; left: 5px; width: 8px; height: 4px; border: 3px solid #669999; border-top: none; border-right: none; transform: rotate(-45deg); opacity: 0; } input[type=\"radio\"]:checked + label:after { opacity: 1; } .flax { display: flex; justify-content: space-around; } .btn-block { margin-top: 10px; text-align: center; align-items: center; } button { width: 150px; padding: 10px; border: none; border-radius: 5px; background: #669999; font-size: 16px; color: #fff; cursor: pointer; } button:hover { background: #a3c2c2; }";
     webpage+="@media (min-width: 568px) { .name-item, .city-item { display: flex; flex-wrap: wrap; justify-content: space-between; } .name-item input, .name-item div { width: calc(50% - 20px); } .name-item div input { width: 97%; } .name-item div label { display: block; padding-bottom: 5px; } } table { font-family: arial, sans-serif; width: 90%; align-items: center; } td, th { border: 1px solid #dddddd; text-align: left; padding: 8px; } tr:nth-child(even) { background-color: #dddddd; }";
    webpage += "</style>";
   webpage += "</head>";
   
   webpage += "<body><div class=\"testbox\">";
   webpage +="<form action=\"/\">";
   webpage +="<h1 style=\"right:70px\">  AIRSPEC</h1> <div class=\"banner\"> <h1>Check whether you are safe....</h1> </div> <div class=\"colums\"> <div class=\"item\"> </div> <div class=\"item\"> </div>";

   String IPaddress = WiFi.localIP().toString();
   webpage += "<form action='http://"+IPaddress+"/result"+"' method='GET'>";
   webpage += "&nbsp;&nbsp;&nbsp;&nbsp;Please enter the latitude:<input type='text' name='name_input' size=\"50\">";
   webpage += "Please enter the lognitude:<input type='text' name='address_input' size=\"50\">&nbsp;<input type='submit' value='Enter'>"; // omit <input type='submit' value='Enter'> for just 'enter'
   webpage += "</form>";

   webpage +="</form>";
   webpage +="<h2 style=\"font-size:200%;\">Air quality parameters</h2> <div> </div>";
   webpage +="<div><h3 style=\"font-size:175%;\">PM2.5</h3></div> <p align=\"justify\" style=\"font-size:100%;\">PM2.5 refers to particles that have diameter less than 2.5 micrometres (more than 100 times thinner than a human hair) and remain suspended for longer. These particles are formed as a result of burning fuel and chemical reactions that take place in the atmosphere</p>";
   webpage +="<div><h3 style=\"font-size:175%;\">PM1</h3></div> <p align=\"justify\" style=\"font-size:100%;\">PM1: Ultrafine particles with an aerodynamic diameter less than 1 micrometers. Ultra-fine dust is the most damaging variant of fine particles because the particles penetrate directly through the lungs into the bloodstream and are thus spread to the organs.</p>";
   webpage +="<div><h3 style=\"font-size:175%;\">PM10</h3></div> <p align=\"justify\" style=\"font-size:100%;\">PM10 is any particulate matter in the air with a diameter of 10 micrometers or less, including smoke, dust, soot, salts, acids, and metals. Particulate matter can also be formed indirectly when gases emitted from motor vehicles and industries undergo chemical reactions in the atmosphere.</p> </div>";
   webpage +="</div>";
   //webpage +="";
   webpage += "</body>";
  webpage += "</html>";
  server.send(200, "text/html", webpage);

  
    if (server.args() > 0 ) { // Arguments were received
    for ( uint8_t i = 0; i < server.args(); i++ ) {
      Serial.print(server.argName(i)); // Display the argument
      Argument_Name = server.argName(i);
      if (server.argName(i) == "name_input") {
        Serial.print(" Input received was: ");
        Serial.println(server.arg(i));
        Clients_Response1 = server.arg(i);
        // e.g. range_maximum = server.arg(i).toInt();   // use string.toInt()   if you wanted to convert the input to an integer number
        // e.g. range_maximum = server.arg(i).toFloat(); // use string.toFloat() if you wanted to convert the input to a floating point number
      }
      if (server.argName(i) == "address_input") {
        Serial.print(" Input received was: ");
        Serial.println(server.arg(i));
        Clients_Response2 = server.arg(i);
        // e.g. range_maximum = server.arg(i).toInt();   // use string.toInt()   if you wanted to convert the input to an integer number
        // e.g. range_maximum = server.arg(i).toFloat(); // use string.toFloat() if you wanted to convert the input to a floating point number
      }
    }
  }
  }
//===============================================HTML & CSS=======Side2=========================================
void ShowClientResponse() {
  String webpage;
  webpage =  "<html>";
   webpage += "<head><title>ESP8266 Input Example</title><link href=\"https://fonts.googleapis.com/css?family=Roboto:300,400,500,700\"rel=\"stylesheet\"/>";
   webpage +="<link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.5.0/css/all.css\"integrity=\"sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU\"crossorigin=\"anonymous\"/>";
    webpage += "<style>";
     webpage += "body { min-height: 100%; }body,div,form,input,select,textarea,label,";
     webpage += "p { padding: 0; margin: 0; outline: none; font-family: Roboto, Arial, sans-serif; font-size: 14px; color: #666; line-height: 22px; } h1 { position: absolute; margin: 0; font-size: 40px; color: #fff; z-index: 2; line-height: 83px; } textarea { width: calc(100% - 12px); padding: 5px; } .testbox { display: flex; justify-content: center; align-items: center; height: inherit; padding: 20px; } form { width: 100%; padding: 20px; border-radius: 6px; background: #fff; box-shadow: 0 0 8px #669999; }";
     webpage+=".banner { position: relative; height: 500px; background-image: url(\"https://news.cgtn.com/news/3d3d674d3155444f33457a6333566d54/img/65d4acadc348426faecc19da4a5fbc07/65d4acadc348426faecc19da4a5fbc07.jpg\"); background-size: cover; display: flex; justify-content: center; align-items: center; text-align: center; }";
     webpage+=".banner::after { content: \"\"; background-color: rgba(0, 0, 0, 0.2); position: absolute; width: 100%; height: 100%; } input, select, textarea { margin-bottom: 10px; border: 1px solid #ccc; border-radius: 3px; } input { width: calc(100% - 10px); padding: 5px; } input[type=\"date\"] { padding: 4px 5px; } textarea { width: calc(100% - 12px); padding: 5px; }";
     webpage+=".item:hover p, .item:hover i, .question:hover p, .question label:hover, input:hover::placeholder { color: #669999; } .item input:hover, .item select:hover, .item textarea:hover { border: 1px solid transparent; box-shadow: 0 0 3px 0 #669999; color: #669999; } .item { position: relative; margin: 10px 0; } .item span { color: red; } .week { display: flex; justfiy-content: space-between; }";
     webpage+=".colums { display: flex; justify-content: space-between; flex-direction: row; flex-wrap: wrap; } .colums div { width: 48%; } input[type=\"date\"]::-webkit-inner-spin-button { display: none; } .item i, input[type=\"date\"]::-webkit-calendar-picker-indicator { position: absolute; font-size: 20px; color: #a3c2c2; } .item i { right: 1%; top: 30px; z-index: 1; } input[type=\"radio\"], input[type=\"checkbox\"] { display: none; } label.radio { position: relative; display: inline-block; margin: 5px 20px 15px 0; cursor: pointer; } .question span { margin-left: 30px; } .question-answer label { display: block; } label.radio:before { content: \"\"; position: absolute; left: 0; width: 17px; height: 17px; border-radius: 50%; border: 2px solid #ccc; } input[type=\"radio\"]:checked + label:before, label.radio:hover:before { border: 2px solid #669999; }";  
     webpage+="label.radio:after { content: \"\"; position: absolute; top: 6px; left: 5px; width: 8px; height: 4px; border: 3px solid #669999; border-top: none; border-right: none; transform: rotate(-45deg); opacity: 0; } input[type=\"radio\"]:checked + label:after { opacity: 1; } .flax { display: flex; justify-content: space-around; } .btn-block { margin-top: 10px; text-align: center; align-items: center; } button { width: 150px; padding: 10px; border: none; border-radius: 5px; background: #669999; font-size: 16px; color: #fff; cursor: pointer; } button:hover { background: #a3c2c2; }";
     webpage+="@media (min-width: 568px) { .name-item, .city-item { display: flex; flex-wrap: wrap; justify-content: space-between; } .name-item input, .name-item div { width: calc(50% - 20px); } .name-item div input { width: 97%; } .name-item div label { display: block; padding-bottom: 5px; } } table { font-family: arial, sans-serif; width: 90%; align-items: center; } td, th { border: 1px solid #dddddd; text-align: left; padding: 8px; } tr:nth-child(even) { background-color: #dddddd; }";
    webpage += "</style>";
   webpage += "</head>";

   webpage += "<body><div class=\"testbox\">";
   webpage +="<form action=\"/\">";
   webpage +="<h1 style=\"right:70px\">  AIRSPEC</h1> <div class=\"banner\"> <h1>Your safety level is</h1> </div>";
    
   
   webpage +="<div><table align=\"center\">";
   webpage +="<tr> <th>Parameter</th> <th>Value</th> <th>Normal range</th> </tr>";
   webpage =webpage +"<tr><td>PM1(micrograms)</td><td>" + PM1 + "</td><td>" + "<35" +"</td></tr>";
   webpage =webpage +"<tr><td>PM25(micrograms)</td><td>" +PM25+ "</td><td>" + "51-100" +"</td></tr>";
   webpage =webpage +"<tr><td>PM10(micrograms)</td><td>" +PM10 + "</td><td>" + "<100" +"</td></tr>";
   webpage =webpage +"<tr><td>Temperature(C)</td><td>" +Temperature+ "</td><td>" + "<40" +"</td></tr>";
   webpage =webpage +"<tr><td>Humidity</td><td>" +Humidity+ "%</td><td>" + "0%-100%" +"</td></tr>";
   webpage =webpage +"<tr><td>Pressure(atm)</td><td>" +Pressure+ "</td><td>" + "N/A" +"</td></tr>";

    
    webpage +="</table></div>";

   
   webpage += "</form>";
    //webpage += "<p>Name received was: " + Clients_Response1 + "</p>";
    //webpage += "<p>Address received was: " + Clients_Response2 + "</p>";
   webpage+="</div>";
   webpage += "</body>";
  webpage += "</html>";
  server.send(200, "text/html", webpage); // Send a response to the client asking for input
}




//=========================================================================================================
void handleUpdate() {
  // The value will be passed as a URL argument
  cordinates = server.arg("value");
  Serial.println(cordinates);
  server.send(200,"text/plain","Updated");
}










//=========================================================================================================

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

//===============================
//ESP8266 local server//

  server.on("/", HandleClient);
  server.on("/result", ShowClientResponse);
  server.on("/update",handleUpdate); // use this route to update the sensor value(Use this link to send cordinates from mobile)
  server.on("/server", handleRootPath);    //Associate the handler function to the path(Home of the esp8266 server)
  server.begin();                    //Start the server
  Serial.println("Server listening"); 
}





//==========================================================================================================
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  server.handleClient();
  
  //data="{\"PM1\":\"12\",\"PM25\":\"58\",\"PM10\":\"34\",\"Temperature\":\"45\",\"Humidity\":\"67.45\",\"Pressure\":\"12\"}";
  
  String latitude=Clients_Response1;
  String longnitude=Clients_Response2;
  cordinates=latitude+","+longnitude;
  
  client.loop();
  int value=analogRead(A0);
  if (data!=cpydata){
    //============================
     int count=0;
     float dataArray[6]={0,0,0,0,0,0};
  
     for(int j=0;j<data.length();j++){
        int shift=1;
        String basic="";
        //Serial.println(data[j]==',');
        if(data[j]==':'){
          Serial.println(data[j+shift]);
          while((data[j+shift]!=',')&&(data[j+shift]!='}')){
            basic+=data[j+shift];
            Serial.println(basic);
            shift++;
        }
      }
     if(shift>1){
        float games=basic.toFloat();
        dataArray[count]=games;
        count++;
      
      }
    };
    PM1=dataArray[0];
    Serial.print(dataArray[0]);
    Serial.print(data);
    Serial.print(cpydata);
    PM10=dataArray[1];
    PM25=dataArray[2];
    Temperature=dataArray[3];
    Humidity=dataArray[4];
    Pressure=dataArray[5];
    cpydata=data;
    
  //===============================
    }
  if (cordinates != cpycordinates){
    String str=cordinates;
    const char * c = str.c_str();
    snprintf (msg, 75,c);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outair", msg);
    cpycordinates=cordinates;
    }
  delay(5000);
}
