

#define STATE enum {GREEN_STATE, YELLOW_STATE,  BLINK_STATE, RED_STATE} 

#define GREEN_TIMER_SECONDS 5
#define RED_TIMER_SECONDS 1
#define YELLOW_TIMER_SECONDS 3

STATE currentState = GREEN_STATE
STATE previousState = GREEN_STATE
Int timerValue = GREEN_TIMER_SECONDS

While (1) {
	
	If (buttonPressed && currentState == BLINK_STATE) {
		currentState = previousState;
	}else if (buttonPressed ) { // and in any non-blink state
		previousSTate = currentSTate;
		currentState = BLINK_STATE;
	}else { // button was not pressed, so cover timer elapsed cases
		If (!timer elapsed) {
			Continue;
		}else { // timer did elapse, where do we go?
			If(GREEN_STATE == currentState) {
				previousState = currentState;
				currentState = YELLOW_STATE;
			}
			Else if (YELLOW_STATE == currentState) {
				previousState = currentState;
				currentState = RED_STATE;
			}
			Else { // RED
				previousState = currentState;
				currentState = GREEN_STATE;
			}
		}
	}
}
