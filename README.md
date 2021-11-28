# AIRSPEC: An IoT-empowered Air Quality Monitoring System integrated with a Machine Learning Framework to Detect and Predict defined Air Quality parameters

### **Problem statement**

* The air that surrounds us is the main source of our respiration.So, it is undoubtedly vital to state that the balanced air quality is utmost important to the environmental existence including the survival of humankind as well as other animals and plants.

* The air around us contains various harmful substances leading to a gradual deterioration of global air homeostasis. Particulate matter is identified to be a great threat to that homeostasis which includes a mixture of solid particles and liquid droplets found in the air.

* Some of these particles, such as dust, dirt, soot, or smoke, are large or dark enough to be seen with the naked eye. Others are so small they can only be detected using an electron microscope.

* Approach of this project is to implement a platform to display the air quality measurements in user's location and if that area is in danger level, the system that we build sent email to the user. 

### **System Overview**

The IoT based system is comprised of three crucial blocks: the node-red framework (including the dashboard interface), the communication between the node-red framework and node-mcu (through MQTT) and the mobile client (which is accessible via a web portal and a mobile application).


<img src="https://user-images.githubusercontent.com/74449277/134492217-f6e41ddb-5733-42cf-ba87-873f30f22615.png">


### **system functions**

* “airly” air monitoring API
* Node-red framework
* Node-red dashboard representation
* Mosquitto server and protocols
* Mobile client: Web portal and the mobile application

### **System Implementation**

#### **Node-red framework**

Node-red is utilized as the base framework for obtaining the data from airly.org API and for visualizing the data. Further, it is the base for constructing the conventional machine learning model of decision tree prediction which is implemented in order to predict the time-series forecast values of the air parameters. Further, it communicates with the mode-mcu via assigned mqtt broker and the thus, the mobile client in order to process the interests of the users within the application arena.

#### **Node MCU web server implementation**

ESP8266 is used as the webserver for the data transmission between Node-RED dashboard and mobile. Data communication between ESP8266 and Node-RED is occurring through the MQTT communication protocol. The selected broker service is Eclipse Mosquitto. Node MCU and Node-RED both working as publisher and subscriber. Data communication between ESP8266 and mobile is occurring through the HTTP protocol. Here we developed a mobile app and web pages to communicate with the client and view requested data.As the ESP8266 is a local server, mobile phone and ESP8266 should be connected with the same WIFI network, unless it does not work as expected.

#### **Web Portal**

In the system, a web portal has been created for user to input location coordinates from one web page and obtain air quality data from another web page.


### **System functionality achieved**

#### **Node-red framework**

The admin user can enter the coordinates of the location where he prefers to obtain the air quality. The temporal variations and the raw data are visualized through the dashboard of the node-red. Further, the user can request and visualize the immediate past data and obtain the forecasted data through the API as well as the built machine learning model.

In addition to the basic capabilities, the user can download raw data files and data set which is used to develop the machine learning model. Furthermore, the framework is integrated to work with the requests which are adhered through the mqtt requests through the node-mcu and web and mobile portals of the users.

<img src="https://user-images.githubusercontent.com/74449277/134506865-9a42f1d3-fb1b-40f6-a21f-91a376153bc0.png">

#### **Web Portal**
The user visit the web portal and input the current location coordinates and enter. Then user receives air quality data of the location he entered.

https://user-images.githubusercontent.com/74449277/134512210-6de2afd4-f756-4fe3-8c2e-d5995d91be7b.mp4

