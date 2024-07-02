#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "switch_state_1_handler.h"

char toggle_red()
{                        // Function to toggle the red LED.
  static char state = 0; // Static variable to keep track of the current state.

  switch (state)
  {
  case 0:
    red_on = 1; // Turn the red LED on.
    state = 1;
    break;
  case 1:
    red_on = 0; // Turn the red LED off.
    state = 0;
    break;
  }
  return 1; // Indicate that the LED state has changed.
}

char toggle_green()
{ // Function to toggle the green LED based on the red LED state.
  char changed = 0;
  if (red_on)
  {
    green_on ^= 1; // Toggle the green LED if the red LED is on.
    changed = 1;
  }
  return changed;
}

void led_state_advance()
{
  char changed = 0;
  static enum { R = 0,
                G = 1 } color = G; // Static variable to keep track of the current color state.

  switch (color)
  { // State machine for alternating between red and green LEDs.
  case R:
    changed = toggle_red();
    color = G;
    break;
  case G:
    changed = toggle_green();
    color = R;
    break;
  }

  led_changed = changed; // Update the LED changed flag.
  led_update();          // Update the LEDs.
}

void switch_state_advance()
{
  switch (switch_state)
  {
  case 1:
    switch_state_1_handler(); // Call the assembly function for switch state 1
    break;
  case 2:
    buzzer_set_period(200); // Set the buzzer frequency for switch state 2.
    break;
  case 3:
    buzzer_set_period(700); // Set the buzzer frequency for switch state 3.
    break;
  case 4:
    buzzer_off(); // Turn off the buzzer for switch state 4.
    break;
  }
  led_update(); // Update the LEDs.
}
