// Give the pin-numbers a name: 

int buttonPin = 3;     // the number of the pushbutton pin

//INSERT CODE HERE

// Define the variables that will be used to store the password:

//INSET CODE HERE

// Define a variable for showing the pushbutton status
volatile int buttonState = 0;  



void setup() {
  
  Serial.begin(9600);

  // Initialize the LED pins as an output:
  
  //INSERT CODE HERE

  // Initialize the switch pins as an input:
  
  //INSERT CODE HERE

  // Initialize the pushbutton pin as an input - INPUT_PULLUP means that when there is no input the pin is set to high by the arduino. This is done to get a stable signal.
  // If the pin is always high, it means that the button must set the pin to low when pressed for it to make a change - this is called an active low button.
  pinMode(buttonPin, INPUT_PULLUP);

  

  // Attach an interrupt to the button pin. This makes sure that if you press the button the program is told about it immediatly.
  // digitalPinToInterrupt(buttonPin) - this tells which pin to watch out for the button press on.
  // ISR_button_pushed - this is a function. A function is an instruction that is executed when you tell it to. Here we tell it to do the instruction when the button is pressed.
  // What the function/instruction is can be seen in the bottom of the code.
  // FALLING - this means that we are looking for the situation where the pin goes from high to low since our button is active low as previously described.
  attachInterrupt(digitalPinToInterrupt(buttonPin), ISR_button_pushed, FALLING);
  buttonState = 0;  // Reset the buttonState variable to 0 after initializing the interrupt

  // Wait for the first button press - this while-loop will pause the code until the button has been pressed
  while (!buttonState) {
    Serial.println("No button press yet");
    delay(1000);
  }
  // When the first button press has happened the code will continue from here 

  // Read the value of switches and store each switch value in a password variable:

  //INSERT CODE HERE

  // Always reset the buttonState variable after you have acted on the button press so that it is ready to detect a new press:
  buttonState = 0;  

}

void loop() {

  // Use an if-statement here to check if the pushbutton is pressed. If it is, the buttonState is 1:

  
  if () {

    //Inside the if-statement read the value of the switches into the check-password variable - NOT into the password variables 

    //INSERT CODE HERE

    //Use another if-statement to check if the typed in combination matches with the password
    // && means "and" which will make sure that all the digits must be correct at the same time for the combination to match the password.

    if (check_password1 == password1  && check_password2 == password2) {

      // If the combination was correct we turn on the green LED and turn off the red:

      //INSERT CODE HERE
      

    } else {
      // If the combination was not correct we turn the red LED on and the green off:

      //INSERT CODE HERE
      
    }

    // Always reset the buttonState variable after you have acted on the button press so that it is ready to detect a new press:
    buttonState = 0;
  }
}


// The function where we tell the code what to do when the button is pressed.
void ISR_button_pushed(void) {
  buttonState = 1;
}