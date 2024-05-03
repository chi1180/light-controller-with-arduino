
#include <Arduino.h>
#include <Servo.h>

const int PORT = 9600;
const int servo_pin = 9;
const int sensor = 8;
const int touch_pin = 6;

const int deg = 15;

Servo servo;

void setup()
{
    Serial.begin(PORT);
    servo.attach(servo_pin);

    pinMode(sensor, INPUT);
    pinMode(touch_pin, INPUT);

    servo.write(0);
}

static int is_first = 1;

void loop()
{
    if (digitalRead(sensor)) {
        if (is_first == 1) {
            Serial.println("SERVO IS WORK!!");

            analogWrite(touch_pin, 1);
            for (int i = 0; i < 3; i ++) {
                servo.write(deg);
                delay(500);
                servo.write(0);
                delay(500);
            }
            analogWrite(touch_pin, 0);

            is_first = 2;
        }
    } else if (is_first == 2) {
        Serial.println("SERVO IS EXIT!!");

        analogWrite(touch_pin, 1);
        servo.write(deg);
        delay(500);
        servo.write(0);
        analogWrite(touch_pin, 0);

        is_first = 1;
    }

    delay(10000);
}

