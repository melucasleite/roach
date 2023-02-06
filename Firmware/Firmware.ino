#define IN1 8
#define IN2 7
#define IN3 6
#define IN4 5
#define IN5 13
#define IN6 12
#define IN7 11
#define IN8 10
#define UP "308"
#define DOWN "304"
#define LEFT "307"
#define RIGHT "305"
void run_demo()
{
    move_forward();
    delay(2000);
    stop();
    delay(3000);
    move_backward();
    delay(2000);
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
    // run_demo();
}

void m1_forward()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
}

void m2_forward()
{

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void m3_forward()
{
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
}

void m4_forward()
{
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
}
void m1_backward()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
}

void m2_backward()
{

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void m3_backward()
{
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
}

void m4_backward()
{
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
}

void move_forward()
{
    m1_forward();
    m2_forward();
    m3_forward();
    m4_forward();
}

void move_backward()
{
    m1_backward();
    m2_backward();
    m3_backward();
    m4_backward();
}

void move_right()
{
    m1_forward();
    m2_backward();
    m3_backward();
    m4_forward();
}

void move_left()
{
    m1_backward();
    m2_forward();
    m3_forward();
    m4_backward();
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
        if (data.equals(UP))
        {
            move_forward();
            delay(150);
            stop();
        }
        if (data.equals(DOWN))
        {
            move_backward();
            delay(150);
            stop();
        }
        if (data.equals(LEFT))
        {
            move_left();
            delay(150);
            stop();
        }
        if (data.equals(RIGHT))
        {
            move_right();
            delay(150);
            stop();
        }
        
    }
}

void loop()
{
    serial_loop();
}
