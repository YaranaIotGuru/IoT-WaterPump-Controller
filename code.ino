#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

#define FIREBASE_HOST "androidstatus-8ebf1.firebaseio.com" // Firebase project URL

//https://yarana-test-default-rtdb.firebaseio.com/
#define FIREBASE_AUTH "AIzaSyAdD0OqUE8lO2JBjaHVE4OUdPZu9n2kO-s" // Firebase secret key

// AIzaSyB5IWMu72Vdse25aW4EyrhcMf_HgMTQJ6o
#define WIFI_SSID "YaranaFiberOffice" // Your WiFi name
#define WIFI_PASSWORD "Yarana@7052" // WiFi password
#define SOIL_MOISTURE_PIN 34 // Soil Moisture sensor pin number

int motor = 2;  // Motor control pin

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(motor, OUTPUT); // Set motor pin as output
  pinMode(SOIL_MOISTURE_PIN, INPUT); // Set soil moisture sensor pin as input

  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is: ");
  Serial.println(WiFi.localIP());

  // Connect to Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("MOTOR_STATUS", "0"); // Initialize Motor status to OFF (0)
}

void loop() {
  // Read soil moisture sensor data
  int sensorValue = analogRead(SOIL_MOISTURE_PIN);
  int moisturePercentage = map(sensorValue, 0, 4095, 100, 0);

  // Constrain moisture value to be within 0-100%
  moisturePercentage = constrain(moisturePercentage, 0, 100);

  // Send soil moisture data to Firebase
  Firebase.setInt("SOIL_MOISTURE", moisturePercentage);
  Serial.print("Soil Moisture Percentage: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  // Fetch Motor status from Firebase
  String fireStatus = Firebase.getString("MOTOR_STATUS");

  // Control motor based on the fetched status
  if (fireStatus == "1") {
    Serial.println("Motor Turned ON");
    digitalWrite(motor, HIGH); // Turn on the Motor
  } else if (fireStatus == "0") {
    Serial.println("Motor Turned OFF");
    digitalWrite(motor, LOW); // Turn off the Motor
  } else {
    Serial.println("Invalid Motor Status! Please send 0 or 1");
  }

  delay(1000); // Delay for stability
}
