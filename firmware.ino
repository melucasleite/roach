#define IN1 8
#define IN2 7
#define IN3 6
#define IN4 5
#define IN5 13
#define IN6 12
#define IN7 11
#define IN8 10

void run_demo()
{
    move_forward();
    delay(1000);
    move_backward();
    delay(1000);
    move_left();
    delay(1000);
    move_right();
    delay(1000);
    stop();
}

void setup()
{
    Serial.begin(115200);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(IN5, OUTPUT);
    pinMode(IN6, OUTPUT);
    pinMode(IN7, OUTPUT);
    pinMode(IN8, OUTPUT);
    stop();
    run_demo();
}

void move_forward()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
}

void move_backward()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
}

void move_right()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
}

void move_left()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
}

void stop()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);
}

void serial_loop()
{
    if (Serial.available() > 0)
    {
        String data = Serial.readStringUntil('\n');
        if (data.equals("305"))
        {
            Serial.println("FORWARD");
            move_forward();
            delay(3000);
            Serial.println("STOP");
            stop();
        }
        Serial.print("You sent me: ");
        Serial.println(data);
    }
}

void loop()
{
    serial_loop();
}
