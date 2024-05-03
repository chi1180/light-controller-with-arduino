
#include <Arduino.h>
#include <Servo.h>

const int PORT = 9600;
const int servo_pin = 9;
const int sensor = 8;

const int deg = 15;

Servo servo;

void setup()
{
    Serial.begin(PORT);
    servo.attach(servo_pin);

    pinMode(sensor, INPUT);

    servo.write(0);
}

static int is_first = 1;
static int is_none_count = 0;

void loop()
{
    if (digitalRead(sensor)) {
        if (is_first == 1) {
            Serial.println("SERVO IS WORK!!");

            for (int i = 0; i < 3; i ++) {
                servo.write(deg);
                delay(500);
                servo.write(0);
                delay(500);
            }

            is_first = 2;

            if (is_none_count) {
                is_none_count = 0;
            }
        }
    } else if (is_first == 2) {
        if (is_none_count < 6) {
            is_none_count ++;
        } else if (is_none_count == 6) {
            is_none_count = 0;

            Serial.println("SERVO IS EXIT!!");

            servo.write(deg);
            delay(500);
            servo.write(0);

            is_first = 1;
        }
    }

    delay(10000);
}

