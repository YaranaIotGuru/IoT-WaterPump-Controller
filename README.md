# IoT-WaterPump-Controller

**A smart irrigation system that monitors soil moisture levels and controls a water pump remotely via an Android app, using ESP32 and Firebase. This project includes the complete code and APK for seamless IoT automation in smart farming.**

## Features

- 🌱 **Soil Moisture Monitoring**: Continuously monitors soil moisture levels using a soil moisture sensor.
- 📱 **Remote Control**: Control the water pump remotely through an Android app.
- 🔗 **Firebase Integration**: Real-time data storage and retrieval using Firebase.
- ⚡ **ESP32**: Utilizes the ESP32 microcontroller for Wi-Fi connectivity and data processing.
- 🌿 **Smart Irrigation**: Automatically triggers the water pump based on soil moisture thresholds.

## Requirements

- ESP32 microcontroller
- Soil moisture sensor
- Relay module
- Water pump
- Android Studio (for app development)
- Firebase account
## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/IoT-WaterPump-Controller.git
2. **Set Up Firebase**
   
a. Create a Firebase Project:
   - Go to the Firebase Console: https://console.firebase.google.com/
   - Click on "Add Project" and follow the setup wizard to create a new project.

b. Add Firebase Realtime Database:
   - In the Firebase Console, navigate to "Realtime Database".
   - Click on "Create Database" and choose the location for your database.
   - Set up the database rules (you can start with public rules for testing, but make sure to secure it later).

c. Obtain Firebase Credentials:
   - Go to "Project Settings" in the Firebase Console.
   - Under the "General" tab, find your Firebase project’s Web API Key and Realtime Database URL.
   - Note these credentials for configuring your ESP32 and Android app.
3.**ESP32 Setup**
- Install the ESP32 board in the Arduino IDE.
- Open the provided ESP32 code in the Arduino IDE.
- Update the code with your Firebase credentials and Wi-Fi credentials.
- Connect the ESP32 to your computer and upload the code to the board.
  
4.**Android App**
- Open the Android Studio project included in the repository.
- Configure Firebase in the project:
  - Go to "Tools" > "Firebase" in Android Studio to open the Firebase Assistant.
  - Follow the steps to add Firebase to your Android project, including adding the `google-services.json` file.
- Build and install the APK on your Android device.
5. **Connect the Hardware**
  - Wire the soil moisture sensor to the ESP32.
  - Connect the relay module to the ESP32 and the water pump.
6. **Configure Soil Moisture Thresholds:**
    - Adjust the soil moisture thresholds in the ESP32 code according to your requirements.
7. **Run the System**
- Power on the ESP32 and ensure it connects to your Wi-Fi network.
- Open the Android app and use it to monitor soil moisture and control the water pump.
## Video Tutorial

[![Watch the Video](https://img.youtube.com/vi/NFRJDUmAJCE/hqdefault.jpg)](https://youtu.be/NFRJDUmAJCE)

For a detailed walkthrough, watch the video on our channel.

## Channel

Check out more of our projects and tutorials on our YouTube channel: [Yarana IoT Guru](https://www.youtube.com/channel/UCkQdMBElOY6MvhVzzK-DxJQ).

