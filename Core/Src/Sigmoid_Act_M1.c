#include <math.h>
#include "Sigmoid_Act_M1.h"
// Sigmoid aktivasyon fonksiyonu
/*float sigmoid_M1(float z) {
    return 1.0f / (1.0f + expf(-z));
}

// Ana fonksiyon: 3 girişten 4 çıktı üretir
void predict_motor_state_M1(float x1, float x2, float x3, float* output) {
    // Ağırlıklar ve biaslar (y0, y1, y2, y3 için)
    float weights[4][3] = {
        {0.2f,  -0.1f,  0.05f},   // y0: hareketsiz
        {0.4f,   0.3f,  0.6f},    // y1: kalkış
        {0.1f,   0.05f, 0.2f},    // y2: hareket
        {-0.3f,  0.2f,  0.1f}     // y3: duruş
    };

    float biases[4] = {-0.3f, -0.2f, -0.1f, 0.0f};

    for (int i = 0; i < 4; i++) {
        float z = x1 * weights[i][0] + x2 * weights[i][1] + x3 * weights[i][2] + biases[i];
        output[i] = sigmoid_M1(z);
    }
}
*/




// Sigmoid aktivasyonu
float sigmoid_M1(float z) {
    return 1.0f / (1.0f + expf(-z));
}

// Normalize edilmiş 3 giriş ile tahmin
float predict_motor_state_M1(float speed_norm, float pos_diff_norm, float current_norm) {
    float w1 = 0.40;
    float w2 = 0.45;
    float w3 = +0.15;
    float bias = 0;

    float z = speed_norm * w1 + pos_diff_norm * w2 + current_norm * w3 + bias;
    return sigmoid_M1(z);
}


float Reverse_sigmoid_M1(float z) {
    return 1.0f / (1.0f + expf(-z));
}

// Normalize edilmiş 3 giriş ile tahmin
float Reverse_predict_motor_state_M1(float speed_norm, float pos_diff_norm, float current_norm) {
    float w1 = 0.40;
    float w2 = 0.45;
    float w3 = +0.15;
    float bias = 0.0;

    float z = speed_norm * w1 + pos_diff_norm * w2 + current_norm * w3 + bias;
    return sigmoid_M1(z);
}
