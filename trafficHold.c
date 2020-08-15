#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include <applibs/log.h>
#include <applibs/gpio.h>

// Time lights but constantly check button state in between change

// Good for type checking
//#define STATE enum {GREEN_STATE, YELLOW_STATE,  BLINK_STATE, RED_STATE}
const int GREEN_STATE = 1;
const int RED_STATE = 2;
const int YELLOW_STATE = 3;
const int BUTTON_PRESSED = 0;
int active_led = GREEN_STATE;
//LED_color active_led = GREEN_STATE;

//Declare function
int traffic_light(int, int, int, int, int);

//change all leds to fd

// This function should blink Yellow until button A is pressed to switch to typical working traffic light
void caution_light(int y1, int y2, int btnA, int green_led, int red_led) {
    GPIO_SetValue(green_led, GPIO_Value_High);
    GPIO_SetValue(red_led, GPIO_Value_High);

    // This should blink on and off for one second
    const struct timespec sleepTime = { 1, 0 };
    while (true) {
        //// check to see if button A was pressed
        GPIO_Value_Type value;
        GPIO_GetValue(btnA, &value);
        Log_Debug(
            "Button value (%d)\n", value);


        //when button A is pressed activate working light
        if (value == 0) {
            traffic_light(y1, y2, btnA, green_led, red_led);
        }
        GPIO_SetValue(y1, GPIO_Value_Low);
        GPIO_SetValue(y2, GPIO_Value_Low);
        nanosleep(&sleepTime, NULL);
        GPIO_SetValue(y1, GPIO_Value_High);
        GPIO_SetValue(y2, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);
        
    }


}

//Build Errors: type of defalts to int (need to specify file descriptor)
//function declaration isn't a prototype
// statements have no effect are just comments
//function declaration isn't a prototype
//conflicting types for traffic light

// Pass in file descriptors
int traffic_light(int y1, int y2, int btnA, int green_led, int red_led) {
    // check to see if button A was pressed
    // if so, switch to caution and repeat

    //Define green, yellow and red lights 
    // Blink on different leds
    /*int color1 = green_led;
    int color2 = green_led;
    int off = red_led;*/

    // We need a state machine to check when button is pressed and specific time elapsed.
    const struct timespec sleepTime = { 0, 10000000 };

    while (true) {
        
        // In the first pass turn_led_on is 0 and we turn both leds off.
        // In the second pass turn_led_on is 1 and we turn the active led on.  
        for (int turn_led_on = 0; turn_led_on < 2; ++turn_led_on) {

            if (turn_led_on == 1) {
                if (active_led == RED_STATE) {
                    GPIO_SetValue(red_led, GPIO_Value_Low);
                }
                else if (active_led == GREEN_STATE) {
                    GPIO_SetValue(green_led, GPIO_Value_Low);
                }
                else if (active_led == YELLOW_STATE) {
                    GPIO_SetValue(y1, GPIO_Value_Low);
                    GPIO_SetValue(y2, GPIO_Value_Low);
                }

            }
            else{
                GPIO_SetValue(green_led, GPIO_Value_High);
                GPIO_SetValue(red_led, GPIO_Value_High);
                GPIO_SetValue(y1, GPIO_Value_High);
                GPIO_SetValue(y2, GPIO_Value_High);
            }
        //// for loop to count one second
        //for (int i = 0; i < 100; i++) {
        //    //active led
        //    GPIO_SetValue(off, GPIO_Value_High);
        //    GPIO_SetValue(color1, GPIO_Value_Low);
        //    GPIO_SetValue(color2, GPIO_Value_Low);
        //    nanosleep(&sleepTime, NULL);
        //    GPIO_SetValue(color1, GPIO_Value_High);
        //    GPIO_SetValue(color2, GPIO_Value_High);
        //    nanosleep(&sleepTime, NULL);

        //}
        // Now we read the button every 10ms for 10 times.
        // After 10 times reading the button every 10ms,

            for (int i = 0; i < 10; ++i) {
                GPIO_Value_Type value;
                GPIO_GetValue(btnA, &value);
                Log_Debug(
                    "Button value (%d)\n", value);

                //Turns LED ON; Button not pressed down
                if (value == BUTTON_PRESSED) {
                    return;
                }
                else {
                        // Flip LEDs
                        if (active_led == GREEN_STATE) {
                            active_led = YELLOW_STATE;
                        }
                        else if (active_led == YELLOW_STATE) {
                            active_led = RED_STATE;
                        }
                        else if (active_led == RED_STATE) {
                            active_led = GREEN_STATE;
                        }
                    }
                }
                // Sleep for 10ms for the next read.
                nanosleep(&sleepTime, NULL);
            }
        }

        //if (active_led == GREEN_STATE) {
        //    // switch to red
        //    Log_Debug("Reached the Red\n");
        //    color1 = red_led;
        //    color2 = red_led;
        //    off = green_led;
        //    active_led = RED_STATE;
        //    Log_Debug("Active Led is: %d\n", active_led);
        //}
        //
        //else if (active_led == RED_STATE) {
        //    //switch to yellow
        //    Log_Debug("Reached the Yellow\n");
        //    color1 = y1;
        //    color2 = y2;
        //    off = red_led;
        //    active_led = YELLOW_STATE;
        //}

        //else if (active_led == YELLOW_STATE) {
        //    // switch to green
        //    color1 = green_led;
     //       color2 = green_led;
       //     off = red_led;
        //    active_led = GREEN_STATE;
        //}
        // check to see if button A was pressed
            //uncomment ctrl+k+u
        //GPIO_Value_Type value;
        //GPIO_GetValue(btnA, &value);
        //Log_Debug(
        //    "Button value (%d)\n", value);

        ////when button A is pressed activate working light
        //if (value == 0) {
        //    return;
        //} 
    }

int main(void)
{
    int green_led = GPIO_OpenAsOutput(9, GPIO_OutputMode_PushPull, GPIO_Value_High);
    if (green_led < 0) {
        Log_Debug(
            "Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
            strerror(errno), errno);
        return -1;
    }

    int red_led = GPIO_OpenAsOutput(15, GPIO_OutputMode_PushPull, GPIO_Value_High);
    if (red_led < 0) {
        Log_Debug(
            "Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
            strerror(errno), errno);
        return -1;
    }

    int yellow_led = GPIO_OpenAsOutput(18, GPIO_OutputMode_PushPull, GPIO_Value_High);
    if (yellow_led < 0) {
        Log_Debug(
            "Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
            strerror(errno), errno);
        return -1;
    }

    int yellow_led2 = GPIO_OpenAsOutput(19, GPIO_OutputMode_PushPull, GPIO_Value_High);
    if (yellow_led2 < 0) {
        Log_Debug(
            "Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
            strerror(errno), errno);
        return -1;
    }

    int button_A = GPIO_OpenAsInput(12);
    if (button_A < 0) {
        Log_Debug(
            "Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
            strerror(errno), errno);
        return -1;
    }
    //activate caution blink first
    // pass in light variables
    caution_light(yellow_led, yellow_led2, button_A, green_led, red_led);

    return 0;


}
