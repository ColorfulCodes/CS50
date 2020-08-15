while (true) {
        int msec = 0, trigger = 100; /* 10ms */
        clock_t before = clock();
        int msec4 = 0;
        int trigger4 = 100; /* 10ms */
        clock_t before4 = clock();
        
        // reading input only when pressed and turn off other led
        
        // read button every 10 ms
        //off for 100ms
        do {
            // on for 100ms
            if (active_led == GREEN_LED) {
                int msec1 = 0;
                int trigger1 = 100; /* 10ms */
                clock_t before1 = clock();
                // turn on
                GPIO_SetValue(blue_led_fd, GPIO_Value_High);
                GPIO_SetValue(green_led_fd, GPIO_Value_Low);
                do {
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
                    clock_t difference = clock() - before1;
                    msec1 = difference * 1000 / CLOCKS_PER_SEC;

                } while (msec1 < trigger1);

                clock_t difference = clock() - before;
                msec = difference * 1000 / CLOCKS_PER_SEC;

            } while (msec < trigger);
            int msec2 = 0, trigger2 = 100; /* 10ms */
            clock_t before2 = clock();
            do {
                // led off 100
                GPIO_SetValue(green_led_fd, GPIO_Value_Low);
                int msec3 = 0, trigger3 = 100; /* 10ms */
                clock_t before3 = clock();
                do {
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
                    clock_t difference = clock() - before3;
                    msec3 = difference * 1000 / CLOCKS_PER_SEC;

                } while (msec3 < trigger3);

                clock_t difference = clock() - before2;
                msec3 = difference * 1000 / CLOCKS_PER_SEC;

            } while (msec2 < trigger2);
        
            else if (active_led == BLUE_LED) {
                int msec5 = 0;
                int trigger5 = 100; /* 10ms */
                clock_t before5 = clock();
                // turn on
                GPIO_SetValue(green_led_fd, GPIO_Value_High);
                GPIO_SetValue(blue_led_fd, GPIO_Value_Low);
                do {
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
                    clock_t difference = clock() - before5;
                    msec5 = difference * 1000 / CLOCKS_PER_SEC;

                } while (msec5 < trigger5);

                clock_t difference = clock() - before4;
                msec4 = difference * 1000 / CLOCKS_PER_SEC;

                } while (msec4 < trigger4);

                int msec6 = 0, trigger6 = 100; /* 10ms */
                clock_t before6 = clock();

                do {
                    // led off 100
                    GPIO_SetValue(green_led_fd, GPIO_Value_Low);
                    int msec7 = 0, trigger7 = 100; /* 10ms */
                    clock_t before7 = clock();
                    do {
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
                        clock_t difference = clock() - before7;
                        msec7 = difference * 1000 / CLOCKS_PER_SEC;

                    } while (msec7 < trigger7);

                    clock_t difference = clock() - before6;
                    msec6 = difference * 1000 / CLOCKS_PER_SEC;

                } while (msec6 < trigger6);
        }

                printf("Time taken %d seconds %d milliseconds\n",
                    msec / 1000, msec % 1000);
            
            