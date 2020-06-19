#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <applibs/storage.h>

#include <applibs/log.h>
#include <applibs/gpio.h>


const int BUTTON_PRESSED = 0;
const int BUTTON_UNPRESSED = 1;

const int GREEN_LED = 0;
const int BLUE_LED = 1;

int main(void)

{
    // Change this GPIO number and the number in app_manifest.json if required by your hardware.
    //GPIO_OutputMode_PushPull means
    //Low turns LED on, High turns off

    // fd stand for file descriptor : button A_fd
    int button_A_fd = GPIO_OpenAsInput(12);

    //mutable storage means you can mutate the storage, most apis only open a file in read-only mode
    if (button_A_fd < 0) {
        Log_Debug(
            "Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
            strerror(errno), errno);
        return -1;
    }

    // Blue led
    int blue_led_fd = GPIO_OpenAsOutput(10, GPIO_OutputMode_PushPull, GPIO_Value_High);
    if (blue_led_fd < 0) {
        Log_Debug(
            "Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
            strerror(errno), errno);
        return -1;
    }
    // green led 2
    int green_led_fd = GPIO_OpenAsOutput(16, GPIO_OutputMode_PushPull, GPIO_Value_High);

    if (green_led_fd < 0) {
        Log_Debug(
            "Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
            strerror(errno), errno);
        return -1;
    }

    int fd_storage = Storage_OpenMutableFile();
    int active_led;
    // set to unpressed for first run
    int last_button_state = BUTTON_UNPRESSED;

    // check to see if file is empty
    int result = read(fd_storage, &active_led, sizeof(active_led));

    if (result < 0) {
        Log_Debug(
            "Error: Invalid %s %d.\n",
            strerror(errno), errno);
        return -1;
    }

    // check if file is empty
    if (result == 0 || active_led < 0 || active_led > 1) {
        // Default to active LED 1
        active_led = BLUE_LED;
    }

    // 10ms
    const struct timespec sleepTime = { 0, 10000000 };
    // Loop #1
    while (true) {

        // In the first pass turn_led_on is 0 and we turn both leds off.
        // In the second pass turn_led_on is 1 and we turn the active led on.  
        for (int turn_led_on = 0; turn_led_on < 2; ++turn_led_on) {

            if (turn_led_on == 1) {
                if (active_led == BLUE_LED) {
                    GPIO_SetValue(blue_led_fd, GPIO_Value_Low);
                }
                else if (active_led == GREEN_LED) {
                    GPIO_SetValue(green_led_fd, GPIO_Value_Low);
                }

            }
            else {


                GPIO_SetValue(green_led_fd, GPIO_Value_High);
                GPIO_SetValue(blue_led_fd, GPIO_Value_High);
            }

            // Now we read the button every 10ms for 10 times.
            // After 10 times reading the button every 10ms,

            for (int i = 0; i < 10; ++i) {
                GPIO_Value_Type value;
                GPIO_GetValue(button_A_fd, &value);
                Log_Debug(
                    "Button value (%d)\n", value);
                // Processing the button.
                //Turns LED ON; Button not pressed down
                if (value == BUTTON_UNPRESSED) {
                    last_button_state = BUTTON_UNPRESSED;
                }
                else {
                    // if last button state is 1 then now it is being pressed
                    if (last_button_state == BUTTON_UNPRESSED) {
                        // Flip LEDs
                        if (active_led == BLUE_LED) {
                            active_led = GREEN_LED;
                        }
                        else if (active_led == GREEN_LED) {
                            active_led = BLUE_LED;
                        }
                        last_button_state = BUTTON_PRESSED;
                        // sets the pointer to the 0 bit of the file to write
                        lseek(fd_storage, 0, SEEK_SET);
                        write(fd_storage, &active_led, sizeof(active_led));
                    }
                }
                // Sleep for 10ms for the next read.
                nanosleep(&sleepTime, NULL);
            }
        }
    }
}

