# GaitSense
(ESP32-C3, C/C++, FreeRTOS, ADC, BLE, ESP-NOW, AWS API Gateway, Lambda, Firebase, TypeScript, React)

- This wearable interfaces with an Fs-ins-16z insole pressure sensor array comprising of 16 FSR (Force Sensing Resistor) sensors.

- It is powered by a 120 mAh LiPo battery with USB-C charging. The sensor readings are captured at 50 Hz via the MCU’s ADC.

- The left wearable records the left foot sensor data and transmits it to the right wearable via ESP-NOW.
  
- The right wearable records the right foot data, combines it with the left foot data, and sends both to the mobile application over BLE.

- FreeRTOS is implemented to create a deterministic architecture by ensuring that wireless transmission does not block sensor sampling

- A binary semaphore is used to synchronize the hardware timer interrupt with the high-priority sampling task.

- Queues are used to safely move data between sensor sampling and wireless tranmission tasks.

- A state machine is implemented to respond to wireless start/stop commands and handle hardware initialization, communication failures and queue overflow faults.

- The mobile app visualizes the force distribution across the foot using a heatmap, while the plot displays the total force summed over all 16 sensors per foot.

- This system enables real-time analysis of pressure distribution in each foot during gait cycles.

  
<br>
<br>
<p align="center">
<img width="1512"   alt="image" src="https://github.com/user-attachments/assets/11913fb6-6b77-46c6-b666-1f65c0c83e0d" />


<br>
  <em>Fig. 1: Circuit Diagram</em>
</p><br>

<p align="center">
<img width="500"   alt="image" src="https://github.com/user-attachments/assets/d9f25340-71f7-4ef2-8c82-00468122a199" />


<br>
  <em>Fig. 2: Routing Layout of 4-Layer PCB</em>
</p><br>

<p align="center">
<img width="900" height="281" alt="image" src="https://github.com/user-attachments/assets/8cf80a89-a078-4014-9371-c363290d6877" />
<br>
  <em> Fig. 3: 3D Model of PCB </em>
</p><br>

<p align="center">
<img width="900" alt="image" src="https://github.com/user-attachments/assets/4e353265-96f8-4eea-b802-aa1139f960bc" />

<br>
  <em>Fig. 4: Enclosure Design Features </em>
</p><br>


<p align="center">
<img width="700"   alt="image" src="https://github.com/user-attachments/assets/fbc0543d-5bf9-4dd8-8f39-3dfd9694cd70" />
<br>
  <em>Fig. 5: Device Components and Features </em>
</p><br>



<p align="center">
<img width="350"   alt="image" src="https://github.com/user-attachments/assets/2e6e940f-9788-48ef-b19f-4f6b325f626e" />


<br>
  <em>Fig. 6: Heatmap Interface in Mobile App </em>
</p><br>


<p align="center">
<img width="350" alt="image" src="https://github.com/user-attachments/assets/00de37b5-00ff-444a-9b5f-292db98a213c" />


<br>
  <em>Fig. 7: Total Force Per Foot Plot </em>
</p><br>





 

 


