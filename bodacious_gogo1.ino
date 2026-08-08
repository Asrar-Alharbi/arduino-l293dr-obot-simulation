// تعريقات منافذ L293D IC #1 (المحركات اليمنى)
const int motor1_A = 2; // محرك 1 (يمين أمام)
const int motor1_B = 3;
const int motor2_A = 4; // محرك 2 (يمين خلف)
const int motor2_B = 5;

// تعريقات منافذ L293D IC #2 (المحركات اليسرى)
const int motor3_A = 6;  // محرك 3 (يسار أمام)
const int motor3_B = 7;
const int motor4_A = 8;  // محرك 4 (يسار خلف)
const int motor4_B = 11;

void setup() {
  // ضبط جميع منافذ التحكم كمخرجات
  pinMode(motor1_A, OUTPUT); pinMode(motor1_B, OUTPUT);
  pinMode(motor2_A, OUTPUT); pinMode(motor2_B, OUTPUT);
  pinMode(motor3_A, OUTPUT); pinMode(motor3_B, OUTPUT);
  pinMode(motor4_A, OUTPUT); pinMode(motor4_B, OUTPUT);
}

void loop() {
  // 1. للأمام: تتحرك المحركات الأربعة للأمام لمدة 30 ثانية
  moveForward();
  delay(30000); // 30 ثانية

  // 2. للخلف: تعكس المحركات اتجاهها وتتحرك للخلف لمدة 60 ثانية (دقيقة)
  moveBackward();
  delay(60000); // 60 ثانية

  // 3. لليمين ولليسار بالتناوب لمدة دقيقة كاملة (60 ثانية)
  // يتم عمل 6 دورات تناوب (كل دورة: 5 ثوانٍ يمين + 5 ثوانٍ يسار = 10 ثوانٍ)
  for (int i = 0; i < 6; i++) {
    turnRight();
    delay(5000); // 5 ثوانٍ يمين
    
    turnLeft();
    delay(5000); // 5 ثوانٍ يسار
  }

  // إيقاف المحركات مؤقتاً قبل إعادة الحلقة
  stopMotors();
  delay(2000);
}

// دالة الحركة للأمام
void moveForward() {
  digitalWrite(motor1_A, HIGH); digitalWrite(motor1_B, LOW);
  digitalWrite(motor2_A, HIGH); digitalWrite(motor2_B, LOW);
  digitalWrite(motor3_A, HIGH); digitalWrite(motor3_B, LOW);
  digitalWrite(motor4_A, HIGH); digitalWrite(motor4_B, LOW);
}

// دالة الحركة للخلف
void moveBackward() {
  digitalWrite(motor1_A, LOW); digitalWrite(motor1_B, HIGH);
  digitalWrite(motor2_A, LOW); digitalWrite(motor2_B, HIGH);
  digitalWrite(motor3_A, LOW); digitalWrite(motor3_B, HIGH);
  digitalWrite(motor4_A, LOW); digitalWrite(motor4_B, HIGH);
}

// دالة الدوران لليمين (المحركات اليسرى تتقدم واليمنى ترجع للخلف)
void turnRight() {
  digitalWrite(motor1_A, LOW);  digitalWrite(motor1_B, HIGH);
  digitalWrite(motor2_A, LOW);  digitalWrite(motor2_B, HIGH);
  digitalWrite(motor3_A, HIGH); digitalWrite(motor3_B, LOW);
  digitalWrite(motor4_A, HIGH); digitalWrite(motor4_B, LOW);
}

// دالة الدوران لليسار (المحركات اليمنى تتقدم واليسرى ترجع للخلف)
void turnLeft() {
  digitalWrite(motor1_A, HIGH); digitalWrite(motor1_B, LOW);
  digitalWrite(motor2_A, HIGH); digitalWrite(motor2_B, LOW);
  digitalWrite(motor3_A, LOW);  digitalWrite(motor3_B, HIGH);
  digitalWrite(motor4_A, LOW);  digitalWrite(motor4_B, HIGH);
}

// دالة إيقاف جميع المحركات
void stopMotors() {
  digitalWrite(motor1_A, LOW); digitalWrite(motor1_B, LOW);
  digitalWrite(motor2_A, LOW); digitalWrite(motor2_B, LOW);
  digitalWrite(motor3_A, LOW); digitalWrite(motor3_B, LOW);
  digitalWrite(motor4_A, LOW); digitalWrite(motor4_B, LOW);
}