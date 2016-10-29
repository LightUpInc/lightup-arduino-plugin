// replace these constants with your 2 data points
// these are sample values that will get you in the ballpark (in degrees C)
// take a temperature reading (= LU_internal_temp1)
// and observe the rawData by Serial.println(rawData) (= LU_internal_data1)
// take another temperature reading (= LU_internal_temp2)
// and observe the rawData by Serial.println(rawData) (= LU_internal_data2)

static float LU_internal_temp1 = 0;
static long LU_internal_data1 = 274;
static float LU_internal_temp2 = 25.0;
static long LU_internal_data2 = 304;

float readTemp() {

  ADMUX = _BV(REFS1) | _BV(REFS0) | _BV(MUX2) | _BV(MUX1) | _BV(MUX0);
  ADCSRB = _BV(MUX5); // the MUX5 bit is in the ADCSRB register

  delay(2); // Wait for ADMUX setting to settle
  ADCSRA |= _BV(ADSC); // Start conversion
  while (bit_is_set(ADCSRA,ADSC)); // measuring

  static uint8_t low = ADCL; // must read ADCL first - it then locks ADCH
  static uint8_t high = ADCH; // unlocks both
  static long result = (high << 8) | low; // combine the two

  // calculate the scale factor
  static float scaleFactor = (LU_internal_temp2 - LU_internal_temp1) / (LU_internal_data2 - LU_internal_data1);

  // now calculate the temperature
  static float LU_internal_temp = scaleFactor * (result - LU_internal_data1) + LU_internal_temp1;

  return LU_internal_temp;
}

void changeTemp(float temp1, long data1, float temp2, long data2) {

  LU_internal_temp1 = temp1;
  LU_internal_data1 = data1;
  LU_internal_temp2 = temp2;
  LU_internal_data2 = data2;
}