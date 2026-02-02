#include "Classify.h"


int classify_motor_state(float* output) {
    int class_idx = 0;
    float max_val = output[0];

    for (int i = 1; i < 4; i++) {
        if (output[i] > max_val) {
            max_val = output[i];
            class_idx = i;
        }
    }

    return class_idx;  // 0: hareketsiz, 1: kalkış, 2: hareket, 3: duruş
}
