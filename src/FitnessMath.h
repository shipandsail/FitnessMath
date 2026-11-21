// FitnessMath: dependency-free fitness and nutrition formulas for DIY trackers.
// BMR (Mifflin-St Jeor 1990), TDEE, MET calories burned, macro calories, BMI.
// Estimates for general wellness, not medical advice. https://snowbelly.app/tools/calorie-calculator/
#ifndef FITNESS_MATH_H
#define FITNESS_MATH_H

namespace FitnessMath {
enum Sex { FEMALE = 0, MALE = 1 };

// Resting energy in kcal/day: 10*kg + 6.25*cm - 5*age + 5 (male) / -161 (female).
inline float bmr(float weightKg, float heightCm, float age, Sex sex) {
  return 10.0f * weightKg + 6.25f * heightCm - 5.0f * age + (sex == MALE ? 5.0f : -161.0f);
}
// Daily energy: BMR x activity factor (1.2 sedentary ... 1.9 extra active).
inline float tdee(float weightKg, float heightCm, float age, Sex sex, float activityFactor) {
  return bmr(weightKg, heightCm, age, sex) * activityFactor;
}
// Calories burned for an activity: MET x 3.5 x kg / 200 per minute.
inline float metCalories(float met, float weightKg, float minutes) {
  return met * 3.5f * weightKg / 200.0f * minutes;
}
// MET values (2024 Adult Compendium of Physical Activities).
const float MET_WALK_2_5_MPH = 3.0f;
const float MET_WALK_3_5_MPH = 4.8f;
const float MET_RUN_6_MPH = 9.3f;
const float MET_CYCLE_12_MPH = 8.0f;
// Energy from macros (Atwater): 4 kcal/g protein and carbs, 9 fat, 7 alcohol.
inline float macroCalories(float proteinG, float carbsG, float fatG, float alcoholG = 0) {
  return 4.0f * proteinG + 4.0f * carbsG + 9.0f * fatG + 7.0f * alcoholG;
}
inline float bmi(float weightKg, float heightCm) { float m = heightCm / 100.0f; return weightKg / (m * m); }
inline float proteinRdaG(float weightKg) { return 0.8f * weightKg; }
}  // namespace FitnessMath
#endif
