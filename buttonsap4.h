//=================================================
//  MULTI-CLICK:  One Button, Multiple Events
// Button timing variables
int debounce = 30;          // ms debounce period to prevent flickering when pressing or releasing the button
int DCgap = 250;            // max ms between clicks for a double click event
int holdTime = 2000;        // ms hold period: how long to wait for press+hold event
int longHoldTime = 4000;    // ms long hold period: how long to wait for press+hold event

const int PIN_BUTTON1 = gv_PIN_BUTTON1;
const int PIN_BUTTON2 = gv_PIN_BUTTON2;
const int PIN_BUTTON3 = gv_PIN_BUTTON3;
const int PIN_BUTTON4 = gv_PIN_BUTTON4; // D8 não funcinava... nao testei mais, simnplesmente alterei


// Button variables
boolean buttonVal = HIGH;   // value read from button
boolean buttonLast = HIGH;  // buffered value of the button's previous state
boolean DCwaiting = false;  // whether we're waiting for a double click (down)
boolean DConUp = false;     // whether to register a double click on next release, or whether to wait and click
boolean singleOK = true;    // whether it's OK to do a single click
long downTime = -1;         // time the button was pressed down
long upTime = -1;           // time the button was released
boolean ignoreUp = false;   // whether to ignore the button release because the click+hold was triggered
boolean waitForUp = false;        // when held, whether to wait for the up event
boolean holdEventPast = false;    // whether or not the hold event happened already
boolean longHoldEventPast = false;// whether or not the long hold event happened already

int checkButton() {
   int event = 0;
   buttonVal = digitalRead(PIN_BUTTON1);
   // Button pressed down
   if (buttonVal == LOW && buttonLast == HIGH && (millis() - upTime) > debounce)
   {
       downTime = millis();
       ignoreUp = false;
       waitForUp = false;
       singleOK = true;
       holdEventPast = false;
       longHoldEventPast = false;
       if ((millis()-upTime) < DCgap && DConUp == false && DCwaiting == true)  DConUp = true;
       else  DConUp = false;
       DCwaiting = false;
   }
   // Button released
   else if (buttonVal == HIGH && buttonLast == LOW && (millis() - downTime) > debounce)
   {
       if (not ignoreUp)
       {
           upTime = millis();
           if (DConUp == false) DCwaiting = true;
           else
           {
               event = 2;
               DConUp = false;
               DCwaiting = false;
               singleOK = false;
           }
       }
   }
   // Test for normal click event: DCgap expired
   if ( buttonVal == HIGH && (millis()-upTime) >= DCgap && DCwaiting == true && DConUp == false && singleOK == true && event != 2)
   {
       event = 1;
       DCwaiting = false;
   }
   // Test for hold
   if (buttonVal == LOW && (millis() - downTime) >= holdTime) {
       // Trigger "normal" hold
       if (not holdEventPast)
       {
           event = 3;
           waitForUp = true;
           ignoreUp = true;
           DConUp = false;
           DCwaiting = false;
           //downTime = millis();
           holdEventPast = true;
       }
       // Trigger "long" hold
       if ((millis() - downTime) >= longHoldTime)
       {
           if (not longHoldEventPast)
           {
               event = 4;
               longHoldEventPast = true;
           }
       }
   }
   buttonLast = buttonVal;
   return event;
}

boolean buttonVal2 = HIGH;   // value read from button
boolean buttonLast2 = HIGH;  // buffered value of the button's previous state
boolean DCwaiting2 = false;  // whether we're waiting for a double click (down)
boolean DConUp2 = false;     // whether to register a double click on next release, or whether to wait and click
boolean singleOK2 = true;    // whether it's OK to do a single click
long downTime2 = -1;         // time the button was pressed down
long upTime2 = -1;           // time the button was released
boolean ignoreUp2 = false;   // whether to ignore the button release because the click+hold was triggered
boolean waitForUp2 = false;        // when held, whether to wait for the up event
boolean holdEventPast2 = false;    // whether or not the hold event happened already
boolean longHoldEventPast2 = false;// whether or not the long hold event happened already

int checkButton2() {
   int event = 0;
   buttonVal2 = digitalRead(PIN_BUTTON2);
   // Button pressed down
   if (buttonVal2 == LOW && buttonLast2 == HIGH && (millis() - upTime2) > debounce)
   {
       downTime2 = millis();
       ignoreUp2 = false;
       waitForUp2 = false;
       singleOK2 = true;
       holdEventPast2 = false;
       longHoldEventPast2 = false;
       if ((millis()-upTime2) < DCgap && DConUp2 == false && DCwaiting2 == true)  DConUp2 = true;
       else  DConUp2 = false;
       DCwaiting2 = false;
   }
   // Button released
   else if (buttonVal2 == HIGH && buttonLast2 == LOW && (millis() - downTime2) > debounce)
   {
       if (not ignoreUp2)
       {
           upTime2 = millis();
           if (DConUp2 == false) DCwaiting2 = true;
           else
           {
               event = 2;
               DConUp2 = false;
               DCwaiting2 = false;
               singleOK2 = false;
           }
       }
   }
   // Test for normal click event: DCgap expired
   if ( buttonVal2 == HIGH && (millis()-upTime2) >= DCgap && DCwaiting2 == true && DConUp2 == false && singleOK2 == true && event != 2)
   {
       event = 1;
       DCwaiting2 = false;
   }
   // Test for hold
   if (buttonVal2 == LOW && (millis() - downTime2) >= holdTime) {
       // Trigger "normal" hold
       if (not holdEventPast2)
       {
           event = 3;
           waitForUp2 = true;
           ignoreUp2 = true;
           DConUp2 = false;
           DCwaiting2 = false;
           //downTime = millis();
           holdEventPast2 = true;
       }
       // Trigger "long" hold
       if ((millis() - downTime2) >= longHoldTime)
       {
           if (not longHoldEventPast2)
           {
               event = 4;
               longHoldEventPast2 = true;
           }
       }
   }
   buttonLast2 = buttonVal2;
   return event;
}

boolean buttonVal3 = HIGH;   // value read from button
boolean buttonLast3 = HIGH;  // buffered value of the button's previous state
boolean DCwaiting3 = false;  // whether we're waiting for a double click (down)
boolean DConUp3 = false;     // whether to register a double click on next release, or whether to wait and click
boolean singleOK3 = true;    // whether it's OK to do a single click
long downTime3 = -1;         // time the button was pressed down
long upTime3 = -1;           // time the button was released
boolean ignoreUp3 = false;   // whether to ignore the button release because the click+hold was triggered
boolean waitForUp3 = false;        // when held, whether to wait for the up event
boolean holdEventPast3 = false;    // whether or not the hold event happened already
boolean longHoldEventPast3 = false;// whether or not the long hold event happened already

int checkButton3() {
   int event = 0;
   buttonVal3 = digitalRead(PIN_BUTTON3);
   // Button pressed down
   if (buttonVal3 == LOW && buttonLast3 == HIGH && (millis() - upTime3) > debounce)
   {
       downTime3 = millis();
       ignoreUp3 = false;
       waitForUp3 = false;
       singleOK3 = true;
       holdEventPast3 = false;
       longHoldEventPast3 = false;
       if ((millis()-upTime3) < DCgap && DConUp3 == false && DCwaiting3 == true)  DConUp3 = true;
       else  DConUp3 = false;
       DCwaiting3 = false;
   }
   // Button released
   else if (buttonVal3 == HIGH && buttonLast3 == LOW && (millis() - downTime3) > debounce)
   {
       if (not ignoreUp3)
       {
           upTime3 = millis();
           if (DConUp3 == false) DCwaiting3 = true;
           else
           {
               event = 2;
               DConUp3 = false;
               DCwaiting3 = false;
               singleOK3 = false;
           }
       }
   }
   // Test for normal click event: DCgap expired
   if ( buttonVal3 == HIGH && (millis()-upTime3) >= DCgap && DCwaiting3 == true && DConUp3 == false && singleOK3 == true && event != 2)
   {
       event = 1;
       DCwaiting3 = false;
   }
   // Test for hold
   if (buttonVal3 == LOW && (millis() - downTime3) >= holdTime) {
       // Trigger "normal" hold
       if (not holdEventPast3)
       {
           event = 3;
           waitForUp3 = true;
           ignoreUp3 = true;
           DConUp3 = false;
           DCwaiting3 = false;
           //downTime = millis();
           holdEventPast3 = true;
       }
       // Trigger "long" hold
       if ((millis() - downTime3) >= longHoldTime)
       {
           if (not longHoldEventPast3)
           {
               event = 4;
               longHoldEventPast3 = true;
           }
       }
   }
   buttonLast3 = buttonVal3;
   return event;
}

boolean buttonVal4 = HIGH;   // value read from button
boolean buttonLast4 = HIGH;  // buffered value of the button's previous state
boolean DCwaiting4 = false;  // whether we're waiting for a double click (down)
boolean DConUp4 = false;     // whether to register a double click on next release, or whether to wait and click
boolean singleOK4 = true;    // whether it's OK to do a single click
long downTime4 = -1;         // time the button was pressed down
long upTime4 = -1;           // time the button was released
boolean ignoreUp4 = false;   // whether to ignore the button release because the click+hold was triggered
boolean waitForUp4 = false;        // when held, whether to wait for the up event
boolean holdEventPast4 = false;    // whether or not the hold event happened already
boolean longHoldEventPast4 = false;// whether or not the long hold event happened already

int checkButton4() {
   int event = 0;
   buttonVal4 = digitalRead(PIN_BUTTON4);
   // Button pressed down
   if (buttonVal4 == LOW && buttonLast4 == HIGH && (millis() - upTime4) > debounce)
   {
       downTime4 = millis();
       ignoreUp4 = false;
       waitForUp4 = false;
       singleOK4 = true;
       holdEventPast4 = false;
       longHoldEventPast4 = false;
       if ((millis()-upTime4) < DCgap && DConUp4 == false && DCwaiting4 == true)  DConUp4 = true;
       else  DConUp4 = false;
       DCwaiting4 = false;
   }
   // Button released
   else if (buttonVal4 == HIGH && buttonLast4 == LOW && (millis() - downTime4) > debounce)
   {
       if (not ignoreUp4)
       {
           upTime4 = millis();
           if (DConUp4 == false) DCwaiting4 = true;
           else
           {
               event = 2;
               DConUp4 = false;
               DCwaiting4 = false;
               singleOK4 = false;
           }
       }
   }
   // Test for normal click event: DCgap expired
   if ( buttonVal4 == HIGH && (millis()-upTime4) >= DCgap && DCwaiting4 == true && DConUp4 == false && singleOK4 == true && event != 2)
   {
       event = 1;
       DCwaiting4 = false;
   }
   // Test for hold
   if (buttonVal4 == LOW && (millis() - downTime4) >= holdTime) {
       // Trigger "normal" hold
       if (not holdEventPast4)
       {
           event = 3;
           waitForUp4 = true;
           ignoreUp4 = true;
           DConUp4 = false;
           DCwaiting4 = false;
           //downTime = millis();
           holdEventPast4 = true;
       }
       // Trigger "long" hold
       if ((millis() - downTime4) >= longHoldTime)
       {
           if (not longHoldEventPast4)
           {
               event = 4;
               longHoldEventPast4 = true;
           }
       }
   }
   buttonLast4 = buttonVal4;
   return event;
}


//=================================================
// Events to trigger
void clickEvent() {
  // client.publish(ConvCallLiftCmndPower, "ON");
  Serial.println("Click");
}
void doubleClickEvent() {
   // ledVal2 = !ledVal2;
   // digitalWrite(PIN_LED2, ledVal2);
   Serial.println("DoubleClick");
}

void clickEvent2() {
  // client.publish(shutterKitchenTopicCmndPower, "OPEN");
  // client.publish(shutterLivingTopicCmndPower, "OPEN");
  // client.publish(shutterBed1TopicCmndPower, "OPEN");
  // client.publish(shutterBed2TopicCmndPower, "OPEN");
  // client.publish(shutterBed3TopicCmndPower, "OPEN");
  Serial.println("Click2");
}
void doubleClickEvent2() {
   Serial.println("DoubleClick2");
}

void clickEvent3() {
  // client.publish(shutterBed1TopicCmndPower, "OPEN");
  cmdGoUp(); //envia o comando localmente para caso o broker esteja off ele executa independente..
  // client.publish(ConvDoorEntranceCmndPower, "ON");
  Serial.println("Click3");
}
void doubleClickEvent3() {
   Serial.println("DoubleClick3");
}

void clickEvent4() {
  cmdGoDn();
  // client.publish(shutterKitchenTopicCmndPower, "CLOSE");
  // client.publish(shutterLivingTopicCmndPower, "CLOSE");
  // client.publish(shutterBed1TopicCmndPower, "CLOSE");
  // client.publish(shutterBed2TopicCmndPower, "CLOSE");
  // client.publish(shutterBed3TopicCmndPower, "CLOSE");
  Serial.println("Click4");
}
void doubleClickEvent4() {
   Serial.println("DoubleClick4");
}

void buttonsSetup(){

  pinMode(PIN_BUTTON1, INPUT_PULLUP);
  digitalWrite(PIN_BUTTON1, HIGH);

  pinMode(PIN_BUTTON2, INPUT_PULLUP);
  digitalWrite(PIN_BUTTON2, HIGH);

  pinMode(PIN_BUTTON3, INPUT_PULLUP);
  digitalWrite(PIN_BUTTON3, HIGH);

  pinMode(PIN_BUTTON4, INPUT_PULLUP);
  digitalWrite(PIN_BUTTON4, HIGH);

}

void buttonsLoop(){
  int b = checkButton();
  if (b == 1) clickEvent();
  if (b == 2) doubleClickEvent();


  int c = checkButton2();
  if (c == 1) clickEvent2();
  if (c == 2) doubleClickEvent2();

  int d = checkButton3();
  if (d == 1) clickEvent3();
  if (d == 2) doubleClickEvent3();

  int e = checkButton4();
  if (e == 1) clickEvent4();
  if (e == 2) doubleClickEvent4();

}
