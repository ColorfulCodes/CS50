#include <stdbool.h>
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

    // Current issue: why is active led not saving when being restarted when the memory there
    //is indeed written and result is not empty, it is always 0. Also why does log output not
    //work. Also still blinks when stopped, occasionally

    

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

    const struct timespec sleepTime = { 0, 100000000};

    while (true) {
        
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
            GPIO_Value_Type value;
            GPIO_GetValue(button_A_fd, &value);
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
        // Blinking the active LED.
        // reading input only when pressed and turn off other led
        if (active_led == GREEN_LED) {
            GPIO_SetValue(blue_led_fd, GPIO_Value_High);
            GPIO_SetValue(green_led_fd, GPIO_Value_Low);
            nanosleep(&sleepTime, NULL);
            GPIO_SetValue(green_led_fd, GPIO_Value_High);
            nanosleep(&sleepTime, NULL);
        }
        else if (active_led == BLUE_LED) {
            GPIO_SetValue(green_led_fd, GPIO_Value_High);
            GPIO_SetValue(blue_led_fd, GPIO_Value_Low);
            nanosleep(&sleepTime, NULL);
            GPIO_SetValue(blue_led_fd, GPIO_Value_High);
            nanosleep(&sleepTime, NULL);
        }
    }
}


