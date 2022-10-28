#include <PZEM004Tv30.h>
#include <SoftwareSerial.h>

/* Use software serial for the PZEM
 * Pin  Rx (Connects to the Tx pin on the PZEM)
 * Pin  Tx (Connects to the Rx pin on the PZEM)
 * This example uses two software serial instance and two PZEM-004 modules
*/


SoftwareSerial pzemSWSerial(4, 5); //rx tx 4 5
PZEM004Tv30 pzem(pzemSWSerial);

SoftwareSerial pzemSWSerial2(12, 14); //rx tx 12 14
PZEM004Tv30 pzem2(pzemSWSerial2);

void setup() {
    /* Debugging serial */
    Serial.begin(115200);
}

void loop() {
         
    Serial.print("Custom Address:");
    Serial.println(pzem.readAddress(), HEX);

    // Read the data from the sensor
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();

    // Check if the data is valid
    if(isnan(voltage)){
        Serial.println("Error reading voltage");
    } else if (isnan(current)) {
        Serial.println("Error reading current");
    } else if (isnan(power)) {
        Serial.println("Error reading power");
    } else if (isnan(energy)) {
        Serial.println("Error reading energy");
    } else if (isnan(frequency)) {
        Serial.println("Error reading frequency");
    } else if (isnan(pf)) {
        Serial.println("Error reading power factor");
    } else {

        // Print the values to the Serial console
        Serial.print("Voltage: ");      Serial.print(voltage);      Serial.println("V");
        Serial.print("Current: ");      Serial.print(current);      Serial.println("A");
        Serial.print("Power: ");        Serial.print(power);        Serial.println("W");
        Serial.print("Energy: ");       Serial.print(energy,3);     Serial.println("kWh");
        Serial.print("Frequency: ");    Serial.print(frequency, 1); Serial.println("Hz");
        Serial.print("PF: ");           Serial.println(pf);
    }

    Serial.println();
    delay(2000);
    Serial.println("-------------------------");

    Serial.print("Custom Address:");
    Serial.println(pzem2.readAddress(), HEX);

    // Read the data from the sensor
    float voltage2 = pzem2.voltage();
    float current2 = pzem2.current();
    float power2 = pzem2.power();
    float energy2 = pzem2.energy();
    float frequency2 = pzem2.frequency();
    float pf2 = pzem2.pf();

    // Check if the data is valid
    if(isnan(voltage)){
        Serial.println("Error reading voltage");
    } else if (isnan(current)) {
        Serial.println("Error reading current");
    } else if (isnan(power)) {
        Serial.println("Error reading power");
    } else if (isnan(energy)) {
        Serial.println("Error reading energy");
    } else if (isnan(frequency)) {
        Serial.println("Error reading frequency");
    } else if (isnan(pf)) {
        Serial.println("Error reading power factor");
    } else {

        // Print the values to the Serial console
        Serial.print("Voltage: ");      Serial.print(voltage2);      Serial.println("V");
        Serial.print("Current: ");      Serial.print(current2);      Serial.println("A");
        Serial.print("Power: ");        Serial.print(power2);        Serial.println("W");
        Serial.print("Energy: ");       Serial.print(energy2,3);     Serial.println("kWh");
        Serial.print("Frequency: ");    Serial.print(frequency2, 1); Serial.println("Hz");
        Serial.print("PF: ");           Serial.println(pf2);
    }

    Serial.println();
    delay(2000);
}