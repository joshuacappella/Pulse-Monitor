#define NOTE_A5S 932.3
#define NOTE_A5  880.0
#define NOTE_G5  784.0
#define NOTE_F5  698.5
#define NOTE_E5  659.3
#define NOTE_D5  587.3
#define NOTE_C5  523.3
#define NOTE_B4  493.9
#define NOTE_A4  440.0
#define NOTE_E4  329.6
#define NOTE_D4S 311.1
#define NOTE_B3  246.9
#define NOTE_G3S 207.7 
#define NOTE_REST 0

int buzzerPin = 8; // Speaker connected to D8

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  playCrabRave();       //Recommended for low heart rate, call at will
  playShootingStars();  //Recommended for high heart rate, call at will
}

void playCrabRave() {
  // Define note frequencies and durations
  float crabRave[] = {NOTE_D5, NOTE_A5S, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_D5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_E5, NOTE_F5};
  //int noteDurations[] = {250, 250, 250, 125, 250, 125, 250, 250, 125, 250, 125, 250, 250, 125, 250, 250, 250, 125, 250}; // in milliseconds
  //int noteDurations[] = {167, 167, 167, 83, 167, 83, 167, 167, 83, 167, 83, 167, 167, 83, 167, 167, 167, 83, 167}; // in milliseconds
  int noteDurations[] = {187, 187, 187, 103, 187, 103, 187, 187, 103, 187, 103, 187, 187, 103, 187, 187, 187, 103, 187}; // in milliseconds, adjusted for 30ms playNote delay

  // Play song
  for (int i = 0; i < sizeof(crabRave) / sizeof(crabRave[0]); i++) {
    playNote(crabRave[i], noteDurations[i]);
    delay(10); // Add a small delay between notes
  }
}

void playShootingStars() {
  // Define note frequencies and durations
  float shootingStars[] = {NOTE_D4S, NOTE_REST, NOTE_D4S, NOTE_E4, NOTE_REST, NOTE_B3, NOTE_G3S};
  //int noteDurations[] = {500, 100, 150, 275, 50, 150, 125}; // in milliseconds
  int noteDurations[] = {520, 120, 170, 295, 70, 170, 150}; // in milliseconds, adjusted for 30ms playNote delay

  // Play song
  for (int i = 0; i < sizeof(shootingStars) / sizeof(shootingStars[0]); i++) {
    playNote(shootingStars[i], noteDurations[i]);
    delay(30); // Add a small delay between notes
  }
}

void playNote(float noteFrequency, int duration) {
  tone(buzzerPin, noteFrequency, duration);
  delay(duration + 30); // Add a small delay between notes (30)
  noTone(buzzerPin);
}
