const int outputs[5] = {3, 4, 5, 6, 7};
const int interruptPin = 2;
const int longdelay = 10000;
const int shortdelay = 5000;

int countvar = 0;

void setup() {
    //Serial.begin(9600);
    pinMode(interruptPin, INPUT_PULLUP);
    for(int i; i < 5; i++){
        pinMode(outputs[i], OUTPUT);
    }
    attachInterrupt(digitalPinToInterrupt(interruptPin), count, FALLING);
}

void(* resetFunc) (void) = 0; 

void loop() {
    if(countvar == 1){
        ablauf();
    }
    else{
        clear();
    }
}

void ablauf(){
    digitalWrite(outputs[0], HIGH);
    delay(longdelay);
    digitalWrite(outputs[1], HIGH);
    delay(shortdelay);
    digitalWrite(outputs[2], HIGH);
    delay(shortdelay);
    digitalWrite(outputs[1], LOW);
    delay(shortdelay);
    digitalWrite(outputs[3], HIGH);
    delay(shortdelay);
    digitalWrite(outputs[4], HIGH);
    delay(longdelay);
    clear();
    countvar = 0;
}

void count() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();

    if (interrupt_time - last_interrupt_time > 200) {
        if(countvar != 0){
            resetFunc();
        }
        countvar++;
        //Serial.println(countvar);
    }
    last_interrupt_time = interrupt_time;
}

void clear() {
    for(int i=0; i<5; i++){
        digitalWrite(outputs[i], LOW);
    }
}
