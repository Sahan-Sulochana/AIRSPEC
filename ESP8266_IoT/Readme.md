The publish-subscribe network protocol between NodeRED and NodeMCU is established by Mosquitto broker. The NodeMCU web server is implemented
through an Arduino code which is presented here. 

*Then the processed data is communicated to the mobile end-user by the mobile application through NodeMCU server and the users can even view the processed data from NodeRED dashboard via the subscription through Mosquitto. Here, ESP8266 is used to implement the local server for the data transmission between NodeRED dashboard
and mobile or web application. Data communication between ESP8266 and NodeRED occurs through the MQTT communication protocol via the selected broker service of
Mosquitto. Therefore, NodeMCU is working as a subscriber to the NodeRED framework under publish-subscriber architecture, while the NodeRED dashboard works as a client for
the primary server sensor network under a server-client architecture. Data communication between ESP8266 and mobile application occurs through the hyper-text transfer protocol
(HTTP). A web application is also implemented to communicate with the web server and view the requested data. Since the ESP8266 is utilized as the local server, the mobile application and ESP8266 are connected within the same Wi-Fi
network.*  - N. Bandara, S. Hettiarachchi, and P. Athukorala, “Airspec: An iot-empowered air quality monitoring system integrated with a machine learning framework to detect and predict defined air quality parameters,” CoRR, vol. abs/2111.14125, 2021. [Online]. Available: https://arxiv.org/abs/2111.1412
