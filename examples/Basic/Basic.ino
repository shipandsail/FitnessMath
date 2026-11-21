#include <FitnessMath.h>
using namespace FitnessMath;

void setup() {
  Serial.begin(9600);
  float b = bmr(70, 175, 30, MALE);              // 1648.75 kcal/day
  float t = tdee(70, 175, 30, MALE, 1.55f);      // ~2556 kcal/day
  float walk = metCalories(MET_WALK_3_5_MPH, 70, 30);  // 30 min brisk walk
  Serial.print("BMR: "); Serial.println(b);
  Serial.print("TDEE: "); Serial.println(t);
  Serial.print("30 min walk kcal: "); Serial.println(walk);
}

void loop() {}
