#include "Dynami_Battery.h"

Dynami_Battery::Dynami_Battery() {}

void Dynami_Battery::batterySetup()
{
  // Setup charger GPIO as input, without pull up resistor.
  pinMode(chargerPin, INPUT);

  // Initial check for battery connection
  batConnected = isBatteryConnected();
  // Initial check for charger connection
  chargerConnected = isChargerConnected();

  // Initial check for Voltage status
  if (batConnected)
  {
    checkVoltage();
    batPercentageToCells();
  }
}

void Dynami_Battery::batteryLoop()
{

  // Check Voltage routine
  if (millis() > voltageLastCheckTime + voltageFrecuencyCheck)
  {
    if (batConnected)
    {
      checkVoltage();
      updateBatPercToCells();
    }
    voltageLastCheckTime = millis();
  }

  if (millis() > batteryConnectedLastCheckTime + batteryConnectedFrecuencyCheck)
  { // debounce batery
    // battery check routine
    batConnected = isBatteryConnected();

    // Check charger routine
    chargerConnected = isChargerConnected();

    batteryConnectedLastCheckTime = millis(); // debounce counter store
  }

  chargerStatusChanged();
  batteryConnectionStatusChanged();
}

void Dynami_Battery::checkVoltage()
{
  int batteryValueArr[10];
  for (int i = 0; i < 10; i++) // batteryCheckTimes = 10
  {
    batteryValueArr[i] = analogRead(batteryPin);
  }
  sortArray(batteryValueArr, 10);
  batteryValue = (batteryValueArr[4] + batteryValueArr[5] + batteryValueArr[6]) / 3;

  batVoltage = (float)(batteryValue * 3.3 / 4096) * 4.2 / 3.3;
  batPercentage = map(batteryValue, 2900, 4096, 0, 100); // 3.3V as Battery Cut off Voltage & 4.1V as Maximum Voltage
  batPercentage = constrain(batPercentage, 0, 100);
}

bool Dynami_Battery::isBatteryConnected()
{
  if (analogRead(batteryPin) >= 300)
    return true;
  return false;
}

void Dynami_Battery::batteryConnectionStatusChanged()
{
  if (batConnected != batConnectedLast)
  {
    dynamiMediator->Notify(this, "batteryConnectionStatusChanged");

    batConnectedLast = batConnected;
  }
}

bool Dynami_Battery::isChargerConnected()
{
  chargerPinReading = digitalRead(chargerPin);
  if (chargerPinReading == HIGH)
    return true;
  return false;
}

void Dynami_Battery::chargerStatusChanged()
{
  if (chargerPinReading != chargerLastStatus)
  {
    dynamiMediator->Notify(this, "chargerStatusChanged");
    chargerLastStatus = chargerPinReading;
  }
}

void Dynami_Battery::updateBatPercToCells()
{
  int upperTreshold = 10;
  int lowerTreshold = 5;

  if (batPercentage >= (cellsQty * 20) + upperTreshold)
  {
    cellsQty++;
    dynamiMediator->Notify(this, "cellsQtyChanged");
  }
  else if (batPercentage <= ((cellsQty - 1) * 20) - lowerTreshold)
  {
    cellsQty--;
    dynamiMediator->Notify(this,"cellsQtyChanged");
  }
}

void Dynami_Battery::batPercentageToCells()
{
  cellsQty = map(batPercentage, 0, 100, 1, 5);
}